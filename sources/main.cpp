#include "raylib.h"
#include "scenes.hpp"
#include <iostream>
#include <string>

#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)

#define WINDOW_TITLE "Two Player FNAF"


int main () {
    InitWindow (SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS (120);

    Scene* curr_scene = new StartMenu ();
    curr_scene->screen_height = SCREEN_HEIGHT;
    curr_scene->screen_width  = SCREEN_WIDTH;
    SetConfigFlags (FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    while (!WindowShouldClose ()) {
        BeginDrawing ();

        ClearBackground (RAYWHITE);

        curr_scene->listen (curr_scene);
        curr_scene->update ();

        EndDrawing ();
    }

    CloseWindow ();

    return 0;
}
