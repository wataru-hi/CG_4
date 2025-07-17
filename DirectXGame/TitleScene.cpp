#include "TitleScene.h"

#include "SpriteManager/SpriteManger.h"
#include "SpriteManager/GlobalSpriteManger.h"


using namespace KamataEngine;
using namespace KamataEngine::MathUtility;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() { 
	globalSpriteManager.RemoveSprite(TitleSpriteId);
	globalSpriteManager.RemoveSprite(TitleBGSpriteId);

}

void TitleScene::Initialize() { 
	TitleSpriteId = globalSpriteManager.CreateSprite("title.png", Vector2{0.0f, 0.0f});
	TitleSpaceKeySpriteId = globalSpriteManager.CreateSprite("titleSpace.png", Vector2{0.0f, 0.0f});
	TitleBGSpriteId = globalSpriteManager.CreateSprite("titleBG.png", Vector2{0.0f, 0.0f});
	TitleBGSubSpriteId = globalSpriteManager.CreateSprite("titleBG.png", Vector2{0.0f, 0.0f});


	globalSpriteManager.SetSpritePosition(TitleSpriteId, titlePos);
	globalSpriteManager.SetSpritePosition(TitleSpaceKeySpriteId, titleSpacePos);

	globalSpriteManager.SetSpritePosition(TitleBGSubSpriteId, Vector2{1280, 0});
}

void TitleScene::Update() { 
	BlimlimgTitleSprite(TitleSpaceKeySpriteId);

	Vector2 titleBGspriteNewPos = globalSpriteManager.GetSprite(TitleBGSpriteId)->GetPosition();
	Vector2 titleBGSecondspriteNewPos = globalSpriteManager.GetSprite(TitleBGSubSpriteId)->GetPosition();
	
	titleBGspriteNewPos.x -= scrollSpeed;
	if (titleBGspriteNewPos.x <= -1280.0f)
		titleBGspriteNewPos.x = 1280.0f;

	titleBGSecondspriteNewPos.x -= scrollSpeed;
	if (titleBGSecondspriteNewPos.x <= -1280.0f)
		titleBGSecondspriteNewPos.x = 1280.0f;

	globalSpriteManager.SetSpritePosition(TitleBGSpriteId, titleBGspriteNewPos);
	globalSpriteManager.SetSpritePosition(TitleBGSubSpriteId, titleBGSecondspriteNewPos);

	isStart = true;

	ImGui::Begin("Title");
	ImGui::DragFloat("scrollSpeed", &scrollSpeed, 0.01f);
	ImGui::DragFloat2("SpritePos", &titleBGspriteNewPos.x, 0.01f);
	ImGui::DragFloat2("subSpritePos", &titleBGSecondspriteNewPos.x, 0.01f);
	ImGui::End();

	if (Input::GetInstance()->PushKey(DIK_SPACE))
		endTitleScene = true;
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	globalSpriteManager.DrawSprite(TitleBGSpriteId);
	globalSpriteManager.DrawSprite(TitleBGSubSpriteId);
	globalSpriteManager.DrawSprite(TitleSpaceKeySpriteId);
	globalSpriteManager.DrawSprite(TitleSpriteId);

	Sprite::PostDraw();
}

void TitleScene::BlimlimgTitleSprite(uint32_t SpriteId) {
	time += 1.0f / 60.0f;

	if (time >= 0.5f) {
		toggleFlag = !toggleFlag; // フラグを反転
		time = 0.0f;              // 経過時間をリセット
	}

	if (toggleFlag)
		globalSpriteManager.GetSprite(SpriteId)->SetColor(Vector4{1, 1, 1, 0});
	else
		globalSpriteManager.GetSprite(SpriteId)->SetColor(Vector4{1, 1, 1, 1});
}
