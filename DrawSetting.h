//-----------------------------------------------------------
// DrawSetting.h
// 設定画面の描画
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawSetting {
public:
private:
    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // シーンマネージャー
    int back;
public:
    DrawSetting(GameData*, GameState*); // コンストラクタ
    ~DrawSetting();             // デストラクタ
    void init();                 // 初期化
    void loadImage();           // 画像読み込み
    void draw();                // 描画
};