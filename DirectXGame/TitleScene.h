#pragma once
#include "kamataEngine.h"

class TitleScene {
public:
	TitleScene();
	~TitleScene();

	void Initialize();
	void Update();
	void Draw();

private:
	uint32_t titleBGTextureHandle_ = 0;
	std::unique_ptr<KamataEngine::Sprite> spriteTitleBG_ = nullptr;

	KamataEngine::Vector2 titlePos = {240, 88};
};
