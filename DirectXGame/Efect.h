#pragma once
#include "KamataEngine.h"

class Efect
{
public:
	Efect() {}
	~Efect() {}

	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 rot, KamataEngine::Vector3 sca, KamataEngine::Vector3 pos);
	void Update();
	void Draw(KamataEngine::Camera& camera);

	KamataEngine::WorldTransform& GetWorldTransform() { return worldTransform_; }

private:
	KamataEngine::Model* model_;

	KamataEngine::WorldTransform worldTransform_;
};

