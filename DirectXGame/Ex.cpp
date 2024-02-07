#include "Ex.h"
void Ex::Initialize() {
	isExSprite_ = false;
}

void Ex::Update() {
	/// ゲームパッドの状態を得る変数
	XINPUT_STATE joyState;
	if (Input::GetInstance()->GetJoystickState(0, joyState)) {
		if ((joyState.Gamepad.wButtons == XINPUT_GAMEPAD_Y)) {
			if (isExSprite_ == false) {
				isExSprite_ = true;
				Sleep(1 * 120);
			} else {
				isExSprite_ = false;
				Sleep(1 * 120);
			}
		} 
	}
}

void Ex::Draw() { isExSprite_ = true; }