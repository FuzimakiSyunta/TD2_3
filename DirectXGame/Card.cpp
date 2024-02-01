#include "Card.h"
#include "ImGuiManager.h"

void Card::Initialize()
{
	/// カードのテクスチャ読み込み
	cardTexture_ = TextureManager::Load("HEALcardBase.png");
	cardSprite_ = Sprite::Create(cardTexture_, {0, 0});
}

void Card::DeckUpdate() {
	/*///攻撃カード
	if (decknumber_ > 0&&decknumber_ <= 10) {
		isATCcard_ = true;
		isDEFcard_ = false;
		isHealcard_ = false;
		isBufcard_ = false;
	}
	///防御カード
	if (decknumber_ >= 11 && decknumber_ <= 15) {
		isATCcard_ = false;
		isDEFcard_ = true;
		isHealcard_ = false;
		isBufcard_ = false;
	}
	/// 回復カード
	if (decknumber_ >= 16 && decknumber_ <= 18) {
		isATCcard_ = false;
		isDEFcard_ = false;
		isHealcard_ = true;
		isBufcard_ = false;
	}
	/// バフカード
	if (decknumber_ >= 19 && decknumber_ <= 20) {
		isATCcard_ = false;
		isDEFcard_ = false;
		isHealcard_ = false;
		isBufcard_ = true;
	}*/
	///// IMGUI
	//ImGui::Begin("Decknumber");
	//ImGui::Text("%d\n", decknumber_);
	///*ImGui::Text("%d\n", isATCcard_);
	//ImGui::Text("%d\n", isDEFcard_);
	//ImGui::Text("%d\n", isHealcard_);
	//ImGui::Text("%d\n", isBufcard_);*/
	//ImGui::End();
}

void Card::HandCardUpdate() {

}

void Card::Draw() { 
	cardSprite_->Draw();
}

