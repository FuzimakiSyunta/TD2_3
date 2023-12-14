#pragma once
class ATK {
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

	enum LowATKCard {
		ONE,   // 0
		THREE, // 1
		FIVE,  // 2
		SEVEN, // 3
		NINE,  // 4
	};
	enum HightATKCard {
		TWO,   // 0
		FOUR,  // 1
		SIX,   // 2
		EIGHT, // 3
		TEN,   // 4
	};

private:

	//カードを使ったときの処理
	void UseONE(){};
	void UseTWO();
	void UseTHREE();
	void UseFOUR();
	void UseFIVE();
	void UseSIX();
	void UseSEVEN();
	void UseEIGHT();
	void UseNINE();
	void UseTEN();


	//カードを捨てたときの処理
	void DisposeONE();
	void DisposeTWO();
	void DisposeTHREE();
	void DisposeFOUR();
	void DisposeFIVE();
	void DisposeSIX();
	void DisposeSEVEN();
	void DisposeEIGHT();
	void DisposeNINE();
	void DisposeTEN();
};
