#include "Player.h"
using namespace KamataEngine;

void Player::Initialize(KamataEngine::Model* model) { 
	model_ = model;
	worldtransform.Initialize();
}

void Player::Update()
{ 
}

void Player::Draw(Camera& camera) { 
	model_->Draw(worldtransform, camera); 
}
