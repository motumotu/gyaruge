//-----------------------------------------------------------
// main.cpp
// main
// 制作日 2015.04.05
// 制作者 motumotu
//-----------------------------------------------------------

//-----------------------------------------------------------
// ヘッダーインクルード
//-----------------------------------------------------------
#include "DxLib.h"
#include "Game.h"

//-----------------------------------------------------------
// WinMain
//-----------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //---- システムデータ読み込み
    SystemData::loadSystemData();
    SetGraphMode(                             // ウィンドウ設定
        SystemData::getWindowWidth(),         // 画面幅
        SystemData::getWindowHeight(),        // 画面高さ
        SystemData::getWindowColor());        // 使用カラー
    //---- 設定
    ChangeWindowMode(TRUE);
    SetWindowText("ギャルゲ");                // タイトル名
    if (DxLib_Init() == -1) { return -1; }    // DXライブラリ初期化
    if (SetDrawScreen(DX_SCREEN_BACK) != 0) { return -1; }  // 描画先を裏画面に

    //----- デバッグ用コンソール
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);

    //---- ゲーム処理
    Game *game = new Game();
    game->init();
    game->mainLoop();
    game->end();
    delete(game);

    //---- 終了処理
    DxLib_End();
    return 0;
}
