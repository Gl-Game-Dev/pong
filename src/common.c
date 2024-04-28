#include "raylib.h"
#include "globals.h"
#include "ui.h"
#include <stdio.h>

int centerTextX(const char *text, int fontSize) {
    int textWidth = MeasureText(text, fontSize);
    return ((screenWidth - textWidth) / 2);
}

int centerTextY(int fontSize) {
    return  (screenHeight - fontSize) / 2;
}

void checkUpdateScore() {
    if (playerScoreInt == 3 || aiScoreInt == 3) {
        if (playerScoreInt == 3) {
            GameOver(0);
        } else {
            GameOver(1);
        }
    }

    sprintf(playerScore, "%d", playerScoreInt);
    sprintf(aiScore, "%d", aiScoreInt);
}
