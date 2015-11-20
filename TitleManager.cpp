//-----------------------------------------------------------
// TitleManager.cpp
// �^�C�g����ʂ̐���
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#include "TitleManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
TitleManager::TitleManager(GameData* _game_data, GameState *_game_state)
{
    game_data = _game_data;
    game_state = _game_state;
    input_state = game_state->getInputState();
    title_state = game_state->getSceneState()->getTitleState();
    init();     // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
TitleManager::~TitleManager()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void TitleManager::init()
{

}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void TitleManager::update()
{
    // �}�E�X���W�X�V
    title_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        if (title_state->getNowState() == TitleState::TITLE_STATE_TITLE) {
            int obj = title_state->getNowMouseOnObj();
            //---- �u�͂��߂���v�{�^��
            if (obj == TitleState::TITLE_MOUSEON_NEWGAME) {
                clickFirst();
            }
            //---- �u�Â�����v�{�^��
            else if (obj == TitleState::TITLE_MOUSEON_CONTINUE) {
                clickContinue();
            }
            //---- �u�ݒ�{�^���v
            else if (obj == TitleState::TITLE_MOUSEON_SETTING) {
                clickSetting();
            }
            //---- �u�����T�C�g�v�{�^��
            else if (obj == TitleState::TITLE_MOUSEON_SITE) {
                clickSite();
            }
            //---- �u�I���v�{�^��
            else if (obj == TitleState::TITLE_MOUSEON_END) {
                clickEnd();
            }
        }
    }
}

//-----------------------------------------------------------
// �u�͂��߂���v�{�^���N���b�N
//-----------------------------------------------------------
void TitleManager::clickFirst()
{
    game_state->getSceneState()->getStoryState()->setNowTextNum(1);
    game_state->getSceneState()->changeScene(SceneState::SCENE_STORY);
}

//-----------------------------------------------------------
// �u�Â�����v�{�^���N���b�N
//-----------------------------------------------------------
void TitleManager::clickContinue()
{
    game_state->getSceneState()->changeScene(SceneState::SCENE_LOAD);
}
//-----------------------------------------------------------
// �u�V�X�e���ݒ�v�{�^���N���b�N
//-----------------------------------------------------------
void TitleManager::clickSetting()
{
    game_state->getSceneState()->changeScene(SceneState::SCENE_SETT);
}

//-----------------------------------------------------------
// �u�����T�C�g�v�{�^���N���b�N
//-----------------------------------------------------------
void TitleManager::clickSite()
{
    ShellExecute(
        NULL,
        TEXT("open"),
        TEXT("http://yahoo.co.jp"),
        NULL,
        TEXT(""),
        SW_SHOW);
}

//-----------------------------------------------------------
// �u�Q�[���I���v�{�^���N���b�N
//-----------------------------------------------------------
void TitleManager::clickEnd()
{
    game_state->gameEnd();
}

//===========================================================
// getter
//===========================================================