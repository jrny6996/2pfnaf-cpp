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
    std::vector<Vector4> scene_objects;
    Camera camera = { 0 };
    void init () override {
        Vector4 box_vector{};
        // this->scene_objects.push_back (box_vector);
    };
   
};
