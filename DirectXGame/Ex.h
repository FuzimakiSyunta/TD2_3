#pragma once
//ヘッダファイルのインクルード
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "TextureManager.h"
#include <cassert>
class Ex {
public:
	void Initialize(); // 初期化
	void Update();     // 更新
	void Draw();       // 描画
public:
	//スプライトの幅
	/*Vector2 size_ = {1920.0f, 1080.0f};*/
	//出すかどうか
	bool isExSprite_ = false;

private:
	// キー
	Input* input_ = nullptr;
	// ワールドトランスフォーム　
	WorldTransform worldTransform_;

};
