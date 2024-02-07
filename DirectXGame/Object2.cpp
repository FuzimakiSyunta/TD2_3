#include "Object2.h"
void Object2::Initialize(Model* modelDynamite, Model* modelBox) {
	modelDynamite_ = modelDynamite;
	modelBox_ = modelBox;
	// 初期化
	worldTransformDynamite_.Initialize();
	worldTransformBox_.Initialize();

	worldTransformDynamite_.scale_ = {4.0f, 4.0f, 4.0f};
	worldTransformDynamite_.rotation_ = {0.0f, 0.0f, 0.0f};
	worldTransformDynamite_.translation_ = {-30.0f, -10.0f, 10.0f};

	worldTransformBox_.scale_ = {4.0f, 4.0f, 4.0f};
	worldTransformBox_.rotation_ = {0.0f, 0.0f, 0.0f};
	worldTransformBox_.translation_ = {-30.0f, -10.0f, 10.0f};
}

void Object2::Update() {
	worldTransformDynamite_.UpdateMatrix();
	worldTransformBox_.UpdateMatrix();
};

void Object2::Draw(ViewProjection& viewProjection) {
	modelDynamite_->Draw(worldTransformDynamite_, viewProjection);
	modelBox_->Draw(worldTransformBox_, viewProjection);
}