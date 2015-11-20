//-----------------------------------------------------------
// StoryData.h
// �X�g�[���[��ʂ̃f�[�^
// ����� 2015.03.23
// ����� motumotu
//-----------------------------------------------------------
#pragma once

class StoryData {
public:
    // �E�B���h�E
    static const int TEXT_WINDOW_POS_X;
    static const int TEXT_WINDOW_POS_Y;
    // �e�L�X�g�G���A
    static const int TEXT_AREA_POS_X;
    static const int TEXT_AREA_POS_Y;
    // �{�^��
    static const int STORY_BUTTON_SIZE_X;
    static const int STORY_BUTTON_SIZE_Y;
    static const int STORY_BUTTON_POS_X;
    static const int STORY_BUTTON_POS_Y;
    // ����{�^��
    static const int STORY_BUTTON_CLOSE_SIZE_X;
    static const int STORY_BUTTON_CLOSE_SIZE_Y;
    static const int STORY_BUTTON_CLOSE_POS_X;
    static const int STORY_BUTTON_CLOSE_POS_Y;
    // �X�N���[���o�[
    static const int STORY_SCROLLBAR_AREA_POS_X;
    static const int STORY_SCROLLBAR_AREA_POS_Y;
    static const int STORY_SCROLLBAR_AREA_SIZE_X;
    static const int STORY_SCROLLBAR_AREA_SIZE_Y;
    // �X�N���[���o�[�{�^��
    static const int STORY_SCROLLBAR_BUTTON_SIZE_X;
    static const int STORY_SCROLLBAR_BUTTON_SIZE_Y;
    // �X�N���[���o�[��{�^��
    static const int STORY_SCROLLBAR_BUTTON_UP_POS_X;
    static const int STORY_SCROLLBAR_BUTTON_UP_POS_Y;
    // �X�N���[���o�[���{�^��
    static const int STORY_SCROLLBAR_BUTTON_DOWN_POS_X;
    static const int STORY_SCROLLBAR_BUTTON_DOWN_POS_Y;
    // EXIT���O�߂�
    static const int STORY_BACKLOG_BUTTON_EXIT_POS_X;
    static const int STORY_BACKLOG_BUTTON_EXIT_POS_Y;
    static const int STORY_BACKLOG_BUTTON_EXIT_SIZE_X;
    static const int STORY_BACKLOG_BUTTON_EXIT_SIZE_Y;
private:
public:
    StoryData();    // �R���X�g���N�^
    ~StoryData();   // �f�X�g���N�^
    int getPosButtonAutoX();  // �I�[�g�{�^���̈ʒux
    int getPosButtonAutoY();  // �I�[�g�{�^���̈ʒuy
    int getPosButtonSkipX();  // �X�L�b�v�{�^���̈ʒux
    int getPosButtonSkipY();  // �X�L�b�v�{�^���̈ʒuy
    int getPosButtonLogX();   // �o�b�N���O�{�^���̈ʒux
    int getPosButtonLogY();   // �o�b�N���O�{�^���̈ʒuy
    int getPosButtonConfX();  // �R���t�B�O�{�^���̈ʒux
    int getPosButtonConfY();  // �R���t�B�O�{�^���̈ʒuy
    int getPosButtonSaveX();  // �Z�[�u�{�^���̈ʒux
    int getPosButtonSaveY();  // �Z�[�u�{�^���̈ʒuy
    int getPosButtonLoadX();  // ���[�h�{�^���̈ʒux
    int getPosButtonLoadY();  // ���[�h�{�^���̈ʒuy
    int getPosButtonCloseX(); // ����{�^���̈ʒux
    int getPosButtonCloseY(); // ����{�^���̈ʒuy
};