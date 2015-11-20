//-----------------------------------------------------------
// StoryData.h
// ストーリー画面のデータ
// 制作日 2015.03.23
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once

class StoryData {
public:
    // ウィンドウ
    static const int TEXT_WINDOW_POS_X;
    static const int TEXT_WINDOW_POS_Y;
    // テキストエリア
    static const int TEXT_AREA_POS_X;
    static const int TEXT_AREA_POS_Y;
    // ボタン
    static const int STORY_BUTTON_SIZE_X;
    static const int STORY_BUTTON_SIZE_Y;
    static const int STORY_BUTTON_POS_X;
    static const int STORY_BUTTON_POS_Y;
    // 閉じるボタン
    static const int STORY_BUTTON_CLOSE_SIZE_X;
    static const int STORY_BUTTON_CLOSE_SIZE_Y;
    static const int STORY_BUTTON_CLOSE_POS_X;
    static const int STORY_BUTTON_CLOSE_POS_Y;
    // スクロールバー
    static const int STORY_SCROLLBAR_AREA_POS_X;
    static const int STORY_SCROLLBAR_AREA_POS_Y;
    static const int STORY_SCROLLBAR_AREA_SIZE_X;
    static const int STORY_SCROLLBAR_AREA_SIZE_Y;
    // スクロールバーボタン
    static const int STORY_SCROLLBAR_BUTTON_SIZE_X;
    static const int STORY_SCROLLBAR_BUTTON_SIZE_Y;
    // スクロールバー上ボタン
    static const int STORY_SCROLLBAR_BUTTON_UP_POS_X;
    static const int STORY_SCROLLBAR_BUTTON_UP_POS_Y;
    // スクロールバー下ボタン
    static const int STORY_SCROLLBAR_BUTTON_DOWN_POS_X;
    static const int STORY_SCROLLBAR_BUTTON_DOWN_POS_Y;
    // EXITログ戻る
    static const int STORY_BACKLOG_BUTTON_EXIT_POS_X;
    static const int STORY_BACKLOG_BUTTON_EXIT_POS_Y;
    static const int STORY_BACKLOG_BUTTON_EXIT_SIZE_X;
    static const int STORY_BACKLOG_BUTTON_EXIT_SIZE_Y;
private:
public:
    StoryData();    // コンストラクタ
    ~StoryData();   // デストラクタ
    int getPosButtonAutoX();  // オートボタンの位置x
    int getPosButtonAutoY();  // オートボタンの位置y
    int getPosButtonSkipX();  // スキップボタンの位置x
    int getPosButtonSkipY();  // スキップボタンの位置y
    int getPosButtonLogX();   // バックログボタンの位置x
    int getPosButtonLogY();   // バックログボタンの位置y
    int getPosButtonConfX();  // コンフィグボタンの位置x
    int getPosButtonConfY();  // コンフィグボタンの位置y
    int getPosButtonSaveX();  // セーブボタンの位置x
    int getPosButtonSaveY();  // セーブボタンの位置y
    int getPosButtonLoadX();  // ロードボタンの位置x
    int getPosButtonLoadY();  // ロードボタンの位置y
    int getPosButtonCloseX(); // 閉じるボタンの位置x
    int getPosButtonCloseY(); // 閉じるボタンの位置y
};