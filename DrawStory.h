//-----------------------------------------------------------
// DrawStory.h
// �X�g�[���[��ʂ̕`��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class DrawStory {
public:
private:
    GameData *game_data;      // �Q�[���f�[�^
    GameState *game_state;    // �Q�[�����
    StoryState *story_state;  // �X�g�[���[���
    StoryData *story_data;    // �X�g�[���[�f�[�^
    int handl_window;         // �E�B���h�E�`��
    int handl_button_auto[3]; // �I�[�g�{�^��
    int handl_button_skip[3]; // �X�L�b�v�{�^��
    int handl_button_log[3];  // ���O�{�^��
    int handl_button_conf[3]; // �R���t�B�O�{�^��
    int handl_button_save[3]; // �Z�[�u�{�^��
    int handl_button_load[3]; // ���[�h�{�^��
    int handl_button_close[2];// ����{�^��
    int handl_backlog_back;   // �o�b�N���O�w�i
    int handl_scroll_bar;     // �X�N���[���o�[�G���A
    int handl_backlog_up[2];   // �o�b�N���O���
    int handl_backlog_down[2]; // �o�b�N���O����
    int handl_backlog_exit[2]; // exit�{�^��

    int color_white;          // �F_��
    int color_gray;           // �F_�O���[
    int color_scrollbar;      // �F_�X�N���[���o�[
    int font;
    int font_name;            // ���O�̃t�H���g
    int font_name_e;          // ���O�C���O���b�V��
public:
    DrawStory(GameData*, GameState*); // �R���X�g���N�^
    ~DrawStory();             // �f�X�g���N�^
    void init();              // ������
    void update();            // �X�V
    void draw();              // �`��
    void loadImage();         // �摜�ǂݍ���
    void drawWindow();        // �e�L�X�g�E�B���h�E�`��
    void drawNowText();       // ���݂̃e�L�X�g�`��
    void drawChara(int);      // �L�����`��
    void drawBacklog();       // �o�b�N���O�`��
    void drawTextPos(int, int, int); // �e�L�X�g�ꏊ
    void drawScrollbar();     // �X�N���[���o�[�`��
};