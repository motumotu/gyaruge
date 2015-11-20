//-----------------------------------------------------------
// SaveLoadManager.cpp
// �ݒ��ʂ̊Ǘ�
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#include "SaveLoadManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SaveLoadManager::SaveLoadManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    saveload_state = state->getSceneState()->getSaveLoadState();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SaveLoadManager::~SaveLoadManager()
{

}
//-----------------------------------------------------------
// ��������
//-----------------------------------------------------------
void SaveLoadManager::init()
{

}

//-----------------------------------------------------------
// �X�V����
//-----------------------------------------------------------
void SaveLoadManager::update()
{
    saveload_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- �N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
}

//-----------------------------------------------------------
// ���N���b�N���ꂽ�u��
//-----------------------------------------------------------
void SaveLoadManager::leftClickFirst()
{
    int obj = saveload_state->getMousePosObject();

    //---- �_�C�A���OYES
    if (obj == SaveLoadState::SAVELOAD_OBJ_DIALOG_YES) {
        int n = saveload_state->getSelectBaseNum() + 1;
        // �f�[�^�폜
        if (saveload_state->getDialogMode() == SaveLoadState::SAVELOAD_DIALOG_DELETE) {
            game_data->getSaveData()->deleteSaveData(n);
        }
        // �㏑���ۑ�
        if (saveload_state->getDialogMode() == SaveLoadState::SAVELOAD_DIALOG_OVERWRITE) {
            int pos = game_state->getSceneState()->getStoryState()->getNowTextNum();
            game_data->getSaveData()->saveSaveData(n, pos);
        }
        // �f�[�^���[�h
        if (saveload_state->getDialogMode() == SaveLoadState::SAVELOAD_DIALOG_LOAD) {
            int text_num = game_data->getSaveData()->getStoryPos(n);
            //game_state->getSceneState()->getStoryState()->setNowTextNum(text_num);
            game_state->getSceneState()->getStoryState()->changeText(text_num);
            game_state->getSceneState()->changeScene(SceneState::SCENE_STORY);
        }
        // 
        saveload_state->deleteDialog();
    }


    //---- �_�C�A���ONO
    if (obj == SaveLoadState::SAVELOAD_OBJ_DIALOG_NO) {
        saveload_state->deleteDialog();
    }


    //---- �f�[�^�I��
    if (obj == SaveLoadState::SAVELOAD_OBJ_BASE) {
        int num = saveload_state->getMousePosBaseNum() - 1;
        saveload_state->setSelectBaseNum(num);
        // �Z�[�u���[�h��
        if (saveload_state->getMode() == SaveLoadState::SAVELOAD_MODE_SAVE) {
            // �Z�[�u�f�[�^������Ƃ�
            if (game_data->getSaveData()->getIsData(num + 1)) {
                puts("�㏑������");
                saveload_state->createDialog(SaveLoadState::SAVELOAD_DIALOG_OVERWRITE);
            }
            // �Z�[�u�f�[�^���Ȃ��Ƃ�
            else {
                puts("�f�[�^�ۑ�����");
                int pos = game_state->getSceneState()->getStoryState()->getNowTextNum();
                game_data->getSaveData()->saveSaveData(num + 1, pos);
            }
        }
        // ���[�h���[�h��
        if (saveload_state->getMode() == SaveLoadState::SAVELOAD_MODE_LOAD) {
            // �Z�[�u�f�[�^������Ƃ�
            if (game_data->getSaveData()->getIsData(num + 1)) {
                puts("�f�[�^�����[�h���܂�");
                saveload_state->createDialog(SaveLoadState::SAVELOAD_DIALOG_LOAD);
            }
        }
    }


    //---- �폜�{�^��
    if (obj == SaveLoadState::SAVELOAD_OBJ_BUTTON_CLOSE) {
        int num = saveload_state->getMousePosBaseNum() - 1;
        saveload_state->setSelectBaseNum(num);
        puts("�폜");
        saveload_state->createDialog(SaveLoadState::SAVELOAD_DIALOG_DELETE);
    }
    //---- �ԍ��擾
    if (obj == SaveLoadState::SAVELOAD_OBJ_BUTTON_NUM) {
        int num = saveload_state->getMousePosButtonNum();
        if (num >= 1) {
            saveload_state->setSelectNum(num - 1);
        }
    }
    //---- �߂�{�^��
    if (obj == SaveLoadState::SAVELOAD_OBJ_BUTTON_BACK) {
        game_state->getSceneState()->changePreScene();
    }
    //---- �����Ȃ��Ƃ���
    if (obj == SaveLoadState::SAVELOAD_OBJ_NONE) {
        
    }
}