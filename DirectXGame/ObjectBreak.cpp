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
	
	
}

void ObjectBreak::Draw(const ViewProjection& viewProjection) {
	
}
