#pragma once
#include "KamataEngine.h"

#include "Particle.h"



class GameScene
{
public:
	GameScene() {}
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

	void ParticleBorn(KamataEngine::Vector3 pos);

private:
	KamataEngine::Model* modelParticle_ = nullptr;

	KamataEngine::Camera camera_;

	std::list<std::shared_ptr<Particle>> particles_;
};

