﻿#pragma  once
#include <Card.h>
#include <time.h>
#include <optional>
#include <list>


class CardOperator {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 手札動作更新
	/// </summary>
	void TakeUpdate();

	/// <summary>
	/// 手札動作初期化
	/// </summary>
	void TakeInitialize();

	/// <summary>
	/// 捨てる動作
	/// </summary>
	void TrashUpdate();

	/// <summary>
	/// カード描画
	/// </summary>
	void Draw();

	/// <summary>
	/// フェーズ
	/// </summary>
	enum class Riquest {
		kTake,
		kAttack,
		kTrash,
	};


private:
	Riquest riquest_ = Riquest::kTake;
	std::optional<Riquest> fazeRequest_ = std::nullopt;
	/// カードの生成
	Card* card_ = nullptr;
	/// 手札に加える
	bool isTake_[5];
	///カードの有無
	bool isCardtrash_[5];
	///出たカード
	int OpenCard_=0;
	/// 山札用のランダム変数
	int cardnumber_ = 1;
	/// 攻撃カード
	bool isATCcard_ = false;
	/// 防御カード
	bool isDEFcard_ = false;
	/// 回復カード
	bool isHealcard_ = false;
	/// バフカード
	bool isBufcard_ = false;	


	/// カードテクスチャ
	uint32_t cardTexture_[4] = {0, 0, 0, 0};
	// スプライト
	Sprite* cardSprite_[4] = {nullptr, nullptr, nullptr, nullptr};

	// 手札
	std::list<Card*> hands_;
	// デッキ
	std::list<Card*> deck_;
	

};
