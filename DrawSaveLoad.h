//-----------------------------------------------------------
// DrawSaveLoad.h
// セーブ・ロード画面の描画
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawSaveLoad {
public:
private:
    GameData *game_data;            // ゲームデータ
    GameState *game_state;          // シーンマネージャー
    SaveLoadData *saveload_data;
    SaveLoadState *saveload_state;
    int handl_back;
    int handl_base[2];               // 基礎
    int handl_button_num[20];        // セーブデータ番号
    int handl_button_back[2];        // 戻るボタン
    int handl_logo_save;             // ロゴセーブ
    int handl_logo_load;             // ロードロゴ
    int handl_below;                 // サムネ下埋め用
    int handl_nodata;                // データなし
    int handl_button_close[2];       // 閉じるボタン
    int handl_dialog;
    int handl_dialog_yes[2];
    int handl_dialog_no[2];

    int color_font;                  // フォント用の色
    int font_time;                   // セーブ時間のフォント
    int font_dialog;                 // ダイアログ
public:
    DrawSaveLoad(GameData*, GameState*); // コンストラクタ
    ~DrawSaveLoad();             // デストラクタ
    void init();                 // 初期化
    void loadImage();           // 画像読み込み
    void draw();                // 描画
    void drawSaveData();        // セーブデータ描画
    void drawThumbnail(int, int, int); // サムネ描画
    void drawDialog();          // ダイアログ描画
};