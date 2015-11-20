//-----------------------------------------------------------
// SceneState.h
// �e�V�[���̏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "TitleState.h"
#include "StoryState.h"
#include "SettingState.h"
#include "SaveLoadState.h"

class SceneState {
public:
    static const int SCENE_TITLE;   // �^�C�g�����
    static const int SCENE_STORY;   // �X�g�[���[���
    static const int SCENE_SAVE;    // �Z�[�u���
    static const int SCENE_LOAD;    // ���[�h���
    static const int SCENE_SETT;    // �ݒ���

    static const int FADE_FAST;
    static const int FADE_NORMAL;   // 
    static const int FADE_SLOW;     // �x��

private:
    GameData *game_data;       // �Q�[���f�[�^
    TitleState *title_state;   // �^�C�g�����
    StoryState *story_state;   // �X�g�[���[���
    SettingState *setting_state; // �ݒ���
    SaveLoadState *saveload_state; // �Z�[�u���[�h���
    int now_scene;             // ���݃V�[��
    int pre_scene;
    int change_scene;          // �ω���̃V�[��
    int is_fade_out_now;       // �t�F�[�h�A�E�g����
    int is_fade_in_now;        // �t�F�[�h�C������
    int fade_val;              // �t�F�[�h�ʎ擾
    int fade_speed;            // �t���[���̑���       

public:
    SceneState(GameData*);     // �R���X�g���N�^
    ~SceneState();             // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void changeScene(int);     // �V�[���ύX
    void changePreScene();     // �O�V�[���ɕύX
    void change();             // �`�F���W

    void setFadeSpeed(int);
    int getNowScene();         // ���݂̃V�[���擾
    int getIsFadeOutNow();     // �t�F�[�h����
    int getIsFadeInNow();      // �t�F�[�h����
    int getFadeVal();          // �t�F�[�h�ʎ擾
    TitleState *getTitleState(); // �^�C�g�����
    StoryState *getStoryState(); // �X�g�[���[���
    SettingState *getSettingState(); // �ݒ���
    SaveLoadState *getSaveLoadState(); // �Z�[�u���[�h���
};