#pragma once
#include <Card.h>
#include <time.h>

class CardOperator {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 更新
	/// </summary>
	void CardUpdate();

private:
	/// カードの生成
	Card* card_ = nullptr;

};
