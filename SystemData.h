//-----------------------------------------------------------
// SystemData.h
// �V�X�e���f�[�^
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

class SystemData {
private:
    static int window_width;      // ��ʃT�C�Y��
    static int window_height;     // ��ʃT�C�Y����
    static int window_color;      // �g�p�J���[
public:
    static void loadSystemData(); // �V�X�e���f�[�^�ǂݍ���
    static int getWindowWidth();  // ��ʕ��擾
    static int getWindowHeight(); // ��ʍ����擾
    static int getWindowColor();  // �g�p�J���[�擾
};