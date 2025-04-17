#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model* model)
{
	assert(model);
	model_ = model;

	worldTransform_.Initialize();

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
}

void Particle::Update()
{
	objectColor_.SetColor(color_);

	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

	worldTransform_.UpdateMatirx();
}

void Particle::Draw(Camera& camera)
{
	model_->Draw(worldTransform_, camera, &objectColor_);
}
