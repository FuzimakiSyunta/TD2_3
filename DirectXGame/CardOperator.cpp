#include "CardOperator.h"
#include "ImGuiManager.h"
#include <TextureManager.h>

void CardOperator::Initialize() { 
	/// 乱数の初期化(シード値の設定)
	srand((unsigned int)time(nullptr));
	
	/// カードの生成と初期化
	card_ = new Card();
	card_->Initialize();
	/// カードの有無
	for (int i = 0; i < 5; i++) {
		isCardtrash_[i] = false;
	}
	TakeInitialize();
	
	// 範囲for
	// Card* card 代入先
	// deck_ 代入するやつ
	// 要はdeck_の要素分ループさせ、ループごとの要素をcardに代入している
	for (Card* card : deck_) {
		card->Initialize();
	}
	//山札の総数
	for (int i = 0; i < 20; i++) {
		deck_.push_back(new Card());
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
	for (int i = 0; i < 5; i++) {
		isTake_[i] = false;
	}
}

void CardOperator::TakeUpdate() {
	/// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;
	/// カードの処理
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_A) {
			// どろー、deck_から手札にcard移動する
			hands_.splice(hands_.end(), std::move(deck_), deck_.begin());
			Sleep(1 * 1000);
		}
	}
	
	/// 攻撃カード
	if (cardnumber_ > 0 && cardnumber_ <= 10) {
		isATCcard_ = true;
		isDEFcard_ = false;
		isHealcard_ = false;
		isBufcard_ = false;
	}
	/// 防御カード
	if (cardnumber_ >= 11 && cardnumber_ <= 15) {
		isATCcard_ = false;
		isDEFcard_ = true;
		isHealcard_ = false;
		isBufcard_ = false;
	}
	/// 回復カード
	if (cardnumber_ >= 16 && cardnumber_ <= 18) {
		isATCcard_ = false;
		isDEFcard_ = false;
		isHealcard_ = true;
		isBufcard_ = false;
	}
	/// バフカード
	if (cardnumber_ >= 19 && cardnumber_ <= 20) {
		isATCcard_ = false;
		isDEFcard_ = false;
		isHealcard_ = false;
		isBufcard_ = true;
	}
	
}

void CardOperator::TrashUpdate() {
	
}

void CardOperator::Draw() { 
	if (isHealcard_ == true) {
		cardSprite_[0]->Draw();
	}
	if (isATCcard_ == true) {
		cardSprite_[1]->Draw();
	}
	if (isBufcard_ == true) {
		cardSprite_[2]->Draw();
	}
	if (isDEFcard_ == true) {
		cardSprite_[3]->Draw();
	}
}





