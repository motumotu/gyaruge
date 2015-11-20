//-----------------------------------------------------------
// SaveLoadData.h
// �Z�[�u�E���[�h��ʂ̃f�[�^
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#pragma once

class SaveLoadData {
public:
    static const int SAVELOAD_BASE_SIZE_X;
    static const int SAVELOAD_BASE_SIZE_Y;
    static const int SAVELOAD_BASE_POS_X;
    static const int SAVELOAD_BASE_POS_Y;
    static const int SAVELOAD_BUTTON_NUM_SIZE_X;
    static const int SAVELOAD_BUTTON_NUM_SIZE_Y;
    static const int SAVELOAD_BUTTON_NUM_POS_X;
    static const int SAVELOAD_BUTTON_NUM_POS_Y;
    // ����
    static const int SAVELOAD_BUTTON_NUM;
    static const int SAVELOAD_BASE_NUM;
    // �߂�{�^��
    static const int SAVELOAD_BUTTON_BACK_SIZE_X;
    static const int SAVELOAD_BUTTON_BACK_SIZE_Y;
    static const int SAVELOAD_BUTTON_BACK_POS_X;
    static const int SAVELOAD_BUTTON_BACK_POS_Y;
    // ����{�^��
    static const int SAVELOAD_BUTTON_CLOSE_SIZE_X;
    static const int SAVELOAD_BUTTON_CLOSE_SIZE_Y;
    static const int SAVELOAD_BUTTON_CLOSE_POS_X;
    static const int SAVELOAD_BUTTON_CLOSE_POS_Y;
    // �_�C�A���O
    static const int SAVELOAD_DIALOG_SIZE_X;
    static const int SAVELOAD_DIALOG_SIZE_Y;
    static const int SAVELOAD_DIALOG_POS_X;
    static const int SAVELOAD_DIALOG_POS_Y;
    // �_�C�A���O�̃{�^��
    static const int SAVELOAD_DIALOG_BUTTON_SIZE_X;
    static const int SAVELOAD_DIALOG_BUTTON_SIZE_Y;
    // �_�C�A���O��YES
    static const int SAVELOAD_DIALOG_YES_POS_X;
    static const int SAVELOAD_DIALOG_YES_POS_Y;
    // �_�C�A���O��NO
    static const int SAVELOAD_DIALOG_NO_POS_X;
    static const int SAVELOAD_DIALOG_NO_POS_Y;
private:
public:
    SaveLoadData();    // �R���X�g���N�^
    ~SaveLoadData();   // �f�X�g���N�^
    int getPosBaseX(int);
    int getPosBaseY(int);
    int getPosButtonNumX(int);
    int getPosButtonNumY(int);
};