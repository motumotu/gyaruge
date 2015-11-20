//-----------------------------------------------------------
// DrawSaveLoad.cpp
// �Z�[�u�E���[�h��ʂ̕`��
// ����� 2015.04.10
// ����� motumotu
//-----------------------------------------------------------
#include "DrawSaveLoad.h"

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
DrawSaveLoad::DrawSaveLoad(GameData* data, GameState* state)
{
    game_data = data;
    game_state = state;
    saveload_data = data->getSaveLoadData();
    saveload_state = state->getSceneState()->getSaveLoadState();
    font_time = CreateFontToHandle("MS�S�V�b�N", 16, 3, DX_FONTTYPE_ANTIALIASING);
    font_dialog = CreateFontToHandle("MS�S�V�b�N", 25, 3, DX_FONTTYPE_ANTIALIASING);
    color_font = GetColor(63, 56, 51);
    loadImage();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
DrawSaveLoad::~DrawSaveLoad()
{

}
//-----------------------------------------------------------
// ��������
//-----------------------------------------------------------
void DrawSaveLoad::init()
{

}

//-----------------------------------------------------------
// �摜�ǂݍ���
//-----------------------------------------------------------
void DrawSaveLoad::loadImage()
{
    handl_back = LoadGraph("image/save_load/save_load.png");
    //handl_base = LoadGraph("image/save_load/base.png");
    LoadDivGraph("image/save_load/button_num.png", SaveLoadData::SAVELOAD_BUTTON_NUM * 2,
        SaveLoadData::SAVELOAD_BUTTON_NUM, 2, 40, 40, handl_button_num);
    LoadDivGraph("image/save_load/base.png", 2, 1, 2,
        SaveLoadData::SAVELOAD_BASE_SIZE_X, SaveLoadData::SAVELOAD_BASE_SIZE_Y, handl_base);
    LoadDivGraph("image/save_load/button_back.png", 2, 2, 1, SaveLoadData::SAVELOAD_BUTTON_BACK_SIZE_X,
        SaveLoadData::SAVELOAD_BUTTON_BACK_SIZE_Y, handl_button_back);
    handl_logo_save = LoadGraph("image/save_load/logo_save.png");
    handl_logo_load = LoadGraph("image/save_load/logo_load.png");
    handl_below = LoadGraph("image/save_load/below.png");
    handl_nodata = LoadGraph("image/save_load/nodata.png");
    LoadDivGraph("image/save_load/button_close.png", 2, 2, 1,SaveLoadData::SAVELOAD_BUTTON_CLOSE_SIZE_X,
        SaveLoadData::SAVELOAD_BUTTON_CLOSE_SIZE_Y, handl_button_close);
    handl_dialog = LoadGraph("image/save_load/dialog_back.png");
    handl_dialog_yes[0] = LoadGraph("image/save_load/dialog_yes.png");
    handl_dialog_yes[1] = LoadGraph("image/save_load/dialog_yes2.png");
    handl_dialog_no[0] = LoadGraph("image/save_load/dialog_no.png");
    handl_dialog_no[1] = LoadGraph("image/save_load/dialog_no2.png");
}

//-----------------------------------------------------------
// �`��
//-----------------------------------------------------------
void DrawSaveLoad::draw()
{
    int image;
    //---- �w�i
    DrawGraph(0, 0, handl_back, TRUE);

    //---- �Z�[�u�f�[�^
    drawSaveData();
    DrawGraph(0, 0, handl_below, TRUE);

    //---- �Z�[�u�ꏊ�{�^��
    for (int i = 0; i < SaveLoadData::SAVELOAD_BUTTON_NUM; i++) {
        image = saveload_state->getImageButtonNum(i);
        DrawGraph(
            saveload_data->getPosButtonNumX(i),
            saveload_data->getPosButtonNumY(i),
            handl_button_num[image], TRUE);
    }
    //---- �߂�{�^��
    image = saveload_state->getImageButtonBack();
    DrawGraph(
        SaveLoadData::SAVELOAD_BUTTON_BACK_POS_X,
        SaveLoadData::SAVELOAD_BUTTON_BACK_POS_Y,
        handl_button_back[image], TRUE);
    //---- ���S
    image = (saveload_state->getMode() == SaveLoadState::SAVELOAD_MODE_SAVE) ? handl_logo_save : handl_logo_load;
    DrawGraph(10, 5, image, TRUE);

    //---- �_�C�A���O�`��
    if (saveload_state->isDialog()) {
        drawDialog();
    }
}

//-----------------------------------------------------------
// �Z�[�u�f�[�^�`��
//-----------------------------------------------------------
void DrawSaveLoad::drawSaveData()
{
    for (int i = 0; i < SaveLoadData::SAVELOAD_BASE_NUM; i++) {
        int n = i + saveload_state->getSelectNum() * SaveLoadData::SAVELOAD_BASE_NUM + 1;
        int px = saveload_data->getPosBaseX(i);
        int py = saveload_data->getPosBaseY(i);

        //---- �T���l�C��
        if (game_data->getSaveData()->getIsData(n)) {
            drawThumbnail(px + 5, py + 5, n);
        } else {
            DrawGraph(px + 5, py + 5, handl_nodata, TRUE);
        }
        // �x�[�X
        int image = saveload_state->getImageBase(n - 1);
        DrawGraph(px, py, handl_base[image], TRUE);
        DrawGraph(px, py + SaveLoadData::SAVELOAD_BASE_SIZE_Y, handl_below, TRUE);

        // ����{�^��
        if (game_data->getSaveData()->getIsData(n)) {
            int image = saveload_state->getImageButtonClose(n - 1);
            DrawGraph(
                px + SaveLoadData::SAVELOAD_BUTTON_CLOSE_POS_X,
                py + SaveLoadData::SAVELOAD_BUTTON_CLOSE_POS_Y,
                handl_button_close[image], TRUE);
        }
        // �T�u�^�C�g��
        // �e�L�X�g�ꕔ
        // �Z�[�u����
        DrawFormatStringToHandle(
            px + 315,
            py + 80,
            color_font,
            font_time,
            "%s %s",
            game_data->getSaveData()->getSaveDay(n).c_str(),
            game_data->getSaveData()->getSaveTime(n).c_str());
    }
}

//-----------------------------------------------------------
// �T���l�C���`��
//-----------------------------------------------------------
void DrawSaveLoad::drawThumbnail(int x, int y, int n)
{
    ImageData *image = game_data->getImageData();
    int pos = game_data->getSaveData()->getStoryPos(n);
    StoryTextData *data = game_data->getAllStoryTextData()->getStoryTextData(pos);

    //---- �w�i
    SetDrawMode(DX_DRAWMODE_BILINEAR);
    int bn = data->getBack();
    DrawExtendGraph(x, y, x + 150, y + 90, image->getBack(bn), TRUE);

    //---- �L����
    for (int n = 1; n <= data->getCharaNum(); n++) {
        int pos = data->getCharaPos(n);
        int image = data->getCharaImage(n);
        if (pos == 1) DrawExtendGraph(x + 22, y - 15, x + 139, y + 219, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 2) DrawExtendGraph(x + 38, y + 7, x + 111, y + 153, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 3) DrawExtendGraph(x + 9, y + 7, x + 82, y + 146, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 4) DrawExtendGraph(x + 77, y + 7, x + 150, y + 153, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 5) DrawExtendGraph(x + 55, y + 15, x + 98, y + 102, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 6) DrawExtendGraph(x + 4, y + 15, x + 55, y + 102, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 7) DrawExtendGraph(x + 102, y + 15, x + 146, y + 102, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 8) DrawExtendGraph(x + 28, y + 15, x + 72, y + 102, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 9) DrawExtendGraph(x + 78, y + 15, x + 121, y + 102, game_data->getImageData()->getChara(image), TRUE);
    }
    SetDrawMode(DX_DRAWMODE_NEAREST);
}

//-----------------------------------------------------------
// �_�C�A���O�`��
//-----------------------------------------------------------
void DrawSaveLoad::drawDialog()
{
    int image;
    int x = SaveLoadData::SAVELOAD_DIALOG_POS_X;
    int y = SaveLoadData::SAVELOAD_DIALOG_POS_Y;

    // �_�C�A���O
    DrawGraph(x, y, handl_dialog, TRUE);

    // YES
    image = (saveload_state->isPosDialogYes()) ? 1 : 0;
    DrawGraph(
        x + SaveLoadData::SAVELOAD_DIALOG_YES_POS_X,
        y + SaveLoadData::SAVELOAD_DIALOG_YES_POS_Y,
        handl_dialog_yes[image], TRUE);

    // NO
    image = (saveload_state->isPosDialogNo()) ? 1 : 0;
    DrawGraph(
        x + SaveLoadData::SAVELOAD_DIALOG_NO_POS_X,
        y + SaveLoadData::SAVELOAD_DIALOG_NO_POS_Y,
        handl_dialog_no[image], TRUE);

    // ���b�Z�[�W
    DrawFormatStringToHandle(
        x + 20,
        y + 20,
        color_font,
        font_dialog,
        "%s",
        saveload_state->getDialogText());

}