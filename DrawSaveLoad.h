//-----------------------------------------------------------
// DrawSaveLoad.h
// �Z�[�u�E���[�h��ʂ̕`��
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawSaveLoad {
public:
private:
    GameData *game_data;            // �Q�[���f�[�^
    GameState *game_state;          // �V�[���}�l�[�W���[
    SaveLoadData *saveload_data;
    SaveLoadState *saveload_state;
    int handl_back;
    int handl_base[2];               // ��b
    int handl_button_num[20];        // �Z�[�u�f�[�^�ԍ�
    int handl_button_back[2];        // �߂�{�^��
    int handl_logo_save;             // ���S�Z�[�u
    int handl_logo_load;             // ���[�h���S
    int handl_below;                 // �T���l�����ߗp
    int handl_nodata;                // �f�[�^�Ȃ�
    int handl_button_close[2];       // ����{�^��
    int handl_dialog;
    int handl_dialog_yes[2];
    int handl_dialog_no[2];

    int color_font;                  // �t�H���g�p�̐F
    int font_time;                   // �Z�[�u���Ԃ̃t�H���g
    int font_dialog;                 // �_�C�A���O
public:
    DrawSaveLoad(GameData*, GameState*); // �R���X�g���N�^
    ~DrawSaveLoad();             // �f�X�g���N�^
    void init();                 // ������
    void loadImage();           // �摜�ǂݍ���
    void draw();                // �`��
    void drawSaveData();        // �Z�[�u�f�[�^�`��
    void drawThumbnail(int, int, int); // �T���l�`��
    void drawDialog();          // �_�C�A���O�`��
};