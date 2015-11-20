//-----------------------------------------------------------
// SaveLoadData.h
// セーブ・ロード画面のデータ
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once

class SaveLoadData {
public:
    static const int SAVELOAD_BASE_SIZE_X;
    static const int SAVELOAD_BASE_SIZE_Y;
    static const int SAVELOAD_BASE_POS_X;
    static const int SAVELOAD_BASE_POS_Y;
    static const int SAVELOAD_BUTTON_NUM_SIZE_X;
    static const int SAVELOAD_BUTTON_NUM_SIZE_Y;
    static const int SAVELOAD_BUTTON_NUM_POS_X;
    static const int SAVELOAD_BUTTON_NUM_POS_Y;
    // 総数
    static const int SAVELOAD_BUTTON_NUM;
    static const int SAVELOAD_BASE_NUM;
    // 戻るボタン
    static const int SAVELOAD_BUTTON_BACK_SIZE_X;
    static const int SAVELOAD_BUTTON_BACK_SIZE_Y;
    static const int SAVELOAD_BUTTON_BACK_POS_X;
    static const int SAVELOAD_BUTTON_BACK_POS_Y;
    // 閉じるボタン
    static const int SAVELOAD_BUTTON_CLOSE_SIZE_X;
    static const int SAVELOAD_BUTTON_CLOSE_SIZE_Y;
    static const int SAVELOAD_BUTTON_CLOSE_POS_X;
    static const int SAVELOAD_BUTTON_CLOSE_POS_Y;
    // ダイアログ
    static const int SAVELOAD_DIALOG_SIZE_X;
    static const int SAVELOAD_DIALOG_SIZE_Y;
    static const int SAVELOAD_DIALOG_POS_X;
    static const int SAVELOAD_DIALOG_POS_Y;
    // ダイアログのボタン
    static const int SAVELOAD_DIALOG_BUTTON_SIZE_X;
    static const int SAVELOAD_DIALOG_BUTTON_SIZE_Y;
    // ダイアログのYES
    static const int SAVELOAD_DIALOG_YES_POS_X;
    static const int SAVELOAD_DIALOG_YES_POS_Y;
    // ダイアログのNO
    static const int SAVELOAD_DIALOG_NO_POS_X;
    static const int SAVELOAD_DIALOG_NO_POS_Y;
private:
public:
    SaveLoadData();    // コンストラクタ
    ~SaveLoadData();   // デストラクタ
    int getPosBaseX(int);
    int getPosBaseY(int);
    int getPosButtonNumX(int);
    int getPosButtonNumY(int);
};