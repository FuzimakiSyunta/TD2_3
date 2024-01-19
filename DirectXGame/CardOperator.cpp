#include "CardOperator.h"
#include "ImGuiManager.h"

void CardOperator::Initialize() { 
	/// 乱数の初期化(シード値の設定)
	srand((unsigned int)time(nullptr));
	/// カードの生成と初期化
	for (int i = 0; i < 5; i++) {
		card_[i] = new Card();
		card_[i]->Initialize();
	}
	TakeInitialize();
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
	if (isTake_[0] == false) {
		card_[0]->SetDecknumber((rand() % 20 + 1));
	}
	if (isTake_[1] == false) {
		card_[1]->SetDecknumber((rand() % 20 + 1));
	}
	if (isTake_[2] == false) {
		card_[2]->SetDecknumber((rand() % 20 + 1));
	}
	if (isTake_[3] == false) {
		card_[3]->SetDecknumber((rand() % 20 + 1));
	}
	if (isTake_[4] == false) {
		card_[4]->SetDecknumber((rand() % 20 + 1));
	}

	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_A) {
			for (int i = 0; i < 5; i++) {
				/// ランダムで山札から取る
				isTake_[i] = true;
			}	
		}
		if (joyState.Gamepad.wButtons == XINPUT_GAMEPAD_X) {
			for (int i = 0; i < 5; i++) {
				/// ランダムで山札から取る
				isTake_[i] = false;
			}
		}
		
	}

	for (int i = 0; i < 5; i++) {
		card_[i]->DeckUpdate();
	}
}

void CardOperator::TrashUpdate() {
	
}

void CardOperator::Update()
{ 
	switch (riquest_) {
	case Riquest::kTake:
	default:
		/// 手札からランダムで取る
		TakeUpdate();
		break;
	case Riquest::kTrash:
		/// カードを捨てる
		TrashUpdate();
		break;
	} 
  
	/*/// IMGUI
	ImGui::Begin("Faze");
	ImGui::Text("%d\n", riquest_);
	ImGui::End();*/
}




