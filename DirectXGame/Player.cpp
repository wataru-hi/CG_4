#include "Player.h"

#include "SpriteManager/SpriteManger.h"
#include "SpriteManager/GlobalSpriteManger.h"

using namespace KamataEngine;

void Player::Initialize(KamataEngine::Model* model) { 
	model_ = model;
	worldtransform.Initialize();

	HpGageRedId = globalSpriteManager.CreateSprite("HPGageLed.png", Vector2{0.0f, 0.0f});
	HpGageGreId = globalSpriteManager.CreateSprite("HPGageGreen.png", Vector2{0.0f, 0.0f});

	globalSpriteManager.SetSpritePosition(HpGageRedId, Vector2{0.0f, 0.0f});
	globalSpriteManager.GetSprite(HpGageRedId)->SetSize(Vector2{300.0f, 20.0f});
	globalSpriteManager.GetSprite(HpGageRedId)->SetColor(Vector4{1,1,1,0.8f});
	globalSpriteManager.SetSpritePosition(HpGageGreId, Vector2{0.0f, 0.0f});
	globalSpriteManager.GetSprite(HpGageGreId)->SetSize(Vector2{300.0f, 20.0f});
	globalSpriteManager.GetSprite(HpGageGreId)->SetColor(Vector4{1, 1, 1, 0.8f});
}

void Player::Update() { 
	Vector2 GreSpriteSce = globalSpriteManager.GetSprite(HpGageGreId)->GetSize();
	GreSpriteSce.x -= 0.1f;
	globalSpriteManager.GetSprite(HpGageGreId)->SetSize(GreSpriteSce);
}

void Player::Draw(Camera& camera) { 
	model_->Draw(worldtransform, camera); 
}

void Player::SpriteDraw() { 
	globalSpriteManager.DrawSprite(HpGageRedId); 
	globalSpriteManager.DrawSprite(HpGageGreId); 
}
