#include "Efect.h"

using namespace KamataEngine;

void Efect::Initialize(Model* model, Vector3 rot, Vector3 sca, Vector3 pos)
{
	assert(model);

	model_= model;

	worldTransform_.Initialize();

	worldTransform_.rotation_ = rot;
	worldTransform_.scale_ = sca;
	worldTransform_.translation_ = pos;
}

void Efect::Update()
{	
	if (isFinished_)
		return;

	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration_)
	{
		counter_ = kDuration_;
		isFinished_ = true;
	}

	worldTransform_.UpdateMatirx();

	
}

void Efect::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera);
}
