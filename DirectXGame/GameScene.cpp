#include "gameScene.h"

#include <random>

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

	Vector3 pos = {0.0f, 0.0f, 0.0f};

	for (int i = 0; i < 150; i++) {
		std::shared_ptr<Particle> particle = std::make_shared<Particle>();

		Vector3 vel = {distridution(randomEngine), distridution(randomEngine), 0};

		Normalize(vel);
		vel *= distridution(randomEngine);
		vel *= 0.1f;

		particle->Initialize(modelParticle_, pos, vel);
		particles_.push_back(particle);
	}
}

void GameScene::Update() {
	
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
