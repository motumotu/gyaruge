//-----------------------------------------------------------
// ImageData.cpp
// 画像データ
// 制作日 2015.04.11
// 制作者 motumotu
//-----------------------------------------------------------
#include "ImageData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
ImageData::ImageData()
{
    init();
    loadImage();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
ImageData::~ImageData()
{

}

//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void ImageData::init()
{

}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void ImageData::loadImage()
{
    // 背景
    handl_back[1] = LoadGraph("image/back/back_1.png");
    handl_back[2] = LoadGraph("image/back/back_2.png");
    // キャラ
    handl_chara[1] = LoadGraph("image/chara/chara_1.png");
    handl_chara[2] = LoadGraph("image/chara/chara_2.png");
    handl_chara[3] = LoadGraph("image/chara/chara_3.png");
    handl_chara[4] = LoadGraph("image/chara/chara_4.png");
    handl_chara[5] = LoadGraph("image/chara/chara_5.png");
}

//-----------------------------------------------------------
// 画像取得
//-----------------------------------------------------------
int ImageData::getBack(int n) { return handl_back[n]; }
int ImageData::getChara(int n) { return handl_chara[n]; }