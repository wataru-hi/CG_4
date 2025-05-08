#pragma once
#include "KamataEngine.h"

class Efect
{
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 rot, KamataEngine::Vector3 sca, KamataEngine::Vector3 pos);
	void Update();
	void Draw(KamataEngine::Camera& camera);

	bool IsFinished() { return isFinished_; }
	KamataEngine::WorldTransform& GetWorldTransform() { return worldTransform_; }

	void SetColor(KamataEngine::Vector3 color) { 
		color_.x = color.x;  
		color_.y = color.y;  
		color_.z = color.z;  
	}
	void SetMove(KamataEngine::Vector3 move) { move_ = move; }

private:
	KamataEngine::Model* model_;

	KamataEngine::WorldTransform worldTransform_;

	bool isFinished_ = false;
	float counter_ = 0.0f;
	const float kDuration_ = 1.0f;

	KamataEngine::ObjectColor objectColor;
	KamataEngine::Vector4 color_;

	KamataEngine::Vector3 move_;
};

