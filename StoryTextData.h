//-----------------------------------------------------------
// StoryTextData.h
// ストーリーテキストデータ
// 制作日 2015.03.24
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include <string>

class StoryTextData {
public:
private:
    int num;              // 番号
    int next_num;         // 次の番号
    std::string name;     // 名前
    std::string text1;    // テキスト１
    std::string text2;    // テキスト２
    std::string text3;    // テキスト３
    int chara_num;        // キャラ数
    int chara_pos[10];    // キャラ位置
    int chara_image[10];  // キャラ画像
    int back;             // 背景画像
    int fade;             // フェード
public:
    StoryTextData();    // コンストラクタ
    ~StoryTextData();   // デストラクタ
    void init();        // 初期処理

    //---- setter
    void setNum(int);
    void setnextNum(int);
    void setName(std::string);
    void setText1(std::string);
    void setText2(std::string);
    void setText3(std::string);
    void setCharaNum(int);
    void setCharaPos(int, int);
    void setCharaImage(int, int);
    void setBack(int);
    void setFade(int);

    //---- getter
    int getNum();
    int getNextNum();
    std::string getName();         // 名前
    std::string getText1();        // テキスト１取得
    std::string getText2();        // テキスト２取得
    std::string getText3();        // テキスト３取得
    std::string getEName();        // 英語名取得
    int getCharaNum();             // キャラ数取得
    int getCharaPos(int);          // キャラの場所取得
    int getCharaImage(int);        // キャラ画像取得
    int getBack();                 // 背景画像取得
    int getFade();                 // フェードか
};