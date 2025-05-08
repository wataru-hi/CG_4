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
}

void GameScene::Initialize() {
	srand((unsigned)time(NULL));
	
	modelEfect = Model::CreateFromOBJ("board");

	for (int i = 0; i < 10; i++)
	{
		std::unique_ptr<Efect> newEfect = std::make_unique<Efect>();

		Vector3 sca = Vector3{1.0f, 1.0f, 1.0f};
		sca.y = distridution(randomEngine);
		Vector3 rot = Vector3Zero();
		rot.z = radianFromMinus2pi(randomEngine);
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

	// ImGuiでEfectのworldTransformを操作
    ImGui::Begin("Efect Transform Editor");
    for (size_t i = 0; i < efects_.size(); ++i) {
		WorldTransform& transform = efects_[i]->GetWorldTransform();


        ImGui::Text("Efect %zu", i);
        ImGui::DragFloat3("Scale", &transform.scale_.x, 0.1f);
        ImGui::DragFloat3("Rotation", &transform.rotation_.x, 0.1f);
        ImGui::DragFloat3("Translation", &transform.translation_.x, 0.1f);
    }
    ImGui::End();
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

