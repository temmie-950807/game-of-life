#ifndef DRAW_H
#define DRAW_H

#include <GLFW/glfw3.h>

#include "board.h"
#include "item.h"

void print_cell(double x, double y){
    // scale ratio, [0~49] -> [-1, 1]
    x=x/25-1; 
    y=y/25-1;

    // len = 2 / board size
    double len=0.04;

    // print square
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x+len, y);
    glVertex2f(x+len, y+len);
    glVertex2f(x, y+len);
    glEnd();
    return;
}

void print(Board board){
    bool status;

    // traverse board
    for (int y=0;y<board.get_size();y++){
        for (int x=0;x<board.get_size();x++){
            status = board.get(x, y);
            if(status){
                print_cell(x, y);
            }
        }
    }

    return;
}

#endif