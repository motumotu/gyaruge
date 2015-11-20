//-----------------------------------------------------------
// SaveLoadManager.cpp
// 設定画面の管理
// 制作日 2015.04.10
// 制作者 motumotu
//-----------------------------------------------------------
#include "SaveLoadManager.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SaveLoadManager::SaveLoadManager(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    input_state = state->getInputState();
    saveload_state = state->getSceneState()->getSaveLoadState();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SaveLoadManager::~SaveLoadManager()
{

}
//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void SaveLoadManager::init()
{

}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void SaveLoadManager::update()
{
    saveload_state->updateMousePos(
        input_state->getPointX(),
        input_state->getPointY());

    //---- クリック処理
    // 左クリックされた瞬間
    if (input_state->getClick(MOUSE_INPUT_LEFT) == 1) {
        leftClickFirst();
    }
}

//-----------------------------------------------------------
// 左クリックされた瞬間
//-----------------------------------------------------------
void SaveLoadManager::leftClickFirst()
{
    int obj = saveload_state->getMousePosObject();

    //---- ダイアログYES
    if (obj == SaveLoadState::SAVELOAD_OBJ_DIALOG_YES) {
        int n = saveload_state->getSelectBaseNum() + 1;
        // データ削除
        if (saveload_state->getDialogMode() == SaveLoadState::SAVELOAD_DIALOG_DELETE) {
            game_data->getSaveData()->deleteSaveData(n);
        }
        // 上書き保存
        if (saveload_state->getDialogMode() == SaveLoadState::SAVELOAD_DIALOG_OVERWRITE) {
            int pos = game_state->getSceneState()->getStoryState()->getNowTextNum();
            game_data->getSaveData()->saveSaveData(n, pos);
        }
        // データロード
        if (saveload_state->getDialogMode() == SaveLoadState::SAVELOAD_DIALOG_LOAD) {
            int text_num = game_data->getSaveData()->getStoryPos(n);
            //game_state->getSceneState()->getStoryState()->setNowTextNum(text_num);
            game_state->getSceneState()->getStoryState()->changeText(text_num);
            game_state->getSceneState()->changeScene(SceneState::SCENE_STORY);
        }
        // 
        saveload_state->deleteDialog();
    }


    //---- ダイアログNO
    if (obj == SaveLoadState::SAVELOAD_OBJ_DIALOG_NO) {
        saveload_state->deleteDialog();
    }


    //---- データ選択
    if (obj == SaveLoadState::SAVELOAD_OBJ_BASE) {
        int num = saveload_state->getMousePosBaseNum() - 1;
        saveload_state->setSelectBaseNum(num);
        // セーブモード時
        if (saveload_state->getMode() == SaveLoadState::SAVELOAD_MODE_SAVE) {
            // セーブデータがあるとき
            if (game_data->getSaveData()->getIsData(num + 1)) {
                puts("上書き処理");
                saveload_state->createDialog(SaveLoadState::SAVELOAD_DIALOG_OVERWRITE);
            }
            // セーブデータがないとき
            else {
                puts("データ保存処理");
                int pos = game_state->getSceneState()->getStoryState()->getNowTextNum();
                game_data->getSaveData()->saveSaveData(num + 1, pos);
            }
        }
        // ロードモード時
        if (saveload_state->getMode() == SaveLoadState::SAVELOAD_MODE_LOAD) {
            // セーブデータがあるとき
            if (game_data->getSaveData()->getIsData(num + 1)) {
                puts("データをロードします");
                saveload_state->createDialog(SaveLoadState::SAVELOAD_DIALOG_LOAD);
            }
        }
    }


    //---- 削除ボタン
    if (obj == SaveLoadState::SAVELOAD_OBJ_BUTTON_CLOSE) {
        int num = saveload_state->getMousePosBaseNum() - 1;
        saveload_state->setSelectBaseNum(num);
        puts("削除");
        saveload_state->createDialog(SaveLoadState::SAVELOAD_DIALOG_DELETE);
    }
    //---- 番号取得
    if (obj == SaveLoadState::SAVELOAD_OBJ_BUTTON_NUM) {
        int num = saveload_state->getMousePosButtonNum();
        if (num >= 1) {
            saveload_state->setSelectNum(num - 1);
        }
    }
    //---- 戻るボタン
    if (obj == SaveLoadState::SAVELOAD_OBJ_BUTTON_BACK) {
        game_state->getSceneState()->changePreScene();
    }
    //---- 何もないところ
    if (obj == SaveLoadState::SAVELOAD_OBJ_NONE) {
        
    }
}