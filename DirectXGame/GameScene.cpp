#include "GameScene.h"
#include "RandomUtility.h"

using namespace KamataEngine;
using namespace MathUtility;

using namespace RandomUtility;

GameScene::~GameScene() {
}

void GameScene::Initialize() {
	modelEfect = Model::CreateFromOBJ("board");

	camera_.Initialize();
}

void GameScene::Update() {

	if (efectBottunTimer > 0.0f)
		efectBottunTimer -= flameTime;

	if (Input::GetInstance()->PushKey(DIK_SPACE))
	{
		if (efectBottunTimer <= 0.0f) {
			EfectBorn();
			efectBottunTimer = efectBottunTime;
		}
	}

	for(auto& efect : efects_)
	{
		efect->Update();
	}

	efects_.remove_if([](std::shared_ptr<Efect> particle_ptr) { return particle_ptr->IsFinished(); });

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

void GameScene::EfectBorn() {
	Vector2 newPos = {GetRandom() * 30.0f, GetRandom() * 20.0f}; 
	Vector3 color = {GetRandomZeroToOne(), GetRandomZeroToOne(), GetRandomZeroToOne()};
	float rotSpd = GetRandomZeroToOne();
	for (int i = 0; i < 10; i++) {
		std::shared_ptr<Efect> newEfect = std::make_shared<Efect>();

		Vector3 sca = Vector3{0.2f, GetRandomZeroToOne() * 2.5f, 1.0f};
		Vector3 rot = Vector3{0.0f, 0.0f, GetRandomZeroToOne() * 6.28f};
		Vector3 pos = Vector3{newPos.x, newPos.y, 0.0f};
		
		newEfect->Initialize(modelEfect, rot, sca, pos);

		newEfect->SetColor(color);
		newEfect->SetGameScene(this);
		newEfect->SetRot(rotSpd);

		efects_.push_back(newEfect);
	}
}

