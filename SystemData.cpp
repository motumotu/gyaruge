//-----------------------------------------------------------
// SystemData.cpp
// システムデータ
// 制作日 2015.04.05
// 制作者 motumotu
//-----------------------------------------------------------
#include "SystemData.h"

int SystemData::window_width;      // 画面サイズ幅
int SystemData::window_height;     // 画面サイズ高さ
int SystemData::window_color;      // 使用カラー

//-----------------------------------------------------------
// システムデータ読み込み
//-----------------------------------------------------------
void SystemData::loadSystemData()
{
    std::string str;
    std::ifstream ifs("system/conf.dat");

    if (ifs.fail()) {
        std::cout << "conf.datの読み込みに失敗しました。" << std::endl;
        return;
    }
    while (getline(ifs, str)) {
        std::stringstream ss(str);
        ss >> str;
        //---- 画面幅
        if (str == "WINDOW_SIZE_WIDTH") {
            ss >> str;
            window_width = atoi(str.c_str());
        }
        //---- 画面高
        else if (str == "WINDOW_SIZE_HEIGHT") {
            ss >> str;
            window_height = atoi(str.c_str());
        }
        //---- 使用カラー数
        else if (str == "WINDOW_USE_COLOR") {
            ss >> str;
            window_color = atoi(str.c_str());
        }
    }
}

//===========================================================
// getter
//===========================================================
int SystemData::getWindowWidth() { return window_width; }
int SystemData::getWindowHeight() { return window_height; }
int SystemData::getWindowColor() { return window_color; }
