#pragma once
#include "KamataEngine.h"

class Efect
{
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 rot, KamataEngine::Vector3 sca, KamataEngine::Vector3 pos);
	void Update();
	void Draw(KamataEngine::Camera& camera);

private:
	KamataEngine::Model* model_;

	KamataEngine::WorldTransform worldTransform_;
};

