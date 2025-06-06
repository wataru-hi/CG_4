#pragma once
#include "KamataEngine.h"
#include "Model2.h"
class GameScene
{
public:
	GameScene() {}
	~GameScene();

	void Initialize();
	void Update();
	void Draw();
private:
	void CreateFiveSquear();

	KamataEngine::Camera camera_;

	KamataEngine::WorldTransform worldTransform;

	std::unique_ptr<KamataEngine::Model2> model_;

	uint32_t Texturehandel_;

	std::unique_ptr<KamataEngine::ObjectColor> objectColor;

	KamataEngine::Vector4 color;
};

