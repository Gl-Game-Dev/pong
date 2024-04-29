#include "physics.h"
#include "globals.h"
#include <stdlib.h>

void updatePhysics(BALL* ball, int* aiScoreInt, int* playerScoreInt, Sound scoreSound, Player* player, Player* ai, Sound hitSound, float deltaTime) {
    ball->pos.x += ball->Speed.x * deltaTime;
    ball->pos.y += ball->Speed.y * deltaTime;

    Rectangle playerColider = {
        player->rect.x + player->rect.width - 5,
        player->rect.y,
        .001,
        player->rect.height
    };

    Rectangle aiColider = {
        ai->rect.x,   // Start at the current x position of the AI paddle
        ai->rect.y,
        .001,       // Assuming you want a thin collider edge
        ai->rect.height
    };

    if (ball->pos.y > screenHeight - 20) {
        ball->Speed.y *= -1;
    }

    if (ball->pos.y < 30 + 10) {
        ball->Speed.y *= -1;
    }

    if (ball->pos.x > screenWidth) {
        ball->Speed.x *= -1;
        (*playerScoreInt) += 1;
        PlaySound(scoreSound);
        ball->pos.x = (float)screenWidth/2;
        ball->pos.y = (float)screenHeight/2;
        ball->Speed.y = 100;
    }

    if (ball->pos.x < 0) {
        ball->Speed.x *= -1;
        (*aiScoreInt) += 1;
        PlaySound(scoreSound);
        ball->pos.x = (float)screenWidth/2;
        ball->pos.y = (float)screenHeight/2;
        ball->Speed.y = 100;
    }

    // Collision with paddles
    if (CheckCollisionCircleRec(ball->pos, 10, playerColider)) {
        float hitPosition = (ball->pos.y - playerColider.y)/player->rect.height;
        if (hitPosition < 0.5) {
            ball->Speed.y = abs((int)ball->Speed.y) * -1;
        } else {
            ball->Speed.y = abs((int)ball->Speed.y);
        }
        ball->Speed.y += rand() % 100 - 0;
        ball->Speed.x = abs((int) ball->Speed.x);
        PlaySound(hitSound);
    }
    if (CheckCollisionCircleRec(ball->pos, 10, aiColider)) {
        float hitPosition = (ball->pos.y - playerColider.y)/player->rect.height;
        if (hitPosition < 0.5) {
            ball->Speed.y = abs((int)ball->Speed.y) * -1;
        } else {
            ball->Speed.y = abs((int)ball->Speed.y);
        }
        ball->Speed.y += rand() % 100 - 0;
        ball->Speed.x = abs((int) ball->Speed.x) * -1;
        PlaySound(hitSound);
    }
}
