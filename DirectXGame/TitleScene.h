#pragma once
#include "kamataEngine.h"

class TitleScene {
public:
	TitleScene();
	~TitleScene();

	void Initialize();
	void Update();
	void Draw();

	bool IsendTitleScene() { return endTitleScene; }

private:
	void BlimlimgTitleSprite(uint32_t SpriteId);

	uint32_t TitleSpriteId;
	uint32_t TitleSpaceKeySpriteId;
	uint32_t TitleBGSpriteId;
	uint32_t TitleBGSubSpriteId;

	KamataEngine::Vector2 titlePos = {240, 88};
	KamataEngine::Vector2 titleSpacePos = {460, 400};

	bool isStart = false;

	bool endTitleScene = false;

	float scrollSpeed = 0.5f;

	// 追加: フラグと経過時間
	float time = 0.0f;
	bool toggleFlag = false;
};
