//-----------------------------------------------------------
// ImageData.h
// �摜�f�[�^
// ����� 2015.04.11
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class ImageData {
public:
private:
    int handl_back[10];       // �w�i
    int handl_chara[10];      // �L�����摜
public:
    ImageData();             // �R���X�g���N�^
    ~ImageData();            // �f�X�g���N�^
    void init();             // ������
    void loadImage();        // �摜�ǂݍ���

    // getter
    int getBack(int);        // �w�i�擾
    int getChara(int);       // �L�����擾
};