﻿#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "WinApp.h"
#include "Scene.h"
#include "TitleScene.h"
#include "ExScene.h"
#include "ClearScene.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	// 汎用機能
	Input* input = nullptr;
	Audio* audio = nullptr;
	AxisIndicator* axisIndicator = nullptr;
	PrimitiveDrawer* primitiveDrawer = nullptr;
	GameScene* gameScene = nullptr;
	TitleScene* titleScene = nullptr;
	ExScene* exScene = nullptr;
	ClearScene* clearScene = nullptr;

	// ゲームウィンドウの作成
	win = WinApp::GetInstance();
	win->CreateGameWindow();

	// DirectX初期化処理
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

#pragma region 汎用機能初期化
	// ImGuiの初期化
	ImGuiManager* imguiManager = ImGuiManager::GetInstance();
	imguiManager->Initialize(win, dxCommon);

	// 入力の初期化
	input = Input::GetInstance();
	input->Initialize();

	// オーディオの初期化
	audio = Audio::GetInstance();
	audio->Initialize();

	// テクスチャマネージャの初期化
	TextureManager::GetInstance()->Initialize(dxCommon->GetDevice());
	TextureManager::Load("white1x1.png");

	// スプライト静的初期化
	Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::kWindowWidth, WinApp::kWindowHeight);

	// 3Dモデル静的初期化
	Model::StaticInitialize();

	// 軸方向表示初期化
	axisIndicator = AxisIndicator::GetInstance();
	axisIndicator->Initialize();

	primitiveDrawer = PrimitiveDrawer::GetInstance();
	primitiveDrawer->Initialize();
#pragma endregion

	// ゲームシーンの初期化
	gameScene = new GameScene();
	gameScene->Initialize();

	titleScene = new TitleScene();
	titleScene->Initialize();

	exScene = new ExScene;
	exScene->Initialize();

	Scene scene = Scene::TITLE;

	// メインループ
	while (true) {
		// メッセージ処理
		if (win->ProcessMessage()) {
			break;
		}

		// ImGui受付開始
		imguiManager->Begin();
		// 入力関連の毎フレーム処理
		input->Update();

		switch (scene) { 
		case Scene::TITLE:

			if (titleScene->IsSceneEnd() == true) {
				//次シーンの値を代入してシーン切り替え
				scene = titleScene->NextScene();
			}
			//タイトルシーンの毎フレーム処理
			titleScene->Update();

			break;

		case Scene::EX:
			//ここでエラーが起きている
			if (exScene->IsSceneEnd() == true) {
				//次のシーンの値を代入してシーン切り替え
				scene = exScene->NextScene();
			}
			//説明シーンの舞フレーム処理
			exScene->Update();

			break;

		case Scene::GAME:
			//ゲームシーンの毎日フレーム処理
			gameScene->Update();

			//if (gameScene->IsSceneEnd() == true) {
			//	//次のシーンの値を代入してシーン切り替え
			//	scene = gameScene->NextScene();
			//}

			break;

		case Scene::CLEAR:

			if (clearScene->IsSceneEnd() == true) {
				scene = clearScene->NextScene();
				clearScene->Reset();
			}

			clearScene->Updata();

			break;
		}
		// 軸表示の更新
		axisIndicator->Update();
		// ImGui受付終了
		imguiManager->End();

		// 描画開始
		dxCommon->PreDraw();

		switch (scene) { case Scene::TITLE:
			//タイトルシーンの描画
			titleScene->Draw();

			break;
		case Scene::EX:

			exScene->Draw();

			break;
		case Scene::GAME:
			break;
		case Scene::CLEAR:
			clearScene->Draw();
			break;
		}
		// 軸表示の描画
		axisIndicator->Draw();
		// プリミティブ描画のリセット
		primitiveDrawer->Reset();
		// ImGui描画
		imguiManager->Draw();
		// 描画終了
		dxCommon->PostDraw();
	}

	// 各種解放
	delete gameScene;
	// 3Dモデル解放
	Model::StaticFinalize();
	audio->Finalize();
	// ImGui解放
	imguiManager->Finalize();

	// ゲームウィンドウの破棄
	win->TerminateGameWindow();

	return 0;
}