//-----------------------------------------------------------
// TitleState.h
// �^�C�g����ʂ̏��
// ����� 2015.03.15
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include <algorithm>
#include "GameData.h"
#include "DxLib.h"

class TitleState {
public:
    static const int TITLE_STATE_CIRCLE_LOGO;   // �T�[�N�����S�\��
    static const int TITLE_STATE_TITLE;         // �^�C�g���\��
    static const int TITLE_MOUSEON_NONE;        // ���̏�ł��Ȃ�
    static const int TITLE_MOUSEON_NEWGAME;     // �͂��߂���
    static const int TITLE_MOUSEON_CONTINUE;    // �Â�����
    static const int TITLE_MOUSEON_SETTING;     // �V�X�e���ݒ�
    static const int TITLE_MOUSEON_SITE;        // �����T�C�g
    static const int TITLE_MOUSEON_END;         // �I��
private:
    GameData *game_data;       // �Q�[���f�[�^
    TitleData *title_data;     // �^�C�g����ʂ̃f�[�^
    int cnt_frame;             // �o�߃t���[����
    int now_state;             // ���݂̏��
    int mouse_pos_x;           // �}�E�X�ʒux
    int mouse_pos_y;           // �}�E�X�ʒuy
public:
    TitleState(GameData*);     // �R���X�g���N�^
    ~TitleState();             // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void updateMousePos(int, int); // �}�E�X���W�X�V

    bool isPosButtonNewgame(int, int);  // ���̈ʒu���u�͂��߂���v��
    bool isPosButtonContinue(int, int); // ���̈ʒu���u�Â�����v��
    bool isPosButtonSetting(int, int);  // ���̈ʒu���u�V�X�e���ݒ�v��
    bool isPosButtonSite(int, int);     // ���̈ʒu���u�����T�C�g�v��
    bool isPosButtonEnd(int, int);      // ���̈ʒu���u�Q�[���I���v��

    int getNowMouseOnObj();    // ���݃}�E�X������Ă���I�u�W�F�N�g�擾
    int getNowState();         // ��Ԏ擾
    int getAlpha();            // ���ߓx�擾
    int getCntFrame();         // �o�߃t���[�����擾
};