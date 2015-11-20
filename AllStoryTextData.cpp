//-----------------------------------------------------------
// AllStoryTextData.cpp
// �S�X�g�[���[�e�L�X�g�f�[�^
// ����� 2015.03.24
// ����� motumotu
//-----------------------------------------------------------
#include "AllStoryTextData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
AllStoryTextData::AllStoryTextData()
{
    // ��������
    for (int i = 0; i < 1000; i++) {
        story_text_data[i] = NULL;
    }
    // �f�[�^�ǂݍ���
    loadData();
}

//-----------------------------------------------------------
// �f�X�g���N�^
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
// �f�[�^�ǂݍ���
//-----------------------------------------------------------
void AllStoryTextData::loadData()
{
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;
    int fp = FileRead_open("dat/story_text.dat");
    // �t�@�C���ǂݍ��ݎ��s
    if (fp == 0) {
        puts("story_text.dat�t�@�C���ǂݍ��ݎ��s");
        return;
    }
    // �t�@�C���ǂݍ��ݏ���
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        ss >> s;
        //---- �ԍ�
        if (s == "#NUM") {
            ss >> s;
            num = atoi(s.c_str());
            story_text_data[num] = new StoryTextData();
            story_text_data[num]->setNum(num);
        }
        //---- ���O
        else if (s == "#NAME") {
            ss >> s;
            story_text_data[num]->setName(s);
        }
        //---- �e�L�X�g1
        else if (s == "#TEXT1") {
            ss >> s;
            story_text_data[num]->setText1(s);
        }
        //---- �e�L�X�g2
        else if (s == "#TEXT2") {
            ss >> s;
            story_text_data[num]->setText2(s);
        }
        //---- �e�L�X�g3
        else if (s == "#TEXT3") {
            ss >> s;
            story_text_data[num]->setText3(s);
        }
        //---- ��
        else if (s == "#NEXT") {
            ss >> s;
            story_text_data[num]->setnextNum(atoi(s.c_str()));
        }
        //---- �L����
        else if (s == "#CHARA") {
            // �L������
            int n = story_text_data[num]->getCharaNum() + 1;
            story_text_data[num]->setCharaNum(n);
            // �L�����ʒu
            ss >> s;
            story_text_data[num]->setCharaPos(n, atoi(s.c_str()));
            // �L�����摜
            ss >> s;
            story_text_data[num]->setCharaImage(n, atoi(s.c_str()));
        }
        //---- �w�i
        else if (s == "#BACK") {
            ss >> s;
            story_text_data[num]->setBack(atoi(s.c_str()));
        }
        //---- �t�F�[�h�̎��
        else if (s == "#FADE") {
            ss >> s;
            story_text_data[num]->setFade(atoi(s.c_str()));
        }
    }

    FileRead_close(fp);
}

//-----------------------------------------------------------
// �O�̃L�����Ɠ�����
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
// �O�̃L�����Ɠ�����
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
// �O�̃L�����Ɠ�����
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
// �f�[�^�擾
//-----------------------------------------------------------
StoryTextData *AllStoryTextData::getStoryTextData(int n) {
    return story_text_data[n];
}