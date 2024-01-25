#pragma once
#include <Card.h>
#include <time.h>
#include <optional>

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
	/// フェーズ初期化
	/// </summary>
	void FazeInitialize();

	/// <summary>
	/// フェーズ更新
	/// </summary>
	void FazeUpdate();

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
	Card* card_[5] = {nullptr,nullptr,nullptr,nullptr,nullptr};
	/// 手札に加える
	bool isTake_[5];
	

};
