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
#include <math.h>
#include <optional>

#define _USE_MATH_DEFINES


class ObjectBreak
{
public:

	enum class Behavior
	{
		kStandby,	//待機
		kAttack,	//攻撃
		kRespawn,	//リスポーン
	};

	void Initialize(Model* model); // 初期化
	void Update();     // 更新
	void Draw(const ViewProjection& viewProjection);    // 描画

	/// <summary>
	///ワールド座標を取得 
	/// </summary>
	Vector3 GetPosition();
	const WorldTransform& GetWorldTransform();

	//オブジェクト１

	//待機
	void BehaviorStanbyInitialize();	//初期化
	void BehaviorStanbyUpdate();		//更新

	//攻撃
	void BehaviorAttackInitialize();	//初期化
	void BehaviorAttackUpdate();		//更新

	//リスポーン
	void BehaviorRespawnInitialize();	//初期化
	void BehaviorRespawnUpdate();		//更新

	//行動
	Behavior behavior_ = Behavior::kStandby;

private:
	//次の行動
	std::optional<Behavior> behaviorRepuest_ = std::nullopt;

	//カードを受け付けるフラグ
	float cardReception = 1;

	// キー
	Input* input_ = nullptr;

	// ワールドトランスフォーム　
	WorldTransform worldTransform_;
	
	//テクスチャハンドル
	uint32_t ObjectTextureHandle_ = 0;

	//カメラビュープロジェクション
	const ViewProjection* viewProjection_ = nullptr;

	// 3Dモデル
	Model* model_ = nullptr;
};
