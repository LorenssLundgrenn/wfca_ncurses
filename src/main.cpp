#include <ncursesw/ncurses.h>

#include <string>

#include <constants.h>
#include <connector.h>

// assuming the terminal size remains
// constant throughout runtime
int height, width;

void init_variables() {
    getmaxyx(stdscr, height, width);
}

int main() {
    initscr();
    init_variables();

    printw("Height: %d, Width: %d", height, width);
    
    refresh();
    getch();

    endwin();

    return 0;
}