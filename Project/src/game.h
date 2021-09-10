// Global declarations

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#define GRAVITY 0.35f
#define GAME_OFF 0
#define GAME_ON 1
#define GAME_OVER 2

typedef struct
{
    float x, y;
    float dx,dy;
    char *name;
    int onGround;
    int animFrame;

} Character;

typedef struct
{
    int x, y, w, h;

} Ground;

typedef struct
{
    int x, y;

} Obstacle;

typedef struct
{
    float scrollX;
    int gameStatus;
    int time, score, hiscore;

    Mix_Chunk *jumpSound, *scoreSound;

    // Character
     Character tux;

    // Obstacles
    Obstacle obstacles[50];

    // Grounds
    Ground tiles[100];
    
    //Images
    SDL_Texture *obstacle;
    SDL_Texture *background;
    SDL_Texture *ground;
    SDL_Texture *tuxFrames[3];
    
    SDL_Texture *label, *label2, *label3, *label4, *label5, *label6, *scorel;
    int labelw, labelh, label2w, label2h, label3w, label3h, label4w, label4h, label5w, label5h, label6w, label6h, scorew, scoreh; 

    TTF_Font *font, *font2;

    SDL_Renderer *renderer;

} Game;

void doRender(Game *game);

