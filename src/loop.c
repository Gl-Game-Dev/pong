#include "loop.h"
#include "globals.h"
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

    Texture background = LoadTexture("assets/sprites/pongbackground.png");
    Texture backgroundScrolling = LoadTexture("assets/sprites/pongbackgroundscrolling.png");
    Texture ballSprite = LoadTexture("assets/sprites/ball.png");


    SetTargetFPS(90);               // Set our game to run at 60 frames-per-second
    //ToggleFullscreen();
    //--------------------------------------------------------------------------------------
    float scrollingBackFar; // Far background scrolls slowest
    float scrollingBackMedium; // Far background scrolls slowest

    MainMenu();
    // Main game loop
    while (!WindowShouldClose() && !gameover)    // Detect window close button or ESC key
    {
        //----------------------------------------------------------------------------------
        // Update your variables here
        //----------------------------------------------------------------------------------
        float deltaTime = GetFrameTime();
        scrollingBackFar -= 5.0f *deltaTime;
        scrollingBackMedium -= 15.0f *deltaTime;
        if (scrollingBackFar <= -backgroundScrolling.width*2) scrollingBackFar = 0;
        if (scrollingBackMedium <= -background.width*2) scrollingBackMedium = 0;

        checkInput(&player, deltaTime);
        runAI(&ai, &ball.pos, deltaTime);

        checkUpdateScore();
        updatePhysics(&ball, &aiScoreInt, &playerScoreInt, scoreSound, &player, &ai, hitSound, deltaTime);

        UpdateMusicStream(music); // Keeps music playing smoothly

        BeginDrawing();

            ClearBackground(BLACK);

            // Draw Background
            DrawTextureEx(background, (Vector2){ scrollingBackMedium, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBackMedium, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(backgroundScrolling, (Vector2){ scrollingBackFar, 20 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(backgroundScrolling, (Vector2){ backgroundScrolling.width*2 + scrollingBackFar, 20 }, 0.0f, 2.0f, WHITE);
            // Draw HUD
            DrawText(title.TEXT, title.POSX, title.POSY, title.FONTSIZE, title.COLOR);
            DrawText(playerScore, 15, 0, 30, WHITE);
            DrawText(aiScore, screenWidth - 40, 0, 30, WHITE);
            // Draw boundaries
            DrawRectangle(0, 30, screenWidth, 1, WHITE);
            DrawRectangle(0, screenHeight - 1, screenWidth, 1, WHITE);
            // Draw Player, Ball, and AI
            DrawCircle(ball.pos.x, ball.pos.y, 10., YELLOW);
            DrawRectangle(player.rect.x, player.rect.y, 20, 100, BLUE);
            DrawRectangle(ai.rect.x, ai.rect.y, 20, 100, RED);

        EndDrawing();
    }

    // TODO: De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    StopMusicStream(music);
    UnloadMusicStream(music);
    CloseAudioDevice();

}
