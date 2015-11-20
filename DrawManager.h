//-----------------------------------------------------------
// DrawManager.h
// �`�搧��
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "GameData.h"
#include "GameState.h"
#include "DrawTitle.h"
#include "DrawStory.h"
#include "DrawSetting.h"
#include "DrawSaveLoad.h"

class DrawManager {
private:
    //----------
    GameData *game_data;                  // �Q�[���f�[�^
    GameState *game_state;                // �Q�[���̏��
    DrawTitle *draw_title;                // �^�C�g����ʂ̕`��
    DrawStory *draw_story;                // �X�g�[���[��ʂ̕`��
    DrawSetting *draw_setting;            // �ݒ��ʂ̕`��
    DrawSaveLoad *draw_saveload;          // �Z�[�u���[�h��ʂ̕`��
    int color_black;
public:
    DrawManager(GameData*, GameState*);   // �R���X�g���N�^
    ~DrawManager();                       // �f�X�g���N�^
    void init();                          // ������
    void update();                        // �X�V
    void draw();                          // �`��
};