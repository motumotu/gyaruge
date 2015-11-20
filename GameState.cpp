//-----------------------------------------------------------
// GameState.cpp
// �Q�[���̏��
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#include "GameState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
GameState::GameState(GameData* _game_data)
{
    game_data = _game_data;
    input_state = new InputState();
    scene_state = new SceneState(game_data);
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
GameState::~GameState()
{
    delete(scene_state);
    delete(input_state);
}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void GameState::init()
{
    is_game_end = false;
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void GameState::update()
{
    input_state->update();
    scene_state->update();
}

//-----------------------------------------------------------
// �Q�[���I��
//-----------------------------------------------------------
void GameState::gameEnd() { is_game_end = true; }

//===========================================================
// getter
//===========================================================
SceneState *GameState::getSceneState() { return scene_state; }
InputState *GameState::getInputState() { return input_state; }
bool GameState::isGameEnd() { return is_game_end; }