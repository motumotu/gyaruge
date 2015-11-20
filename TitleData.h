//-----------------------------------------------------------
// TitleData.h
// タイトル画面のデータ
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "SystemData.h"

class TitleData {
public:
    static const int TITLE_BUTTON_SIZE_X;   // ボタンの大きさx
    static const int TITLE_BUTTON_SIZE_Y;   // ボタンの大きさy
    static const int TITLE_CIRCLE_LOGO_SIZE_X; // サークルロゴの位置x
    static const int TITLE_CIRCLE_LOGO_SIZE_Y; // サークルロゴの位置y
    static const int TITLE_GAME_LOGO_SIZE_X;   // ゲームロゴの位置x
    static const int TITLE_GAME_LOGO_SIZE_Y;   // ゲームロゴの位置y
private:
public:
    TitleData();                  // コンストラクタ
    ~TitleData();                 // デストラクタ
    int getPosButtonNewgameX();   // ボタン「はじめから」の位置x
    int getPosButtonNewgameY();   // ボタン「はじめから」の位置y
    int getPosButtonContinueX();  // ボタン「つづきから」の位置x
    int getPosButtonContinueY();  // ボタン「つづきから」の位置y
    int getPosButtonSettingX();   // ボタン「システム設定」の位置x
    int getPosButtonSettingY();   // ボタン「システム設定」の位置y
    int getPosButtonSiteX();      // ボタン「公式サイト」の位置x
    int getPosButtonSiteY();      // ボタン「公式サイト」の位置y
    int getPosButtonEndX();       // ボタン「ゲーム終了」の位置x
    int getPosButtonEndY();       // ボタン「ゲーム終了」の位置y
    int getPosCirCleLogoX();      // サークルロゴの位置x
    int getPosCirCleLogoY();      // サークルロゴの位置y
    int getPosTitleLogoX();       // タイトルロゴの位置x
    int getPosTitleLogoY();       // タイトルロゴの位置y
};