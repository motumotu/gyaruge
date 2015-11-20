//-----------------------------------------------------------
// AllStoryTextData.h
// �S�X�g�[���[�e�L�X�g�f�[�^
// ����� 2015.03.24
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "StoryTextData.h"
#include <sstream>
#include <string>
#include <iostream>

class AllStoryTextData {
public:
private:
    StoryTextData *story_text_data[1000]; // �X�g�[���[�f�[�^
public:
    AllStoryTextData();    // �R���X�g���N�^
    ~AllStoryTextData();   // �f�X�g���N�^
    void loadData();       // �f�[�^�ǂݍ���
    bool isPreAllCharaEqual(int); // �O�̃L�����Ɠ�����
    bool isPreCharaEqual(int, int, int); // �O�̃L�����Ɠ�����
    bool isNowCharaEqual(int, int, int); // ���̉�ʂɓ����L���������邩
    StoryTextData *getStoryTextData(int); // �擾
};