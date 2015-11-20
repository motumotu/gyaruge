//-----------------------------------------------------------
// SaveLoadData.cpp
// セーブ・ロード画面のデータ
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#include "SaveLoadData.h"

//-----------------------------------------------------------
// 定数
//-----------------------------------------------------------
const int SaveLoadData::SAVELOAD_BASE_SIZE_X = 450;
const int SaveLoadData::SAVELOAD_BASE_SIZE_Y = 100;
const int SaveLoadData::SAVELOAD_BASE_POS_X = 50;
const int SaveLoadData::SAVELOAD_BASE_POS_Y = 70;
const int SaveLoadData::SAVELOAD_BUTTON_NUM_SIZE_X = 40;
const int SaveLoadData::SAVELOAD_BUTTON_NUM_SIZE_Y = 40;
const int SaveLoadData::SAVELOAD_BUTTON_NUM_POS_X = 490;
const int SaveLoadData::SAVELOAD_BUTTON_NUM_POS_Y = 15;
// 総数
const int SaveLoadData::SAVELOAD_BUTTON_NUM = 9;
const int SaveLoadData::SAVELOAD_BASE_NUM = 10;
// 戻るボタン
const int SaveLoadData::SAVELOAD_BUTTON_BACK_SIZE_X = 68;
const int SaveLoadData::SAVELOAD_BUTTON_BACK_SIZE_Y = 41;
const int SaveLoadData::SAVELOAD_BUTTON_BACK_POS_X = 900;
const int SaveLoadData::SAVELOAD_BUTTON_BACK_POS_Y = 15;
// 閉じるボタン
const int SaveLoadData::SAVELOAD_BUTTON_CLOSE_SIZE_X = 25;
const int SaveLoadData::SAVELOAD_BUTTON_CLOSE_SIZE_Y = 25;
const int SaveLoadData::SAVELOAD_BUTTON_CLOSE_POS_X = 423;
const int SaveLoadData::SAVELOAD_BUTTON_CLOSE_POS_Y = 2;
// ダイアログ
const int SaveLoadData::SAVELOAD_DIALOG_SIZE_X = 370;
const int SaveLoadData::SAVELOAD_DIALOG_SIZE_Y = 150;
const int SaveLoadData::SAVELOAD_DIALOG_POS_X = 327;
const int SaveLoadData::SAVELOAD_DIALOG_POS_Y = 225;
// ダイアログのボタン
const int SaveLoadData::SAVELOAD_DIALOG_BUTTON_SIZE_X = 110;
const int SaveLoadData::SAVELOAD_DIALOG_BUTTON_SIZE_Y = 60;
// ダイアログのYES
const int SaveLoadData::SAVELOAD_DIALOG_YES_POS_X = 50;
const int SaveLoadData::SAVELOAD_DIALOG_YES_POS_Y = 80;
// ダイアログのNO
const int SaveLoadData::SAVELOAD_DIALOG_NO_POS_X = 210;
const int SaveLoadData::SAVELOAD_DIALOG_NO_POS_Y = 80;

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SaveLoadData::SaveLoadData()
{

}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SaveLoadData::~SaveLoadData()
{

}

//-----------------------------------------------------------
// 位置取得
//-----------------------------------------------------------
int SaveLoadData::getPosBaseX(int n) {
    return SAVELOAD_BASE_POS_X + (n % 2) * (SAVELOAD_BASE_SIZE_X + 20);
}
int SaveLoadData::getPosBaseY(int n) {
    return SAVELOAD_BASE_POS_Y + (n / 2) * (SAVELOAD_BASE_SIZE_Y + 5);
}
int SaveLoadData::getPosButtonNumX(int n) {
    int margin = 5;
    return SAVELOAD_BUTTON_NUM_POS_X + (SAVELOAD_BUTTON_NUM_SIZE_X + margin) * n;
}
int SaveLoadData::getPosButtonNumY(int n) {
    return SAVELOAD_BUTTON_NUM_POS_Y;
}