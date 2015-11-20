//-----------------------------------------------------------
// StoryManager.h
// �X�g�[���[�̐���
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "StoryManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
StoryManager::StoryManager(GameData *data, GameState *state)
{
    game_state = state;
    game_data = data;
    input_state = state->getInputState();
    story_state = state->getSceneState()->getStoryState();
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
StoryManager::~StoryManager()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void StoryManager::init()
{
    wheel = 0;
    click_bar_area = 0;
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void StoryManager::update()
{
    //---- �}�E�X�z�C�[��
    mouseWheel();

    //---- �}�E�X�ʒu
    story_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- �N���b�N����
    // ���N���b�N���ꂽ�u��
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    // ���N���b�N��
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        leftClickNow();
    }
    // ���N���b�N�I����
    if (input_state->isRereaseClick(MOUSE_INPUT_LEFT)) {
        leftClickEnd();
    }
}

//-----------------------------------------------------------
// ���N���b�N���ꂽ�u��
//-----------------------------------------------------------
void StoryManager::leftClickFirst()
{
    int obj = story_state->getMousePosObject();
    if (obj == StoryState::STORY_OBJ_NONE) story_state->clickNone();
    if (obj == StoryState::STORY_OBJ_BUTTON_CLOSE) story_state->clickButtonClose();
    if (obj == StoryState::STORY_OBJ_BUTTON_AUTO) story_state->clickButtonAuto();
    if (obj == StoryState::STORY_OBJ_BUTTON_SKIP) story_state->clickButtonSkip();
    if (obj == StoryState::STORY_OBJ_BUTTON_LOG) story_state->clickButtonLog();
    if (obj == StoryState::STORY_OBJ_BUTTON_CONF) {
        story_state->clickButtonConf();
        game_state->getSceneState()->changeScene(SceneState::SCENE_SETT);
    }
    if (obj == StoryState::STORY_OBJ_BUTTON_SAVE) {
        story_state->clickButtonSave();
        game_state->getSceneState()->changeScene(SceneState::SCENE_SAVE);
    }
    if (obj == StoryState::STORY_OBJ_BUTTON_LOAD) {
        story_state->clickButtonLoad();
        game_state->getSceneState()->changeScene(SceneState::SCENE_LOAD);
    }
    if (obj == StoryState::STORY_OBJ_BACKLOG_BUTTON_UP) {
        story_state->clickBacklogButtonUp();
    }
    if (obj == StoryState::STORY_OBJ_BACKLOG_BUTTON_DOWN) {
        story_state->clickBacklogButtonDown();
    }
    if (obj == StoryState::STORY_OBJ_BACKLOG_BUTTON_EXIT) {
        story_state->clickBacklogButtonExit();
    }
    if (obj == StoryState::STORY_OBJ_BACKLOG_AREA) {
        click_bar_area = 1;
    }
}
//-----------------------------------------------------------
// ���N���b�N����Ă���� 
//-----------------------------------------------------------
void StoryManager::leftClickNow()
{
    if (click_bar_area) {
        story_state->scrollBarAdjustmentMousePos();
    }
}
//-----------------------------------------------------------
// ���N���b�N�I����
//-----------------------------------------------------------
void StoryManager::leftClickEnd()
{
    click_bar_area = 0;
}

//-----------------------------------------------------------
// �}�E�X�z�C�[��
//-----------------------------------------------------------
void StoryManager::mouseWheel()
{
    wheel += input_state->getMouseWheel();
    // ����
    if (wheel < 0) {
        // �o�b�N���O��
        if (story_state->isBacklog() == true) {
            if (story_state->downBacklogPos()) {
                story_state->closeBacklog();
            }
        }
        // �ʏ펞
        else {
            story_state->clickNone();
        }
        wheel++;
    }
    // ��
    if (wheel > 0) {
        // �o�b�N���O��
        if (story_state->isBacklog() == true) {
            story_state->upBacklogPos();
        }
        // �ʏ펞 �o�b�N���O�\��
        else {
            story_state->openBacklog();
        }
        wheel--;
    }
}


//===========================================================
// getter
//===========================================================

