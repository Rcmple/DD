//
// Created by Ivan Novikov on 07.03.2024.
//
#ifndef DARKEST_DUNGEON_LITE_GRAPHICS_H
#define DARKEST_DUNGEON_LITE_GRAPHICS_H



#include <chrono>
#include <cmath>
#include <ncurses.h>


#include "BMPParser/BMP.h"
#include "model/MapGenerators/MapFabric.h"
#include "controller/FSM.h"
#include "controller/Game.h"



struct BlinkingArea { // в каждой area ровно один color
    std::vector<std::vector <std::pair <int, int>>> area;
    std::vector <int> colors;
};


// это набор областей с одним и тем же цветом

class Monitor{
public:
    Monitor();
    ~Monitor();
    void divide_screen(FSMGame &fsm, Map &map);
    void draw_dot(int x, int y);
    void draw_rectangle(int x1, int y1, int x2, int y2);
    void draw_hero_position(int x, int y);
    void make_an_event_loop();
    void make_an_event_loop1(FSMGame &fsm);
    void make_an_event_loop2(FSMGame &fsm);
    void which_move(int input_char, int& x, int& y);
    void draw_colored_dot(int x, int y, int color); // тупо цветная точка (мб помогут функции attron и attroff)
    void draw_colored_rectangle(int x1, int y1, int x2, int y2, int color); //прямоугольник с цветными границами
    void fill_rectangle(int x1, int y1, int x2, int y2, int color); // заливка прясоугольника
    void fill_area(std::pair <int, int> * pairs, int color); // заливка набора квадратов (по идее может пригодиться для отрисовки боя)

    void draw_blinking_rectangle(int x1, int y1, int x2, int y2, short colour_1, short colour_2); // можно юзать либу std::chrono для засекания времени
    void draw_blinking_area(std::vector <std::pair<int, int>>& pairs, short colour_1, short colour_2); //мигающая область
    void draw_circle(int x0, int y0, int r); // не идеальный круг, просто какой-то из каких-то ascii символов (типа *)
    BlinkingArea parse_bmp(std::string filename); //парсим bmp (и вот тут нам придется написать свою либу...)
};
class window_work {
protected:
    WINDOW* cur_win;
    int y_mx, x_mx;
    int y_cur;
    int x_cur;
public:
    //friend class Map;
    virtual void update();
    virtual void resize_win(int new_y, int new_x);
    virtual void paint_sides();

    virtual void draw_dot(int x, int y);
    virtual void draw_rectangle(int x1, int y1, int x2, int y2);
    virtual void draw_colored_dot(int x, int y, int color);
    virtual void draw_colored_rectangle(int x1, int y1, int x2, int y2, int color);
    virtual void draw_blinking_rectangle(int x1, int y1, int x2, int y2, short colour_1, short colour_2);
    virtual void fill_rectangle(int x1, int y1, int x2, int y2, int color);
    virtual void fill_area(std::pair <int, int> * pairs, int color);

};
class Dungeon_Map : public window_work {
public:
    friend class Map;
    friend void Monitor::divide_screen(FSMGame &fsm, Map &map);
    Dungeon_Map(WINDOW* win, int y, int x);
    void display_hero();
    void mv_up(); // Движение вверх
    void mv_down(); // Движение вниз
    void mv_left(); // Движение влево
    void mv_right(); // Движение вправо
    int get_mv(); // Смотрим, что нажал пользователь
};

class Fight_Map : public window_work {
public:
    friend class Map;
    friend void Monitor::divide_screen(FSMGame &fsm, Map &map);
    Fight_Map(WINDOW* win, int y, int x);
};

class Abilities_Map : public window_work {
public:
    friend class Map;
    friend void Monitor::divide_screen(FSMGame &fsm, Map &map);
    Abilities_Map(WINDOW* win, int y, int x);
};
static Monitor cur;

class Text {
public:
    std::string text; 
    int colorPair; 
    bool isBold; // Жирный текст

    Text(const std::string& text, int colorPair, bool isBold = false);

    // Метод для отображения текста
    void display(int x, int y) const;
};


#endif //DARKEST_DUNGEON_LITE_GRAPHICS_H

