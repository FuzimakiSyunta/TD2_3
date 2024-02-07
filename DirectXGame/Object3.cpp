#include "Object3.h"
void Object3::Initialize(Model* modelJar, Model* modelShelf) {
	modelJar_ = modelJar;
	modelShelf_ = modelShelf;
	// 初期化
	worldTransformJar_.Initialize();
	worldTransformShelf_.Initialize();

	worldTransformJar_.scale_ = {4.0f, 4.0f, 4.0f};
	worldTransformJar_.rotation_ = {0.0f, 0.0f, 0.0f};
	worldTransformJar_.translation_ = {30.0f, -10.0f, 30.0f};

	worldTransformShelf_.scale_ = {4.0f, 4.0f, 4.0f};
	worldTransformShelf_.rotation_ = {0.0f, 2.0f, 0.0f};
	worldTransformShelf_.translation_ = {30.0f, -10.0f, 30.0f};
}

void Object3::Update() {
	worldTransformJar_.UpdateMatrix();
	worldTransformShelf_.UpdateMatrix();
};

void Object3::Draw(ViewProjection& viewProjection) {
	modelJar_->Draw(worldTransformJar_, viewProjection);
	modelShelf_->Draw(worldTransformShelf_, viewProjection);
}
