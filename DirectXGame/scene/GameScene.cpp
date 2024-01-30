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
	/// 山札の生成
	card_ = std::make_unique<Card>();
	/// カードのテクスチャ読み込み
	cardTexture_ = TextureManager::Load("HEALcardBase.png");
	cardSprite_ = Sprite::Create(cardTexture_, {0, 0});
	///山札
	card_->Initialize();

	/// 
	cardOperator_ = std::make_unique<CardOperator>();
	

	cardOperator_->Initialize();

	//ゲージのスプライト読み込み
	textureHandle_ = TextureManager::Load("Stamina.png");

	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	gauge_ = std::make_unique<Gauge>();
	gauge_->Initialize();
	
	
}

void GameScene::Update() 
{
	//カード操作
	cardOperator_->Update();
	/// 山札
	card_->DeckUpdate();

	///
	cardOperator_->FazeUpdate();
	///
	cardOperator_->TakeUpdate();



	size = sprite_->GetSize();

	size.x = gauge_->GetGauge();

	sprite_->SetSize(size);

	gauge_->Update();
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
	cardSprite_->Draw();
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
