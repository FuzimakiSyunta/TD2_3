#pragma once
class BUFF {
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

	enum BUFFCard {
		BUFF3, // 0
		BUFF3, // 1
	};

private:

	//カードを使う処理
	void UseBUFF3();

	//カードを捨てる処理
	void DisposeBUFF3();
};
