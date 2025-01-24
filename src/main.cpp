#define _XOPEN_SOURCE 700

#include "constants.h"
#include "connector.h"
#include "functions.h"

#include <ncurses.h>
#include <string>
#include <array>
#include <vector>
#include <random>
#include <locale.h>

constexpr int gridw = 5;
constexpr int gridh = 5;
constexpr int area = gridw * gridh;
std::array<std::vector<E_Item>, area> grid {};
std::array<bool, area> collapse_table {};

bool running = true;

void init_variables();
void calculate_entropy();
void collapse_entropy();
void draw();

int main() {
    init_variables();

    setlocale(LC_ALL, "");
    initscr();
    curs_set(0);
    clear();

    while (running) {
        calculate_entropy();
        collapse_entropy();
        draw();

        refresh();
        int ch = getch();
        if (ch == 'q') { 
            running = false;
        }
    }

    endwin();

    return 0;
}

void init_variables() {
    for (int i = 0; i < area; ++i) {
        for (int j = 0; j < N_ITEMS; ++j) {
            grid[i].push_back(static_cast<E_Item>(j));
        }
    }

    collapse_table.fill(false);
}

void draw() {
    clear();
    for (int i = 0; i < area; ++i) {
        int x = i % gridw;
        int y = i / gridw;

        move(y, x);

        if (grid[i].size() == 1) {
            E_Item item = grid[i][0];
            wchar_t character = character_connector[item];
            addnwstr(&character, 1);
        } else {
            addwstr(L" ");
        }
    }

    refresh();
}

void update_local_entropy(int i, int source, int cardinal_mask) {
    std::vector<E_Item> connectable_items {};
    std::vector<E_Item> items = grid[i];
    for (int i =  0; i < (int)items.size(); i++) {
        E_Item item = items[i];
        int target = cardinal_connector[item];
        if (matching_bits(source, target, cardinal_mask)) {
            connectable_items.push_back(item);
        }
    }

    grid[i] = connectable_items;
}

void calculate_entropy() {
    for (int i = 0; i < area; i++) {
        if (grid[i].size() == 1) {
            E_Item item = grid[i][0];
            int source = bitswap(cardinal_connector[item]);

            int x = i % gridw;
            int y = i / gridw;
            if (x > 0)          update_local_entropy(i - 1, source, EAST);
            if (x < gridw-1)    update_local_entropy(i + 1, source, WEST);
            if (y > 0)          update_local_entropy(i - gridw, source, SOUTH);
            if (y < gridh-1)    update_local_entropy(i + gridw, source, NORTH);
        }
    }
}

void collapse_entropy() {
    int min_entropy = INT_MAX;
    std::vector<int> index_bank {};

    for (int i = 0; i < area; i++) {
        int entropy = grid[i].size();
        if (entropy < min_entropy && !collapse_table[i]) {
            min_entropy = entropy;
            index_bank.clear();
            index_bank.push_back(i);
        } else if (entropy == min_entropy) {
            index_bank.push_back(i);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    int index;

    if (index_bank.empty()) {
        std::uniform_int_distribution<> dist(0, grid.size() - 1);
        index = dist(gen);
    } else {
        std::uniform_int_distribution<> dist(0, index_bank.size() - 1);
        index = index_bank[dist(gen)];
    }

    int n_items = grid[index].size();
    std::uniform_int_distribution<> dist(0, n_items - 1);
    grid[index] = { grid[index][dist(gen)] };
    collapse_table[index] = true;
}