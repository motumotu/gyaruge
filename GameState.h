//-----------------------------------------------------------
// GameState.h
// �Q�[���̏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "InputState.h"
#include "SceneState.h"

class GameState {
private:
    GameData *game_data;
    InputState *input_state;   // ���͏��
    // �V�X�e�����
    // �v���C���[���
    SceneState *scene_state;   // �e�V�[�����

    bool is_game_end;          // �Q�[���I����
public:
    GameState(GameData*);      // �R���X�g���N�^
    ~GameState();              // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void gameEnd();            // �Q�[���I��
    SceneState *getSceneState(); // �V�[����Ԏ擾
    InputState *getInputState();
    bool isGameEnd();
};