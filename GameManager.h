//-----------------------------------------------------------
// GameManager.h
// �Q�[�����䕔
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"
#include "GameState.h"
#include "DrawManager.h"
#include "FPSManager.h"
#include "SceneManager.h"

class GameManager {
private:
    DrawManager *draw_manager;   // �`�搧��
    // ��������
    FPSManager *fps_manager;     // FPS����
    SceneManager *scene_manager; // �e�V�[���̐���

    GameData *game_data;         // �Q�[���f�[�^
    GameState *game_state;       // �Q�[�����

public:
    GameManager(GameData*, GameState*); // �R���X�g���N�^
    ~GameManager();              // �f�X�g���N�^
    void init();                 // ������
    void update();               // �X�V

    DrawManager *getDrawManager();
    FPSManager *getFPSManager();
    SceneManager *getSceneManager();
};