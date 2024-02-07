﻿//ゲージのヘッダーファイル
#pragma once
//ヘッダファイルのインクルード
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <cassert>

class Gauge
{
public:
	void Initialize();	//初期化
	void Update();		//更新
	void Draw();		//描画
public:

	//スプライトの幅
	Vector2 size_ = {100.0f, 100.0f};
	
	float GetGauge() { return gauge; };

	float GetHPgauge() { return HPgauge; };

private:
	//キー入力待機用の変数
	int keyCoolTime_;

	//HPゲージの変数
	int HPgauge_;

	//キー
	Input* input_ = nullptr;

	//ワールドトランスフォーム　
	WorldTransform worldTransform_;

	// 警戒値のゲージ
	float gauge;
	//HPゲージ
	float HPgauge;
};
