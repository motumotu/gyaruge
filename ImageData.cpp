//-----------------------------------------------------------
// ImageData.cpp
// �摜�f�[�^
// ����� 2015.04.11
// ����� motumotu
//-----------------------------------------------------------
#include "ImageData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
ImageData::ImageData()
{
    init();
    loadImage();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
ImageData::~ImageData()
{

}

//-----------------------------------------------------------
// ��������
//-----------------------------------------------------------
void ImageData::init()
{

}

//-----------------------------------------------------------
// �X�V����
//-----------------------------------------------------------
void ImageData::loadImage()
{
    // �w�i
    handl_back[1] = LoadGraph("image/back/back_1.png");
    handl_back[2] = LoadGraph("image/back/back_2.png");
    // �L����
    handl_chara[1] = LoadGraph("image/chara/chara_1.png");
    handl_chara[2] = LoadGraph("image/chara/chara_2.png");
    handl_chara[3] = LoadGraph("image/chara/chara_3.png");
    handl_chara[4] = LoadGraph("image/chara/chara_4.png");
    handl_chara[5] = LoadGraph("image/chara/chara_5.png");
}

//-----------------------------------------------------------
// �摜�擾
//-----------------------------------------------------------
int ImageData::getBack(int n) { return handl_back[n]; }
int ImageData::getChara(int n) { return handl_chara[n]; }