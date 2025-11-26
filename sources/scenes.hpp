#pragma once
#include "base_scenes.hpp"
#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>


class MainScene : public ThreeDScene {


    void listen (Scene*& curr_scene) override {


        this->mouse_position = GetMousePosition ();

        UpdateCamera (&this->camera, CAMERA_FREE);

        return;
    }
    void lock_cursor () {
        return;
    }
};


class StartMenu : public Scene {

    float start_btn_pos[3];
    void update () override {

        const char* welcome   = "Welcome";
        const char* start_txt = "Start";
        auto text_size = MeasureTextEx (GetFontDefault (), start_txt, 64, 6);

        this->start_btn_pos[0] =
        this->screen_width / 2 - (MeasureText (start_txt, 64)) / 2 - 32;
        this->start_btn_pos[1] =
        this->screen_width / 2 - (MeasureText (start_txt, 64)) - 4;
        this->start_btn_pos[2] = text_size.x + 16;
        this->start_btn_pos[3] = text_size.y + 8;

        DrawRectangle (this->start_btn_pos[0], this->start_btn_pos[1],
        this->start_btn_pos[2], this->start_btn_pos[3], RED);

        DrawText (welcome,
        this->screen_width / 2 - (MeasureText (welcome, 128)) / 2, 120, 128, BLACK);
        DrawText (start_txt, this->start_btn_pos[0] + 8, this->start_btn_pos[1], 64, BLACK);
        DrawCircleV (this->mouse_position, 12, BLUE);
    };
    void listen (Scene*& curr_scene) override {
        this->mouse_position = GetMousePosition ();
        // std::cout << this->mouse_position.x << "," << this->mouse_position.y << "\n"
        //           << this->start_btn_pos[0] << this->start_btn_pos[1] << "\n";
        if (this->mouse_position.x >= this->start_btn_pos[0] &&
        this->mouse_position.x <= this->start_btn_pos[2] + this->start_btn_pos[0] &&
        this->mouse_position.y >= this->start_btn_pos[1] &&
        this->mouse_position.y <= this->start_btn_pos[3] + this->start_btn_pos[1]) {
            if (IsMouseButtonPressed (MOUSE_BUTTON_LEFT))
                start_game (curr_scene);
        }
    }
    void start_game (Scene*& curr_scene) {
        Scene* new_scene = new MainScene ();
        delete curr_scene;
        curr_scene = new_scene;
        curr_scene->init ();
    };
};
