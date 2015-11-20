//-----------------------------------------------------------
// StoryTextData.cpp
// 全ストーリーテキストデータ
// 制作日 2015.03.24
// 制作者 motumotu
//-----------------------------------------------------------
#include "StoryTextData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
StoryTextData::StoryTextData()
{
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
StoryTextData::~StoryTextData()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void StoryTextData::init()
{
    num = 0;              // 番号
    next_num = 0;         // 次の番号
    name = "";            // 名前
    text1 = "";           // テキスト１
    text2 = "";           // テキスト２
    text3 = "";           // テキスト３
    chara_num = 0;
    for (int i = 0; i < 5; i++) {
        chara_pos[i] = 0;
        chara_image[i] = 0;
    }
    back = 0;
    fade = 0;
}

//-----------------------------------------------------------
// setter
//-----------------------------------------------------------
void StoryTextData::setNum(int n) { num = n; }
void StoryTextData::setnextNum(int n) { next_num = n; }
void StoryTextData::setName(std::string n) { name = n; }
void StoryTextData::setText1(std::string n) { text1 = n; }
void StoryTextData::setText2(std::string n) { text2 = n; }
void StoryTextData::setText3(std::string n) { text3 = n; }
void StoryTextData::setCharaNum(int n) { chara_num = n; }
void StoryTextData::setCharaPos(int n, int pos) { chara_pos[n] = pos; }
void StoryTextData::setCharaImage(int n, int image) { chara_image[n] = image; }
void StoryTextData::setBack(int n) { back = n; }
void StoryTextData::setFade(int n) { fade = n; }

//-----------------------------------------------------------
// getter
//-----------------------------------------------------------
int StoryTextData::getNum() { return num; }
int StoryTextData::getNextNum() { return next_num; }
std::string StoryTextData::getName() { return name; }
std::string StoryTextData::getText1() { return text1; }
std::string StoryTextData::getText2() { return text2; }
std::string StoryTextData::getText3() { return text3; }
std::string StoryTextData::getEName() {
    if (name == "宮本夕夏") { return "Yuuka Miyamoto"; }
    return "";
}
int StoryTextData::getCharaNum() { return chara_num; }
int StoryTextData::getCharaPos(int n) { return chara_pos[n]; }
int StoryTextData::getCharaImage(int n) { return chara_image[n]; }
int StoryTextData::getBack() { return back; }
int StoryTextData::getFade() { return fade; }