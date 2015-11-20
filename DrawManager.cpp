//-----------------------------------------------------------
// DrawManager.cpp
// �`�搧��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "DrawManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DrawManager::DrawManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    draw_title = new DrawTitle(data, state);
    draw_story = new DrawStory(data, state);
    draw_setting = new DrawSetting(data, state);
    draw_saveload = new DrawSaveLoad(data, state);
    color_black = GetColor(0, 0, 0);
    init();      // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DrawManager::~DrawManager()
{
    delete(draw_saveload);
    delete(draw_setting);
    delete(draw_story);
    delete(draw_title);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void DrawManager::init()
{
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void DrawManager::update()
{

}

//-----------------------------------------------------------
// �`��
//-----------------------------------------------------------
void DrawManager::draw()
{
    int scene = game_state->getSceneState()->getNowScene();

    //---- �^�C�g�����
    if (scene == SceneState::SCENE_TITLE) {
        draw_title->draw();
    }
    //---- �X�g�[���[���
    else if (scene == SceneState::SCENE_STORY) {
        draw_story->draw();
    }
    //---- �ݒ���
    else if (scene == SceneState::SCENE_SETT) {
        draw_setting->draw();
    }
    //---- �Z�[�u���
    else if (scene == SceneState::SCENE_SAVE) {
        draw_saveload->draw();
    }
    //---- ���[�h���
    else if (scene == SceneState::SCENE_LOAD) {
        draw_saveload->draw();
    }

    //---- �t�F�[�h�C����
    if (game_state->getSceneState()->getIsFadeInNow()) {
        int val = game_state->getSceneState()->getFadeVal();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, val);
        DrawBox(0, 0, SystemData::getWindowWidth(), SystemData::getWindowHeight(),
            color_black, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    //---- �t�F�[�h�A�E�g��
    if (game_state->getSceneState()->getIsFadeOutNow()) {
        int val = game_state->getSceneState()->getFadeVal();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, val);
        DrawBox(0, 0, SystemData::getWindowWidth(), SystemData::getWindowHeight(),
            color_black, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    // ����ʕ`��
    ScreenFlip();
}

//===========================================================
// getter
//===========================================================

