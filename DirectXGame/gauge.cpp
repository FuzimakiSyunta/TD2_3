#include "Gauge.h"

void Gauge::Initialize() 
{
	//ゲージの初期化
	gauge = 100.0f;
	//シングルだから呼び出す
	input_ = Input::GetInstance();
}

void Gauge::Update() 
{ 
	if (input_->PushKey(DIK_SPACE))
	{
		gauge -= 5.0f;
	}
}

void Gauge::Draw() {}
