//-----------------------------------------------------------
// SystemData.cpp
// �V�X�e���f�[�^
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#include "SystemData.h"

int SystemData::window_width;      // ��ʃT�C�Y��
int SystemData::window_height;     // ��ʃT�C�Y����
int SystemData::window_color;      // �g�p�J���[

//-----------------------------------------------------------
// �V�X�e���f�[�^�ǂݍ���
//-----------------------------------------------------------
void SystemData::loadSystemData()
{
    std::string str;
    std::ifstream ifs("system/conf.dat");

    if (ifs.fail()) {
        std::cout << "conf.dat�̓ǂݍ��݂Ɏ��s���܂����B" << std::endl;
        return;
    }
    while (getline(ifs, str)) {
        std::stringstream ss(str);
        ss >> str;
        //---- ��ʕ�
        if (str == "WINDOW_SIZE_WIDTH") {
            ss >> str;
            window_width = atoi(str.c_str());
        }
        //---- ��ʍ�
        else if (str == "WINDOW_SIZE_HEIGHT") {
            ss >> str;
            window_height = atoi(str.c_str());
        }
        //---- �g�p�J���[��
        else if (str == "WINDOW_USE_COLOR") {
            ss >> str;
            window_color = atoi(str.c_str());
        }
    }
}

//===========================================================
// getter
//===========================================================
int SystemData::getWindowWidth() { return window_width; }
int SystemData::getWindowHeight() { return window_height; }
int SystemData::getWindowColor() { return window_color; }
