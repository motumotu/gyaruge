//-----------------------------------------------------------
// SettingState.h
// 設定画面の状態
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class SettingState {
public:
private:
    GameData *game_data;       // ゲームデータ
public:
    SettingState(GameData*);   // コンストラクタ
    ~SettingState();           // デストラクタ
    void init();               // 初期化
    void update();             // 更新
};