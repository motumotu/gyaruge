//-----------------------------------------------------------
// AllStoryTextData.h
// 全ストーリーテキストデータ
// 制作日 2015.03.24
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "StoryTextData.h"
#include <sstream>
#include <string>
#include <iostream>

class AllStoryTextData {
public:
private:
    StoryTextData *story_text_data[1000]; // ストーリーデータ
public:
    AllStoryTextData();    // コンストラクタ
    ~AllStoryTextData();   // デストラクタ
    void loadData();       // データ読み込み
    bool isPreAllCharaEqual(int); // 前のキャラと同じか
    bool isPreCharaEqual(int, int, int); // 前のキャラと同じか
    bool isNowCharaEqual(int, int, int); // 今の画面に同じキャラがいるか
    StoryTextData *getStoryTextData(int); // 取得
};