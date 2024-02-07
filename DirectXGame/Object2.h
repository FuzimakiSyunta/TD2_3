#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <Input.h>
#include <math.h>
class Object2 {
public:
	void Initialize(Model* modelDynamite,Model*modelBox);

	void Update();

	void Draw(ViewProjection& viewProjection);

private:
	// ワールド変換データ
	WorldTransform worldTransformDynamite_;
	WorldTransform worldTransformBox_;
	// モデル
	Model* modelDynamite_;
	Model* modelBox_;

	// オブジェクト2のHP
	int object2HP = 5;
};
