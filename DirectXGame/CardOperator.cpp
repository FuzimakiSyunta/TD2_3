#include "CardOperator.h"
#include "ImGuiManager.h"

void CardOperator::Initialize() { 
	/// 乱数の初期化(シード値の設定)
	srand((unsigned int)time(nullptr));
	card_ = new Card();
	card_->Initialize();
}

void CardOperator::CardUpdate() {
	// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_B) {
			/// ランダムで山札から取る
			card_->SetDecknumber((rand() % 20 + 1));
		}
	}
	card_->DeckUpdate();
}


void CardOperator::Update() { 
	///手札からランダムで取る
	CardUpdate();
}


