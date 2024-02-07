#include "Card.h"
#include "ImGuiManager.h"

// やること初期化の引数でカードのテクスチャハンドルをカードｵﾍﾟﾚｰﾀｰから受け取る
// 受け取ったテクスチャハンドルでspriteをクリエイトする

void Card::Initialize(CardType cardType, uint32_t textureHandle) { 
	cardType_ = cardType;
	textureHandle_ = textureHandle;
	
	// spriteの実体生成
	sprite_ = Sprite::Create(textureHandle_, {0,0});
}

void Card::Update() {
}

void Card::Draw() { 
	sprite_->Draw();
}

void Card::SetSpritePos(Vector2 pos) { 
	sprite_->SetPosition(pos); 
}

