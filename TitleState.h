//-----------------------------------------------------------
// TitleState.h
// タイトル画面の状態
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <algorithm>
#include "GameData.h"
#include "DxLib.h"

class TitleState {
public:
    static const int TITLE_STATE_CIRCLE_LOGO;   // サークルロゴ表示
    static const int TITLE_STATE_TITLE;         // タイトル表示
    static const int TITLE_MOUSEON_NONE;        // 何の上でもない
    static const int TITLE_MOUSEON_NEWGAME;     // はじめから
    static const int TITLE_MOUSEON_CONTINUE;    // つづきから
    static const int TITLE_MOUSEON_SETTING;     // システム設定
    static const int TITLE_MOUSEON_SITE;        // 公式サイト
    static const int TITLE_MOUSEON_END;         // 終了
private:
    GameData *game_data;       // ゲームデータ
    TitleData *title_data;     // タイトル画面のデータ
    int cnt_frame;             // 経過フレーム数
    int now_state;             // 現在の状態
    int mouse_pos_x;           // マウス位置x
    int mouse_pos_y;           // マウス位置y
public:
    TitleState(GameData*);     // コンストラクタ
    ~TitleState();             // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void updateMousePos(int, int); // マウス座標更新

    bool isPosButtonNewgame(int, int);  // その位置が「はじめから」か
    bool isPosButtonContinue(int, int); // その位置が「つづきから」か
    bool isPosButtonSetting(int, int);  // その位置が「システム設定」か
    bool isPosButtonSite(int, int);     // その位置が「公式サイト」か
    bool isPosButtonEnd(int, int);      // その位置が「ゲーム終了」か

    int getNowMouseOnObj();    // 現在マウスが乗っているオブジェクト取得
    int getNowState();         // 状態取得
    int getAlpha();            // 透過度取得
    int getCntFrame();         // 経過フレーム数取得
};