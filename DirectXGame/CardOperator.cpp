﻿#include "CardOperator.h"
#include "ImGuiManager.h"
#include <TextureManager.h>
#include <iostream>

void CardOperator::Initialize() { 
	/// 乱数の初期化(シード値の設定)
	srand((unsigned int)time(nullptr));
	/// カードのテクスチャ読み込み
	cardTexture_[0] = TextureManager::Load("ATKcardBase.png");
	cardTexture_[1] = TextureManager::Load("DEFcardBase.png");
	cardTexture_[2] = TextureManager::Load("BUFFcardBase.png");
	///山札の総数20枚
	//ATK
	for (int i = 0; i < 10; i++) {
		// デッキに入れる前に初期化をしてカードタイプ決めてる
		Card* card = new Card();
		card->Initialize(CardType::kAtk, cardTexture_[static_cast<size_t>(CardType::kAtk)]);
		deck_.push_back(card);
	}
	//DEF
	for (int i = 0; i < 6; i++) {
		// デッキに入れる前に初期化をしてカードタイプ決めてる
		Card* card = new Card();
		card->Initialize(CardType::kDef, cardTexture_[static_cast<size_t>(CardType::kDef)]);
		deck_.push_back(card);
	}
	//BUFF
	for (int i = 0; i < 4; i++) {
		// デッキに入れる前に初期化をしてカードタイプ決めてる
		Card* card = new Card();
		card->Initialize(CardType::kBuff, cardTexture_[static_cast<size_t>(CardType::kBuff)]);
		deck_.push_back(card);
	}

	//デッキのランダム
	size_t length = deck_.size();
	for (size_t i = length - 1; i > 0; --i) {
		int j = rand() % (i + 1);
		std::swap(*next(deck_.begin(), i), *next(deck_.begin(), j));
	}
	for (Card* card : deck_) {
		std::cout << card << std::endl;
	}
	//引いた数カウント
	TakeCount_ = 0;
	// 5枚でストップ
	Handslimit_ = false;

	isAtc=0;
	isBuff=0;

	Vector2 pos = {0, 0};
}

void CardOperator::TakeUpdate() {
	// どろー、deck_から手札にcard移動する
	hands_.splice(hands_.end(), std::move(deck_), deck_.begin());
	DeckCount_ += 1;
	TakeCount_ += 1;
}

void CardOperator::Update() {
	/// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;
	if (DeckCount_ < 40) {//
		///
		if (Input::GetInstance()->GetJoystickState(0, joyState)) {
			if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_X) {
				if (Handslimit_ == false) {
					TakeUpdate(); // カードを追加
				}
				int i = 0;
				// 例　手札の描画用位置の設定
				for (Card* card : hands_) {
					// 　変数で指定するか直性値入れるか
					card->SetSpritePos({(float)(560 + i * 140), 540});
					// card->SetSpritePos(pos);
					i++;
				}
			}
			if (Handslimit_ == true) {
				if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_B) {
					// どろー、deck_から手札にcard移動する
					deck_.splice(deck_.end(), std::move(hands_), hands_.begin());
					TakeCount_ -= 1 ;
					DeckCount_ -= 1;
				}

			}
		}
		/// 5枚手札を用意
		if (TakeCount_ == 5) {
			Handslimit_ = true;
		}
		
	}
#ifdef _DEBUG
	// 画面の座標を表示
	ImGui::Begin("Card");
	ImGui::Text("DeckCount %d\n", DeckCount_);
	ImGui::Text("TakeCount %d\n", TakeCount_);
	ImGui::Text("isAtc %d\n", isAtc);
	ImGui::End();
#endif !_DEBUG

}


void CardOperator::Draw() {
	// 手札描画
	for (Card* card : hands_) {
		card->Draw();
	}
}


void CardOperator::SetType(int cardType) { 
	cardType_ = static_cast<CardType>(cardType); 
}





