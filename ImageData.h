//-----------------------------------------------------------
// ImageData.h
// 画像データ
// 制作日 2015.04.11
// 制作者 motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class ImageData {
public:
private:
    int handl_back[10];       // 背景
    int handl_chara[10];      // キャラ画像
public:
    ImageData();             // コンストラクタ
    ~ImageData();            // デストラクタ
    void init();             // 初期化
    void loadImage();        // 画像読み込み

    // getter
    int getBack(int);        // 背景取得
    int getChara(int);       // キャラ取得
};