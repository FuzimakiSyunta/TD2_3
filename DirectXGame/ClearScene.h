//クリアシーンのヘッダファイル
#pragma once

// ヘッダーファイルのインクルード
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Scene.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class ClearScene 
{
public:
	ClearScene();  // コンストラクタ
	~ClearScene(); // デストラクタ

	void Initialize(); // 初期化
	void Update();     // 更新
	void Draw();       // 描画

	void SceneReset(); // シーンのリセット

	bool isSceneEnd = false;
	bool IsSceneEnd() { return isSceneEnd; }

	// 次のシーンをゲームプレイシーンへ
	SceneType NextScene() { return SceneType::kTitle; }

private:
	DirectXCommon* dxCommon_ = nullptr;

	Input* input_ = nullptr;

	Sprite* spriteOver_ = nullptr;
};
