#include "ObjectBreak.h"

void ObjectBreak::Initialize(Model* model) 
{
	//
	input_ = Input::GetInstance();

	//ワールドトランスフォーム
	worldTransform_.Initialize();

	assert(model);
	model_ = model;
}

void ObjectBreak::Update() 
{ 
	worldTransform_.TransferMatrix();

	//オブジェクトのゲームシーン

	//待機シーン更新
	BehaviorStanbyUpdate();

	//trueなら初期化
	if (behaviorRepuest_)
	{
		// std::nullopt以外の値が入っている時trueになる
		behavior_ = behaviorRepuest_.value(); 


		switch (behavior_) 
		{
		case ObjectBreak::Behavior::kStandby:

			BehaviorStanbyInitialize(); // 初期化
		
			break;
		case ObjectBreak::Behavior::kAttack:

			BehaviorAttackInitialize(); // 初期化
		
			break;
		case ObjectBreak::Behavior::kRespawn:

			BehaviorRespawnInitialize(); // 初期化
		
			break;
		default:
			break;
		}

		//falseにする
		behaviorRepuest_ = std::nullopt;
	}

	//オブジェクト１の更新処理
	switch (behavior_) 
	{
	case ObjectBreak::Behavior::kStandby:

		BehaviorStanbyUpdate(); // 更新
	
		break;
	case ObjectBreak::Behavior::kAttack:

		BehaviorAttackUpdate(); // 更新
	
		break;
	case ObjectBreak::Behavior::kRespawn:

		BehaviorRespawnUpdate(); // 更新
	
		break;
	default:
		break;
	}

}

void ObjectBreak::Draw(const ViewProjection& viewProjection)
{
	model_->Draw(worldTransform_, viewProjection);
}

Vector3 ObjectBreak::GetPosition() 
{ 
	//ワールド座標を入れる変数
	Vector3 worldPos;

	// ワールド行列の平行移動成分を取得(ワールド座標)
	worldPos.x = worldTransform_.matWorld_.m[3][0];
	worldPos.y = worldTransform_.matWorld_.m[3][1];
	worldPos.z = worldTransform_.matWorld_.m[3][2];

	return worldPos; 
}

const WorldTransform& ObjectBreak::GetWorldTransform() {
	// TODO: return ステートメントをここに挿入します
	return worldTransform_;
}

//オブジェクト1

//待機
//初期化
void ObjectBreak::BehaviorStanbyInitialize() 
{ 
	//フラグをtrueへ
	cardReception = 1;
}

//更新
void ObjectBreak::BehaviorStanbyUpdate() 
{
	//フラグがtrueで対応するカードのフラグをもらったら時攻撃シーンへ
	if (cardReception == 1) 
	{
		cardReception = 0;
		Behavior::kAttack;
	}
}

//攻撃
// 初期化
void ObjectBreak::BehaviorAttackInitialize()
{
	//位置の初期化

}

// 更新
void ObjectBreak::BehaviorAttackUpdate() 
{
	//攻撃のモーション（落下のイージング？
	
	
	
	//モーションが終わったら、
	//敵にダメージ＆オブジェクトの削除＆リスポーンシーンへ
	Behavior::kRespawn;
}

//リスポーン
// 初期化
void ObjectBreak::BehaviorRespawnInitialize() 
{
	//リスポーンタイマーの初期化
	//描画フラグの初期化
}

// 更新
void ObjectBreak::BehaviorRespawnUpdate() 
{
	//描画フラグをfalseにして消し、リスポーンタイマーを起動


	//タイマーが終わったら待機シーンにしall初期化
	behaviorRepuest_ = Behavior::kStandby;
	Behavior::kStandby;

}
	