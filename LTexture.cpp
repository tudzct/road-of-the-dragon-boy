#include "LTexture.h"


LTexture::LTexture()
{
	mTexture = NULL;

	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	Free();
}

void LTexture::Free()
{
	if (mTexture != NULL)
	{
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

bool LTexture::LoadFromRenderedText(std::string textureText, TTF_Font* gFont, SDL_Color textColor, SDL_Renderer* gRenderer)
{
	Free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		std::cout << "Unable to render text surface! " << TTF_GetError();
	}
	else
	{
		mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (mTexture == NULL)
		{
			std::cout << "Unable to create texture from rendered text! " << SDL_GetError();
		}
		else
		{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		SDL_FreeSurface(textSurface);
	}

	return mTexture != NULL;
}

bool LTexture::LoadFromFile(std::string path, SDL_Renderer* gRenderer)
{
	Free();

	SDL_Texture* tmpTexture = NULL;

	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	if (tmpSurface == NULL)
	{
		LogError("Can not load image! ", IMG_ERROR);
	}
	else
	{
		SDL_SetColorKey(tmpSurface, SDL_TRUE, SDL_MapRGB(tmpSurface->format, 0, 255, 255));

		tmpTexture = SDL_CreateTextureFromSurface(gRenderer, tmpSurface);
		if (tmpTexture == NULL)
		{
			LogError("Can not create texture from surface! ", SDL_ERROR);
		}
		else
		{
			mWidth = tmpSurface->w;
			mHeight = tmpSurface->h;
		}

		SDL_FreeSurface(tmpSurface);
	}

	mTexture = tmpTexture;

	return mTexture != NULL;
}

void LTexture::Render(int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

int LTexture::GetWidth()
{
	return mWidth;
}

int LTexture::GetHeight()
{
	return mHeight;
}
