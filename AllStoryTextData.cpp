//-----------------------------------------------------------
// AllStoryTextData.cpp
// 全ストーリーテキストデータ
// 制作日 2015.03.24
// 制作者 motumotu
//-----------------------------------------------------------
#include "AllStoryTextData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
AllStoryTextData::AllStoryTextData()
{
    // 初期処理
    for (int i = 0; i < 1000; i++) {
        story_text_data[i] = NULL;
    }
    // データ読み込み
    loadData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
AllStoryTextData::~AllStoryTextData()
{
    for (int i = 0; i < 1000; i++) {
        if (story_text_data[i] != NULL) {
            delete(story_text_data[i]);
            story_text_data[i] = NULL;
        }
    }
}

//-----------------------------------------------------------
// データ読み込み
//-----------------------------------------------------------
void AllStoryTextData::loadData()
{
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;
    int fp = FileRead_open("dat/story_text.dat");
    // ファイル読み込み失敗
    if (fp == 0) {
        puts("story_text.datファイル読み込み失敗");
        return;
    }
    // ファイル読み込み処理
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        ss >> s;
        //---- 番号
        if (s == "#NUM") {
            ss >> s;
            num = atoi(s.c_str());
            story_text_data[num] = new StoryTextData();
            story_text_data[num]->setNum(num);
        }
        //---- 名前
        else if (s == "#NAME") {
            ss >> s;
            story_text_data[num]->setName(s);
        }
        //---- テキスト1
        else if (s == "#TEXT1") {
            ss >> s;
            story_text_data[num]->setText1(s);
        }
        //---- テキスト2
        else if (s == "#TEXT2") {
            ss >> s;
            story_text_data[num]->setText2(s);
        }
        //---- テキスト3
        else if (s == "#TEXT3") {
            ss >> s;
            story_text_data[num]->setText3(s);
        }
        //---- 次
        else if (s == "#NEXT") {
            ss >> s;
            story_text_data[num]->setnextNum(atoi(s.c_str()));
        }
        //---- キャラ
        else if (s == "#CHARA") {
            // キャラ数
            int n = story_text_data[num]->getCharaNum() + 1;
            story_text_data[num]->setCharaNum(n);
            // キャラ位置
            ss >> s;
            story_text_data[num]->setCharaPos(n, atoi(s.c_str()));
            // キャラ画像
            ss >> s;
            story_text_data[num]->setCharaImage(n, atoi(s.c_str()));
        }
        //---- 背景
        else if (s == "#BACK") {
            ss >> s;
            story_text_data[num]->setBack(atoi(s.c_str()));
        }
        //---- フェードの種類
        else if (s == "#FADE") {
            ss >> s;
            story_text_data[num]->setFade(atoi(s.c_str()));
        }
    }

    FileRead_close(fp);
}

//-----------------------------------------------------------
// 前のキャラと同じか
//-----------------------------------------------------------
bool AllStoryTextData::isPreAllCharaEqual(int n)
{
    if (n <= 1) return false;
    if (story_text_data[n]->getCharaNum() != story_text_data[n - 1]->getCharaNum())return false;
    for (int i = 1; i <= story_text_data[n]->getCharaNum(); i++) {
        if (story_text_data[n]->getCharaImage(i) != story_text_data[n - 1]->getCharaImage(i)) return false;
        if (story_text_data[n]->getCharaPos(i) != story_text_data[n - 1]->getCharaPos(i)) return false;
    }

    return true;
}

//-----------------------------------------------------------
// 前のキャラと同じか
//-----------------------------------------------------------
bool AllStoryTextData::isPreCharaEqual(int n, int image, int pos)
{
    if (n == 0) return false;
    for (int i = 1; i <= story_text_data[n - 1]->getCharaNum(); i++) {
        if (story_text_data[n - 1]->getCharaImage(i) == image &&
            story_text_data[n - 1]->getCharaPos(i) == pos) return true;
    }
    return false;
}

//-----------------------------------------------------------
// 前のキャラと同じか
//-----------------------------------------------------------
bool AllStoryTextData::isNowCharaEqual(int n, int image, int pos)
{
    for (int i = 1; i <= story_text_data[n]->getCharaNum(); i++) {
        if (story_text_data[n]->getCharaImage(i) == image &&
            story_text_data[n]->getCharaPos(i) == pos) return true;
    }
    return false;
}

//-----------------------------------------------------------
// データ取得
//-----------------------------------------------------------
StoryTextData *AllStoryTextData::getStoryTextData(int n) {
    return story_text_data[n];
}