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
	if (cardnumber_ > 0&&cardnumber_ <= 10) {
		isATCcard_ = true;
		isDEFcard_ = false;
		isHealcard_ = false;
		isBufcard_ = false;
	}
	///防御カード
	if (cardnumber_ >= 11 && cardnumber_ <= 15) {
		isATCcard_ = false;
		isDEFcard_ = true;
		isHealcard_ = false;
		isBufcard_ = false;
	}
	/// 回復カード
	if (cardnumber_ >= 16 && cardnumber_ <= 18) {
		isATCcard_ = false;
		isDEFcard_ = false;
		isHealcard_ = true;
		isBufcard_ = false;
	}
	/// バフカード
	if (cardnumber_ >= 19 && cardnumber_ <= 20) {
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
	
	cardSprite_[0]->Draw();
	
	
	cardSprite_[1]->Draw();
	
	
	cardSprite_[2]->Draw();
	
	
	cardSprite_[3]->Draw();
	
}

