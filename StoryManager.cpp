//-----------------------------------------------------------
// StoryManager.h
// ストーリーの制御
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "StoryManager.h"

//-----------------------------------------------------------
// コンストラクタ
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
// デストラクタ
//-----------------------------------------------------------
StoryManager::~StoryManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void StoryManager::init()
{
    wheel = 0;
    click_bar_area = 0;
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void StoryManager::update()
{
    //---- マウスホイール
    mouseWheel();

    //---- マウス位置
    story_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- クリック処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
    // 左クリック中
    if (input_state->getClick(MOUSE_INPUT_LEFT) > 1) {
        leftClickNow();
    }
    // 左クリック終了時
    if (input_state->isRereaseClick(MOUSE_INPUT_LEFT)) {
        leftClickEnd();
    }
}

//-----------------------------------------------------------
// 左クリックされた瞬間
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
// 左クリックされている間 
//-----------------------------------------------------------
void StoryManager::leftClickNow()
{
    if (click_bar_area) {
        story_state->scrollBarAdjustmentMousePos();
    }
}
//-----------------------------------------------------------
// 左クリック終了時
//-----------------------------------------------------------
void StoryManager::leftClickEnd()
{
    click_bar_area = 0;
}

//-----------------------------------------------------------
// マウスホイール
//-----------------------------------------------------------
void StoryManager::mouseWheel()
{
    wheel += input_state->getMouseWheel();
    // 下に
    if (wheel < 0) {
        // バックログ中
        if (story_state->isBacklog() == true) {
            if (story_state->downBacklogPos()) {
                story_state->closeBacklog();
            }
        }
        // 通常時
        else {
            story_state->clickNone();
        }
        wheel++;
    }
    // 上
    if (wheel > 0) {
        // バックログ中
        if (story_state->isBacklog() == true) {
            story_state->upBacklogPos();
        }
        // 通常時 バックログ表示
        else {
            story_state->openBacklog();
        }
        wheel--;
    }
}


//===========================================================
// getter
//===========================================================

