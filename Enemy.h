#pragma once

#include "GameBase.h"
#include "LTexture.h"

class Enemy
{
public:
	Enemy(int _type = 0);

	~Enemy();


	void LoadFromFile(std::string path, SDL_Renderer* gRenderer);

	void Move(const int& acceleration);

	void Render(SDL_Renderer* gRenderer, SDL_Rect* currentClip = nullptr);

	int GetType();

	int GetSpeed(const int& acceleration);

	int GetPosX();

	int GetPosY();

	int GetWidth();

	int GetHeight();

	bool IsDead();

	void SetDead();
private:
	int posX, posY;

	int eWidth, eHeight;

	int type; bool IfDead;

	SDL_Texture* EnemyTexture;
};