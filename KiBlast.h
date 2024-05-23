#pragma once

#include "GameBase.h"
#include "Character.h"
#include <vector>
#include <iostream>
#include <SDL.h>

class KiBlast 
{
private:
    int posX, posY;
    int B_NUMBER;
    int B_SPEED;
    int B_WIDTH;
    int B_HEIGHT;

    Uint32 lastUseTime;
    Uint32 coolDownTime;
    Uint32 currentTime;

    bool isMove;
    bool isHit;
    bool isFired;

    SDL_Texture* KiTexture;

public:
    KiBlast();
    KiBlast(int x, int y, int speed, int width, int height, SDL_Texture* texture);

    std::vector<KiBlast> blasts;

    void HandleEvent(SDL_Event& e, Character& character, SDL_Renderer* gRenderer, int& mana, Mix_Chunk* gBlast);
    void LoadFromFile(std::string path, SDL_Renderer* gRenderer);
    void Render(SDL_Renderer* gRenderer);
    void Move();
    void SetBlasts(int number);
    void SetHit(bool hit);

    bool IsHit();
    bool IfFired();

    int GetPosX();
    int GetPosY();
    int GetWidth();
    int GetHeight();
};