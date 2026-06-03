#include "gen.h"
void calc_next_gen(const int* current_state,int* next_state)
{
    for(int i = 0;i < SIZE;i++) {
        for(int j = 0;j < SIZE;j++) {
            int countA = 0;
            int countB =0;

            count_neighbours(current_state,i,j,countA,countB);
            int idx = (i * SIZE) + j;
            int current_cell = current_state[idx];

            switch (current_cell) {
                case FRIEND:
                    if (countB > 0) {
                        next_state[idx] = DEAD; 
                    } else if (countA < 2 || countA > 3) {
                        next_state[idx] = DEAD; 
                    } else {
                        next_state[idx] = FRIEND; //idt we need this idk tho
                    }
                    break; 

                case FOE:
                    if (countA > 0) {
                        next_state[idx] = DEAD; 
                    } else if (countB < 2 || countB > 3) {
                        next_state[idx] = DEAD;
                    } else {
                        next_state[idx] = FOE; //same thing here
                    }
                    break; 
                case DEAD:
                default:
                    if (countA == 3) {
                        next_state[idx] = FRIEND;
                    } else if (countB == 3) {
                        next_state[idx] = FOE;
                    } else {
                        next_state[idx] = DEAD;
                    }
                    break;
            }
        }
    }
}

void count_neighbours(const int* state,int rows,int cols,int& countA,int& countB)
{
    countA = 0;
    countB = 0;
    for(int c = -1;c <= 1;c++){
        for(int r = -1;r <= 1;r++){
            if(r == 0 && c == 0) continue;

            int target_c = (cols + c + SIZE) % SIZE;
            int target_r = (rows + r + SIZE) % SIZE;
            
            int neighbour_state = state[(target_r * SIZE) + target_c];
            
            if(neighbour_state == FRIEND){
                countA++;
            }else if(neighbour_state == FOE){
                countB++;
            }else{
                continue;
            }
        }
    }
}

