#include "CardOperator.h"
#include "ImGuiManager.h"
#include <TextureManager.h>
#include <iostream>

void CardOperator::Initialize() { 
	/// 乱数の初期化(シード値の設定)
	srand((unsigned int)time(nullptr));
	
	/// カードの生成と初期化
	card_ = new Card();
	card_->Initialize();
	TakeInitialize();
	
	//山札の総数
	for (int i = 0; i < 20; i++) {
		deck_.push_back(new Card());
	}

	// 範囲for
	// Card* card 代入先
	// deck_ 代入するやつ
	// 要はdeck_の要素分ループさせ、ループごとの要素をcardに代入している
	for (Card* card : deck_) {
		card->Initialize();
	}
	/// カードのテクスチャ読み込み
	cardTexture_[0] = TextureManager::Load("HEALcardBase.png");
	cardTexture_[1] = TextureManager::Load("ATKcardBase.png");
	cardTexture_[2] = TextureManager::Load("BUFFcardBase.png");
	cardTexture_[3] = TextureManager::Load("DEFcardBase.png");
	cardSprite_[0] = Sprite::Create(cardTexture_[0], {120, 180});
	cardSprite_[1] = Sprite::Create(cardTexture_[1], {260, 180});
	cardSprite_[2] = Sprite::Create(cardTexture_[2], {400, 180});
	cardSprite_[3] = Sprite::Create(cardTexture_[3], {540, 180});

	
}

void CardOperator::TakeInitialize() { 
	
}

void CardOperator::Update() {
	/// デッキのランダム
	size_t length = deck_.size();
	for (size_t i = length - 1; i > 0; --i) {
		int j = rand() % (i + 1);
		std::swap(*next(deck_.begin(), i), *next(deck_.begin(), j));
		if (j<=9) {
			cardType_ = CardType::kAtk;
		}
		if (j >= 10&&j <= 14) {
			cardType_ = CardType::kDef;
		}
		if (j >= 15 && j <= 18) {
			cardType_ = CardType::kHeal;
		}
		if (j >= 19 && j <= 20) {
			cardType_ = CardType::kBuff;
		}
	}
	for (Card* card : deck_) {
		std::cout << card << std::endl;
	}
	
}

void CardOperator::FarstTakeUpdate() {
	///最初に5まいとる
	if (TakeCount_<5) {
		StartTakeTime_++;
	}

	if (StartTakeTime_>=10) {
		// どろー、deck_から手札にcard移動する
		hands_.splice(hands_.end(), std::move(deck_), deck_.begin());
		TakeCount_ += 1;
		StartTakeTime_ = 0;
		Sleep(1 * 100);
	}

#ifdef _DEBUG
	// 画面の座標を表示
	ImGui::Begin("Card");
	ImGui::Text("%d\n", TakeCount_);
	ImGui::End();
#endif !_DEBUG

}

void CardOperator::TrashUpdate() {
	/// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;
	/// カードの捨てる処理
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_A) {
			
		}
	}
}

void CardOperator::Draw() { 
	if (cardType_ == CardType::kHeal) {
		cardSprite_[0]->Draw();
	}
	if (cardType_ == CardType::kAtk) {
		cardSprite_[1]->Draw();
	}
	if (cardType_ == CardType::kBuff) {
		cardSprite_[2]->Draw();
	}
	if (cardType_ == CardType::kDef) {
		cardSprite_[3]->Draw();
	}
	
}

void CardOperator::SetType(int cardType) { 
	cardType_ = static_cast<CardType>(cardType); 
}





