//-----------------------------------------------------------
// TitleData.cpp
// タイトル画面のデータ
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "TitleData.h"

//-----------------------------------------------------------
// 定数
//-----------------------------------------------------------
const int TitleData::TITLE_BUTTON_SIZE_X = 200;   // ボタンの大きさx
const int TitleData::TITLE_BUTTON_SIZE_Y = 40;    // ボタンの大きさy
const int TitleData::TITLE_CIRCLE_LOGO_SIZE_X = 400; // サークルロゴx
const int TitleData::TITLE_CIRCLE_LOGO_SIZE_Y = 300; // サークルロゴy
const int TitleData::TITLE_GAME_LOGO_SIZE_X = 650;   // ゲームロゴx
const int TitleData::TITLE_GAME_LOGO_SIZE_Y = 230;   // ゲームロゴy

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
TitleData::TitleData()
{

}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
TitleData::~TitleData()
{

}

//-----------------------------------------------------------
// ボタン位置取得
//-----------------------------------------------------------
int TitleData::getPosButtonNewgameX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonNewgameY() {
    return SystemData::getWindowHeight() - 240;
}
int TitleData::getPosButtonContinueX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonContinueY() {
    return SystemData::getWindowHeight() - 200;
}
int TitleData::getPosButtonSettingX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonSettingY() {
    return SystemData::getWindowHeight() - 160;
}
int TitleData::getPosButtonSiteX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonSiteY() {
    return SystemData::getWindowHeight() - 120;
}
int TitleData::getPosButtonEndX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonEndY() {
    return SystemData::getWindowHeight() - 80;
}
int TitleData::getPosCirCleLogoX() {
    return SystemData::getWindowWidth() / 2 - TITLE_CIRCLE_LOGO_SIZE_X / 2;
}
int TitleData::getPosCirCleLogoY() {
    return SystemData::getWindowHeight() / 2 - TITLE_CIRCLE_LOGO_SIZE_Y / 2;
}
int TitleData::getPosTitleLogoX() {
    return SystemData::getWindowWidth() / 2 - TITLE_GAME_LOGO_SIZE_X / 2;
}
int TitleData::getPosTitleLogoY() {
    return 100;
}