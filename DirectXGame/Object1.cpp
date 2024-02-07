#include "Object1.h"
void Object1::Initialize(Model* modelObject1) {
	modelObject1_ = modelObject1;
	// 初期化
	worldTransform_.Initialize();
	worldTransform_.scale_ = {2.0f, 2.0f, 2.0f};
	worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};
	worldTransform_.translation_ = {0.0f, 12.0f, 0.0f};
}

void Object1::Update() { worldTransform_.UpdateMatrix(); };

void Object1::Draw(ViewProjection& viewProjection) {
	modelObject1_->Draw(worldTransform_, viewProjection);
}
