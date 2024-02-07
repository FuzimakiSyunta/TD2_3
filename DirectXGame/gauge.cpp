#include "Gauge.h"

void Gauge::Initialize() 
{
	//ゲージの初期化
	gauge = 1100.0f;
	//HPゲージの初期化
	HPgauge = 500.0f;
	//キー入力待機時間の初期化
	keyCoolTime_ = 30;
	//シングルだから呼び出す
	input_ = Input::GetInstance();
}

void Gauge::Update() 
{	//キー入力待機時間の更新
	if (keyCoolTime_ > 0) {
		keyCoolTime_--;
	} else if (keyCoolTime_ <= 0) {
		keyCoolTime_ = 0;
	}

	if (keyCoolTime_ == 0) {
		if (gauge >= 0&&gauge<=1100) {
			// デバッグ用キー
			if (input_->PushKey(DIK_DOWN)) {
				gauge -= 1100.0f;
				keyCoolTime_ = 30;
			}
			if (input_->PushKey(DIK_UP)) {
				gauge += 1100.0f;
				keyCoolTime_ = 30;
			}
			// Aキーを押したときに警戒値ゲージを50下げる
			if (input_->PushKey(DIK_A)) {
				gauge -= 50.0f;
				keyCoolTime_ = 30;
			}
			//左キーを押したときに警戒値ゲージを100下げる
			if (input_->PushKey(DIK_LEFT)) {
				gauge -= 100.0f;
				keyCoolTime_ = 30;
			}
			//Dキーを押したときに警戒値ゲージを50あげる
			if (input_->PushKey(DIK_D)) {
				gauge += 50.0f;
				HPgauge -= 50.0f;
				keyCoolTime_ = 30;
			}
			//右キーを押したときに警戒値ゲージを100上げる
			if (input_->PushKey(DIK_RIGHT)) {
				gauge += 100.0f;
				HPgauge -= 100.0f;
				keyCoolTime_ = 30;
			}
		}
	}
	

	if (gauge <= 0) {
		gauge = 0;
	}
	if (gauge >= 1100) {
		gauge = 1100;
	}
	if (HPgauge <= 0) {
		HPgauge = 0;
	}
	if (HPgauge >= 500) {
		HPgauge = 500;
	}
	
	
}

void Gauge::Draw() {}