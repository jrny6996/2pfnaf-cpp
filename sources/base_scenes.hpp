#pragma once

#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>

class Scene {

    public:
    int screen_width;
    int screen_height;
    Vector2 mouse_position;
    Scene () {};
    virtual void update () {
        return;
    };

    virtual void listen (Scene*& curr_scene) {
        return;
    }
    virtual void init () {
        return;
    }
};
class ThreeDScene : public Scene {
    public:
    std::vector<Vector3> scene_objects;
    Camera3D camera = { 0 };

    void init () override {
        Vector3 box_vector{};
        DisableCursor ();

        this->camera.position = (Vector3){ 0.0f, 10.0f, 10.0f }; // Camera position
        this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f }; // Camera looking at point
        this->camera.up =
        (Vector3){ 0.0f, 1.0f, 0.0f }; // Camera up vector (rotation towards target)
        this->camera.fovy       = 45.0f; // Camera field-of-view Y
        this->camera.projection = CAMERA_PERSPECTIVE;


        this->scene_objects.push_back (box_vector);
    };

    void update () override {
        BeginMode3D (this->camera);
        DrawCube (this->scene_objects[0], 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires (this->scene_objects[0], 2.0f, 2.0f, 2.0f, MAROON);

        DrawGrid (10, 1.0f);

        EndMode3D ();
        // DrawCircleV (this->mouse_position, 12, BLUE);
    }
};
