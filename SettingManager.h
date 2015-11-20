//-----------------------------------------------------------
// SettingManager.h
// 設定画面の管理
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class SettingManager {
public:
private:
    GameData *game_data;       // ゲームデータ
    GameState *game_state;     // ゲームの状態
    InputState *input_state;   // 入力状態
public:
    SettingManager(GameData*, GameState*); // コンストラクタ
    ~SettingManager();           // デストラクタ
    void init();               // 初期化
    void update();             // 更新
};