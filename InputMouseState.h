//-----------------------------------------------------------
// InputMouseState.h
// �}�E�X�̓��͏��
// ����� 2014.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"

class InputMouseState {
public:
    static const int CLICK_MAX = 8;

private:
    int point_x;           // �}�E�X�̍��Wx
    int point_y;           // �}�E�X�̍��Wy
    int click[CLICK_MAX];  // �N���b�N���
    int pre_click[CLICK_MAX]; // �O�t���[���̃N���b�N���
    int wheel;             // �}�E�X��]��

public:
    InputMouseState();     // �R���X�g���N�^
    ~InputMouseState();    // �f�X�g���N�^
    void init();           // ��������
    void update();         // �X�V����
    // getter
    int getMouseWheel();   // �}�E�X�z�C�[����]�ʎ擾
    int getPointX();       // ���Wx���擾
    int getPointY();       // ���Wy���擾
    int getClick(int);     // �N���b�N���擾
    int getPreClick(int);  // �O�t���[���N���b�N���擾
    bool isRereaseClick(int); // �w��N���b�N�������ꂽ��
};