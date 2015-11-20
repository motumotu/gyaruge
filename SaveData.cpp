//-----------------------------------------------------------
// SaveData.h
// システムデータ
// 制作日 2015.04.11
// 制作者 motumotu
//-----------------------------------------------------------
#include "SaveData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
SaveData::SaveData()
{
    init();           // 初期処理
    loadSaveData();   // セーブデータ読み込み
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
SaveData::~SaveData()
{
}

//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void SaveData::init()
{
    for (int i = 0; i < 100; i++) {
        is_data[i] = 0;
        story_pos[i] = 0;
        save_day[i] = "----/--/--";
        save_time[i] = "--:--";
    }
}

//-----------------------------------------------------------
// セーブデータ読み込み処理
//-----------------------------------------------------------
void SaveData::loadSaveData()
{
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;

    // ファイルオープン処理
    int fp = FileRead_open("savedata/savedata.dat");
    if (fp == 0) {
        puts("savedata.datファイル読み込み失敗");
        return;
    }
    // ファイル読み込み処理
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        //---- 番号
        ss >> s;
        num = atoi(s.c_str());
        is_data[num] = 1;
        //---- 場所
        ss >> s;
        story_pos[num] = atoi(s.c_str());
        //---- プレイ時間
        ss >> s;
        save_day[num] = s;
        ss >> s;
        save_time[num] = s;
    }
}

//-----------------------------------------------------------
// セーブデータ削除
//-----------------------------------------------------------
void SaveData::deleteSaveData(int n)
{
    is_data[n] = 0;
    story_pos[n] = 0;
    save_day[n] = "----/--/--";
    save_time[n] = "--:--";
}

//-----------------------------------------------------------
// セーブデータ保存
//-----------------------------------------------------------
void SaveData::saveSaveData(int n, int pos)
{
    printf("%d\n", pos);
    //---- 番号
    is_data[n] = 1;

    //---- 場所
    story_pos[n] = pos;

    //---- 日
    char c[256];
    DATEDATA date;
    GetDateTime(&date);
    std::stringstream ds;
    sprintf_s(c, "%02d", date.Year);
    ds << c << "/";
    sprintf_s(c, "%02d", date.Mon);
    ds << c << "/";
    sprintf_s(c, "%02d", date.Day);
    ds << c;
    save_day[n] = ds.str();

    //---- 時間
    ds.str("");
    sprintf_s(c, "%02d", date.Hour);
    ds << c << ":";
    sprintf_s(c, "%02d", date.Min);
    ds << c;
    save_time[n] = ds.str();

}

//===========================================================
// getter
//===========================================================
int SaveData::getIsData(int n) { return is_data[n]; }
int SaveData::getStoryPos(int n) { return story_pos[n]; }
std::string SaveData::getSaveDay(int n) { return save_day[n]; }
std::string SaveData::getSaveTime(int n) { return save_time[n]; }