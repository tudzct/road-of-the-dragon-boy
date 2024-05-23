#include "Hud.h"

Bar::Bar()
{
    srand(time(NULL));
    posX = 0;
    posY = 0;
    F_WIDTH = 0;
    F_HEIGHT = 0;
    posX = 100;
    posY = 50;
    BarTexture = NULL;
}

Bar::~Bar()
{
    srand(time(NULL));
    posX = 0;
    posY = 0;
    F_WIDTH = 0;
    F_HEIGHT = 0;
    posX = 100;
    posY = 49;
    BarTexture = NULL;
}

void Bar::LoadFromFile(std::string path, SDL_Renderer* gRenderer)
{
    SDL_Texture* tmpTexture = NULL;

    SDL_Surface* tmpSurface = IMG_Load(path.c_str());
    if (tmpSurface == NULL)
    {
        LogError("Can not load image.", IMG_ERROR);
    }
    else
    {
        SDL_SetColorKey(tmpSurface, SDL_TRUE, SDL_MapRGB(tmpSurface->format, 0, 255, 255));

        tmpTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
        if (tmpTexture == NULL)
        {
            LogError("Can not create texture from surface.", SDL_ERROR);
        }
        else
        {
            F_WIDTH = tmpSurface->w - 130;
            F_HEIGHT = tmpSurface->h - 180;
        }

        SDL_FreeSurface(tmpSurface);
    }

    BarTexture = tmpTexture;
}

void Bar::Render(SDL_Renderer* gRenderer, SDL_Rect* currentClip)
{
    SDL_Rect renderSpace = { posX, posY, F_WIDTH, F_HEIGHT };

    if (currentClip != NULL)
    {
        renderSpace.w = currentClip->w;
        renderSpace.h = currentClip->h;
    }
    SDL_RenderCopy(gRenderer, BarTexture, currentClip, &renderSpace);
}

int Bar::GetPosX() {
    return posX;
}

int Bar::GetPosY() {
    return posY;
}

int Bar::GetWidth() {
    return F_WIDTH;
}

int Bar::GetHeight() {
    return F_HEIGHT;
}
