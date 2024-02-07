#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "WinApp.h"
#include "TitleScene.h"
#include "ExScene.h"
#include "ClearScene.h"
#include "OverScene.h"
#include "gauge.h"

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
	ExScene* exScene = nullptr;
	TitleScene* titleScene = nullptr;
	ClearScene* clearScene = nullptr;
	OverScene* overScene = nullptr;
	Gauge* gauge = nullptr;
	ExScene* exScene = nullptr;

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

	//タイトルシーンの初期化																																																																																																																																														
	titleScene = new TitleScene();
	titleScene->Initialize();

	// クリアシーンの初期化
	clearScene = new ClearScene();
	clearScene->Initialize();

	// オーバーシーンの初期化
	overScene = new OverScene();
	overScene->Initialize();

	//説明の初期化
	exScene = new ExScene;
	exScene->Initialize();

	gauge = new Gauge();
	gauge->Initialize();

	SceneType sceneNo = SceneType::kTitle;

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

		//ゲーム全体のシーン管理
		switch (sceneNo) 
		{
		case SceneType::kTitle:
			//タイトルシーン更新
			titleScene->Update();

			//シーンの切り替え処理＆タイトルシーンのリセット
			if (titleScene->IsSceneEnd() == true)
			{
				sceneNo = titleScene->NextScene();

				titleScene->SceneReset();
			}
			break;
		case SceneType::kEX:
			if (exScene->IsSceneEnd() == true) {
				// 次のシーンを値を代入してシーン切り替え
				sceneNo = exScene->NextScene();
				exScene->Reset();
			}

			// タイトルシーンの毎フレーム処理
			exScene->Updata();

			break;
		case SceneType::kGame:
			//ゲームシーンの更新
			gameScene->Update();

			gauge->Update();

			if (gauge->IsHpEnd() == true)
			{
				sceneNo = gameScene->NextScene1();

				gameScene->sceneReset();

				gauge->GaugeReset();
			}

			if (gauge->IsGaugeEnd() == true)
			{
				//オーバーシーンへ
				sceneNo = gameScene->NextScene2();

				gameScene->sceneReset();

				gauge->GaugeReset();
			}

			break;
		case SceneType::kClear:
			//クリアシーンの更新
			clearScene->Update();

				// シーンの切り替え処理＆クリアシーンのリセット
			if (clearScene->IsSceneEnd() == true) {
				sceneNo = clearScene->NextScene();

				clearScene->SceneReset();
			}
			break;
		case SceneType::kOver:
			// オーバーシーンの更新
			overScene->Update();

			// シーンの切り替え処理＆クリアシーンのリセット
			if (overScene->IsSceneEnd() == true) {
				sceneNo = overScene->NextScene();

				overScene->SceneReset();
			}
			break;
		default:
			break;
		}


		//// ゲームシーンの毎フレーム処理
		//gameScene->Update();
		// 軸表示の更新
		axisIndicator->Update();
		// ImGui受付終了
		imguiManager->End();

		// 描画開始
		dxCommon->PreDraw();

		//描画用swich文
		switch (sceneNo) 
		{
		case SceneType::kTitle:
			//タイトルシーンの描画
			titleScene->Draw();
			break;
		case SceneType::kEX:
			exScene->Draw();
			break;
		case SceneType::kGame:
			// ゲームシーンの描画
			gameScene->Draw();
			break;
		case SceneType::kClear:
			//クリアシーンの描画
			clearScene->Draw();
			break;
		case SceneType::kOver:
			overScene->Draw();
			break;
		default:
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