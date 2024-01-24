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
