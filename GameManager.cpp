//-----------------------------------------------------------
// GameManager.cpp
// �Q�[�����䕔
// ����� 2015.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "GameManager.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
GameManager::GameManager(GameData* data, GameState* state)
{
    game_data = data; 
    game_state = state;
    fps_manager = new FPSManager();
    draw_manager = new DrawManager(data, state);
    scene_manager = new SceneManager(data, state);
    init();     // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
GameManager::~GameManager()
{
    delete(scene_manager);
    delete(draw_manager);
    delete(fps_manager);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void GameManager::init()
{
    fps_manager->init();
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void GameManager::update()
{
    scene_manager->update();
}

//===========================================================
// getter
//===========================================================
DrawManager *GameManager::getDrawManager() { return draw_manager; }
FPSManager *GameManager::getFPSManager() { return fps_manager; }
SceneManager *GameManager::getSceneManager() { return scene_manager; }