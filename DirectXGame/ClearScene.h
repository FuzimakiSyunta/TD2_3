#pragma once
#include "Scene.h"
#include "Model.h"
#include "Sprite.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "TextureManager.h"
class ClearScene {
public:
	void Initialize();

	void Updata();

	void Draw();

	bool IsSceneEnd() { return isSceneEnd; }

	Scene NextScene() { return Scene::TITLE; }

	void Reset();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;

	// シーンを終わらせるフラグ
	bool isSceneEnd = false;
	uint32_t textureHandle_ = 0;
	Sprite* sprite_ = nullptr;
};
