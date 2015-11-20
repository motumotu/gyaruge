//-----------------------------------------------------------
// SaveLoadState.h
// セーブロード画面の状態
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class SaveLoadState {
public:
    static const int SAVELOAD_OBJ_NONE;
    static const int SAVELOAD_OBJ_BUTTON_NUM;
    static const int SAVELOAD_OBJ_BUTTON_BACK;
    static const int SAVELOAD_OBJ_BUTTON_CLOSE;
    static const int SAVELOAD_OBJ_BASE;
    static const int SAVELOAD_OBJ_DIALOG_YES;
    static const int SAVELOAD_OBJ_DIALOG_NO;

    static const int SAVELOAD_MODE_SAVE;
    static const int SAVELOAD_MODE_LOAD;

    static const int SAVELOAD_DIALOG_OVERWRITE;  // 上書きしますか
    static const int SAVELOAD_DIALOG_DELETE;     // 削除しますか
    static const int SAVELOAD_DIALOG_LOAD;       // ロードしますか
private:
    GameData *game_data;           // ゲームデータ
    SaveLoadData *saveload_data;   // セーブ画面のデータ
    int mouse_x;                   // マウス位置x
    int mouse_y;                   // マウス位置y
    int select_num;                // 選択中の番号
    int mode;                      // モード
    bool is_dialog;                // ダイアログ中か
    int select_base_num;           // 選択中のベース番号
    int dialog_mode;               // ダイアログモード
public:
    SaveLoadState(GameData*);      // コンストラクタ
    ~SaveLoadState();              // デストラクタ
    void init();                   // 初期化
    void update();                 // 更新
    void updateMousePos(int, int); // マウス位置更新
    int getImageButtonNum(int);    // 番号ボタンの画像取得
    int getImageButtonBack();      // 戻るボタンの画像取得
    int getImageButtonClose(int);  // 閉じるボタンの画像取得
    int getImageBase(int);         // ベースの画像取得
    // 番号取得
    int getMousePosButtonNum();    // 番号取得
    int getMousePosBaseNum();      // ベース番号取得
    // 物体取得
    int getMousePosObject();       // マウス座標の物体取得
    bool isPosButtonNum(int);      // 選択番号
    bool isPosButtonBack();        // 戻るボタン
    bool isPosButtonClose(int);    // 閉じるボタン
    bool isPosBase(int);           // ベース位置か
    bool isPosDialogYes();        
    bool isPosDialogNo();
    // ダイアログ
    void deleteDialog();        // ダイアログ削除
    void createDialog(int);     // ダイアログモード
    char *getDialogText();      // ダイアログテキスト取得

    // セット
    void setSelectNum(int);     // 選択番号設定
    void setMode(int);          // モード設定
    void setSelectBaseNum(int); // 選択ベース番号セット
    // getter
    int getMode();              // モード取得
    int getSelectNum();         // 現在の選択番号取得
    bool isDialog();            // ダイアログ中か
    int getSelectBaseNum();     // 選択ベース番号取得
    int getDialogMode();        // ダイアログモード取得
};