//-----------------------------------------------------------
// main.cpp
// main
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------

//-----------------------------------------------------------
// �w�b�_�[�C���N���[�h
//-----------------------------------------------------------
#include "DxLib.h"
#include "Game.h"

//-----------------------------------------------------------
// WinMain
//-----------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //---- �V�X�e���f�[�^�ǂݍ���
    SystemData::loadSystemData();
    SetGraphMode(                             // �E�B���h�E�ݒ�
        SystemData::getWindowWidth(),         // ��ʕ�
        SystemData::getWindowHeight(),        // ��ʍ���
        SystemData::getWindowColor());        // �g�p�J���[
    //---- �ݒ�
    ChangeWindowMode(TRUE);
    SetWindowText("�M�����Q");                // �^�C�g����
    if (DxLib_Init() == -1) { return -1; }    // DX���C�u����������
    if (SetDrawScreen(DX_SCREEN_BACK) != 0) { return -1; }  // �`���𗠉�ʂ�

    //----- �f�o�b�O�p�R���\�[��
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);

    //---- �Q�[������
    Game *game = new Game();
    game->init();
    game->mainLoop();
    game->end();
    delete(game);

    //---- �I������
    DxLib_End();
    return 0;
}
