//-----------------------------------------------------------
// GameData.h
// ゲームのデータ部
// 制作日 2015.04.05
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "SystemData.h"
#include "TitleData.h"
#include "AllStoryTextData.h"
#include "StoryData.h"
#include "SaveLoadData.h"
#include "SaveData.h"
#include "ImageData.h"

class GameData {
private:
    TitleData *title_data;             // タイトル画面のデータ
    AllStoryTextData *all_story_text_data; // テキストデータ
    StoryData *story_data;             // ストーリー画面のデータ
    SaveLoadData *saveload_data;       // セーブロード画面のデータ
    SaveData *save_data;               // セーブデータ
    ImageData *image_data;             // 画像データ

public:
    GameData();                        // コンストラクタ
    ~GameData();                       // デストラクタ
    TitleData *getTitleData();         // タイトルデータ取得
    AllStoryTextData *getAllStoryTextData(); // テキストデータ取得
    StoryData *getStoryData();         // ストーリーデータ取得
    SaveLoadData *getSaveLoadData();   // セーブロード画面のデータ取得
    SaveData *getSaveData();           // セーブデータ取得
    ImageData *getImageData();         // 画像データ取得
};