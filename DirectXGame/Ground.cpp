﻿#include "Ground.h"

void Ground::Initialize(Model* model) {
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.scale_ = {8.0f, 8.0f, 8.0f};
	worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};
	worldTransform_.translation_ = {0.0f, -10.0f, 0.0f};

	// 行列の転送
	worldTransform_.TransferMatrix();
}

void Ground::Update() {
	// 行列の更新
	worldTransform_.UpdateMatrix();
}

void Ground::Draw(ViewProjection& viewProjection) { model_->Draw(worldTransform_, viewProjection); }