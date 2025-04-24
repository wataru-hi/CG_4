#include <Windows.h>

#include "KamataEngine.h"

#include "GameScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	KamataEngine::Initialize(L"LE3D_12_ヒガ_ワタル");

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	GameScene* gameScene = new GameScene();
	gameScene->Initialize();

	ImGuiManager* imGuiManager = ImGuiManager::GetInstance();

	while (true)
	{
		if (KamataEngine::Update())
		{
			break;
		}

		imGuiManager->Begin();

		gameScene->Update();
		
		imGuiManager->End();
		
		dxCommon->PreDraw();

		gameScene->Draw();

		imGuiManager->Draw();

		dxCommon->PostDraw();
	}

	delete gameScene;

	KamataEngine::Finalize();

	return 0;
}
