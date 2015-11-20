//-----------------------------------------------------------
// DrawTitle.h
// �^�C�g����ʂ̕`��
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "DxLib.h"

class DrawTitle {
private:
    GameData *game_data;      // �Q�[���f�[�^
    GameState *game_state;    // �Q�[�����
    TitleState *title_state;  // �^�C�g����ʂ̏��
    TitleData *title_data;    // �^�C�g����ʂ̃f�[�^
    int handl_circle_logo;    // �T�[�N�����S
    int handl_game_logo;      // �Q�[�����S
    int handl_button[10];     // �{�^��
    int handl_back;           // �w�i
    int color_white;          // �F_��
public:
    DrawTitle(GameData*, GameState*);     // �R���X�g���N�^
    ~DrawTitle();             // �f�X�g���N�^
    void init();              // ������
    void loadImage();         // �摜�ǂݍ���
    void update();            // �X�V
    void draw();              // �`��
    void drawButton();        // �{�^���`��
};