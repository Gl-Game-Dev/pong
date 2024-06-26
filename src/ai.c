#include "ai.h"
#include "globals.h"

void runAI(Player* ai, Vector2* ball, float deltaSpeed) {
        if (ball->x > (int)(screenWidth - 350)) {
            if (ball->y > ai->rect.y + ai->rect.height/2 && ai->rect.y + ai->rect.height < screenHeight) {
                ai->rect.y += ai->speed * deltaSpeed;
            }
            if (ball->y < ai->rect.y + 50 && ai->rect.y > 30) {
                ai->rect.y -= ai->speed * deltaSpeed;
            }
        }
}
