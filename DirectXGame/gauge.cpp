﻿#include "Gauge.h"

void Gauge::Initialize() 
{
	//HPゲージの初期化
	HPgauge = 500.0f;
	//キー入力待機時間の初期化
	keyCoolTime_ = 30;
	gauge = 0.0f;
	//シングルだから呼び出す
	input_ = Input::GetInstance();
	GameoverTime = 0;
}
void Gauge::Update() { // キー入力待機時間の更新
	GameoverTime++;
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
				// 左キーを押したときに警戒値ゲージを100下げる
			    if (GameoverTime>50) {
					gauge -= 100.0f;
					keyCoolTime_ = 30;
				}
				if (gauge_ <= 1000) {
					if (input_->PushKey(DIK_SPACE)) {
						gauge_ += 5.0f;
					}
					// 右キーを押したときに警戒値ゲージを100上げる
					if (GameoverTime>100) {
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

	if (GameoverTime == 500) {
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





