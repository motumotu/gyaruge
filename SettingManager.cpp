//-----------------------------------------------------------
// SettingManager.cpp
// �ݒ��ʂ̊Ǘ�
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#include "SettingManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SettingManager::SettingManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SettingManager::~SettingManager()
{

}
//-----------------------------------------------------------
// ��������
//-----------------------------------------------------------
void SettingManager::init()
{

}

//-----------------------------------------------------------
// �X�V����
//-----------------------------------------------------------
void SettingManager::update()
{
    //---- �N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        game_state->getSceneState()->changePreScene();
    }
}