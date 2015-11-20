//-----------------------------------------------------------
// SaveLoadState.cpp
// セーブロード画面の状態
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#include "SaveLoadState.h"

//-----------------------------------------------------------
// 定数
//-----------------------------------------------------------
const int SaveLoadState::SAVELOAD_OBJ_NONE = 0;
const int SaveLoadState::SAVELOAD_OBJ_BUTTON_NUM = 1;
const int SaveLoadState::SAVELOAD_OBJ_BUTTON_BACK = 2;
const int SaveLoadState::SAVELOAD_OBJ_BUTTON_CLOSE = 3;
const int SaveLoadState::SAVELOAD_OBJ_BASE = 4;
const int SaveLoadState::SAVELOAD_OBJ_DIALOG_YES = 5;
const int SaveLoadState::SAVELOAD_OBJ_DIALOG_NO = 6;

const int SaveLoadState::SAVELOAD_MODE_SAVE = 0;
const int SaveLoadState::SAVELOAD_MODE_LOAD = 1;

const int SaveLoadState::SAVELOAD_DIALOG_OVERWRITE = 1;  // 上書きしますか
const int SaveLoadState::SAVELOAD_DIALOG_DELETE = 2;     // 削除しますか
const int SaveLoadState::SAVELOAD_DIALOG_LOAD = 3;       // ロードしますか

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SaveLoadState::SaveLoadState(GameData* data)
{
    game_data = data;
    saveload_data = data->getSaveLoadData();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SaveLoadState::~SaveLoadState()
{

}
//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void SaveLoadState::init()
{
    mouse_x = 0;
    mouse_y = 0;
    select_num = 0;
    mode = SAVELOAD_MODE_SAVE;
    is_dialog = false;
    select_base_num = 0;
    dialog_mode = 0;
}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void SaveLoadState::update()
{

}

//-----------------------------------------------------------
// マウス位置更新
//-----------------------------------------------------------
void SaveLoadState::updateMousePos(int x, int y)
{
    mouse_x = x;
    mouse_y = y;
}

//-----------------------------------------------------------
// 画像取得
//-----------------------------------------------------------
int SaveLoadState::getImageButtonNum(int n) {
    if (n == select_num) return SaveLoadData::SAVELOAD_BUTTON_NUM + n;
    if (isDialog()) return n;
    if (isPosButtonNum(n)) return SaveLoadData::SAVELOAD_BUTTON_NUM + n;
    return n;
}
int SaveLoadState::getImageButtonBack() {
    if (isDialog()) return 0;
    if (isPosButtonBack()) return 1;
    return 0;
}
int SaveLoadState::getImageButtonClose(int n) {
    if (isDialog()) return 0;
    if (isPosButtonClose(n)) return 1;
    return 0;
}
int SaveLoadState::getImageBase(int n) {
    if (isDialog() && n == select_base_num) return 1;
    if (isDialog()) return 0;
    if (isPosBase(n)) return 1;
    return 0;
}

//-----------------------------------------------------------
// 番号取得
//-----------------------------------------------------------
int SaveLoadState::getMousePosButtonNum()
{
    for (int i = 0; i < SaveLoadData::SAVELOAD_BUTTON_NUM; i++) {
        if (isPosButtonNum(i)) return i + 1;
    }
    return 0;
}
int SaveLoadState::getMousePosBaseNum()
{
    for (int i = 0; i < SaveLoadData::SAVELOAD_BASE_NUM; i++) {
        int n = i + SaveLoadData::SAVELOAD_BASE_NUM * select_num;
        if (isPosBase(i)) return n + 1;
    }
    return 0;
}

//-----------------------------------------------------------
// 物体取得
//-----------------------------------------------------------
int SaveLoadState::getMousePosObject()
{
    // バックログ中
    if (isDialog()) {
        if (isPosDialogYes()) return SAVELOAD_OBJ_DIALOG_YES;
        if (isPosDialogNo()) return SAVELOAD_OBJ_DIALOG_NO;
    }
    // 通常時
    else {
        for (int i = 0; i < SaveLoadData::SAVELOAD_BUTTON_NUM; i++) {
            if (isPosButtonNum(i)) return SAVELOAD_OBJ_BUTTON_NUM;
        }
        if (isPosButtonBack()) return SAVELOAD_OBJ_BUTTON_BACK;
        for (int i = 0; i < SaveLoadData::SAVELOAD_BASE_NUM; i++) {
            int p = i + 1 + select_num * SaveLoadData::SAVELOAD_BASE_NUM;
            if (game_data->getSaveData()->getIsData(p) == 0) continue;
            if (isPosButtonClose(i)) return SAVELOAD_OBJ_BUTTON_CLOSE;
        }
        for (int i = 0; i < SaveLoadData::SAVELOAD_BASE_NUM; i++) {
            if (isPosBase(i)) return SAVELOAD_OBJ_BASE;
        }
    }
    return SAVELOAD_OBJ_NONE;
}
bool SaveLoadState::isPosButtonNum(int n) {
    int px = saveload_data->getPosButtonNumX(n);
    int py = saveload_data->getPosButtonNumY(n);
    int sx = SaveLoadData::SAVELOAD_BUTTON_NUM_SIZE_X;
    int sy = SaveLoadData::SAVELOAD_BUTTON_NUM_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool SaveLoadState::isPosButtonBack() {
    int px = SaveLoadData::SAVELOAD_BUTTON_BACK_POS_X;
    int py = SaveLoadData::SAVELOAD_BUTTON_BACK_POS_Y;
    int sx = SaveLoadData::SAVELOAD_BUTTON_BACK_SIZE_X;
    int sy = SaveLoadData::SAVELOAD_BUTTON_BACK_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool SaveLoadState::isPosButtonClose(int n) {
    int px = SaveLoadData::SAVELOAD_BUTTON_CLOSE_POS_X;
    px += saveload_data->getPosBaseX(n % SaveLoadData::SAVELOAD_BASE_NUM);
    int py = SaveLoadData::SAVELOAD_BUTTON_CLOSE_POS_Y;
    py += saveload_data->getPosBaseY(n % SaveLoadData::SAVELOAD_BASE_NUM);
    int sx = SaveLoadData::SAVELOAD_BUTTON_CLOSE_SIZE_X;
    int sy = SaveLoadData::SAVELOAD_BUTTON_CLOSE_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool SaveLoadState::isPosBase(int n) {
    int px = saveload_data->getPosBaseX(n % SaveLoadData::SAVELOAD_BASE_NUM);
    int py = saveload_data->getPosBaseY(n % SaveLoadData::SAVELOAD_BASE_NUM);
    int sx = SaveLoadData::SAVELOAD_BASE_SIZE_X;
    int sy = SaveLoadData::SAVELOAD_BASE_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool SaveLoadState::isPosDialogYes() {
    int px = SaveLoadData::SAVELOAD_DIALOG_POS_X + SaveLoadData::SAVELOAD_DIALOG_YES_POS_X;
    int py = SaveLoadData::SAVELOAD_DIALOG_POS_Y + SaveLoadData::SAVELOAD_DIALOG_YES_POS_Y;
    int sx = SaveLoadData::SAVELOAD_DIALOG_BUTTON_SIZE_X;
    int sy = SaveLoadData::SAVELOAD_DIALOG_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool SaveLoadState::isPosDialogNo() {
    int px = SaveLoadData::SAVELOAD_DIALOG_POS_X + SaveLoadData::SAVELOAD_DIALOG_NO_POS_X;
    int py = SaveLoadData::SAVELOAD_DIALOG_POS_Y + SaveLoadData::SAVELOAD_DIALOG_NO_POS_Y;
    int sx = SaveLoadData::SAVELOAD_DIALOG_BUTTON_SIZE_X;
    int sy = SaveLoadData::SAVELOAD_DIALOG_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}

//-----------------------------------------------------------
// ダイアログ
//-----------------------------------------------------------
void SaveLoadState::deleteDialog() {
    is_dialog = false;
}
void SaveLoadState::createDialog(int mode) {
    is_dialog = true;
    dialog_mode = mode;
}
char *SaveLoadState::getDialogText() {
    if (dialog_mode == SAVELOAD_DIALOG_OVERWRITE) return "データを上書きしますか？";
    if (dialog_mode == SAVELOAD_DIALOG_DELETE) return "データを削除しますか？";
    if (dialog_mode == SAVELOAD_DIALOG_LOAD) return "データをロードしますか？";
    return "";
}

//-----------------------------------------------------------
// setter
//-----------------------------------------------------------
void SaveLoadState::setSelectNum(int n) { select_num = n; }
void SaveLoadState::setMode(int m) { mode = m; }
void SaveLoadState::setSelectBaseNum(int n) { select_base_num = n; }

//-----------------------------------------------------------
// gettter
//-----------------------------------------------------------
int SaveLoadState::getMode() { return mode; }
int SaveLoadState::getSelectNum() { return select_num; }
bool SaveLoadState::isDialog() { return is_dialog; }
int SaveLoadState::getSelectBaseNum() { return select_base_num; }
int SaveLoadState::getDialogMode() { return dialog_mode; }