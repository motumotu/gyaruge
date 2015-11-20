//-----------------------------------------------------------
// SceneState.cpp
// �e�V�[���̏��
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#include "SceneState.h"

//-----------------------------------------------------------
// �萔
//-----------------------------------------------------------
const int SceneState::SCENE_TITLE = 0;   // �^�C�g�����
const int SceneState::SCENE_STORY = 1;   // �X�g�[���[���
const int SceneState::SCENE_SAVE = 2;    // �Z�[�u���
const int SceneState::SCENE_LOAD = 3;    // ���[�h���
const int SceneState::SCENE_SETT = 4;    // �ݒ���

const int SceneState::FADE_FAST = 20;
const int SceneState::FADE_NORMAL = 10;
const int SceneState::FADE_SLOW = 5;

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SceneState::SceneState(GameData* _game_data)
{
    game_data = _game_data;
    title_state = new TitleState(game_data);
    story_state = new StoryState(game_data);
    setting_state = new SettingState(game_data);
    saveload_state = new SaveLoadState(game_data);
    init();     // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SceneState::~SceneState()
{
    delete(saveload_state);
    delete(setting_state);
    delete(story_state);
    delete(title_state);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void SceneState::init()
{
    now_scene = SCENE_STORY;
    pre_scene = SCENE_STORY;
    is_fade_out_now = 0;
    is_fade_in_now = 0;
    fade_speed = FADE_FAST;
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void SceneState::update()
{
    //---- �t�F�[�h�C����
    if (is_fade_in_now) {
        fade_val -= fade_speed;
        if (fade_val <= 0) {
            fade_val = 0;
            is_fade_in_now = 0;
            fade_speed = FADE_FAST;
            story_state->setIsFade(false);
        }
        return;
    }
    //---- �t�F�[�h�A�E�g��
    if (is_fade_out_now) {
        fade_val += fade_speed;
        if (fade_val >= 255) {
            change();
        }
        return;
    }
    //---- �^�C�g�����
    if (now_scene == SCENE_TITLE) {
        title_state->update();
    }
    //---- �X�g�[���[���
    else if (now_scene == SCENE_STORY) {
        story_state->update();
        if (story_state->isFade()) {
            changeScene(SCENE_STORY);
            fade_speed = FADE_SLOW;
        }
    }
    //---- �ݒ���
    else if (now_scene == SCENE_SETT) {
        setting_state->update();
    }
    //---- �Z�[�u���
    else if (now_scene == SCENE_SAVE) {
        saveload_state->update();
    }
    //---- ���[�h���
    else if (now_scene == SCENE_LOAD) {
        saveload_state->update();
    }
}

//-----------------------------------------------------------
// �V�[���ύX
//-----------------------------------------------------------
void SceneState::changeScene(int scene)
{
    change_scene = scene;
    is_fade_out_now = 1;
    fade_val = 0;
    if (scene == SCENE_SAVE) {
        saveload_state->setMode(SaveLoadState::SAVELOAD_MODE_SAVE);
    }
    else if (scene == SCENE_LOAD) {
        saveload_state->setMode(SaveLoadState::SAVELOAD_MODE_LOAD);
    }
}

//-----------------------------------------------------------
// �O�V�[���ɖ߂�
//-----------------------------------------------------------
void SceneState::changePreScene() { changeScene(pre_scene); }

//-----------------------------------------------------------
// �`�F���W
//-----------------------------------------------------------
void SceneState::change()
{
    pre_scene = now_scene;
    now_scene = change_scene;
    is_fade_in_now = 1;
    is_fade_out_now = 0;
    fade_val = 255;
    if (story_state->isFade() == true && now_scene == SCENE_STORY) {
        story_state->changeNextText();
    }
}

//===========================================================
// setter
//===========================================================
void SceneState::setFadeSpeed(int n) { fade_speed = n; }

//===========================================================
// getter
//===========================================================
int SceneState::getNowScene() { return now_scene; }
int SceneState::getIsFadeOutNow() { return is_fade_out_now; }
int SceneState::getIsFadeInNow() { return is_fade_in_now; }
int SceneState::getFadeVal() { return fade_val; }
TitleState *SceneState::getTitleState() { return title_state; }
StoryState *SceneState::getStoryState() { return story_state; }
SettingState *SceneState::getSettingState() { return setting_state; }
SaveLoadState *SceneState::getSaveLoadState() { return saveload_state; }