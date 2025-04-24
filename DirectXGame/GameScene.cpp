#include "gameScene.h"

void GameScene::Initialize()
{
	efectTextureHandle_ = TextureManager::Load("white1x1.png");

	efectSprite_ = Sprite::Create(efectTextureHandle_, {1,1});
}

void GameScene::Update()
{
}

void GameScene::Draw()
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite

}
