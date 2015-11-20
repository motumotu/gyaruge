//-----------------------------------------------------------
// TitleState.cpp
// �^�C�g����ʂ̏��
// ����� 2015.03.15
// ����� motumotu
//-----------------------------------------------------------
#include "TitleState.h"

//-----------------------------------------------------------
// �萔
//-----------------------------------------------------------
const int TitleState::TITLE_STATE_CIRCLE_LOGO = 0;   // �T�[�N�����S�\��
const int TitleState::TITLE_STATE_TITLE = 1;         // �^�C�g���\��

const int TitleState::TITLE_MOUSEON_NONE = 0;        // ���̏�ł��Ȃ�
const int TitleState::TITLE_MOUSEON_NEWGAME = 1;     // �͂��߂���
const int TitleState::TITLE_MOUSEON_CONTINUE = 2;    // �Â�����
const int TitleState::TITLE_MOUSEON_SETTING = 3;     // �V�X�e���ݒ�
const int TitleState::TITLE_MOUSEON_SITE = 4;        // �����T�C�g
const int TitleState::TITLE_MOUSEON_END = 5;         // �I��


//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
TitleState::TitleState(GameData* _game_data)
{
    game_data = _game_data;
    title_data = game_data->getTitleData();
    init();     // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
TitleState::~TitleState()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void TitleState::init()
{
    cnt_frame = 0;
    now_state = TITLE_STATE_CIRCLE_LOGO;
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void TitleState::update()
{
    cnt_frame++;
    if (cnt_frame == 220) {
        now_state = TITLE_STATE_TITLE;
    }
}

//-----------------------------------------------------------
// �}�E�X���W�X�V
//-----------------------------------------------------------
void TitleState::updateMousePos(int x, int y)
{
    mouse_pos_x = x;
    mouse_pos_y = y;
}

//-----------------------------------------------------------
// �}�E�X���W�X�V
//-----------------------------------------------------------
bool TitleState::isPosButtonNewgame(int x, int y) {
    int bx = title_data->getPosButtonNewgameX();
    int by = title_data->getPosButtonNewgameY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}
bool TitleState::isPosButtonContinue(int x, int y) {
    int bx = title_data->getPosButtonContinueX();
    int by = title_data->getPosButtonContinueY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}
bool TitleState::isPosButtonSetting(int x, int y) {
    int bx = title_data->getPosButtonSettingX();
    int by = title_data->getPosButtonSettingY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}
bool TitleState::isPosButtonSite(int x, int y) {
    int bx = title_data->getPosButtonSiteX();
    int by = title_data->getPosButtonSiteY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}
bool TitleState::isPosButtonEnd(int x, int y) {
    int bx = title_data->getPosButtonEndX();
    int by = title_data->getPosButtonEndY();
    return (x >= bx && x <= bx + TitleData::TITLE_BUTTON_SIZE_X &&
        y >= by && y <= by + TitleData::TITLE_BUTTON_SIZE_Y);
}

//===========================================================
// getter
//===========================================================
int TitleState::getNowMouseOnObj() {
    if (isPosButtonNewgame(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_NEWGAME;
    if (isPosButtonContinue(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_CONTINUE;
    if (isPosButtonSetting(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_SETTING;
    if (isPosButtonSite(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_SITE;
    if (isPosButtonEnd(mouse_pos_x, mouse_pos_y)) return TITLE_MOUSEON_END;
    return TITLE_MOUSEON_NONE;
}
int TitleState::getNowState() { return now_state; }
int TitleState::getAlpha() {
    // �T�[�N�����S�\��
    if (cnt_frame < 150) {
        return min(255, cnt_frame * 5);
    }
    // �T�[�N�����S����
    else if (cnt_frame >= 150 && cnt_frame < 220) {
        return max(0, 1005 - cnt_frame * 5);
    }
    // �^�C�g�����
    else {
        return 255;
    }
}
int TitleState::getCntFrame() { return cnt_frame; }