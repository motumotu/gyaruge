//-----------------------------------------------------------
// TitleManager.cpp
// タイトル画面の制御
// 制作日 2015.04.05
// 制作者 motumotu
//-----------------------------------------------------------
#include "TitleManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
TitleManager::TitleManager(GameData* _game_data, GameState *_game_state)
{
    game_data = _game_data;
    game_state = _game_state;
    input_state = game_state->getInputState();
    title_state = game_state->getSceneState()->getTitleState();
    init();     // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
TitleManager::~TitleManager()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void TitleManager::init()
{

}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void TitleManager::update()
{
    // マウス座標更新
    title_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        if (title_state->getNowState() == TitleState::TITLE_STATE_TITLE) {
            int obj = title_state->getNowMouseOnObj();
            //---- 「はじめから」ボタン
            if (obj == TitleState::TITLE_MOUSEON_NEWGAME) {
                clickFirst();
            }
            //---- 「つづきから」ボタン
            else if (obj == TitleState::TITLE_MOUSEON_CONTINUE) {
                clickContinue();
            }
            //---- 「設定ボタン」
            else if (obj == TitleState::TITLE_MOUSEON_SETTING) {
                clickSetting();
            }
            //---- 「公式サイト」ボタン
            else if (obj == TitleState::TITLE_MOUSEON_SITE) {
                clickSite();
            }
            //---- 「終了」ボタン
            else if (obj == TitleState::TITLE_MOUSEON_END) {
                clickEnd();
            }
        }
    }
}

//-----------------------------------------------------------
// 「はじめから」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickFirst()
{
    game_state->getSceneState()->getStoryState()->setNowTextNum(1);
    game_state->getSceneState()->changeScene(SceneState::SCENE_STORY);
}

//-----------------------------------------------------------
// 「つづきから」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickContinue()
{
    game_state->getSceneState()->changeScene(SceneState::SCENE_LOAD);
}
//-----------------------------------------------------------
// 「システム設定」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickSetting()
{
    game_state->getSceneState()->changeScene(SceneState::SCENE_SETT);
}

//-----------------------------------------------------------
// 「公式サイト」ボタンクリック
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
// 「ゲーム終了」ボタンクリック
//-----------------------------------------------------------
void TitleManager::clickEnd()
{
    game_state->gameEnd();
}

//===========================================================
// getter
//===========================================================