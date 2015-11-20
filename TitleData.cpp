//-----------------------------------------------------------
// TitleData.cpp
// �^�C�g����ʂ̃f�[�^
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "TitleData.h"

//-----------------------------------------------------------
// �萔
//-----------------------------------------------------------
const int TitleData::TITLE_BUTTON_SIZE_X = 200;   // �{�^���̑傫��x
const int TitleData::TITLE_BUTTON_SIZE_Y = 40;    // �{�^���̑傫��y
const int TitleData::TITLE_CIRCLE_LOGO_SIZE_X = 400; // �T�[�N�����Sx
const int TitleData::TITLE_CIRCLE_LOGO_SIZE_Y = 300; // �T�[�N�����Sy
const int TitleData::TITLE_GAME_LOGO_SIZE_X = 650;   // �Q�[�����Sx
const int TitleData::TITLE_GAME_LOGO_SIZE_Y = 230;   // �Q�[�����Sy

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
TitleData::TitleData()
{

}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
TitleData::~TitleData()
{

}

//-----------------------------------------------------------
// �{�^���ʒu�擾
//-----------------------------------------------------------
int TitleData::getPosButtonNewgameX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonNewgameY() {
    return SystemData::getWindowHeight() - 240;
}
int TitleData::getPosButtonContinueX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonContinueY() {
    return SystemData::getWindowHeight() - 200;
}
int TitleData::getPosButtonSettingX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonSettingY() {
    return SystemData::getWindowHeight() - 160;
}
int TitleData::getPosButtonSiteX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonSiteY() {
    return SystemData::getWindowHeight() - 120;
}
int TitleData::getPosButtonEndX() {
    return SystemData::getWindowWidth() / 2 - TITLE_BUTTON_SIZE_X / 2;
}
int TitleData::getPosButtonEndY() {
    return SystemData::getWindowHeight() - 80;
}
int TitleData::getPosCirCleLogoX() {
    return SystemData::getWindowWidth() / 2 - TITLE_CIRCLE_LOGO_SIZE_X / 2;
}
int TitleData::getPosCirCleLogoY() {
    return SystemData::getWindowHeight() / 2 - TITLE_CIRCLE_LOGO_SIZE_Y / 2;
}
int TitleData::getPosTitleLogoX() {
    return SystemData::getWindowWidth() / 2 - TITLE_GAME_LOGO_SIZE_X / 2;
}
int TitleData::getPosTitleLogoY() {
    return 100;
}