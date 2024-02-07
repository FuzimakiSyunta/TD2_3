#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include<math.h>
#include<Input.h>
class Object1 {
public:

	void Initialize(Model* modelObject1);

	void Update();

	void Draw(ViewProjection& viewProjection);

private:
	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* modelObject1_;
};
