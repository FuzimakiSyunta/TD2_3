//�^�C�g���V�[��
#pragma once

//�w�b�_�[�t�@�C���̃C���N���[�h
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Scene.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "TextureManager.h"

class TitleScene 
{
public:

	TitleScene();	//�R���X�g���N�^
	~TitleScene();	//�f�X�g���N�^

	void Initialize();	//������
	void Update();		//�X�V
	void Draw();		//�`��

	void SceneReset();	//�V�[���̃��Z�b�g

	bool isSceneEnd = false;
	bool IsSceneEnd() { return isSceneEnd; }

	//���̃V�[�����Q�[���v���C�V�[����
	SceneType NextScene() { return SceneType::kGame; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	
	Input* input_ = nullptr;

	Sprite* spriteTitle_ = nullptr;
};
