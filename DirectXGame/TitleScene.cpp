#include "TitleScene.h"

// �R���X�g���N�^
TitleScene::TitleScene() {}

// �f�X�g���N�^
TitleScene::~TitleScene() 
{
	delete spriteTitle_;
}

// ������
void TitleScene::Initialize() 
{
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();

	//�e�N�X�`�����[�h
	uint32_t textureTitle = TextureManager::Load("");

	spriteTitle_ =
	    Sprite::Create(textureTitle, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

}

// �X�V
void TitleScene::Update()
{ 
	if (input_->TriggerKey(DIK_SPACE))
	{
		isSceneEnd = true;
	}
}

// �`��
void TitleScene::Draw()
{
	//�R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region �w�i�X�v���C�g�`��
	//�w�i�X�v���C�g�`��
	Sprite::PreDraw(commandList);
	///


	///
	// �X�v���C�g�`��㏈��(
	Sprite::PostDraw();
	//�[�x�o�b�t�@�N���A
	dxCommon_->ClearDepthBuffer();
#pragma endregion
#pragma region 3D�I�u�W�F�N�g�`��
	// 3D�I�u�W�F�N�g�`��O����
	Model::PreDraw(commandList);

	/// <summary>
	/// ������3D�I�u�W�F�N�g�̕`�揈����ǉ��ł���
	/// </summary>

	// 3D�I�u�W�F�N�g�`��㏈��
	Model::PostDraw();
#pragma endregion

#pragma region �O�i�X�v���C�g�`��
	// �O�i�X�v���C�g�`��O����
	Sprite::PreDraw(commandList);

	/// <summary>
	/// �����ɑO�i�X�v���C�g�̕`�揈����ǉ��ł���
	/// </summary>

	spriteTitle_->Draw();

	// �X�v���C�g�`��㏈��
	Sprite::PostDraw();

#pragma endregion

}

// �V�[���̃��Z�b�g
void TitleScene::SceneReset() 
{ 
	isSceneEnd = false;
}
