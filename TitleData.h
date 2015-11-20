//-----------------------------------------------------------
// TitleData.h
// �^�C�g����ʂ̃f�[�^
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "SystemData.h"

class TitleData {
public:
    static const int TITLE_BUTTON_SIZE_X;   // �{�^���̑傫��x
    static const int TITLE_BUTTON_SIZE_Y;   // �{�^���̑傫��y
    static const int TITLE_CIRCLE_LOGO_SIZE_X; // �T�[�N�����S�̈ʒux
    static const int TITLE_CIRCLE_LOGO_SIZE_Y; // �T�[�N�����S�̈ʒuy
    static const int TITLE_GAME_LOGO_SIZE_X;   // �Q�[�����S�̈ʒux
    static const int TITLE_GAME_LOGO_SIZE_Y;   // �Q�[�����S�̈ʒuy
private:
public:
    TitleData();                  // �R���X�g���N�^
    ~TitleData();                 // �f�X�g���N�^
    int getPosButtonNewgameX();   // �{�^���u�͂��߂���v�̈ʒux
    int getPosButtonNewgameY();   // �{�^���u�͂��߂���v�̈ʒuy
    int getPosButtonContinueX();  // �{�^���u�Â�����v�̈ʒux
    int getPosButtonContinueY();  // �{�^���u�Â�����v�̈ʒuy
    int getPosButtonSettingX();   // �{�^���u�V�X�e���ݒ�v�̈ʒux
    int getPosButtonSettingY();   // �{�^���u�V�X�e���ݒ�v�̈ʒuy
    int getPosButtonSiteX();      // �{�^���u�����T�C�g�v�̈ʒux
    int getPosButtonSiteY();      // �{�^���u�����T�C�g�v�̈ʒuy
    int getPosButtonEndX();       // �{�^���u�Q�[���I���v�̈ʒux
    int getPosButtonEndY();       // �{�^���u�Q�[���I���v�̈ʒuy
    int getPosCirCleLogoX();      // �T�[�N�����S�̈ʒux
    int getPosCirCleLogoY();      // �T�[�N�����S�̈ʒuy
    int getPosTitleLogoX();       // �^�C�g�����S�̈ʒux
    int getPosTitleLogoY();       // �^�C�g�����S�̈ʒuy
};