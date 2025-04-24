#include "gameScene.h"

#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distridution(-1.0f, 1.0f);
std::uniform_real_distribution<float> radianFromZero(0, 2.0f * PI);
std::uniform_real_distribution<float> radianFromMinus2pi(-2.0f * PI, 2.0f * PI);

GameScene::~GameScene() {
	delete modelEfect_;
}

void GameScene::Initialize() {
	srand((unsigned)time(NULL));
	
	modelEfect_ = Model::CreateFromOBJ("board");

	worldTransform.Initialize();

	worldTransform.scale_.y = randomEngine(radianFromZero)

	camera_.Initialize();

	
	
}

void GameScene::Update() {
	


	ImGui::Begin("board");
	ImGui::DragFloat3("rot", &worldTransform.rotation_.x, 0.1f);
	ImGui::DragFloat3("sca", &worldTransform.scale_.x, 0.1f);
	ImGui::DragFloat3("pos", &worldTransform.translation_.x, 0.1f);
	ImGui::End();

	worldTransform.UpdateMatirx();
	
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	modelEfect_->Draw(worldTransform, camera_);
	

	Model::PostDraw();
}

