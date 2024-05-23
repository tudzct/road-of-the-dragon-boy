#pragma once

#include "LTexture.h"
#include "GameBase.h"

class Character
{
public:
	Character();

	void Render(SDL_Rect* currentClip, SDL_Renderer* gRenderer, LTexture gCharacterTexture);
	void HandleEvent(SDL_Event& e, Mix_Chunk* gJump, int& mana, Mix_Chunk* gAttack);
	void SetStatus(int x);
	void RenewStatus();

	int GetStatus();
	int GetPosX();
	int GetPosY();

	bool OnGround();
	bool Fight();
	void Move();

private:
	int posX, posY;
	int status;
	int cnt;

	bool isFightingPressed;

	Uint32 lastUseTime;
	Uint32 cooldownTime;
	Uint32 CurrentTime;
};