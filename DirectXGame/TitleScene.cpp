#include "TitleScene.h"

// コンストラクタ
TitleScene::TitleScene() {}

// デストラクタ
TitleScene::~TitleScene() 
{
	delete spriteTitle_;
}

// 初期化
void TitleScene::Initialize() 
{
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();

	//テクスチャロード
	uint32_t textureTitle = TextureManager::Load("Title.png");
	uint32_t textureEx = TextureManager::Load("ex.png");

	spriteTitle_ =
	    Sprite::Create(textureTitle, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	spriteEx_ = Sprite::Create(textureEx, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

}

// 更新
void TitleScene::Update() {
	/// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;

	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_A)
		{
			isSceneEnd = true;
		}
	}
	Sleep(1 * 120);
}


// 描画
void TitleScene::Draw()
{
	//コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	//背景スプライト描画
	Sprite::PreDraw(commandList);
	///


	///
	// スプライト描画後処理(
	Sprite::PostDraw();
	//深度バッファクリア
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

	spriteTitle_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion

}

// シーンのリセット
void TitleScene::SceneReset() 
{ 
	Initialize();
	isSceneEnd = false;
}
