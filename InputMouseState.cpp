//-----------------------------------------------------------
// InputMouseState.h
// �}�E�X�̓��͏��
// ����� 2014.03.01
// ����� motumotu
//-----------------------------------------------------------
#include "InputMouseState.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
InputMouseState::InputMouseState()
{
    init();   // ��������
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
InputMouseState::~InputMouseState()
{

}

//-----------------------------------------------------------
// ��������
//-----------------------------------------------------------
void InputMouseState::init()
{
    point_x = 0;
    point_y = 0;
    wheel = GetMouseWheelRotVol();
    for (int i = 0; i < CLICK_MAX; i++) {
        click[i] = 0;
    }
}

//-----------------------------------------------------------
// �X�V����
//-----------------------------------------------------------
void InputMouseState::update()
{
    // �}�E�X�z�C�[��
    wheel = GetMouseWheelRotVol();

    // �}�E�X�̍��W
    if (GetMousePoint(&point_x, &point_y) == -1) {
        return;
    }
    // �O�t���[���̃N���b�N���
    for (int i = 0; i < CLICK_MAX; i++) {
        pre_click[i] = click[i];
    }
    // �}�E�X�̃N���b�N���
    int MouseInput = GetMouseInput();
    for (int i = 0; i < CLICK_MAX; i++) {
        click[i] = (MouseInput & 1 << i) ? click[i] + 1 : 0;
    }
}

//===========================================================
// getter
//===========================================================
int InputMouseState::getMouseWheel() { return wheel; }
int InputMouseState::getPointX() { return point_x; }
int InputMouseState::getPointY() { return point_y; }
int InputMouseState::getClick(int n) {
    if (n - 1 < 0 || n - 1 >= CLICK_MAX) {
        puts("�͈͊O�Q�� InputMouseState::getClick(int)");
        return 0;
    }
    return click[n - 1];
}
int InputMouseState::getPreClick(int n) {
    if (n - 1 < 0 || n - 1 >= CLICK_MAX) {
        puts("�͈͊O�Q�� InputMouseState::getPreClick(int)");
        return 0;
    }
    return pre_click[n - 1];
}
bool InputMouseState::isRereaseClick(int n) {
    return (click[n - 1] == 0 && pre_click[n - 1] >= 1);
}