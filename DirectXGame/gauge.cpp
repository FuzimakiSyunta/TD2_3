#include "Gauge.h"

void Gauge::Initialize() 
{
	//ゲージの初期化
	gauge_ = 1000.0f;
	//シングルだから呼び出す
	input_ = Input::GetInstance();
}

void Gauge::Update() 
{ 
	if (gaugeCount == 0)
	{
		if (gauge_ >= 1) {
			if (input_->PushKey(DIK_SPACE)) {
				gauge_ -= 5.0f;
			}
		}
		if (gauge_ <= 1)
		{
			gaugeCount = 1;
		}
	}
	if (gaugeCount == 1)
	{
		
	}
	
	
}

void Gauge::Draw() 
{
	
}
