//-----------------------------------------------------------
// SceneManager.cpp
// 各シーンの制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "SceneManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SceneManager::SceneManager(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    title_manager = new TitleManager(data, state);
    story_manager = new StoryManager(data, state);
    setting_manager = new SettingManager(data, state);
    saveload_manager = new SaveLoadManager(data, state);
    init();       // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SceneManager::~SceneManager()
{
    delete(saveload_manager);
    delete(setting_manager);
    delete(story_manager);
    delete(title_manager);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void SceneManager::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void SceneManager::update()
{
    //---- フェード中
    if (game_state->getSceneState()->getIsFadeInNow() ||
        game_state->getSceneState()->getIsFadeOutNow()) {
        return;
    }
    int scene = game_state->getSceneState()->getNowScene();
    //---- タイトル画面
    if (scene == SceneState::SCENE_TITLE) {
        title_manager->update();
    }
    //---- ストーリー画面
    else if (scene == SceneState::SCENE_STORY) {
        story_manager->update();
    }
    //---- 設定画面
    else if (scene == SceneState::SCENE_SETT) {
        setting_manager->update();
    }
    //---- セーブ画面
    else if (scene == SceneState::SCENE_SAVE) {
        saveload_manager->update();
    }
    //---- ロード画面
    else if (scene == SceneState::SCENE_LOAD) {
        saveload_manager->update();
    }
}

//===========================================================
// getter
//===========================================================

