#pragma once
#include "KamataEngine.h"

class GameScene
{
public:
	GameScene() {}
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

private:
	KamataEngine::Model* modelEfect_ = nullptr;

	KamataEngine::WorldTransform worldTransform;

	KamataEngine::Camera camera_;
};

