//-----------------------------------------------------------
// SceneManager.cpp
// �e�V�[���̐���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "SceneManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SceneManager::SceneManager(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    title_manager = new TitleManager(data, state);
    story_manager = new StoryManager(data, state);
    setting_manager = new SettingManager(data, state);
    saveload_manager = new SaveLoadManager(data, state);
    init();       // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SceneManager::~SceneManager()
{
    delete(saveload_manager);
    delete(setting_manager);
    delete(story_manager);
    delete(title_manager);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void SceneManager::init()
{
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void SceneManager::update()
{
    //---- �t�F�[�h��
    if (game_state->getSceneState()->getIsFadeInNow() ||
        game_state->getSceneState()->getIsFadeOutNow()) {
        return;
    }
    int scene = game_state->getSceneState()->getNowScene();
    //---- �^�C�g�����
    if (scene == SceneState::SCENE_TITLE) {
        title_manager->update();
    }
    //---- �X�g�[���[���
    else if (scene == SceneState::SCENE_STORY) {
        story_manager->update();
    }
    //---- �ݒ���
    else if (scene == SceneState::SCENE_SETT) {
        setting_manager->update();
    }
    //---- �Z�[�u���
    else if (scene == SceneState::SCENE_SAVE) {
        saveload_manager->update();
    }
    //---- ���[�h���
    else if (scene == SceneState::SCENE_LOAD) {
        saveload_manager->update();
    }
}

//===========================================================
// getter
//===========================================================

