//-----------------------------------------------------------
// SettingManager.h
// �ݒ��ʂ̊Ǘ�
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class SettingManager {
public:
private:
    GameData *game_data;       // �Q�[���f�[�^
    GameState *game_state;     // �Q�[���̏��
    InputState *input_state;   // ���͏��
public:
    SettingManager(GameData*, GameState*); // �R���X�g���N�^
    ~SettingManager();           // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
};