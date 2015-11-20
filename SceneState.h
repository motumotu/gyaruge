//-----------------------------------------------------------
// SceneState.h
// 各シーンの状態
// 制作日 2015.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "TitleState.h"
#include "StoryState.h"
#include "SettingState.h"
#include "SaveLoadState.h"

class SceneState {
public:
    static const int SCENE_TITLE;   // タイトル画面
    static const int SCENE_STORY;   // ストーリー画面
    static const int SCENE_SAVE;    // セーブ画面
    static const int SCENE_LOAD;    // ロード画面
    static const int SCENE_SETT;    // 設定画面

    static const int FADE_FAST;
    static const int FADE_NORMAL;   // 
    static const int FADE_SLOW;     // 遅い

private:
    GameData *game_data;       // ゲームデータ
    TitleState *title_state;   // タイトル画面
    StoryState *story_state;   // ストーリー画面
    SettingState *setting_state; // 設定画面
    SaveLoadState *saveload_state; // セーブロード画面
    int now_scene;             // 現在シーン
    int pre_scene;
    int change_scene;          // 変化後のシーン
    int is_fade_out_now;       // フェードアウト中か
    int is_fade_in_now;        // フェードイン中か
    int fade_val;              // フェード量取得
    int fade_speed;            // フレームの速さ       

public:
    SceneState(GameData*);     // コンストラクタ
    ~SceneState();             // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void changeScene(int);     // シーン変更
    void changePreScene();     // 前シーンに変更
    void change();             // チェンジ

    void setFadeSpeed(int);
    int getNowScene();         // 現在のシーン取得
    int getIsFadeOutNow();     // フェード中か
    int getIsFadeInNow();      // フェード中か
    int getFadeVal();          // フェード量取得
    TitleState *getTitleState(); // タイトル画面
    StoryState *getStoryState(); // ストーリー画面
    SettingState *getSettingState(); // 設定画面
    SaveLoadState *getSaveLoadState(); // セーブロード画面
};