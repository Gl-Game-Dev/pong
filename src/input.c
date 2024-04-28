#include "input.h"

void checkInput(Player* player, float deltaTime) {
    if (IsKeyPressed(KEY_P)) {
        Pause();
    }
    if (IsKeyDown(KEY_Q)) {
        if (player->rect.y - 10 < 30) {
            player->rect.y = player->rect.y;
        } else {
        player->rect.y -= player->speed * deltaTime;
        }
    }

    if (IsKeyDown(KEY_A)) {
        if ((player->rect.y + 10 + 100) > screenHeight) {
            player->rect.y = player->rect.y;
        } else {
        player->rect.y += player->speed * deltaTime;
        }
    }
}
