#include "raylib.h"
#include "scenes.hpp"
#include <iostream>
#include <string>

#define SCREEN_WIDTH (1920)
#define SCREEN_HEIGHT (1080)

#define WINDOW_TITLE "Two Player FNAF"


int main () {
    // SetConfigFlags (FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_FULLSCREEN_MODE);  

    InitWindow (SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS (120);

    Scene* curr_scene = new StartMenu ();
    curr_scene->screen_height = SCREEN_HEIGHT;
    curr_scene->screen_width  = SCREEN_WIDTH;

    while (!WindowShouldClose ()) {
        BeginDrawing ();

        ClearBackground (RAYWHITE);

        curr_scene->listen (curr_scene);
        curr_scene->update();

        EndDrawing ();
    }

    CloseWindow ();

    return 0;
}
