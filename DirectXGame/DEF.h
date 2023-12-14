#pragma once
class DEF {
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

	enum DEFCard {
		DEF2, // 0
		DEF2, // 1
		DEF3, // 2
		DEF4, // 3
		DEF5, // 4
	};

private:

	//カードを使ったときの処理
	void UseDEF2();
	void UseDEF3();
	void UseDEF4();
	void UseDEF5();

	//カードを捨てたときの処理
	void DisposeDEF2();
	void DisposeDEF3();
	void DisposeDEF4();
	void DisposeDEF5();

};
