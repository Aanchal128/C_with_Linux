// Game start window and game over window

#include "state.h"

void init_status(Game *game)
{
    char str[30] = "";
    char str2[20] = "";
    char str3[20] = "";
    char str4[10] = "";

    sprintf(str4,"WELCOME");
    sprintf(str,"Press SPACE to START");
    sprintf(str2,"UP arrow to JUMP");
    sprintf(str3,"ESC to QUIT");

    SDL_Color black = {0, 0, 0, 255};

    SDL_Surface *tmp = NULL;
    tmp = TTF_RenderText_Blended(game->font, str4, black);
    game->label4w = tmp->w;
    game->label4h = tmp->h;
    
    game->label4 = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);

    tmp = TTF_RenderText_Blended(game->font, str, black);
    game->labelw = tmp->w;
    game->labelh = tmp->h;
    
    game->label = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);

    tmp = TTF_RenderText_Blended(game->font, str2, black);
    game->label2w = tmp->w;
    game->label2h = tmp->h;
    
    game->label2 = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);

    tmp = TTF_RenderText_Blended(game->font, str3, black);
    game->label3w = tmp->w;
    game->label3h = tmp->h;
    
    game->label3 = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);

}

void showMessage(Game *game)
{
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
   
    SDL_Rect textRect4 = {200, 20, game->label4w, game->label4h};
    SDL_RenderCopy(game->renderer, game->label4, NULL, &textRect4);

    SDL_Rect textRect = {20, 120, game->labelw, game->labelh};
    SDL_RenderCopy(game->renderer, game->label, NULL, &textRect);
    
    SDL_Rect textRect2 = {20, 180, game->label2w, game->label2h};
    SDL_RenderCopy(game->renderer, game->label2, NULL, &textRect2);

    SDL_Rect textRect3 = {20, 240, game->label3w, game->label3h};
    SDL_RenderCopy(game->renderer, game->label3, NULL, &textRect3);

}

void shutdown_status(Game *game)
{
    SDL_DestroyTexture(game->label);
    game->label = NULL;

    SDL_DestroyTexture(game->label2);
    game->label2 = NULL;

    SDL_DestroyTexture(game->label3);
    game->label3 = NULL;
    
    SDL_DestroyTexture(game->label4);
    game->label4 = NULL;

}

void gameOver(Game *game)
{
    char str[10] = "";
    char str2[30] = "";

    sprintf(str,"GAME OVER");
    sprintf(str2,"Press SPACE to REPLAY");
    
    SDL_Color black = {0, 0, 0, 255};

    SDL_Surface *tmp = NULL;
    tmp = TTF_RenderText_Blended(game->font, str, black);
    game->label5w = tmp->w;
    game->label5h = tmp->h;
    
    game->label5 = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);

    tmp = TTF_RenderText_Blended(game->font, str2, black);
    game->label6w = tmp->w;
    game->label6h = tmp->h;
    
    game->label6 = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);

    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
   
    SDL_Rect textRect = {200, 20, game->label5w, game->label5h};
    SDL_RenderCopy(game->renderer, game->label5, NULL, &textRect);

    SDL_Rect textRect2 = {10, 120, game->label6w, game->label6h};
    SDL_RenderCopy(game->renderer, game->label6, NULL, &textRect2);

    SDL_DestroyTexture(game->label5);
    game->label5 = NULL;

    SDL_DestroyTexture(game->label6);
    game->label6 = NULL;
}

