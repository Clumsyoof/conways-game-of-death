#pragma once

constexpr int SIZE = 100;
constexpr int DEAD = 0;
constexpr int FRIEND = 1;
constexpr int FOE = 2;

void count_neighbours(const int* state, int row, int col, int& countA, int& countB);

void calc_next_gen(const int* current_state, int* next_state);
