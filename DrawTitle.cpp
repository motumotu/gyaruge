//-----------------------------------------------------------
// DrawTitle.cpp
// �^�C�g����ʂ̕`��
// ����� 2015.03.15
// ����� motumotu
//-----------------------------------------------------------
#include "DrawTitle.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DrawTitle::DrawTitle(GameData *data, GameState *state)
{
    game_data = data;
    game_state = state;
    title_state = state->getSceneState()->getTitleState();
    title_data = data->getTitleData();
    color_white = GetColor(255, 255, 255);
    init();               // ��������
    loadImage();          // �摜�ǂݍ���
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DrawTitle::~DrawTitle()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void DrawTitle::init()
{

}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void DrawTitle::update()
{

}

//-----------------------------------------------------------
// �摜�ǂݍ���
//-----------------------------------------------------------
void DrawTitle::loadImage()
{
    handl_circle_logo = LoadGraph("image/title/circle_logo.png");
    handl_game_logo = LoadGraph("image/title/game_logo.png");
    LoadDivGraph("image/title/button.png", 10, 5, 2, 200, 40, handl_button);
    handl_back = LoadGraph("image/title/back.png");
}

//-----------------------------------------------------------
// �`��
//-----------------------------------------------------------
void DrawTitle::draw()
{
    // �w�i
    DrawBox(0, 0,
        SystemData::getWindowWidth(),
        SystemData::getWindowHeight(),
        color_white, TRUE);

    // �T�[�N�����S
    if (title_state->getNowState() == TitleState::TITLE_STATE_CIRCLE_LOGO) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, title_state->getAlpha());
        DrawGraph(
            title_data->getPosCirCleLogoX(),
            title_data->getPosCirCleLogoY(),
            handl_circle_logo, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);  // �߂�
    }
    // �^�C�g��
    if (title_state->getNowState() == TitleState::TITLE_STATE_TITLE) {
        DrawGraph(0, 0, handl_back, TRUE);
        DrawGraph(
            title_data->getPosTitleLogoX(),
            title_data->getPosTitleLogoY(),
            handl_game_logo, TRUE);
        drawButton();
    }
}

//-----------------------------------------------------------
// �{�^���`��
//-----------------------------------------------------------
void DrawTitle::drawButton()
{
    int image = 0;
    int obj = title_state->getNowMouseOnObj();
    //---- �͂��߂���
    image = 0 + ((obj == TitleState::TITLE_MOUSEON_NEWGAME) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonNewgameX(),
        title_data->getPosButtonNewgameY(),
        handl_button[image], TRUE);
    //---- �Â�����
    image = 1 + ((obj == TitleState::TITLE_MOUSEON_CONTINUE) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonContinueX(),
        title_data->getPosButtonContinueY(),
        handl_button[image], TRUE);
    //----- �V�X�e���ݒ�
    image = 2 + ((obj == TitleState::TITLE_MOUSEON_SETTING) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonSettingX(),
        title_data->getPosButtonSettingY(),
        handl_button[image], TRUE);
    //----- �����T�C�g
    image = 3 + ((obj == TitleState::TITLE_MOUSEON_SITE) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonSiteX(),
        title_data->getPosButtonSiteY(),
        handl_button[image], TRUE);
    //---- �I��
    image = 4 + ((obj == TitleState::TITLE_MOUSEON_END) ? 5 : 0);
    DrawGraph(
        title_data->getPosButtonEndX(),
        title_data->getPosButtonEndY(),
        handl_button[image], TRUE);
}

//===========================================================
// getter
//===========================================================