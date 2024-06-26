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
    char pausebutton[10] = "P = Pause";
    char upButton[9] = "Q = Up";
    char downButton[9] = "A = Down";

    while (!WindowShouldClose()) {  // Check if the user has requested to close the window
        BeginDrawing();
        ClearBackground(BLACK);
        Vector2 mousePosition = GetMousePosition();
        DrawCircleV(mousePosition, 10, MAROON);
        int posXEndContinue = centerTextX(endTextContinue, 30);
        int posXEndEscape = centerTextX(endTextEscape, 20);
        int controlsY = centerTextY(20);
        int controlsX = centerTextX(pausebutton, 20);
        DrawText(upButton, 10, 10, 20, BLUE);
        DrawText(downButton, 10, 40, 20, BLUE);
        DrawText(pausebutton, 10, 70, 20, BLUE);
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
