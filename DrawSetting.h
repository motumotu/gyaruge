//-----------------------------------------------------------
// DrawSetting.h
// �ݒ��ʂ̕`��
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawSetting {
public:
private:
    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �V�[���}�l�[�W���[
    int back;
public:
    DrawSetting(GameData*, GameState*); // �R���X�g���N�^
    ~DrawSetting();             // �f�X�g���N�^
    void init();                 // ������
    void loadImage();           // �摜�ǂݍ���
    void draw();                // �`��
};