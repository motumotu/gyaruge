//-----------------------------------------------------------
// GameData.cpp
// ゲームのデータ部
// 制作日 2015.04.05
// 制作者 motumotu
//-----------------------------------------------------------
#include "GameData.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
GameData::GameData()
{
    title_data = new TitleData();
    all_story_text_data = new AllStoryTextData();
    story_data = new StoryData();
    saveload_data = new SaveLoadData();
    save_data = new SaveData();
    image_data = new ImageData();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
GameData::~GameData()
{
    delete(image_data);
    delete(saveload_data);
    delete(story_data);
    delete(all_story_text_data);
    delete(title_data);
    delete(save_data);
}

//===========================================================
// getter
//===========================================================
TitleData *GameData::getTitleData() { return title_data; }
AllStoryTextData *GameData::getAllStoryTextData() { return all_story_text_data; }
StoryData *GameData::getStoryData() { return story_data; }
SaveLoadData *GameData::getSaveLoadData() { return saveload_data; }
SaveData *GameData::getSaveData() { return save_data; }
ImageData *GameData::getImageData() { return image_data; }