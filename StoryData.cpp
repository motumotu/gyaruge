//-----------------------------------------------------------
// StoryData.cpp
// �X�g�[���[��ʂ̃f�[�^
// ����� 2015.03.23
// ����� motumotu
//-----------------------------------------------------------
#include "StoryData.h"

//-----------------------------------------------------------
// �萔
//-----------------------------------------------------------
const int StoryData::TEXT_WINDOW_POS_X = 0;
const int StoryData::TEXT_WINDOW_POS_Y = 385;
const int StoryData::TEXT_AREA_POS_X = 230;
const int StoryData::TEXT_AREA_POS_Y = 480;
const int StoryData::STORY_BUTTON_SIZE_X = 49;
const int StoryData::STORY_BUTTON_SIZE_Y = 44;
const int StoryData::STORY_BUTTON_POS_X = 910;
const int StoryData::STORY_BUTTON_POS_Y = 445;
const int StoryData::STORY_BUTTON_CLOSE_SIZE_X = 25;
const int StoryData::STORY_BUTTON_CLOSE_SIZE_Y = 25;
const int StoryData::STORY_BUTTON_CLOSE_POS_X = 865;
const int StoryData::STORY_BUTTON_CLOSE_POS_Y = 450;
const int StoryData::STORY_SCROLLBAR_AREA_POS_X = 930;
const int StoryData::STORY_SCROLLBAR_AREA_POS_Y = 50;
const int StoryData::STORY_SCROLLBAR_AREA_SIZE_X = 20;
const int StoryData::STORY_SCROLLBAR_AREA_SIZE_Y = 450;
// �X�N���[���o�[�{�^��
const int StoryData::STORY_SCROLLBAR_BUTTON_SIZE_X = 20;
const int StoryData::STORY_SCROLLBAR_BUTTON_SIZE_Y = 35;
// �X�N���[���o�[��{�^��
const int StoryData::STORY_SCROLLBAR_BUTTON_UP_POS_X = 930;
const int StoryData::STORY_SCROLLBAR_BUTTON_UP_POS_Y = 10;
// �X�N���[���o�[���{�^��
const int StoryData::STORY_SCROLLBAR_BUTTON_DOWN_POS_X = 930;
const int StoryData::STORY_SCROLLBAR_BUTTON_DOWN_POS_Y = 505;
// �o�b�N���O�߂�
const int StoryData::STORY_BACKLOG_BUTTON_EXIT_POS_X = 875;
const int StoryData::STORY_BACKLOG_BUTTON_EXIT_POS_Y = 550;
const int StoryData::STORY_BACKLOG_BUTTON_EXIT_SIZE_X = 130;
const int StoryData::STORY_BACKLOG_BUTTON_EXIT_SIZE_Y = 40;

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
StoryData::StoryData()
{

}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
StoryData::~StoryData()
{

}

//-----------------------------------------------------------
// �ʒu�擾
//-----------------------------------------------------------
int StoryData::getPosButtonAutoX() {
    return STORY_BUTTON_POS_X;
}
int StoryData::getPosButtonAutoY() {
    return STORY_BUTTON_POS_Y;
}
int StoryData::getPosButtonSkipX() {
    return STORY_BUTTON_POS_X + STORY_BUTTON_SIZE_X + 5;
}
int StoryData::getPosButtonSkipY() {
    return STORY_BUTTON_POS_Y;
}
int StoryData::getPosButtonLogX() {
    return STORY_BUTTON_POS_X;
}
int StoryData::getPosButtonLogY() {
    return STORY_BUTTON_POS_Y + STORY_BUTTON_SIZE_Y + 5;
}
int StoryData::getPosButtonConfX() {
    return STORY_BUTTON_POS_X + STORY_BUTTON_SIZE_X + 5;
}
int StoryData::getPosButtonConfY() {
    return STORY_BUTTON_POS_Y + STORY_BUTTON_SIZE_Y + 5;
}
int StoryData::getPosButtonSaveX() {
    return STORY_BUTTON_POS_X;
}
int StoryData::getPosButtonSaveY() {
    return STORY_BUTTON_POS_Y + STORY_BUTTON_SIZE_Y * 2 + 10;
}
int StoryData::getPosButtonLoadX() {
    return STORY_BUTTON_POS_X + STORY_BUTTON_SIZE_X + 5;
}
int StoryData::getPosButtonLoadY() {
    return STORY_BUTTON_POS_Y + STORY_BUTTON_SIZE_Y * 2 + 10;
}
int StoryData::getPosButtonCloseX() {
    return STORY_BUTTON_CLOSE_POS_X;
}
int StoryData::getPosButtonCloseY() {
    return STORY_BUTTON_CLOSE_POS_Y;
}