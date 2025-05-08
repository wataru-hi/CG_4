#include "gameScene.h"

#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
//std::uniform_real_distribution<float> distridution(-1.0f, 1.0f);
std::uniform_real_distribution<float> distridutionZero(0.0f, 1.0f);

GameScene::~GameScene() {
}

void GameScene::Initialize() {
	srand((unsigned)time(NULL));
	
	modelEfect = Model::CreateFromOBJ("board");

	for (int i = 0; i < 10; i++)
	{
		std::shared_ptr<Efect> newEfect = std::make_shared<Efect>();

		Vector3 sca = Vector3{0.2f, distridutionZero(randomEngine) * 2.5f, 1.0f};
		Vector3 rot = Vector3{0.0f, 0.0f, distridutionZero(randomEngine) * 6.28f};
		Vector3 pos = Vector3Zero();

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

	// ImGuiウィンドウを作成
	if (ImGui::Begin("Efect Editor")) {
		int index = 0; // Efectのインデックスを追跡するための変数
		for (auto& efect : efects_) {
			// 各Efectの編集用UIを作成
			ImGui::PushID(index); // 複数の同名ウィジェットを区別するためのID

			KamataEngine::WorldTransform& transform = efect->GetWorldTransform();

			// 位置の編集
			ImGui::Text("Efect %d", index);
			ImGui::DragFloat3("Position", &transform.translation_.x, 0.1f);

			// 回転の編集
			ImGui::DragFloat3("Rotation", &transform.rotation_.x, 0.01f);

			// スケールの編集
			ImGui::DragFloat3("Scale", &transform.scale_.x, 0.1f);

			// ワールド行列を更新
			transform.UpdateMatirx();

			ImGui::Separator(); // 区切り線
			ImGui::PopID();

			++index; // インデックスをインクリメント
		}
	}
	ImGui::End();

	efects_.remove_if([](parti))
	
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

