#include "loop.h"
#include "raylib.h"

void GameLoop() {
    int posx = centerTextX("PONG", 20);
    TITLE title  = {"PONG", posx - 30, 0, 30, WHITE};


    // Define player, ai, and ball positions and properties
    Rectangle playerRect = { 20, (int)(screenHeight / 2 - 50), 20, 100 };
    Player player = {playerRect, playerSpeed};
    Rectangle aiRect= { screenWidth - 40, (int)(screenHeight / 2 - 50), 20, 100 };
    Player ai = {aiRect, 300};
    BALL ball = {200,200, SpeedX, SpeedY};

    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "Raylib - Pong");
    InitAudioDevice(); // Initialize audio device
    Music music = LoadMusicStream("assets/music/pongbackground.wav");
    SetMusicVolume(music, 0.1f); // Set volume, 0.0f (min) to 1.0f (max)
    PlayMusicStream(music);
    Sound hitSound = LoadSound("assets/sounds/pong.wav");
    Sound scoreSound = LoadSound("assets/sounds/ballscore.wav");

    Texture image = LoadTexture("ball.png");

    SetTargetFPS(90);               // Set our game to run at 60 frames-per-second
    //ToggleFullscreen();
    //--------------------------------------------------------------------------------------

    MainMenu();
    // Main game loop
    while (!WindowShouldClose() && !gameover)    // Detect window close button or ESC key
    {
        //----------------------------------------------------------------------------------
        // Update your variables here
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        checkInput(&player, deltaTime);
        runAI(&ai, &ball.pos, deltaTime);

        checkUpdateScore();
        updatePhysics(&ball, &aiScoreInt, &playerScoreInt, scoreSound, &player, &ai, hitSound, deltaTime);

        UpdateMusicStream(music); // Keeps music playing smoothly

        //  Draw stuff
        //----------------------------------------------------------------------------------

        BeginDrawing();

            ClearBackground(BLACK);

            // Draw text
            DrawText(title.TEXT, title.POSX, title.POSY, title.FONTSIZE, title.COLOR);
            DrawRectangle(0, 30, screenWidth, 1, WHITE);
            DrawRectangle(0, screenHeight - 1, screenWidth, 1, WHITE);
            DrawRectangle(player.rect.x, player.rect.y, 20, 100, BLUE);
            DrawRectangle(ai.rect.x, ai.rect.y, 20, 100, RED);
            DrawTexture(image, ball.pos.x - 10, ball.pos.y -10, WHITE);
            DrawCircle(ball.pos.x, ball.pos.y, 10., WHITE);
            DrawText(playerScore, 15, 0, 30, WHITE);
            DrawText(aiScore, screenWidth - 40, 0, 30, WHITE);

        EndDrawing();
    }

    // TODO: De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    StopMusicStream(music);
    UnloadMusicStream(music);
    CloseAudioDevice();

}
