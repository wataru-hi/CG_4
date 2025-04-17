#include "gameScene.h"

#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distridution(-1.0f, 1.0f);

GameScene::~GameScene() {
	delete modelParticle_;
	// particles_のクリア
	particles_.clear();
}

void GameScene::Initialize() {
	modelParticle_ = Model::CreateSphere(4, 4);

	camera_.Initialize();

	srand((unsigned)time(NULL));
	
}

void GameScene::Update() {
	if(rand() % 20 == 0)
	{
		Vector3 position = { distridution(randomEngine) * 30.0f, distridution(randomEngine) * 20.0f, 0 };

		ParticleBorn(position);
	}

	particles_.remove_if([](std::shared_ptr<Particle> particle_ptr) { return particle_ptr->IsFinished(); });

	for (auto& particle : particles_) {
		particle->Update();
	}

	
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (auto& particle : particles_) {
		particle->Draw(camera_);
	}

	Model::PostDraw();
}

void GameScene::ParticleBorn(Vector3 pos)
{
		Vector3 position = pos;

	for (int i = 0; i < 150; i++) {
		std::shared_ptr<Particle> particle = std::make_shared<Particle>();

		Vector3 velocity = {distridution(randomEngine), distridution(randomEngine), 0};

		Normalize(velocity);
		velocity *= distridution(randomEngine);
		velocity *= 0.1f;

		particle->Initialize(modelParticle_, position, velocity);
		particles_.push_back(particle);
	}
}
