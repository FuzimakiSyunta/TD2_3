#include "Enemy.h"
void Enemy::Initialize(Model* modelHead) {

	modelEnemyHead_ = modelHead;

	//初期化
	worldTransformHead_.Initialize();

	//頭の座標
	worldTransformHead_.scale_ = {2.0f, 2.0f, 2.0f};
	worldTransformHead_.rotation_ = {0.0f, 0.0f, 0.0f};
	worldTransformHead_.translation_ = {0.0f, 0.0f, 0.0f};
}

void Enemy::Update() { 
	worldTransformHead_.UpdateMatrix(); 
}

void Enemy::Draw(ViewProjection& viewProjection) {
	modelEnemyHead_->Draw(worldTransformHead_,viewProjection);
}
