//-----------------------------------------------------------
// StoryManager.h
// �X�g�[���[�̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
class StoryManager {
public:
private:
    GameData *game_data;
    GameState *game_state;
    InputState *input_state;
    StoryState *story_state;
    int wheel;
    int click_bar_area;      // 
public:
    StoryManager(GameData*, GameState*);     // �R���X�g���N�^
    ~StoryManager();            // �f�X�g���N�^
    void init();                // ������
    void update();              // �X�V
    void leftClickFirst();      // ���N���b�N���ꂽ�u��
    void leftClickNow();        // ���N���b�N����Ă���� 
    void leftClickEnd();        // ���N���b�N�I����
    void mouseWheel();          // �}�E�X�z�C�[��
};