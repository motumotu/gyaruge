//-----------------------------------------------------------
// DrawManager.cpp
// 描画制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawManager.h"

//-----------------------------------------------------------
// コンストラクタ
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
    init();      // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawManager::~DrawManager()
{
    delete(draw_saveload);
    delete(draw_setting);
    delete(draw_story);
    delete(draw_title);
}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawManager::init()
{
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawManager::update()
{

}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawManager::draw()
{
    int scene = game_state->getSceneState()->getNowScene();

    //---- タイトル画面
    if (scene == SceneState::SCENE_TITLE) {
        draw_title->draw();
    }
    //---- ストーリー画面
    else if (scene == SceneState::SCENE_STORY) {
        draw_story->draw();
    }
    //---- 設定画面
    else if (scene == SceneState::SCENE_SETT) {
        draw_setting->draw();
    }
    //---- セーブ画面
    else if (scene == SceneState::SCENE_SAVE) {
        draw_saveload->draw();
    }
    //---- ロード画面
    else if (scene == SceneState::SCENE_LOAD) {
        draw_saveload->draw();
    }

    //---- フェードイン中
    if (game_state->getSceneState()->getIsFadeInNow()) {
        int val = game_state->getSceneState()->getFadeVal();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, val);
        DrawBox(0, 0, SystemData::getWindowWidth(), SystemData::getWindowHeight(),
            color_black, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    //---- フェードアウト中
    if (game_state->getSceneState()->getIsFadeOutNow()) {
        int val = game_state->getSceneState()->getFadeVal();
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, val);
        DrawBox(0, 0, SystemData::getWindowWidth(), SystemData::getWindowHeight(),
            color_black, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    // 裏画面描画
    ScreenFlip();
}

//===========================================================
// getter
//===========================================================

