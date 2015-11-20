//-----------------------------------------------------------
// DrawStory.h
// ストーリー画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawStory {
public:
private:
    GameData *game_data;      // ゲームデータ
    GameState *game_state;    // ゲーム状態
    StoryState *story_state;  // ストーリー状態
    StoryData *story_data;    // ストーリーデータ
    int handl_window;         // ウィンドウ描画
    int handl_button_auto[3]; // オートボタン
    int handl_button_skip[3]; // スキップボタン
    int handl_button_log[3];  // ログボタン
    int handl_button_conf[3]; // コンフィグボタン
    int handl_button_save[3]; // セーブボタン
    int handl_button_load[3]; // ロードボタン
    int handl_button_close[2];// 閉じるボタン
    int handl_backlog_back;   // バックログ背景
    int handl_scroll_bar;     // スクロールバーエリア
    int handl_backlog_up[2];   // バックログ上に
    int handl_backlog_down[2]; // バックログ下に
    int handl_backlog_exit[2]; // exitボタン

    int color_white;          // 色_黒
    int color_gray;           // 色_グレー
    int color_scrollbar;      // 色_スクロールバー
    int font;
    int font_name;            // 名前のフォント
    int font_name_e;          // 名前イングリッシュ
public:
    DrawStory(GameData*, GameState*); // コンストラクタ
    ~DrawStory();             // デストラクタ
    void init();              // 初期化
    void update();            // 更新
    void draw();              // 描画
    void loadImage();         // 画像読み込み
    void drawWindow();        // テキストウィンドウ描画
    void drawNowText();       // 現在のテキスト描画
    void drawChara(int);      // キャラ描画
    void drawBacklog();       // バックログ描画
    void drawTextPos(int, int, int); // テキスト場所
    void drawScrollbar();     // スクロールバー描画
};