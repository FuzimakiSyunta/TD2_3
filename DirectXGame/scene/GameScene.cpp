#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>


GameScene::GameScene() {}

GameScene::~GameScene() 
{
	delete sprite_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	viewProjection_.Initialize();

	//ワールドトランスフォーム
	worldTransform_.Initialize();

	//ビュープロジェクション
	viewProjection_.Initialize();

	//3Dモデルの生成
	model_.reset(Model::Create());

	/// 
	cardOperator_ = std::make_unique<CardOperator>();
	/// 
	cardOperator_->Initialize();

	// スプライト読み込み
	textureHandle_ = TextureManager::Load("gauge/Stamina.png");
	HPgaugeTexture_ = TextureManager::Load("gauge/HPGauge.png");

	// 警戒値ゲージの描画設定
	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	gauge_ = std::make_unique<Gauge>();
	gauge_->Initialize();
	// HPゲージの描画設定
	HPsprite_ = Sprite::Create(HPgaugeTexture_, {300, 600});
	HPgauge_ = std::make_unique<Gauge>();
	HPgauge_->Initialize();

	//敵の生成
	enemy_ = std::make_unique<Enemy>();
	//敵3Dモデルの作成
	modelEnemyHead_.reset(Model::CreateFromOBJ("enemy", true));
	//敵の初期化
	enemy_->Initialize(modelEnemyHead_.get());
	
	//オブジェクト１の生成
	object1_ = std::make_unique<Object1>();
	//オブジェクト3Dモデルの作成
	modelObject1_.reset(Model::CreateFromOBJ("object1", true));
	//オブジェクト１の初期化
	object1_->Initialize(modelObject1_.get());

	// オブジェクト２の生成
	object2_ = std::make_unique<Object2>();
	// オブジェクト3Dモデルの作成
	modelDynamite_.reset(Model::CreateFromOBJ("dynamite", true));
	modelBox_.reset(Model::CreateFromOBJ("box", true));
	// オブジェクト２の初期化
	object2_->Initialize(modelDynamite_.get(), modelBox_.get());
}

void GameScene::Update() 
{
	//敵キャラの更新　
	enemy_->Update();
	//カード操作
	cardOperator_->Update();
	///
	cardOperator_->TakeUpdate();



	size = sprite_->GetSize();
	size.x = gauge_->GetGauge();
	sprite_->SetSize(size);
	gauge_->Update();

	//HPバーのサイズ変更
	HPsize = HPsprite_->GetSize();
	HPsize.x = HPgauge_->GetHPgauge();
	HPsprite_->SetSize(HPsize);
	HPgauge_->Update();

	//オブジェクトの更新
	object1_->Update();
	object2_->Update();

	gauge_->Update();

	//シーン切り替えのトリガー
	if (input_->TriggerKey(DIK_0))//クリア条件
	{
		clearCount = true;
		isSceneEnd = true;
	}

	if (input_->TriggerKey(DIK_1))//ゲームオーバー条件
	{
		clearCount = false;
		isSceneEnd = true;
	}

}

void GameScene::Draw() { 

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	enemy_->Draw(viewProjection_);
	object1_->Draw(viewProjection_);
	object2_->Draw(viewProjection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	sprite_->Draw();
	HPsprite_->Draw();

	cardOperator_->Draw();
	
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void GameScene::sceneReset() 
{
	isSceneEnd = false;
	clearCount = false;
	Initialize();
}
