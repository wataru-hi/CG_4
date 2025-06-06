#include "Efect.h"
#include "GameScene.h"

#include "RandomUtility.h"

#include <algorithm>

using namespace KamataEngine;
using namespace MathUtility;
using namespace RandomUtility;

void Efect::Initialize(Model* model, Vector3 rot, Vector3 sca, Vector3 pos)
{
	//assert(model);

	model_= model;

	worldTransform_.Initialize();

	worldTransform_.rotation_ = rot;
	worldTransform_.scale_ = sca;
	worldTransform_.translation_ = pos;

	color_ = {1, 1, 1, 1};
	objectColor.Initialize();
}

void Efect::Update()
{	
	if (isFinished_)
		return;

	counter_ += 1.0f / 60.0f;

	moveRot_ *= 0.95f;
	worldTransform_.rotation_.z += moveRot_;

	float t = counter_ / kDuration_;
	color_.w = 1.0f - t; // 時間経過で透明に

	objectColor.SetColor(color_);

	if (counter_ >= kDuration_)
	{
		counter_ = kDuration_;
		isFinished_ = true;
	}

	/*if (GetRandomZeroToOne() < 0.002f)
	{
		Vector3 color = {1, 1, 0};
		for (int i = 0; i < 3; i++) {
			std::shared_ptr<Efect> newEfect = std::make_shared<Efect>();

			Vector3 sca = Vector3{0.2f, GetRandomZeroToOne() * 1.5f, 1.0f};
			Vector3 rot = Vector3{0.0f, 0.0f, GetRandomZeroToOne() * 6.28f};
			Vector3 pos = worldTransform_.translation_;

			newEfect->Initialize(model_, rot, sca, pos);

			newEfect->SetColor(color);
			newEfect->SetMove(Vector3{0.1f, -0.4f, 0.0f});
			newEfect->SetGameScene(gameScene_);

			gameScene_->GetEffect(newEfect);
		}
	}*/

	worldTransform_.UpdateMatrix();

	
}

void Efect::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera, &objectColor); }

void Efect::SetGameScene(GameScene* gameScene) { gameScene_ = gameScene; }
