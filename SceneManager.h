//-----------------------------------------------------------
// SceneManager.h
// 各シーンの制御
// 制作日 2015.04.05
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "TitleManager.h"
#include "StoryManager.h"
#include "SettingManager.h"
#include "SaveLoadManager.h"

class SceneManager {
public:

private:
    TitleManager *title_manager;    // タイトル画面
    StoryManager *story_manager;    // ストーリ画面
    SettingManager *setting_manager;// 設定画面
    SaveLoadManager *saveload_manager; // セーブロード画面
    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // シーンマネージャー

public:
    SceneManager(GameData*, GameState*); // コンストラクタ
    ~SceneManager();             // デストラクタ
    void init();                 // 初期化
    void update();               // 更新
};