#include "gameScene.h"

#include <random>

using namespace KamataEngine;
using namespace MathUtility;

GameScene::~GameScene() {
	delete modelEfect_;
}

void GameScene::Initialize() {
	modelEfect_ = Model::CreateFromOBJ("board");

	worldTransform.Initialize();

	camera_.Initialize();

	//srand((unsigned)time(NULL));
	
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

