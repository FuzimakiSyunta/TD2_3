#include "Card.h"
#include "ImGuiManager.h"

void Card::Initialize()
{
	Decknumber = 1;
	/// 乱数の初期化(シード値の設定)
	srand((unsigned int)time(nullptr));
	
}

void Card::Update() {

	Decknumber = {static_cast<float>(rand() % 20 + 1)};

	ImGui::Begin("Decknumber");
	ImGui::Text("%f\n", Decknumber);
	ImGui::End();

}

void Card::Draw() {}

