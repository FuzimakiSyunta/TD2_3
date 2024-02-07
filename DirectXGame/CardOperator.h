#pragma  once
#include <Card.h>
#include <time.h>
#include <optional>
#include <list>
#include <random>


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
	/// 手札更新
	/// </summary>
	void TakeUpdate();


	/// <summary>
	/// カード描画
	/// </summary>
	void Draw();

	void SetType(int cardType_);

	

private:
	/// カードの生成
	Card* card_ = nullptr;

	/// カードテクスチャ
	uint32_t cardTexture_[3] = {0, 0, 0};

	// 手札
	std::list<Card*> hands_;
	// デッキ
	std::list<Card*> deck_;

	//
	int isAtc;
	int isBuff;
	int HandsNumber[2];

	//引いた数
	int TakeCount_;
	//5枚でストップ
	bool Handslimit_;
	//山札の枚数可視化
	int DeckCount_;
	CardType cardType_;
};
