//-----------------------------------------------------------
// DrawStory.cpp
// ストーリー画面の描画
// 制作日 2015.03.17
// 制作者 motumotu
//-----------------------------------------------------------
#include "DrawStory.h"

//-----------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------
DrawStory::DrawStory(GameData *data, GameState *state)
{
    game_state = state;
    game_data = data;
    story_state = state->getSceneState()->getStoryState();
    story_data = data->getStoryData();
    font = CreateFontToHandle("MSゴシック", 22, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
    font_name = CreateFontToHandle("MSゴシック", 28, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
    font_name_e = CreateFontToHandle("MSゴシック", 16, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
    color_white = GetColor(255, 255, 255);
    color_gray = GetColor(240, 240, 240);
    color_scrollbar = GetColor(240, 240, 240);
    loadImage();
    init();
}

//-----------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------
DrawStory::~DrawStory()
{

}

//-----------------------------------------------------------
// 初期化
//-----------------------------------------------------------
void DrawStory::init()
{
    //SetDrawValidMultiSample(4, 2);
}

//-----------------------------------------------------------
// 更新
//-----------------------------------------------------------
void DrawStory::update()
{

}

//-----------------------------------------------------------
// 画像読み込み
//-----------------------------------------------------------
void DrawStory::loadImage()
{
    handl_window = LoadGraph("image/story/window.png");
    LoadDivGraph("image/story/button_auto.png", 3, 3, 1,
        StoryData::STORY_BUTTON_SIZE_X, StoryData::STORY_BUTTON_SIZE_Y, handl_button_auto);
    LoadDivGraph("image/story/button_skip.png", 3, 3, 1,
        StoryData::STORY_BUTTON_SIZE_X, StoryData::STORY_BUTTON_SIZE_Y, handl_button_skip);
    LoadDivGraph("image/story/button_log.png", 3, 3, 1,
        StoryData::STORY_BUTTON_SIZE_X, StoryData::STORY_BUTTON_SIZE_Y, handl_button_log);
    LoadDivGraph("image/story/button_conf.png", 3, 3, 1,
        StoryData::STORY_BUTTON_SIZE_X, StoryData::STORY_BUTTON_SIZE_Y, handl_button_conf);
    LoadDivGraph("image/story/button_save.png", 3, 3, 1,
        StoryData::STORY_BUTTON_SIZE_X, StoryData::STORY_BUTTON_SIZE_Y, handl_button_save);
    LoadDivGraph("image/story/button_load.png", 3, 3, 1,
        StoryData::STORY_BUTTON_SIZE_X, StoryData::STORY_BUTTON_SIZE_Y, handl_button_load);
    LoadDivGraph("image/story/button_close.png", 2, 2, 1,
        StoryData::STORY_BUTTON_CLOSE_SIZE_X, StoryData::STORY_BUTTON_CLOSE_SIZE_Y, handl_button_close);
    handl_backlog_back = LoadGraph("image/story/backlog_back.png");
    handl_scroll_bar = LoadGraph("image/story/scroll_bar.png");
    // バックログ上に
    LoadDivGraph("image/story/backlog_button_up.png", 2, 2, 1,
        StoryData::STORY_SCROLLBAR_BUTTON_SIZE_X, StoryData::STORY_SCROLLBAR_BUTTON_SIZE_Y, handl_backlog_up);
    // バックログ下に
    LoadDivGraph("image/story/backlog_button_down.png", 2, 2, 1,
        StoryData::STORY_SCROLLBAR_BUTTON_SIZE_X, StoryData::STORY_SCROLLBAR_BUTTON_SIZE_Y, handl_backlog_down);
   // exitボタン
    LoadDivGraph("image/story/backlog_button_exit.png", 2, 1, 2,
        StoryData::STORY_BACKLOG_BUTTON_EXIT_SIZE_X, StoryData::STORY_BACKLOG_BUTTON_EXIT_SIZE_Y, handl_backlog_exit);
}

//-----------------------------------------------------------
// 描画
//-----------------------------------------------------------
void DrawStory::draw()
{
    //---- 背景描画
    int image = story_state->getNowBack();
    DrawGraph(0, 0, game_data->getImageData()->getBack(image), TRUE);

    //---- キャラ描画
    if (story_state->getWhatDraw() == StoryState::STORY_DRAW_CHARA) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - story_state->getCharaAlpha());
        drawChara(1);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, story_state->getCharaAlpha());
        drawChara(2);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        drawChara(0);
    }
    else {
        drawChara(0);
    }
    //---- ウィンドウ
    if (!story_state->isClose() && !story_state->isBacklog()) {
        drawWindow();
    }
    //---- バックログ
    if (story_state->isBacklog()) {
        drawBacklog();
    }
}

//-----------------------------------------------------------
// ウィンドウ描画
//-----------------------------------------------------------
void DrawStory::drawWindow()
{
    //----- ウィンドウ描画
    DrawGraph(
        StoryData::TEXT_WINDOW_POS_X,
        StoryData::TEXT_WINDOW_POS_Y,
        handl_window, TRUE);

    //---- テキスト描画
    drawNowText();

    //---- ボタン描画
    int obj = story_state->getMousePosObject();
    int image;
    // オートボタン
    image = story_state->getImageButtonAuto();
    DrawGraph(
        story_data->getPosButtonAutoX(),
        story_data->getPosButtonAutoY(),
        handl_button_auto[image], TRUE);
    // スキップボタン
    image = story_state->getImageButtonSkip();
    DrawGraph(
        story_data->getPosButtonSkipX(),
        story_data->getPosButtonSkipY(),
        handl_button_skip[image], TRUE);
    // ログボタン
    image = story_state->getImageButtonLog();
    DrawGraph(
        story_data->getPosButtonLogX(),
        story_data->getPosButtonLogY(),
        handl_button_log[image], TRUE);
    // コンフィグボタン
    image = story_state->getImageButtonConf();
    DrawGraph(
        story_data->getPosButtonConfX(),
        story_data->getPosButtonConfY(),
        handl_button_conf[image], TRUE);
    // セーブボタン
    image = story_state->getImageButtonSave();
    DrawGraph(
        story_data->getPosButtonSaveX(),
        story_data->getPosButtonSaveY(),
        handl_button_save[image], TRUE);
    // ロードボタン
    image = story_state->getImageButtonLoad();
    DrawGraph(
        story_data->getPosButtonLoadX(),
        story_data->getPosButtonLoadY(),
        handl_button_load[image], TRUE);
    // 閉じるボタン
    image = story_state->getImageButtonClose();
    DrawGraph(
        story_data->getPosButtonCloseX(),
        story_data->getPosButtonCloseY(),
        handl_button_close[image], TRUE);
}

//-----------------------------------------------------------
// テキスト描画
//-----------------------------------------------------------
void DrawStory::drawNowText()
{
    int x = StoryData::TEXT_AREA_POS_X;
    int y = StoryData::TEXT_AREA_POS_Y;
    //---- 名前
    if (story_state->getNowName() != "") {
        DrawFormatStringToHandle(40, y - 20, color_white, font_name, "%s", story_state->getNowName().c_str());
        DrawFormatStringToHandle(30, y + 10, color_white,font_name_e, story_state->getNowEName().c_str());
    }
    //---- テキスト
    DrawFormatStringToHandle(x, y - 15, color_white, font, "%s", story_state->getNowText1().c_str());
    DrawFormatStringToHandle(x, y + 20, color_white, font, "%s", story_state->getNowText2().c_str());
    DrawFormatStringToHandle(x, y + 55, color_white, font, "%s", story_state->getNowText3().c_str());
}

//-----------------------------------------------------------
// キャラ描画
//-----------------------------------------------------------
void DrawStory::drawChara(int pre)
{
    // 0 変更なしの画像 そのまま
    // 1 変更前の画像 消す
    // 2 変更後の画像 出す

    int n = story_state->getNowTextNum() - 1;
    if (pre == 1 && game_data->getAllStoryTextData()->getStoryTextData(n)->getFade() > 0) return;

    SetDrawMode(DX_DRAWMODE_BILINEAR);
    for (int n = 1; n <= ((pre == 1) ? story_state->getPreCharaNum() : story_state->getNowCharaNum()); n++) {
        int pos = (pre == 1) ? story_state->getPreCharaPos(n) : story_state->getNowCharaPos(n);
        int image = (pre == 1) ? story_state->getPreCharaImage(n) : story_state->getNowCharaImage(n);
        int text_num = story_state->getNowTextNum();

        if (pre == 0 && story_state->getWhatDraw() == StoryState::STORY_DRAW_CHARA &&
            !game_data->getAllStoryTextData()->isPreCharaEqual(text_num, image, pos)) continue;
        if (pre == 1 && game_data->getAllStoryTextData()->isNowCharaEqual(text_num, image, pos)) continue;
        if (pre == 2 && game_data->getAllStoryTextData()->isPreCharaEqual(text_num, image, pos)) continue;

        // キャラ描画
        if (pos == 1) DrawGraph(112, -100, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 2) DrawExtendGraph(262, 50, 762, 1050, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 3) DrawExtendGraph(62, 50, 562, 1050, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 4) DrawExtendGraph(462, 50, 962, 1050, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 5) DrawExtendGraph(374, 100, 674, 700, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 6) DrawExtendGraph(24, 100, 324, 700, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 7) DrawExtendGraph(700, 100, 1000, 700, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 8) DrawExtendGraph(193, 100, 493, 700, game_data->getImageData()->getChara(image), TRUE);
        else if (pos == 9) DrawExtendGraph(531, 100, 831, 700, game_data->getImageData()->getChara(image), TRUE);
    }
    SetDrawMode(DX_DRAWMODE_NEAREST);
}

//-----------------------------------------------------------
// バックログ描画
//-----------------------------------------------------------
void DrawStory::drawBacklog()
{
    //---- 背景
    DrawGraph(0, 0, handl_backlog_back, TRUE);

    //---- テキスト
    int text_num = story_state->getBacklogPos();
    // 1
    int p1 = text_num - 2;
    if (text_num == 1) p1 = 1;
    if (text_num == 2) p1 = 1;
    drawTextPos(p1, 230, 140);
    // 2
    int p2 = text_num - 1;
    if (text_num == 1) p2 = 0;
    if (text_num == 2) p2 = 2;
    if (p2 > 0) {
        drawTextPos(p2, 230, 290);
    }
    // 3
    int p3 = text_num;
    if (text_num <= 2) p3 = 0;
    if (p3 > 0) {
        drawTextPos(p3, 230, 440);
    }
    //---- スクロールバー
    drawScrollbar();
}

void DrawStory::drawTextPos(int n, int x, int y)
{
    StoryTextData *text_data = game_data->getAllStoryTextData()->getStoryTextData(n);
    if (text_data->getName() != "") {
        DrawFormatStringToHandle(x - 15, y - 45, color_gray, font, "【%s】", text_data->getName().c_str());
    }
    DrawFormatStringToHandle(x, y - 15, color_gray, font, "%s", text_data->getText1().c_str());
    DrawFormatStringToHandle(x, y + 20, color_gray, font, "%s", text_data->getText2().c_str());
    DrawFormatStringToHandle(x, y + 55, color_gray, font, "%s", text_data->getText3().c_str());
}

//-----------------------------------------------------------
// バックログ描画
//-----------------------------------------------------------
void DrawStory::drawScrollbar()
{
    int image;

    //---- エリア
    DrawGraph(
        StoryData::STORY_SCROLLBAR_AREA_POS_X,
        StoryData::STORY_SCROLLBAR_AREA_POS_Y,
        handl_scroll_bar, TRUE);

    //---- バー
    if (story_state->getNowTextNum() > 3) {
        int x = StoryData::STORY_SCROLLBAR_AREA_POS_X + 1;
        int y = story_state->getScrollbarPos() + 1;
        int size_x = StoryData::STORY_SCROLLBAR_AREA_SIZE_X - 2;
        int size_y = story_state->getScrollbarSize();
        DrawBox(x, y, x + size_x, y + size_y, color_scrollbar, TRUE);
    }
    // 上
    image = story_state->getImageBacklogButtonUp();
    DrawGraph(
        StoryData::STORY_SCROLLBAR_BUTTON_UP_POS_X,
        StoryData::STORY_SCROLLBAR_BUTTON_UP_POS_Y,
        handl_backlog_up[image], TRUE);
    // 下
    image = story_state->getImageBacklogButtonDown();
    DrawGraph(
        StoryData::STORY_SCROLLBAR_BUTTON_DOWN_POS_X,
        StoryData::STORY_SCROLLBAR_BUTTON_DOWN_POS_Y,
        handl_backlog_down[image], TRUE);
    //---- exitボタン
    image = story_state->getImageBacklogButtonExit();
    DrawGraph(
        StoryData::STORY_BACKLOG_BUTTON_EXIT_POS_X,
        StoryData::STORY_BACKLOG_BUTTON_EXIT_POS_Y,
        handl_backlog_exit[image], TRUE);
}

//===========================================================
// getter
//===========================================================