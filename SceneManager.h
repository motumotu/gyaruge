//-----------------------------------------------------------
// SceneManager.h
// �e�V�[���̐���
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "TitleManager.h"
#include "StoryManager.h"
#include "SettingManager.h"
#include "SaveLoadManager.h"

class SceneManager {
public:

private:
    TitleManager *title_manager;    // �^�C�g�����
    StoryManager *story_manager;    // �X�g�[�����
    SettingManager *setting_manager;// �ݒ���
    SaveLoadManager *saveload_manager; // �Z�[�u���[�h���
    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �V�[���}�l�[�W���[

public:
    SceneManager(GameData*, GameState*); // �R���X�g���N�^
    ~SceneManager();             // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V
};