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
	float Decknumber = 1;
	/// カードを使う
	int UseCard;
	/// カードを捨てる
	int Dispose;

	enum CardKinds {
		ONE,//0
		TWO,//1
		THREE,//2
		FOUR,//3
		FIVE,//4
		SIX,//5
		SEVEN,//6
		EIGHT,//7
		NINE,//8
		TEN,//9
		DEF2,//10
		DEF2,//11
		DEF3,//12
		DEF4,//13
		DEF5,//14
		HEAL4,//15
		HEAL5,//16
		HEAL6,//17
		BUFF3,//18
		BUFF3,//19
	};
};
