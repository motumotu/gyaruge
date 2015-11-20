//-----------------------------------------------------------
// SceneState.cpp
// 各シーンの状態
// 制作日 2015.04.05
// 制作者 motumotu
//-----------------------------------------------------------
#include "SceneState.h"

//-----------------------------------------------------------
// 定数
//-----------------------------------------------------------
const int SceneState::SCENE_TITLE = 0;   // タイトル画面
const int SceneState::SCENE_STORY = 1;   // ストーリー画面
const int SceneState::SCENE_SAVE = 2;    // セーブ画面
const int SceneState::SCENE_LOAD = 3;    // ロード画面
const int SceneState::SCENE_SETT = 4;    // 設定画面

const int SceneState::FADE_FAST = 20;
const int SceneState::FADE_NORMAL = 10;
const int SceneState::FADE_SLOW = 5;

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SceneState::SceneState(GameData* _game_data)
{
    game_data = _game_data;
    title_state = new TitleState(game_data);
    story_state = new StoryState(game_data);
    setting_state = new SettingState(game_data);
    saveload_state = new SaveLoadState(game_data);
    init();     // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SceneState::~SceneState()
{
    delete(saveload_state);
    delete(setting_state);
    delete(story_state);
    delete(title_state);
}

//-----------------------------------------------------------
// 初期化
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
// 更新
//-----------------------------------------------------------
void SceneState::update()
{
    //---- フェードイン中
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
    //---- フェードアウト中
    if (is_fade_out_now) {
        fade_val += fade_speed;
        if (fade_val >= 255) {
            change();
        }
        return;
    }
    //---- タイトル画面
    if (now_scene == SCENE_TITLE) {
        title_state->update();
    }
    //---- ストーリー画面
    else if (now_scene == SCENE_STORY) {
        story_state->update();
        if (story_state->isFade()) {
            changeScene(SCENE_STORY);
            fade_speed = FADE_SLOW;
        }
    }
    //---- 設定画面
    else if (now_scene == SCENE_SETT) {
        setting_state->update();
    }
    //---- セーブ画面
    else if (now_scene == SCENE_SAVE) {
        saveload_state->update();
    }
    //---- ロード画面
    else if (now_scene == SCENE_LOAD) {
        saveload_state->update();
    }
}

//-----------------------------------------------------------
// シーン変更
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
// 前シーンに戻る
//-----------------------------------------------------------
void SceneState::changePreScene() { changeScene(pre_scene); }

//-----------------------------------------------------------
// チェンジ
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