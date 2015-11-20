//-----------------------------------------------------------
// SaveData.h
// �V�X�e���f�[�^
// ����� 2015.04.11
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include <fstream>
#include <iostream>
#include <sstream>

class SaveData {
private:
    int is_data[100];             // �Z�[�u�f�[�^�����邩
    int story_pos[100];           // �ꏊ
    std::string save_day[100];    // �v���C��
    std::string save_time[100];   // �Z�[�u����
public:
    SaveData();               // �R���X�g���N�^
    ~SaveData();              // �f�X�g���N�^
    void init();              // ��������
    void loadSaveData();      // �Z�[�u�f�[�^�ǂݍ���
    void deleteSaveData(int); // �Z�[�u�f�[�^�폜
    void saveSaveData(int, int);  // �Z�[�u�f�[�^�ۑ�����

    // getter
    int getIsData(int);           // �Z�[�u�f�[�^�����邩
    int getStoryPos(int);         // �ǂ���
    std::string getSaveDay(int);  // �Z�[�u��
    std::string getSaveTime(int); // �Z�[�u����
};