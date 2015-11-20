//-----------------------------------------------------------
// SaveData.h
// �V�X�e���f�[�^
// ����� 2015.04.11
// ����� motumotu
//-----------------------------------------------------------
#include "SaveData.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
SaveData::SaveData()
{
    init();           // ��������
    loadSaveData();   // �Z�[�u�f�[�^�ǂݍ���
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
SaveData::~SaveData()
{
}

//-----------------------------------------------------------
// ��������
//-----------------------------------------------------------
void SaveData::init()
{
    for (int i = 0; i < 100; i++) {
        is_data[i] = 0;
        story_pos[i] = 0;
        save_day[i] = "----/--/--";
        save_time[i] = "--:--";
    }
}

//-----------------------------------------------------------
// �Z�[�u�f�[�^�ǂݍ��ݏ���
//-----------------------------------------------------------
void SaveData::loadSaveData()
{
    char str[1024];
    std::string s;
    std::stringstream ss;
    int num;

    // �t�@�C���I�[�v������
    int fp = FileRead_open("savedata/savedata.dat");
    if (fp == 0) {
        puts("savedata.dat�t�@�C���ǂݍ��ݎ��s");
        return;
    }
    // �t�@�C���ǂݍ��ݏ���
    while (FileRead_gets(str, 256, fp) != -1) {
        ss.clear();
        ss.str(str);
        //---- �ԍ�
        ss >> s;
        num = atoi(s.c_str());
        is_data[num] = 1;
        //---- �ꏊ
        ss >> s;
        story_pos[num] = atoi(s.c_str());
        //---- �v���C����
        ss >> s;
        save_day[num] = s;
        ss >> s;
        save_time[num] = s;
    }
}

//-----------------------------------------------------------
// �Z�[�u�f�[�^�폜
//-----------------------------------------------------------
void SaveData::deleteSaveData(int n)
{
    is_data[n] = 0;
    story_pos[n] = 0;
    save_day[n] = "----/--/--";
    save_time[n] = "--:--";
}

//-----------------------------------------------------------
// �Z�[�u�f�[�^�ۑ�
//-----------------------------------------------------------
void SaveData::saveSaveData(int n, int pos)
{
    printf("%d\n", pos);
    //---- �ԍ�
    is_data[n] = 1;

    //---- �ꏊ
    story_pos[n] = pos;

    //---- ��
    char c[256];
    DATEDATA date;
    GetDateTime(&date);
    std::stringstream ds;
    sprintf_s(c, "%02d", date.Year);
    ds << c << "/";
    sprintf_s(c, "%02d", date.Mon);
    ds << c << "/";
    sprintf_s(c, "%02d", date.Day);
    ds << c;
    save_day[n] = ds.str();

    //---- ����
    ds.str("");
    sprintf_s(c, "%02d", date.Hour);
    ds << c << ":";
    sprintf_s(c, "%02d", date.Min);
    ds << c;
    save_time[n] = ds.str();

}

//===========================================================
// getter
//===========================================================
int SaveData::getIsData(int n) { return is_data[n]; }
int SaveData::getStoryPos(int n) { return story_pos[n]; }
std::string SaveData::getSaveDay(int n) { return save_day[n]; }
std::string SaveData::getSaveTime(int n) { return save_time[n]; }