#include "functions.h"

int bitswap(int input) {
    std::bitset<4> binput = input;
    std::bitset<4> output;
    output[0] = binput[1];
    output[1] = binput[0];
    output[2] = binput[3];
    output[3] = binput[2];
    return (int)output.to_ulong();
}

bool matching_bits(int in1, int in2, int mask) {
    return (in1 & mask) == (in2 & mask);
}