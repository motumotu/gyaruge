//-----------------------------------------------------------
// Game.h
// ゲーム中心部
// 制作日 2015.04.05
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameManager.h"
#include "GameState.h"
#include "DxLib.h"
#include <ctime>

class Game {
private:
    GameData *game_data;         // ゲームのデータ
    GameState *game_state;       // ゲームの状態
    GameManager *game_manager;   // ゲームの制御
public:
    Game();                      // コンストラクタ
    ~Game();                     // デストラクタ
    void init();                 // 初期化
    int update();               // 更新
    int mainLoop();             // メインループ
    int end();                  // 終了処理
};