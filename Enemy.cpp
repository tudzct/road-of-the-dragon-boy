#include "Enemy.h"

Enemy::Enemy(int _type)
{
	posX = 0;
	posY = 0;

	eWidth = 0;
	eHeight = 0;

	type = _type;
	if (type == IN_AIR_ENEMY)
	{

		posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
		posY = rand() % (ENEMY_MAX_HEIGHT - ENEMY_MIN_HEIGHT) + ENEMY_MIN_HEIGHT;
	}
	else if (type == ON_GROUND_ENEMY)
	{

		posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
		posY = GROUND;
	}
	else if (type == BEAR_ENEMY)
	{

		posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;
		posY = GROUND;
	}

	EnemyTexture = NULL;
}

Enemy::~Enemy()
{
	posX = 0;
	posY = 0;

	eWidth = 0;
	eHeight = 0;

	type = 0;
	if (EnemyTexture != NULL)
	{
		EnemyTexture = NULL;
	}
}

void Enemy::LoadFromFile(std::string path, SDL_Renderer* gRenderer)
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
			eWidth = tmpSurface->w;
			eHeight = tmpSurface->h;
		}

		SDL_FreeSurface(tmpSurface);
	}

	EnemyTexture = tmpTexture;
}

void Enemy::Move(const int& acceleration)
{

	posX += -(ENEMY_SPEED + acceleration);
	if (posX + MAX_ENEMY_WIDTH < 0)
	{
		IfDead = false;
		posX = rand() % (SCREEN_WIDTH + ENEMY_POSITION_RANGE) + SCREEN_WIDTH;

		if (type == BEAR_ENEMY)
		{
			posY = GROUND;
		}
		if (type == IN_AIR_ENEMY)
		{
			posY = rand() % (ENEMY_MAX_HEIGHT - ENEMY_MIN_HEIGHT) + ENEMY_MIN_HEIGHT;
		}
		if (type == ON_GROUND_ENEMY)
		{
			posY = GROUND;
		}
	}
}

void Enemy::Render(SDL_Renderer* gRenderer, SDL_Rect* currentClip)
{
	if (IfDead)
	{
		return;
	}
	SDL_Rect renderSpace;
	if (type == BEAR_ENEMY)
	{
		renderSpace = { posX, posY - 30, eWidth, eHeight };
	}
	else if (type == ON_GROUND_ENEMY)
	{
		renderSpace = { posX, posY - 40, eWidth, eHeight };
	}
	else
	{
		renderSpace = { posX, posY, eWidth, eHeight };
	}

	if (currentClip != NULL)
	{
		renderSpace.w = currentClip->w;
		renderSpace.h = currentClip->h;
	}
	if (type == BEAR_ENEMY)
	{
		SDL_RenderCopyEx(gRenderer, EnemyTexture, currentClip, &renderSpace, 0, NULL, SDL_FLIP_HORIZONTAL);
	}
	else if (type == IN_AIR_ENEMY)
	{
		SDL_RenderCopyEx(gRenderer, EnemyTexture, currentClip, &renderSpace, 0, NULL, SDL_FLIP_HORIZONTAL);
	}
	else
	{
		SDL_RenderCopy(gRenderer, EnemyTexture, currentClip, &renderSpace);
	}
}

int Enemy::GetType()
{
	if (type == IN_AIR_ENEMY)
	{
		return IN_AIR_ENEMY;
	}
	else if (type == BEAR_ENEMY)
	{
		return BEAR_ENEMY;
	}
	else
	{
		return ON_GROUND_ENEMY;
	}
}

int Enemy::GetSpeed(const int& acceleration)
{
	return ENEMY_SPEED + acceleration;
}

int Enemy::GetPosX()
{
	return posX;
}

int Enemy::GetPosY()
{
	return posY;
}

int Enemy::GetWidth()
{
	return eWidth;
}

int Enemy::GetHeight()
{
	return eHeight;
}

bool Enemy::IsDead()
{
	return IfDead;
}

void Enemy::SetDead()
{
	IfDead = true;
}