#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Card.h"
#include "CardOperator.h"
#include "Gauge.h"
#include "Enemy.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	
	//テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t HPgaugeTexture_ = 0;

	//スプライト
	Sprite* sprite_ = nullptr;
	//HPスプライト
	Sprite* HPsprite_ = nullptr;
	//クリア画面のスプライト
	Sprite* clearSprite_ = nullptr;

	//ワールドトランスフォーム　
	WorldTransform worldTransform_;
	//ビュープロジェクション
	ViewProjection viewProjection_;

	//ゲージ
	std::unique_ptr<Gauge> gauge_;
	//HPゲージ
	std::unique_ptr<Gauge> HPgauge_;

	//表示の大きさ
	Vector2 size;
	//HPゲージの表示の大きさ
	Vector2 HPsize;
	/// 山札
	std::unique_ptr<Card> card_;

	/// 
	std::unique_ptr<CardOperator> cardOperator_;


	//敵
	std::unique_ptr<Enemy>enemy_ = nullptr;
	//敵3Dモデル
	std::unique_ptr<Model>modelEnemyHead_;
};