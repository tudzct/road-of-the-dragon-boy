#pragma once

#include "GameBase.h"
#include "LTexture.h"

class Button
{
public:
	ButtonSprite currentSprite;

	Button();
	Button(int x, int y);

	void Render(SDL_Rect* currentClip, SDL_Renderer* gRenderer, LTexture gButtonTexture);
	void SetPosition(int x, int y);

	bool IsInside(SDL_Event* e, int size);

private:
	SDL_Point position;
};