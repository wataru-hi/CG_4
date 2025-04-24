#include "gameScene.h"

void GameScene::Initialize()
{
	efectTextureHandle_ = TextureManager::Load("uvChecker.png");

	efectSprite_ = Sprite::Create(efectTextureHandle_, {1,1});
}

void GameScene::Update()
{
}

void GameScene::Draw()
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	efectSprite_->Draw();

	Sprite::PostDraw();

}
