//-----------------------------------------------------------
// SettingState.h
// �ݒ��ʂ̏��
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class SettingState {
public:
private:
    GameData *game_data;       // �Q�[���f�[�^
public:
    SettingState(GameData*);   // �R���X�g���N�^
    ~SettingState();           // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
};