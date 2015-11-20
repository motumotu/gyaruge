//-----------------------------------------------------------
// GameData.h
// �Q�[���̃f�[�^��
// ����� 2015.04.05
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "SystemData.h"
#include "TitleData.h"
#include "AllStoryTextData.h"
#include "StoryData.h"
#include "SaveLoadData.h"
#include "SaveData.h"
#include "ImageData.h"

class GameData {
private:
    TitleData *title_data;             // �^�C�g����ʂ̃f�[�^
    AllStoryTextData *all_story_text_data; // �e�L�X�g�f�[�^
    StoryData *story_data;             // �X�g�[���[��ʂ̃f�[�^
    SaveLoadData *saveload_data;       // �Z�[�u���[�h��ʂ̃f�[�^
    SaveData *save_data;               // �Z�[�u�f�[�^
    ImageData *image_data;             // �摜�f�[�^

public:
    GameData();                        // �R���X�g���N�^
    ~GameData();                       // �f�X�g���N�^
    TitleData *getTitleData();         // �^�C�g���f�[�^�擾
    AllStoryTextData *getAllStoryTextData(); // �e�L�X�g�f�[�^�擾
    StoryData *getStoryData();         // �X�g�[���[�f�[�^�擾
    SaveLoadData *getSaveLoadData();   // �Z�[�u���[�h��ʂ̃f�[�^�擾
    SaveData *getSaveData();           // �Z�[�u�f�[�^�擾
    ImageData *getImageData();         // �摜�f�[�^�擾
};