//-----------------------------------------------------------
// TitleState.cpp
// タイトル画面の状態
// 制作日 2015.03.15
// 制作者 motumotu
//-----------------------------------------------------------
#include "TitleState.h"

//-----------------------------------------------------------
// 定数
//-----------------------------------------------------------
const int TitleState::TITLE_STATE_CIRCLE_LOGO = 0;   // サークルロゴ表示
const int TitleState::TITLE_STATE_TITLE = 1;         // タイトル表示

const int TitleState::TITLE_MOUSEON_NONE = 0;        // 何の上でもない
const int TitleState::TITLE_MOUSEON_NEWGAME = 1;     // はじめから
const int TitleState::TITLE_MOUSEON_CONTINUE = 2;    // つづきから
const int TitleState::TITLE_MOUSEON_SETTING = 3;     // システム設定
const int TitleState::TITLE_MOUSEON_SITE = 4;        // 公式サイト
const int TitleState::TITLE_MOUSEON_END = 5;         // 終了


//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
TitleState::TitleState(GameData* _game_data)
{
    game_data = _game_data;
    title_data = game_data->getTitleData();
    init();     // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
TitleState::~TitleState()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void TitleState::init()
{
    cnt_frame = 0;
    now_state = TITLE_STATE_CIRCLE_LOGO;
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void TitleState::update()
{
    cnt_frame++;
    if (cnt_frame == 220) {
        now_state = TITLE_STATE_TITLE;
    }
}

//-----------------------------------------------------------
// マウス座標更新
//-----------------------------------------------------------
void TitleState::updateMousePos(int x, int y)
{
    mouse_pos_x = x;
    mouse_pos_y = y;
}

//-----------------------------------------------------------
// マウス座標更新
//-----------------------------------------------------------
bool TitleState::isPosButtonNewgame(int x, int y) {
    int bx = title_data->getPosButtonNewgameX();
    int by = title_data->getPosButtonNewgameY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}
bool TitleState::isPosButtonContinue(int x, int y) {
    int bx = title_data->getPosButtonContinueX();
    int by = title_data->getPosButtonContinueY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}
bool TitleState::isPosButtonSetting(int x, int y) {
    int bx = title_data->getPosButtonSettingX();
    int by = title_data->getPosButtonSettingY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}
bool TitleState::isPosButtonSite(int x, int y) {
    int bx = title_data->getPosButtonSiteX();
    int by = title_data->getPosButtonSiteY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}
bool TitleState::isPosButtonEnd(int x, int y) {
    int bx = title_data->getPosButtonEndX();
    int by = title_data->getPosButtonEndY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}

//===========================================================
// getter
//===========================================================
int TitleState::getNowMouseOnObj() {
    if (isPosButtonNewgame(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_NEWGAME;
    if (isPosButtonContinue(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_CONTINUE;
    if (isPosButtonSetting(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_SETTING;
    if (isPosButtonSite(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_SITE;
    if (isPosButtonEnd(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_END;
    return TITLE_MOUSEON_NONE;
}
int TitleState::getNowState() { return now_state; }
int TitleState::getAlpha() {
    // サークルロゴ表示
    if (cnt_frame < 150) {
        return min(255, cnt_frame * 5);
    }
    // サークルロゴ消去
    else if (cnt_frame >= 150 && cnt_frame < 220) {
        return max(0, 1005 - cnt_frame * 5);
    }
    // タイトル画面
    else {
        return 255;
    }
}
int TitleState::getCntFrame() { return cnt_frame; }