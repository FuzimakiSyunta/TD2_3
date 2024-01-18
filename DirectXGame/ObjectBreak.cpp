#include "ObjectBreak.h"

void ObjectBreak::Initialize(const std::vector<Model*>& models) 
{
	//
	input_ = Input::GetInstance();

	//ワールドトランスフォーム
	worldTransform_.Initialize();
}

void ObjectBreak::Update() 
{ 
	worldTransform_.TransferMatrix();
}

void ObjectBreak::Draw(const ViewProjection& viewProjection) {
	
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
