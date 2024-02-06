#pragma once
#include<Input.h>
#include "DirectXCommon.h"
#include "Sprite.h"
#include <TextureManager.h>

class Card {
public:
	// デストラクタ

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void DeckUpdate();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	
};
