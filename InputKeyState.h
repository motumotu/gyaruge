//-----------------------------------------------------------
// InputKeyState.h
// �L�[�{�[�h�̓��͏��Ǘ�
// ����� 2014.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class InputKeyState {
public:
    static const int KEY_MAX = 256;

private:
    int key[KEY_MAX];     // �L�[���͏��

public:
    InputKeyState();       // �R���X�g���N�^
    ~InputKeyState();      // �f�X�g���N�^
    void init();           // ��������
    void update();         // �X�V����

    int getKeyState(int);  // �L�[�̓��͏�Ԏ擾
};