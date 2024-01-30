#include "CardOperator.h"
#include "ImGuiManager.h"
#include <TextureManager.h>

void CardOperator::Initialize() { 
	/// 乱数の初期化(シード値の設定)
	srand((unsigned int)time(nullptr));

	
	/*cardTexture_[1] = TextureManager::Load("ATKcardBase.png");
	cardTexture_[2] = TextureManager::Load("BUFFcardBase.png");
	cardTexture_[3] = TextureManager::Load("DEFcardBase.png");*/
	
	/// カードの生成と初期化
	for (int i = 0; i < 5; i++) {
		card_[i] = new Card();
		card_[i]->Initialize();
	}
	/// カードの有無
	for (int i = 0; i < 5; i++) {
		isCardtrash_[i] = false;
	}
	deck_.push_back(new Card());

	TakeInitialize();

	// 範囲for
	// Card* card 代入先
	// deck_ 代入するやつ
	// 要はdeck_の要素分ループさせ、ループごとの要素をcardに代入している
	for (Card* card : deck_) {
		card->Initialize();
	}
	// どろー、deck_から手札にcard移動する
	hands_.splice(hands_.end(), std::move(deck_), deck_.begin());
	
}

void CardOperator::TakeInitialize() { 
	for (int i = 0; i < 5; i++) {
		isTake_[i] = false;
	}
}

void CardOperator::FazeInitialize() { 
	
}

void CardOperator::FazeUpdate() { 
	
}

void CardOperator::TakeUpdate() {
	/// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;
	/// カードのランダム処理
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_A) {
			
		}
	}

	for (int i = 0; i < 5; i++) {
		card_[i]->DeckUpdate();
	}

//#ifdef _DEBUG
//	ImGui::Begin("Card");
//	ImGui::Text("%d", card_);
//	ImGui::End();
//
//#endif // !_DEBUG
}

void CardOperator::TrashUpdate() {
	
}

void CardOperator::Draw() { 
	
}

void CardOperator::Update()
{ 
	/*switch (riquest_) {
	case Riquest::kTake:
	default:
		/// 手札からランダムで取る
		TakeUpdate();
		break;
	case Riquest::kTrash:
		/// カードを捨てる
		TrashUpdate();
		break;
	} */
  
	/*/// IMGUI
	ImGui::Begin("Faze");
	ImGui::Text("%d\n", riquest_);
	ImGui::End();*/
}




