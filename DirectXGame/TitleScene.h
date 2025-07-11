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
	
	uint32_t TitleSpriteId;
	uint32_t TitleSpaceKeySpriteId;
	uint32_t TitleBGSpriteId;

	KamataEngine::Vector2 titlePos = {240, 88};
	KamataEngine::Vector2 titleSpacePos = {460, 400};

	bool endTitleScene = false;

	// 追加: フラグと経過時間
	float time = 0.0f;
	bool toggleFlag = false;
};
