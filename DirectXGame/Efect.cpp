#include "Efect.h"

#include "RandomUtility.h"

#include <algorithm>

using namespace KamataEngine;
using namespace MathUtility;
using namespace RandomUtility;

void Efect::Initialize(Model* model, Vector3 rot, Vector3 sca, Vector3 pos)
{
	assert(model);

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

	color_.w = std::clamp(1.0f - counter_ / kDuration_, 0.0f, 1.0f);
	
	objectColor.SetColor(color_);

	if (counter_ >= kDuration_)
	{
		counter_ = kDuration_;
		isFinished_ = true;
	}

	worldTransform_.translation_ += move_;

	move_.y += 0.005f;

	worldTransform_.UpdateMatirx();

	
}

void Efect::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera, &objectColor);
}
