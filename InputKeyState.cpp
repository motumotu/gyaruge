//-----------------------------------------------------------
// InputKeyState.h
// キーボードの入力情報管理
// 制作日 2014.03.01
// 制作者 motumotu
//-----------------------------------------------------------
#include "InputKeyState.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
InputKeyState::InputKeyState()
{
    init();   // 初期処理
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
InputKeyState::~InputKeyState()
{

}

//-----------------------------------------------------------
// 初期処理
//-----------------------------------------------------------
void InputKeyState::init()
{
    for (int i = 0; i < KEY_MAX; i++) {
        key[i] = 0;
    }
}

//-----------------------------------------------------------
// 更新処理
//-----------------------------------------------------------
void InputKeyState::update()
{
    char tmp_key[KEY_MAX];

    GetHitKeyStateAll(tmp_key);
    for (int i = 0; i < KEY_MAX; i++) {
        key[i] = (tmp_key[i]) ? key[i] + 1 : 0;
    }
}

//===========================================================
// getter
//===========================================================
int InputKeyState::getKeyState(int n) {
    if (n < 0 || n >= KEY_MAX) {
        puts("範囲外参照  InputKeyState::getKeyState(int)");
        return 0;
    }
    return key[n];
}