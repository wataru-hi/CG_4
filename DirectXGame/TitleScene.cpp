#include "TitleScene.h"
#include "SpriteManager/GlobalSpriteManger.h"


using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {}

void TitleScene::Initialize() { 
	titleBGTextureHandle_ = TextureManager::Load("titleBG.png");
	spriteTitleBG_ = std::unique_ptr<Sprite>(Sprite::Create(titleBGTextureHandle_, {0, 0}));
	globalSpriteManager.SetSpritePosition("titleSprite", titlePos);
	//spriteTitle_->SetPosition(titlePos);
}

void TitleScene::Update() { 
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	spriteTitleBG_->Draw();
	globalSpriteManager.DrawSprite("titleSprite");
	//spriteTitle_->Draw();

	Sprite::PostDraw();
}


