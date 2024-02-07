#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Scene.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "TextureManager.h"
class ExScene {
public:
	ExScene();  // コンストラクタ
	~ExScene(); // デストラクタ

	void Initialize(); // 初期化
	void Update();     // 更新
	void Draw();       // 描画

	void SceneReset(); // シーンのリセット

	bool isExSceneEnd = false;
	bool IsExSceneEnd() { return isExSceneEnd; }

	// 次のシーンをゲームプレイシーンへ
	SceneType NextScene() { return SceneType::kGame; }

private:
	DirectXCommon* dxCommon_ = nullptr;

	Input* input_ = nullptr;

	Sprite* spriteEx_;
};
