//-----------------------------------------------------------
// InputState.h
// ���͏��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "InputKeyState.h"
#include "InputMouseState.h"

class InputState {
public:
private:
    InputKeyState *key_state;     // �L�[���͏��
    InputMouseState *mouse_state; // �}�E�X���͏��

public:
    InputState();      // �R���X�g���N�^
    ~InputState();     // �f�X�g���N�^
    void init();       // ��������
    void update();     // �X�V����

    // getter
    int getKeyState(int);  // �L�[�̓��͏�Ԏ擾
    int getMouseWheel();   // �}�E�X�z�C�[����]�ʎ擾
    int getPointX();       // ���Wx���擾
    int getPointY();       // ���Wy���擾
    int getClick(int);     // �N���b�N���擾
    int getPreClick(int);  // �O�t���[���N���b�N���
    bool isRereaseClick(int); // �N���b�N�������ꂽ��
};