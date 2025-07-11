#include <Windows.h>

#include "KamataEngine.h"

#include "GameScene.h"
#include "TitleScene.h"

#include "SpriteManager/GlobalSpriteManger.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	KamataEngine::Initialize(L"LE3D_12_ヒガ_ワタル");

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	std::unique_ptr<GameScene> gameScene = std::make_unique<GameScene>();
	gameScene->Initialize();
	
	std::unique_ptr<TitleScene> titleScene = std::make_unique<TitleScene>();
	titleScene->Initialize();

	ImGuiManager* imGuiManager = ImGuiManager::GetInstance();

	while (true)
	{
		if (KamataEngine::Update())
		{
			break;
		}

		imGuiManager->Begin();

		if (titleScene->IsendTitleScene())
			gameScene->Update();
		else
			titleScene->Update();

		imGuiManager->End();
		
		dxCommon->PreDraw();

		if (titleScene->IsendTitleScene())
			gameScene->Draw();
		else
			titleScene->Draw();

		imGuiManager->Draw();

		dxCommon->PostDraw();
	}

	KamataEngine::Finalize();

	return 0;
}
