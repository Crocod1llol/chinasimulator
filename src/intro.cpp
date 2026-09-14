extern "C" {
    #include "../lib-include/raylib.h"
}

//include timer stuff caus important
typedef struct Timer {

    double lifetime;

    //make start_time automatically begin with the GetTime
    double start_time = GetTime();
} Timer;

bool isTimerDone(Timer *timer);

int GetRemainingTime(Timer* timer);

//music
//the most beautiful track i have ever heard
Music intro_music;

//the background image
Texture2D intro_background;

//timer for intro
Timer intro_duration = {21.5};

bool intro_game() {

    //continue playing the music
    UpdateMusicStream(intro_music);

    BeginDrawing();
    ClearBackground(GRAY);

    //draw raylib logo at the beggining because its an awesome library
    if (GetRemainingTime(&intro_duration) > 17) {

        DrawRectangle(GetRenderWidth()/2 - 128, GetRenderHeight()/2 - 128, 256, 256, BLACK);
        DrawRectangle(GetRenderWidth()/2 - 112, GetRenderHeight()/2 - 112, 224, 224, RAYWHITE);
        DrawText("raylib", GetRenderWidth()/2 - 44, GetRenderHeight()/2 + 48, 50, BLACK);
    } else {
        //draw my name after the raylib logo ends
        
        DrawText("Crocod1l prezents:", 255, 100, 55, GREEN);
    }

    //draw "chinasimulator" when teh music's drop occurs
    if (GetRemainingTime(&intro_duration) < 16) {

        DrawText("chinasimulator", 231, 360, 80, BLACK);
    }

    if (GetRemainingTime(&intro_duration) < 9) {

        DrawTexture(intro_background, 0, 0, WHITE);
    }
    
    //draw text on bottom left to tell that this can be skipped
    DrawText("Press space to skip intro", 10, 750, 16, BLACK);

    EndDrawing();

    return isTimerDone(&intro_duration);
}

//also init intro assets 
void init_intro() {

    //good music = priority
    intro_music = LoadMusicStream("resources/music/intro1.mp3");
    intro_music.looping = false;

    PlayMusicStream(intro_music);

    intro_background = LoadTexture("resources/img/other/intro_background_1000x800.png");
}
