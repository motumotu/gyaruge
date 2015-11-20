//-----------------------------------------------------------
// StoryTextData.h
// �X�g�[���[�e�L�X�g�f�[�^
// ����� 2015.03.24
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <string>

class StoryTextData {
public:
private:
    int num;              // �ԍ�
    int next_num;         // ���̔ԍ�
    std::string name;     // ���O
    std::string text1;    // �e�L�X�g�P
    std::string text2;    // �e�L�X�g�Q
    std::string text3;    // �e�L�X�g�R
    int chara_num;        // �L������
    int chara_pos[10];    // �L�����ʒu
    int chara_image[10];  // �L�����摜
    int back;             // �w�i�摜
    int fade;             // �t�F�[�h
public:
    StoryTextData();    // �R���X�g���N�^
    ~StoryTextData();   // �f�X�g���N�^
    void init();        // ��������

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
    std::string getName();         // ���O
    std::string getText1();        // �e�L�X�g�P�擾
    std::string getText2();        // �e�L�X�g�Q�擾
    std::string getText3();        // �e�L�X�g�R�擾
    std::string getEName();        // �p�ꖼ�擾
    int getCharaNum();             // �L�������擾
    int getCharaPos(int);          // �L�����̏ꏊ�擾
    int getCharaImage(int);        // �L�����摜�擾
    int getBack();                 // �w�i�摜�擾
    int getFade();                 // �t�F�[�h��
};