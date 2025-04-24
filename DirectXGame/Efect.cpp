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
	worldTransform_.UpdateMatirx();
}

void Efect::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera);
}
