#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <Input.h>
#include <math.h>
    class Object3 {
public:
	void Initialize(Model* modelJar, Model* modelShelf);

	void Update();

	void Draw(ViewProjection& viewProjection);

private:
	// ワールド変換データ
	WorldTransform worldTransformJar_;
	WorldTransform worldTransformShelf_;
	// モデル
	Model* modelJar_;
	Model* modelShelf_;

	// オブジェクト3のHP
	int object3HP = 5;
    };
