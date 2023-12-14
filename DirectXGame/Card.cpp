#include "Card.h"
#include "ImGuiManager.h"

void Card::Initialize()
{
	Decknumber = 0;
	/// 乱数の初期化(シード値の設定)
	srand((unsigned int)time(nullptr));
	Decknumber = {static_cast<float>(rand() % 3 + 1)};
}

void Card::Update() {

	
	ImGui::Begin("Decknumber");
	ImGui::Text("%f\n", Decknumber);
	ImGui::End();

}

void Card::Draw() {}

