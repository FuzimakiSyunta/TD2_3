//オブジェクト破壊
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


class ObjectBreak
{
public:
	void Initialize(const std::vector<Model*>& models); // 初期化
	void Update();     // 更新
	void Draw(const ViewProjection& viewProjection);    // 描画

	/// <summary>
	///ワールド座標を取得 
	/// </summary>
	Vector3 GetPosition();
	const WorldTransform& GetWorldTransform();

private:
	// キー
	Input* input_ = nullptr;

	// ワールドトランスフォーム　
	WorldTransform worldTransform_;
	
	//テクスチャハンドル
	uint32_t ObjectTextureHandle_ = 0;

	//カメラビュープロジェクション
	const ViewProjection* viewProjection_ = nullptr;
};
