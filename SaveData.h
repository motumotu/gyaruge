//-----------------------------------------------------------
// SaveData.h
// システムデータ
// 制作日 2015.04.11
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <sstream>

class SaveData {
private:
    int is_data[100];             // セーブデータがあるか
    int story_pos[100];           // 場所
    std::string save_day[100];    // プレイ日
    std::string save_time[100];   // セーブ時間
public:
    SaveData();               // コンストラクタ
    ~SaveData();              // デストラクタ
    void init();              // 初期処理
    void loadSaveData();      // セーブデータ読み込み
    void deleteSaveData(int); // セーブデータ削除
    void saveSaveData(int, int);  // セーブデータ保存処理

    // getter
    int getIsData(int);           // セーブデータがあるか
    int getStoryPos(int);         // どこか
    std::string getSaveDay(int);  // セーブ日
    std::string getSaveTime(int); // セーブ時間
};