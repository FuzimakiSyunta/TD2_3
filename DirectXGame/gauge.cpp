#include "Gauge.h"

void Gauge::Initialize() 
{
	//HPゲージの初期化
	HPgauge = 500.0f;
	//キー入力待機時間の初期化
	keyCoolTime_ = 30;
	gauge = 0.0f;
	//シングルだから呼び出す
	input_ = Input::GetInstance();
}
void Gauge::Update() { // キー入力待機時間の更新
	if (keyCoolTime_ > 0) {
		keyCoolTime_--;
	} else if (keyCoolTime_ <= 0) {
		keyCoolTime_ = 0;
	}

	
		if (keyCoolTime_ == 0) {
			if (gauge >= 0) {
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
				// 左キーを押したときに警戒値ゲージを100下げる
				if (input_->PushKey(DIK_LEFT)) {
					gauge -= 100.0f;
					keyCoolTime_ = 30;
				}
				if (gauge_ <= 1000) {
					if (input_->PushKey(DIK_SPACE)) {
						gauge_ += 5.0f;
					}
					// Dキーを押したときに警戒値ゲージを50あげる
					if (input_->PushKey(DIK_D)) {
						gauge += 50.0f;
						HPgauge -= 30.0f;
						keyCoolTime_ = 30;
					}
					// 右キーを押したときに警戒値ゲージを100上げる
					if (input_->PushKey(DIK_RIGHT)) {
						gauge += 100.0f;
						HPgauge -= 70.0f;
						keyCoolTime_ = 30;
					}
				}
			}
		}
	

	if (gauge >= 700) { // ゲージオーバー
		gaugeCount = 1;  // カウント１
	}

	if (gaugeCount == 1) {
		GaugeOver();
	}

	if (HPgauge <= 0)
	{
		hpCount = 1;
	}

	if (hpCount == 1)
	{
		HpOver();
	}


	if (gauge <= 0) {
		gauge = 0;
	}
	if (gauge >= 700) {
		gauge = 700;
	}
	if (HPgauge <= 0) {
		HPgauge = 0;
	}
	if (HPgauge >= 500) {
		HPgauge = 500;
	}
}

void Gauge::Draw() {}

void Gauge::GaugeOver() 
{
	isGaugeEnd = true; }

void Gauge::GaugeReset()
{
	gaugeCount = 0;
	hpCount = 0;
	isHpEnd = false;
	isGaugeEnd = false;
	Initialize();
}

void Gauge::HpOver() 
{ isHpEnd = true; }

void Gauge::HpReset()
{
}





