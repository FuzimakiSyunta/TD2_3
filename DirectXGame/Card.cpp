#include "Card.h"
#include "ImGuiManager.h"

void Card::Initialize()
{
	/// カードのテクスチャ読み込み
	cardTexture_[0] = TextureManager::Load("HEALcardBase.png");
	cardTexture_[1] = TextureManager::Load("ATKcardBase.png");
	cardTexture_[2] = TextureManager::Load("BUFFcardBase.png");
	cardTexture_[3] = TextureManager::Load("DEFcardBase.png");
	cardSprite_[0] = Sprite::Create(cardTexture_[0], {120, 180});
	cardSprite_[1] = Sprite::Create(cardTexture_[1], {260, 180});
	cardSprite_[2] = Sprite::Create(cardTexture_[2], {400, 180});
	cardSprite_[3] = Sprite::Create(cardTexture_[3], {540, 180});
}

void Card::DeckUpdate() {
	///攻撃カード
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
	}
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
	if (isHealcard_==true) {
		cardSprite_[0]->Draw();
	}
	if (isATCcard_==true) {
		cardSprite_[1]->Draw();
	}
	if (isBufcard_==true) {
		cardSprite_[2]->Draw();
	}
	if (isDEFcard_==true) {
		cardSprite_[3]->Draw();
	}
}

