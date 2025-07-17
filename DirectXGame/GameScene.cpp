#include "gameScene.h"
#include "RandomUtility.h"
#include "TitleScene.h"
#include "Player.h"

using namespace KamataEngine;
using namespace MathUtility;

using namespace RandomUtility;

GameScene::~GameScene() {
	Model2::StaticFinalize();
}

void GameScene::Initialize() {
	camera_.Initialize();

	Model2::StaticInitialize();

	model_ = std::unique_ptr<Model2>(Model2::CreateSqueare(5));
	
	Texturehandel_ = TextureManager::Load("uvChecker.png");

	worldTransform.Initialize();
	worldTransform.scale_ = {5.0f, 5.0f, 1.0f};

	objectColor = std::make_unique<ObjectColor>();
	objectColor->Initialize();

	color = {1.0f, 1.0f, 1.0f, 1.0f};

	objectColor->SetColor(color);

	playerModel = std::unique_ptr<Model>(Model::CreateFromOBJ("cube"));

	player = new Player();
	player->Initialize(playerModel.get());

}

void GameScene::Update() { 


	player->Update();
	ImGui::Begin("a");
	ImGui::DragFloat3("sca", &worldTransform.scale_.x, 0.01f);
	ImGui::DragFloat3("rot", &worldTransform.rotation_.x, 0.01f);
	ImGui::DragFloat3("tra", &worldTransform.translation_.x, 0.01f);
	ImGui::End();

	worldTransform.UpdateMatirx(); 
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();


	Sprite::PreDraw(dxCommon->GetCommandList());
	
	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model::PreDraw(dxCommon->GetCommandList());
	Model2::PreDraw(dxCommon->GetCommandList());

	model_->Draw(worldTransform, camera_, Texturehandel_);
	player->Draw(camera_);
	
	Model::PostDraw();
	Model2::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());

	Sprite::PostDraw();
}
