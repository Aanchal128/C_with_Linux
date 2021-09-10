#include "state.h"

// initialize obstacles positions
void init_obstacles(Game *game)
{
    for(int i = 0; i < 50; i++)
    {
        if(i == 0)
            game->obstacles[i].x = 320;
        else
            game->obstacles[i].x = game->obstacles[i-1].x+80 + random() % (1200);
        game->obstacles[i].y = 376;
    }
}

// Initialize game objects
void initGame(Game *game)
{
    SDL_Surface *surface = NULL;

    // Background image
    surface = IMG_Load("Assets/BG.png");
    if(surface == NULL)
    {
        printf("Cannot find image!!\n");
        SDL_Quit();
        // to return from main when not in main call sys fun exit()
        exit(1);
    }
 
    game->background = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    // Obstacle image
    surface = IMG_Load("Assets/Crystal.png");
    if(surface == NULL)
    {
        printf("Cannot find image!!\n");
        SDL_Quit();
        // to return from main when not in main call sys fun exit()
        exit(1);
    }
 
    game->obstacle = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    
    // main character image in idle mode
    surface = IMG_Load("Assets/penguin.png");
    if(surface == NULL)
    {
        printf("Cannot find image!!\n");
        SDL_Quit();
        exit(1);
    }
 
    game->tuxFrames[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    
    // main character image in walk mode
    surface = IMG_Load("Assets/penguinwalk.png");
    if(surface == NULL)
    {
        printf("Cannot find image!!\n");
        SDL_Quit();
        exit(1);
    }
 
    game->tuxFrames[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    // main character image in jump mode
    surface = IMG_Load("Assets/penguinjump.png");
    if(surface == NULL)
    {
        printf("Cannot find image!!\n");
        SDL_Quit();
        exit(1);
    }
 
    game->tuxFrames[2] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    // ground tile image
    surface = IMG_Load("Assets/tile.png");
    if(surface == NULL)
    {
        printf("Cannot find image!!\n");
        SDL_Quit();
        exit(1);
    } 
    game->ground = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    // Load Sounds
    game->jumpSound = Mix_LoadWAV("Assets/jump.wav");
    Mix_VolumeChunk(game->jumpSound, 192);
    game->scoreSound = Mix_LoadWAV("Assets/score.wav");
    

    game->gameStatus = GAME_OFF;
    game->scrollX = 0;
    game->time = 0;
    game->score = 0, game->hiscore = 0;

    // main character initial position
    game->tux.x = 100;
    game->tux.y = 400-28;
    game->tux.dx = 0.25;   
    game->tux.dy = 0;

    game->tux.onGround = 1;
    game->tux.animFrame = 0;
    
    // Load fonts
    game->font2 = TTF_OpenFont("Assets/font.ttf",24);
    game->font = TTF_OpenFont("Assets/font2.ttf", 48);
    if(!game->font)
    {
        printf("Cannot find font!!\n");
        SDL_Quit();
        exit(1);
    }

    // Initialize obstacle positions
    init_obstacles(game);
    
    // Init tiles positions
    for(int i = 0; i < 100; i++)
    {
        game->tiles[i].w = 128;
        game->tiles[i].h = 64;
        game->tiles[i].x = i*128;
        game->tiles[i].y = 420;
    }
    
    init_status(game);
}

// game process
void process(Game *game)
{
    if(game->gameStatus == GAME_ON)
    {
        shutdown_status(game);
        game->time++;
        if(game->time%6 == 0)
            game->score++;
        if(game->score%100 == 0)
            Mix_PlayChannel(-1, game->scoreSound, 0);
        
        Character *tux = &game->tux;
    
        // accelerate in forward direction
        tux->x += tux->dx;
        tux->y += tux->dy;

        if(tux->onGround)
        {
            if(game->time%8 == 0)   // every 8 frames
            {
                tux->dx += 0.25;
                if(tux->dx > 18)
                    tux->dx *= 0.25;
                if(tux->animFrame == 0)// change frame of character(walking)
                    tux->animFrame = 1;
                else
                    tux->animFrame = 0;
            }
        
        }

        tux->dy += GRAVITY;

        // screen moves forward with character
        game->scrollX = -game->tux.x+60;
    }

    if(game->gameStatus == GAME_OVER)
    {
        // Update high score
        if(game->hiscore == 0 || game->score > game->hiscore)
            game->hiscore = game->score;
    }
     
}

// Bounding box collision detection
int boxcollide(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2)
{
    return(!((x1 > (x2+wt2)) || (x2 > (x1+wt1)) || (y1 > (y2+ht2)) || (y2 > (y1+ht1))));
}

void collisionDetect(Game *game)
{
    // if character collides with the obstacle
    for(int i = 0; i < 50; i++)
    {
        // in case of direct crash with obstacle on ground
        if(game->tux.onGround)
        {
            if(boxcollide(game->tux.x, game->tux.y,game->obstacles[i].x, game->obstacles[i].y, 48-6, 48, 48, 48))
            {
                game->gameStatus = GAME_OVER;
                break;
            }
        }
        // crash while jumping
        else
        {
            if(boxcollide(game->tux.x, game->tux.y,game->obstacles[i].x+48/3+1, game->obstacles[i].y+2, 48-5, 48-3, 48/3-4, 48/3-4) || boxcollide(game->tux.x, game->tux.y,game->obstacles[i].x+3, game->obstacles[i].y+48/3+6, 48-5, 48-3, 48/3, 2*48/3))
            {
                game->gameStatus = GAME_OVER;
                break;
            }
        } 
    }

    // Check for landing on ground
    for(int i = 0; i < 100; i++)
    {
        float tw = 48, th = 48;
        float tx = game->tux.x, ty = game->tux.y;
        float bx = game->tiles[i].x, by = game->tiles[i].y, bw = game->tiles[i].w;

        if(tx+tw > bx && tx < bx+bw)
        {
            // landing on ground after jump
            if(ty+th > by && ty < by && game->tux.dy > 0)
            {
                // correct y
                game->tux.y = by-th;
                ty = by-th;

                // stop jump velocity                
                game->tux.dy = 0;
                game->tux.onGround = 1;
            }
        }
    }
}

// Get input from keyboard
int gameEvents(SDL_Window *window, Game *game)
{
    int done = 0;
    SDL_Event event;

    // Check for events
    // SDL_PollEvent -> returns true if there is an event waiting to be processed
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {   
            case SDL_WINDOWEVENT_CLOSE:
            {
                if(window)
                {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    done = 1;

                }
            }
            break;
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:   // exit from game loop
                        done = 1;
                    break;
                    case SDLK_UP:      // jump
                        if(game->gameStatus == GAME_ON)
                        {
                            Mix_PlayChannel(-1, game->jumpSound, 0);    
                            if(game->tux.onGround)
                            {
                                game->tux.dy = -7;
                                game->tux.onGround = 0;
                            }
                        }
                    break;
                    case SDLK_SPACE:    // start game process
                        if(game->gameStatus == GAME_OFF)
                            game->gameStatus = GAME_ON;
                        else if(game->gameStatus == GAME_OVER)
                        {
                            // Reset everything
                            game->scrollX = 0;
                            game->time = 0;
                            game->score = 0;
                             
                            game->tux.x = 100;
                            game->tux.y = 400-28;   
                            game->tux.dy = 0;
                            game->tux.dx = 0.25;

                            game->tux.onGround = 1;
                            game->tux.animFrame = 0;

                            game->gameStatus = GAME_ON;
                            
                            // Obstacles on new random positions
                            init_obstacles(game);

                        }
                    break;
                }

            }
            break;
            case SDL_QUIT:
                done = 1;
            break;

        }

    }
    
    return done;
}

// show score
void showScore(Game *game)
{
    char str[20] = "";
    
    if(!game->hiscore)
    { 
        sprintf(str,"%d",game->score);
    }
    else
    {   
        sprintf(str,"HI %d %d",game->hiscore,game->score);
    }


    SDL_Color black = {0, 0, 0, 255};

    SDL_Surface *tmp = NULL;
    tmp = TTF_RenderText_Blended(game->font2, str, black);
    game->scorew = tmp->w;
    game->scoreh = tmp->h;
    
    game->scorel = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
   
    SDL_Rect textRect = {500, 5, game->scorew, game->scoreh};
    SDL_RenderCopy(game->renderer, game->scorel, NULL, &textRect);

    SDL_DestroyTexture(game->scorel);
    game->scorel = NULL;
}

// Draw iamges
void doRender(Game *game)
{
    // Background
    SDL_RenderCopy(game->renderer, game->background, NULL, NULL);
    
    // start screen
    if(game->gameStatus == GAME_OFF)
        showMessage(game);

    // game over screen
    if(game->gameStatus == GAME_OVER)
    {     
        gameOver(game);
    }

    // draw ground       
    for(int i = 0; i < 100; i++)
    {
        // store co-ordinates of image and width, height in a struct
        SDL_Rect groundRect = {game->scrollX+game->tiles[i].x, game->tiles[i].y, game->tiles[i].w, game->tiles[i].h};
        SDL_RenderCopy(game->renderer, game->ground, NULL, &groundRect);
    }
    
    // draw idle and walk frame when it is on ground
    if(game->tux.onGround)
    {
        // Create a rectangle at character's position
        //  rect->struct
        SDL_Rect rect = {game->scrollX+game->tux.x, game->tux.y, 48, 48};
        SDL_RenderCopyEx(game->renderer, game->tuxFrames[game->tux.animFrame], NULL, &rect, 0, NULL, 0);
    }
    // draw jump frame when not on ground
    else
    {
        SDL_Rect rect = {game->scrollX+game->tux.x, game->tux.y, 48, 48};
        SDL_RenderCopyEx(game->renderer, game->tuxFrames[2], NULL, &rect, 0, NULL, 0);

    }

    // Draw obstacle image
    for(int i = 0; i < 50; i++)
    {
        SDL_Rect ObstacleRect = {game->scrollX+game->obstacles[i].x, game->obstacles[i].y, 48, 48};
        SDL_RenderCopy(game->renderer, game->obstacle, NULL, &ObstacleRect);
    }
    
    // show game score when game is on and game is over
    if(game->gameStatus != GAME_OFF)
        showScore(game);
 
    // Present on window
    SDL_RenderPresent(game->renderer);
}

// free memory
void shutdownGame(Game *game)
{
    SDL_DestroyTexture(game->obstacle); 
    SDL_DestroyTexture(game->tuxFrames[0]);
    SDL_DestroyTexture(game->tuxFrames[1]);
    SDL_DestroyTexture(game->tuxFrames[2]);
    SDL_DestroyTexture(game->ground);
    SDL_DestroyTexture(game->background);
    
    if(game->label != NULL)
        SDL_DestroyTexture(game->label);
    if(game->label2 != NULL)
        SDL_DestroyTexture(game->label2);
    if(game->label3 != NULL)
        SDL_DestroyTexture(game->label3);
    if(game->label4 != NULL)
        SDL_DestroyTexture(game->label4);
    if(game->label5 != NULL)
        SDL_DestroyTexture(game->label5);
    if(game->label6 != NULL)
        SDL_DestroyTexture(game->label6);
    if(game->scorel != NULL)
        SDL_DestroyTexture(game->scorel);
   
    Mix_FreeChunk(game->jumpSound);
    Mix_FreeChunk(game->scoreSound);

    TTF_CloseFont(game->font);
    TTF_CloseFont(game->font2);

}

int main(int argc, char *argv[])
{
    SDL_Window *window;      // Declare a window
    SDL_Renderer *renderer;  // Declare a renderer
    
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);  // Initialize SDL2 with video and audio support

    // Create a window with following specs
    window = SDL_CreateWindow("Game",               // Window Title
                              SDL_WINDOWPOS_UNDEFINED,// initialize x-position
                              SDL_WINDOWPOS_UNDEFINED,// initialize y-position
                              640,                     // width in pixels
                              480,                     // height in pixels
                              0);                      // flags

    // renderer ---> to draw something on the window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    Game game;  // declare struct Game
    game.renderer = renderer;

    TTF_Init();  // for fonts

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);  // for sound effects

    // initialize game objects
    initGame(&game);

    // Event loop
    int done = 0;
    while(!done)
    {
        // Check for events ---> input from keyboard
        done = gameEvents(window, &game);
       
        process(&game);

        // check for possible collision with the obstacles
        collisionDetect(&game); 
       
        // Render display
        doRender(&game);
        
        SDL_Delay(10);
    }
    
    // Shutdown game and free memory
    shutdownGame(&game);

    TTF_Quit();
    Mix_CloseAudio();

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Clean up
    SDL_Quit();

    return 0;
}
