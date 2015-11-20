//-----------------------------------------------------------
// StoryState.h
// ストーリーの状態
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class StoryState {
public:
    static const int STORY_OBJ_NONE;
    static const int STORY_OBJ_BUTTON_AUTO;
    static const int STORY_OBJ_BUTTON_SKIP;
    static const int STORY_OBJ_BUTTON_LOG;
    static const int STORY_OBJ_BUTTON_CONF;
    static const int STORY_OBJ_BUTTON_SAVE;
    static const int STORY_OBJ_BUTTON_LOAD;
    static const int STORY_OBJ_BUTTON_CLOSE;
    static const int STORY_OBJ_BACKLOG_BUTTON_UP;
    static const int STORY_OBJ_BACKLOG_BUTTON_DOWN;
    static const int STORY_OBJ_BACKLOG_BUTTON_EXIT;
    static const int STORY_OBJ_BACKLOG_AREA;

    static const int STORY_DRAW_CHARA; // キャラ描画中
    static const int STORY_DRAW_TEXT;  // テキスト描画中

private:
    GameData *game_data;       // ゲームデータ
    StoryData *story_data;
    int mouse_x;               // マウス位置x
    int mouse_y;               // マウス位置y
    int now_text_num;          // 現在のテキスト番号
    int cnt_frame;             // 経過フレーム
    int now_text_len;          // 現在のテキスト長
    bool is_draw_end;          // 描画終了してるか
    bool is_close;             // ウィンドウが閉じているか
    bool is_auto;              // オート中か
    bool is_skip;              // スキップ中か
    bool is_backlog;           // バックログ中か
    int what_draw;             // 何を描画中か
    int chara_alpha;           // キャラ透明度
    int backlog_pos;           // バックログの位置
    int scrollbar_pos;         // スクロールバーの位置
    bool is_fade;              // フェード中か
public:
    StoryState(GameData*);     // コンストラクタ
    ~StoryState();             // デストラクタ
    void init();               // 初期化
    void update();             // 更新
    void updateMousePos(int, int); // マウス座標
    int isJapaneseCharacter(unsigned char); // 日本語か
    void fullText();           // 全文表示
    void changeNextText();     // 次のテキスト
    void changeText(int);      // テキスト変更

    // バックログ
    bool downBacklogPos();      // バックログを下に
    void upBacklogPos();        // バックログを上に
    void openBacklog();         // バックログオープン
    void closeBacklog();        // バックログを閉じる
    int getScrollbarPos();      // スクロールバーの位置取得
    int getScrollbarSize();     // スクロールバーサイズ取得
    void scrollBarAdjustment(); // スクロールバー調整
    void scrollBarAdjustmentMousePos(); // 

    // クリック処理
    void clickNone();          // 何もないところをクリック
    void clickButtonClose();   // 閉じるボタンのクリック
    void clickButtonAuto();    // オートボタンのクリック
    void clickButtonSkip();    // スキップボタンのクリック
    void clickButtonLog();     // ログボタンのクリック
    void clickButtonConf();    // コンフィグボタンのクリック
    void clickButtonSave();    // セーブボタンのクリック
    void clickButtonLoad();    // ロードボタンのクリック
    void clickBacklogButtonUp(); // バックログの上ボタンクリック
    void clickBacklogButtonDown(); // バックログの下ボタンクリック
    void clickBacklogButtonExit(); // バックログのEXITボタンクリック


    // テキストデータ取得
    std::string getNowName();  // 現在の名前取得
    std::string getNowEName(); // 英語名取得
    std::string getNowText1(); // 現在のテキスト１取得
    std::string getNowText2(); // 現在のテキスト２取得
    std::string getNowText3(); // 現在のテキスト３取得
    int getNowCharaNum();      // 現在のキャラ数取得
    int getNowCharaPos(int);   // キャラ位置取得
    int getNowCharaImage(int); // キャラ画像取得
    int getNowBack();          // 現在の背景取得
    // 前
    int getPreCharaNum();      // 前のキャラ数取得
    int getPreCharaPos(int);   // 前のキャラ位置取得
    int getPreCharaImage(int); // 前のキャラ画像取得

    // オブジェクト
    int getMousePosObject(); // マウスの座標の物体取得
    bool isPosButtonAuto();  // オートボタン
    bool isPosButtonSkip();  // スキップボタン
    bool isPosButtonLog();   // ログボタン
    bool isPosButtonConf();  // コンフィグボタン
    bool isPosButtonSave();  // セーブボタン
    bool isPosButtonLoad();  // ロードボタン
    bool isPosButtonClose(); // 閉じるボタン
    bool isPosBacklogButtonUp();   // 上に
    bool isPosBacklogButtonDown(); // 下に
    bool isPosBacklogButtonExit(); // EXITボタン
    bool isPosBacklogArea();       // バックログエリア

    // 画像データ取得
    int getImageButtonAuto();
    int getImageButtonSkip();
    int getImageButtonLog();
    int getImageButtonConf();
    int getImageButtonSave();
    int getImageButtonLoad();
    int getImageButtonClose();
    int getImageBacklogButtonUp();   // バックログ上ボタンの画像取得
    int getImageBacklogButtonDown(); // バックログ下ボタンの画像取得
    int getImageBacklogButtonExit(); // EXITボタンの画像取得

    //---- setter
    void setNowTextNum(int);   // 現在のテキスト番号セット
    void setIsClose(bool);     // 閉じているかを設定
    void setIsAuto(bool);      // オート中かセット
    void setIsSkip(bool);      // スキップ中かセット
    void setIsBacklog(bool);   // バックログ中かセット
    void setIsFade(bool);

    //---- getter
    int getNowTextNum();       // 現在のテキスト番号取得
    StoryTextData *getNowStoryTextData(); // 現在のテキストデータ取得
    StoryTextData *getPreStoryTextData(); // 前のテキストデータ取得
    std::string StoryState::getNowText(); // 現在のテキスト取得
    bool isDrawEnd();          // 描画終了してるか
    bool isClose();            // 閉じているか
    bool isAuto();             // オート中か
    bool isSkip();             // スキップ中か
    bool isBacklog();          // バックログ中か取得
    int getWhatDraw();
    int getCharaAlpha();
    int getBacklogPos();       // バックログの位置
    bool isFade();
};