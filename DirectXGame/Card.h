#pragma once
#include<Input.h>
#include "DirectXCommon.h"
#include "Sprite.h"
#include <TextureManager.h>


enum class CardType { kAtk, kDef, kBuff, kHeal };

/// <summary>
/// カード一枚の情報をまとめたクラス
/// </summary>
class Card {
public:
	// デストラクタ

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(CardType cardType, uint32_t textureHandle);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void SetSpritePos(Vector2 pos);

private:
	// カード種類
	CardType cardType_;
	// CardOperatorから受け取るためのテクスチャハンドル
	uint32_t textureHandle_ = 0u;
	// 描画するためのSprite
	Sprite* sprite_ = nullptr;
};
