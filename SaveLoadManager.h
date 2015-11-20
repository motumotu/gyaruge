//-----------------------------------------------------------
// SaveLoadManager.h
// �Z�[�u�E���[�h��ʂ̊Ǘ�
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class SaveLoadManager {
public:
private:
    GameData *game_data;       // �Q�[���f�[�^
    GameState *game_state;     // �Q�[���̏��
    InputState *input_state;   // ���͏��
    SaveLoadState *saveload_state;

public:
    SaveLoadManager(GameData*, GameState*); // �R���X�g���N�^
    ~SaveLoadManager();        // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void leftClickFirst();     // ���N���b�N���ꂽ�u��

    
};