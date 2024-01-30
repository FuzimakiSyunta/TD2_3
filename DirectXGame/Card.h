﻿#pragma once
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

	void HandCardUpdate();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void SetCardNumber(int decknumber) {decknumber_ = decknumber; }

private:
	/// 山札用のランダム変数
	int decknumber_ = 1;
	/// カードを捨てる
	int dispose_;
	/// カードを取る
	bool takeCard_[20];
	/// 一度でたカードの除外
	bool deckFrag_[20];
	///攻撃カード
	bool isATCcard_ = false;
	/// 防御カード
	bool isDEFcard_ = false;
	/// 回復カード
	bool isHealcard_ = false;
	///バフカード
	bool isBufcard_ = false;

private:
	DirectXCommon* dxCommon_ = nullptr;

	
};
