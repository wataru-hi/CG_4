#include "TitleScene.h"

#include "SpriteManager/SpriteManger.h"
#include "SpriteManager/GlobalSpriteManger.h"


using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() { 
	globalSpriteManager.RemoveSprite(TitleSpriteId);
	globalSpriteManager.RemoveSprite(TitleBGSpriteId);

}

void TitleScene::Initialize() { 
	TitleSpriteId = globalSpriteManager.CreateSprite("title.png", Vector2{0.0f, 0.0f});
	TitleSpaceKeySpriteId = globalSpriteManager.CreateSprite("titleSpace.png", Vector2{0.0f, 0.0f});
	TitleBGSpriteId = globalSpriteManager.CreateSprite("titleBG.png", Vector2{0.0f, 0.0f});


	globalSpriteManager.SetSpritePosition(TitleSpriteId, titlePos);
	globalSpriteManager.SetSpritePosition(TitleSpaceKeySpriteId, titleSpacePos);
}

void TitleScene::Update() { 
	time += 1.0f / 60.0f;

	if (time >= 0.5f) {
		toggleFlag = !toggleFlag; // フラグを反転
		time = 0.0f;       // 経過時間をリセット
	}

	if (toggleFlag)
		globalSpriteManager.GetSprite(TitleSpaceKeySpriteId)->SetColor(Vector4{1, 1, 1, 0});
	else
		globalSpriteManager.GetSprite(TitleSpaceKeySpriteId)->SetColor(Vector4{1, 1, 1, 1});


	if (Input::GetInstance()->PushKey(DIK_SPACE))
		endTitleScene = true;

	#ifdef _DEBUG
	ImGui::Begin("a");
	ImGui::Checkbox("a", &toggleFlag);
	ImGui::DragFloat("b", &time);
	ImGui::End();
	#endif
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	globalSpriteManager.DrawSprite(TitleBGSpriteId);
	globalSpriteManager.DrawSprite(TitleSpaceKeySpriteId);
	globalSpriteManager.DrawSprite(TitleSpriteId);

	Sprite::PostDraw();
}


