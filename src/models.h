#ifndef MODELS_H
#define MODELS_H

#include "raylib.h"

typedef struct {
    char    TEXT[5];
    int     POSX;
    int     POSY;
    int     FONTSIZE;
    Color   COLOR;
} TITLE;

typedef struct {
    Rectangle rect;
    float speed;
} Player;

typedef struct {
    Vector2 pos;
    Vector2 Speed;
}BALL;

#endif // MODELS_H
