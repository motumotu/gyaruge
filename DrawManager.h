//-----------------------------------------------------------
// DrawManager.h
// 描画制御
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"
#include "DrawTitle.h"
#include "DrawStory.h"
#include "DrawSetting.h"
#include "DrawSaveLoad.h"

class DrawManager {
private:
    //----------
    GameData *game_data;                  // ゲームデータ
    GameState *game_state;                // ゲームの状態
    DrawTitle *draw_title;                // タイトル画面の描画
    DrawStory *draw_story;                // ストーリー画面の描画
    DrawSetting *draw_setting;            // 設定画面の描画
    DrawSaveLoad *draw_saveload;          // セーブロード画面の描画
    int color_black;
public:
    DrawManager(GameData*, GameState*);   // コンストラクタ
    ~DrawManager();                       // デストラクタ
    void init();                          // 初期化
    void update();                        // 更新
    void draw();                          // 描画
};