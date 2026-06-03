#include <raylib.h>
#include "cell.h"
#include "gen.h"
#include <stdlib.h>
#define DEAD 0
#define FRIEND 1
#define FOE 2
#define SIZE 100

int main(int arg,char** argc)
{
    int* current_state = (int*)std::calloc(SIZE*SIZE,sizeof(int));
    int* next_state = (int*)std::calloc(SIZE*SIZE,sizeof(int));
    
    init_kingdoms(current_state); 

    InitWindow(800,800,"conway");
    SetTargetFPS(60);

    float update = 0.1f;
    float time = 0.0f;

    while(!WindowShouldClose())
    {
        time += GetFrameTime();
        bool update_universe = false;
        
        if(time >= update){
            update_universe = true;
            time -= update;
        }

        if(update_universe){
            calc_next_gen(current_state,next_state);

            int* temp =current_state;
            current_state = next_state;
            next_state=temp;
        }
        
        BeginDrawing();
        ClearBackground(DARKGRAY);
        
        for (int i = 0; i < SIZE*SIZE; i++) {
            if (current_state[i] != DEAD) {
                int r = i / SIZE;
                int c = i % SIZE;

                int x = c * 8;
                int y = r * 8;

                if(current_state[i] == FRIEND){
                    DrawRectangle(x,y,7,7,LIME);
                }else if (current_state[i] == FOE){
                    DrawRectangle(x,y,7,7,PINK);
                }
            }
        }
        EndDrawing();
    }
    std::free(current_state);
    std::free(next_state);
    CloseWindow();

    return 0;
}
