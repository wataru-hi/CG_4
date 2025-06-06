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

	void EfectBorn();

	void GetEffect(std::shared_ptr<Efect> efect)
	{ 
		efects_.push_back(efect);
	}

private:

	KamataEngine::Model* modelEfect;

	std::list<std::shared_ptr<Efect>> efects_;

	KamataEngine::Camera camera_;

	static inline const float flameTime = 1.0f / 60.0f;

	float efectBottunTimer;
	static inline const float efectBottunTime = 0.1f;

};