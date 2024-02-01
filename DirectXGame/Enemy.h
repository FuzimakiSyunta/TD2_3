#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include <assert.h>
#include "ViewProjection.h"
enum Phase {
	Action, // 回復か回避をする
	Waiting,    // プレイヤーの行動待ち
};
class Enemy {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(){};

	/// <summary>
	/// 更新
	/// </summary>
	void Update(){};

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(){};

	/// <summary>
	/// 行動の初期化
	/// </summary>
	void ActionInitialize(){};

private:

	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t enemy_ = 0u;
};
