#pragma once
class HEAL {
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

	enum HEALCard {
		HEAL4, // 0
		HEAL5, // 1
		HEAL6, // 2
	};

private:

	//カードを使う処理
	void UseHEAL4();
	void UseHEAL5();
	void UseHEAL6();

	//カードを捨てる処理
	void DisposeHEAL4();
	void DisposeHEAL5();
	void DisposeHEAL6();

};
