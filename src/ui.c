#include "common.h"
#include "raylib.h"

void Pause() {
        char pauseText[29] = "Press SPACE to start the game";
        int pauseFont = 20;
        int posX = centerTextX(pauseText, pauseFont);
        int posY = centerTextY(pauseFont);

    while (!WindowShouldClose()) {  // Check if the user has requested to close the window
        if (IsKeyPressed(KEY_SPACE)) {
            break;
        }
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(pauseText, posX, posY, pauseFont, LIGHTGRAY);
        EndDrawing();
    }
}

void MainMenu() {
    char endTextContinue[21] = "PRESS SPACE TO START";
    char endTextEscape[21] = "PRESS ESCAPE TO EXIT";

    while (!WindowShouldClose()) {  // Check if the user has requested to close the window
        BeginDrawing();
        ClearBackground(BLACK);
        int posXEndContinue = centerTextX(endTextContinue, 30);
        int posXEndEscape = centerTextX(endTextEscape, 20);
        DrawText(endTextContinue, posXEndContinue, screenHeight/2, 30, GREEN);
        DrawText(endTextEscape, posXEndEscape, 20, 20, RED);
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            return;
        }
    }
}

void GameOver(int player) {
    char pauseText[10] = "XXXXXXXXX";
    char endTextContinue[29] = "PRESS SPACE TO CONTINUE";
    char endTextEscape[21] = "PRESS ESCAPE TO EXIT";
    int pauseFont = 20;
    Color endFontColor;
    int posX = centerTextX(pauseText, pauseFont);
    int posY = centerTextY(pauseFont);
    playerScoreInt = 0;
    aiScoreInt = 0;
    gameover = true;

    while (!WindowShouldClose()) {  // Check if the user has requested to close the window
        BeginDrawing();
        ClearBackground(BLACK);
    if (player == 0) {
        char pauseText[] = "YOU WON!!!";
        Color endFontColor = GREEN;
        DrawText(pauseText, posX, posY, pauseFont, endFontColor);
    } else {
        char pauseText[] = "YOU LOST!!!";
        Color endFontColor = RED;
        DrawText(pauseText, posX, posY, pauseFont, endFontColor);
    }
        int posXEndContinue = centerTextX(endTextContinue, 30);
        int posXEndEscape = centerTextX(endTextEscape, 20);
        DrawText(endTextContinue, posXEndContinue, posY + 30, 30, GREEN);
        DrawText(endTextEscape, posXEndEscape, 20, 20, RED);
        if (IsKeyPressed(KEY_SPACE)) {
            gameover = false;
            return;
        }
        EndDrawing();
    }
}
