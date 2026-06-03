#include <cmath>
#include <random>
#include "cell.h"
#include "gen.h" 

static int state_fill()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> distrib(0,100);
    
    return distrib(gen);
}

void init_kingdoms(int* current_state) {
    int capitalA_row = SIZE / 4;
    int capitalA_col = SIZE / 4;

    int capitalB_row = (3 * SIZE) / 4;
    int capitalB_col = (3 * SIZE) / 4;

    int spawn_radius = 35; 

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int idx = (i * SIZE) + j;

            double dist_to_A = std::sqrt((i - capitalA_row) * (i - capitalA_row) + 
                                         (j - capitalA_col) * (j - capitalA_col));
                                         
            double dist_to_B = std::sqrt((i - capitalB_row) * (i - capitalB_row) + 
                                         (j - capitalB_col) * (j - capitalB_col));

            if (dist_to_A < spawn_radius && dist_to_B < spawn_radius) {
                int roll = state_fill();
                if (roll <= 25){
                    current_state[idx] = FRIEND;
                }else if (roll <= 50){
                    current_state[idx] = FOE;
                }else{
                    current_state[idx] = DEAD;
                }
            }else if (dist_to_A < spawn_radius) {
                current_state[idx] = (state_fill() <= 50) ? FRIEND : DEAD;
            }else if (dist_to_B < spawn_radius) {
                current_state[idx] = (state_fill() <= 50) ? FOE : DEAD;
            }else {
                current_state[idx] = DEAD;
            }
        }
    }
}
