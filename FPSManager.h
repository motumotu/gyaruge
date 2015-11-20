//-----------------------------------------------------------
// FPSManager.h
// FPS�̒���
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class FPSManager {
public:
    static const int FPS = 60;  // FPS�l
private:
    static const int N = 60;    // �T���v����
    int start_time;             // �v���J�n����
    int counter;                // �J�E���^�[
    double fps;                 // ���ۂ�fps

public:
    FPSManager();               // �R���X�g���N�^
    ~FPSManager();              // �f�X�g���N�^
    void init();                // ��������
    void update();              // �X�V
    void wait();                // �����̂��ߑ҂�
};