#include "gameScene.h"
#include "RandomUtility.h"

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
	worldTransform.scale_ = {10.0f, 10.0f, 10.0f};

	objectColor = std::make_unique<ObjectColor>();
	objectColor->Initialize();

	color = {1.0f, 1.0f, 1.0f, 1.0f};

	objectColor->SetColor(color);
}

void GameScene::Update() { 
	UpdateMatirx(); 
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxCommon->GetCommandList());

	model_->Draw(worldTransform, camera_, Texturehandel_);

	Model2::PostDraw();
}
