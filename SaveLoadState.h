//-----------------------------------------------------------
// SaveLoadState.h
// �Z�[�u���[�h��ʂ̏��
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class SaveLoadState {
public:
    static const int SAVELOAD_OBJ_NONE;
    static const int SAVELOAD_OBJ_BUTTON_NUM;
    static const int SAVELOAD_OBJ_BUTTON_BACK;
    static const int SAVELOAD_OBJ_BUTTON_CLOSE;
    static const int SAVELOAD_OBJ_BASE;
    static const int SAVELOAD_OBJ_DIALOG_YES;
    static const int SAVELOAD_OBJ_DIALOG_NO;

    static const int SAVELOAD_MODE_SAVE;
    static const int SAVELOAD_MODE_LOAD;

    static const int SAVELOAD_DIALOG_OVERWRITE;  // �㏑�����܂���
    static const int SAVELOAD_DIALOG_DELETE;     // �폜���܂���
    static const int SAVELOAD_DIALOG_LOAD;       // ���[�h���܂���
private:
    GameData *game_data;           // �Q�[���f�[�^
    SaveLoadData *saveload_data;   // �Z�[�u��ʂ̃f�[�^
    int mouse_x;                   // �}�E�X�ʒux
    int mouse_y;                   // �}�E�X�ʒuy
    int select_num;                // �I�𒆂̔ԍ�
    int mode;                      // ���[�h
    bool is_dialog;                // �_�C�A���O����
    int select_base_num;           // �I�𒆂̃x�[�X�ԍ�
    int dialog_mode;               // �_�C�A���O���[�h
public:
    SaveLoadState(GameData*);      // �R���X�g���N�^
    ~SaveLoadState();              // �f�X�g���N�^
    void init();                   // ������
    void update();                 // �X�V
    void updateMousePos(int, int); // �}�E�X�ʒu�X�V
    int getImageButtonNum(int);    // �ԍ��{�^���̉摜�擾
    int getImageButtonBack();      // �߂�{�^���̉摜�擾
    int getImageButtonClose(int);  // ����{�^���̉摜�擾
    int getImageBase(int);         // �x�[�X�̉摜�擾
    // �ԍ��擾
    int getMousePosButtonNum();    // �ԍ��擾
    int getMousePosBaseNum();      // �x�[�X�ԍ��擾
    // ���̎擾
    int getMousePosObject();       // �}�E�X���W�̕��̎擾
    bool isPosButtonNum(int);      // �I��ԍ�
    bool isPosButtonBack();        // �߂�{�^��
    bool isPosButtonClose(int);    // ����{�^��
    bool isPosBase(int);           // �x�[�X�ʒu��
    bool isPosDialogYes();        
    bool isPosDialogNo();
    // �_�C�A���O
    void deleteDialog();        // �_�C�A���O�폜
    void createDialog(int);     // �_�C�A���O���[�h
    char *getDialogText();      // �_�C�A���O�e�L�X�g�擾

    // �Z�b�g
    void setSelectNum(int);     // �I��ԍ��ݒ�
    void setMode(int);          // ���[�h�ݒ�
    void setSelectBaseNum(int); // �I���x�[�X�ԍ��Z�b�g
    // getter
    int getMode();              // ���[�h�擾
    int getSelectNum();         // ���݂̑I��ԍ��擾
    bool isDialog();            // �_�C�A���O����
    int getSelectBaseNum();     // �I���x�[�X�ԍ��擾
    int getDialogMode();        // �_�C�A���O���[�h�擾
};