#pragma once
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
	void Initialize();

	void Updata();

	void Draw();

	bool IsSceneEnd() { return isSceneEnd; }

	SceneType NextScene() { return SceneType::kGame; }

	void Reset();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;

	// シーンを終わらせるフラグ
	bool isSceneEnd = false;
	uint32_t textureHandle_ = 0;
	Sprite* sprite_ = nullptr;
};
