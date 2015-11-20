//-----------------------------------------------------------
// TitleManager.h
// �^�C�g����ʂ̐���
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"

class TitleManager {
private:
    GameData *game_data;
    GameState *game_state;
    InputState *input_state;
    TitleState *title_state;
public:
    TitleManager(GameData*, GameState*); // �R���X�g���N�^
    ~TitleManager();           // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void clickFirst();         // �ŏ�����
    void clickContinue();      // ��������
    void clickSetting();       // �V�X�e���ݒ�
    void clickSite();          // �����T�C�g
    void clickEnd();           // �Q�[���I��
};