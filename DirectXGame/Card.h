#include<time.h>

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
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();


private:
	/// 山札用のランダム変数
	float Decknumber = 0;
	// カードを使う
	int UseCard;
	// カードを捨てる
	int Dispose;
};
