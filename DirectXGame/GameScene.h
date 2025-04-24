#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class GameScene
{
public:
	void Initialize();
	void Update();
	void Draw();

private:
	uint32_t efectTextureHandle_ = 0;

	Sprite* efectSprite_ = nullptr;
};

