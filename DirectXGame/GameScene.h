#pragma once
#include "KamataEngine.h"
#include "Efect.h"

#include <memory>

class GameScene
{
public:
	GameScene() {}
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

private:
	KamataEngine::Model* modelEfect;

	std::vector<std::unique_ptr<Efect>> efects_;

	KamataEngine::Camera camera_;
};

