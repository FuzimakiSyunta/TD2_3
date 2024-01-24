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
	///山札
	card_->Initialize();

	//ワールドトランスフォーム
	worldTransform_.Initialize();

	//ビュープロジェクション
	viewProjection_.Initialize();

	//3Dモデルの生成
	model_.reset(Model::Create());

	//ゲージのスプライト読み込み
	textureHandle_ = TextureManager::Load("Stamina.png");

	sprite_ = Sprite::Create(textureHandle_, {100, 50});
	gauge_ = std::make_unique<Gauge>();
	gauge_->Initialize();
	

	//3Dモデルのロード
	modelObject_.reset(Model::CreateFromOBJ("syanderia", true));
	objectBreak_ = std::make_unique<ObjectBreak>();
	objectBreak_->Initialize(modelObject_.get());


}

void GameScene::Update() 
{
	/// 山札
	card_->Update();

	size = sprite_->GetSize();

	size.x = gauge_->GetGauge();

	sprite_->SetSize(size);

	gauge_->Update();

	objectBreak_->Update();
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
	
	//オブジェクト	
	objectBreak_->Draw(viewProjection_);

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

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
