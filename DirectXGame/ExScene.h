#pragma once
#include "Scene.h"
#include "Model.h"
#include "Sprite.h"
#include "Input.h"
#include "DirectXCommon.h"
#include "TextureManager.h"
class ExScene {
public:
	void Initialize();

	void Update();

	void Draw();

	bool IsSceneEnd() { return isSceneEnd_; }

	Scene NextScene() { return Scene::GAME; }

	void Reset();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;

	// シーンを終わらせるフラグ
	bool isSceneEnd_ = false;
	uint32_t exTexture_ = 0;
	Sprite* sprite_ = nullptr;
};
