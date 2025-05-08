#include "gameScene.h"

#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distridution(-1.0f, 1.0f);
std::uniform_real_distribution<float> distridutionZero(0.0f, 1.0f);

GameScene::~GameScene() {
}

void GameScene::Initialize() {
	srand((unsigned)time(NULL));
	
	modelEfect = Model::CreateFromOBJ("board");

	for (int i = 0; i < 10; i++)
	{
		std::shared_ptr<Efect> newEfect = std::make_shared<Efect>();

		Vector3 sca = Vector3{1.0f, 1.0f, 1.0f};
		Vector3 rot = Vector3Zero();
		Vector3 pos = Vector3Zero();
		pos.x = static_cast<float>(i);

		newEfect->Initialize(modelEfect, rot, sca, pos);

		efects_.push_back(newEfect);
	}

	camera_.Initialize();
}

void GameScene::Update() {
	for(auto& efect : efects_)
	{
		efect->Update();
	}
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for(auto& efect : efects_)
	{
		efect->Draw(camera_);
	}
	

	Model::PostDraw();
}

