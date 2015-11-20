//-----------------------------------------------------------
// StoryState.h
// �X�g�[���[�̏��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#include "StoryState.h"

//-----------------------------------------------------------
// �萔
//-----------------------------------------------------------
const int StoryState::STORY_OBJ_NONE = 0;
const int StoryState::STORY_OBJ_BUTTON_AUTO = 1;
const int StoryState::STORY_OBJ_BUTTON_SKIP = 2;
const int StoryState::STORY_OBJ_BUTTON_LOG = 3;
const int StoryState::STORY_OBJ_BUTTON_CONF = 4;
const int StoryState::STORY_OBJ_BUTTON_SAVE = 5;
const int StoryState::STORY_OBJ_BUTTON_LOAD = 6;
const int StoryState::STORY_OBJ_BUTTON_CLOSE = 7;
const int StoryState::STORY_OBJ_BACKLOG_BUTTON_UP = 8;
const int StoryState::STORY_OBJ_BACKLOG_BUTTON_DOWN = 9;
const int StoryState::STORY_OBJ_BACKLOG_BUTTON_EXIT = 10;
const int StoryState::STORY_OBJ_BACKLOG_AREA = 11;

const int StoryState::STORY_DRAW_CHARA = 0;
const int StoryState::STORY_DRAW_TEXT = 1;

//-----------------------------------------------------------
// �R���X�g���N�^
//-----------------------------------------------------------
StoryState::StoryState(GameData *data)
{
    game_data = data;
    story_data = data->getStoryData();
    init();
}

//-----------------------------------------------------------
// �f�X�g���N�^
//-----------------------------------------------------------
StoryState::~StoryState()
{

}

//-----------------------------------------------------------
// ������
//-----------------------------------------------------------
void StoryState::init()
{
    mouse_x = 0;
    mouse_y = 0;
    now_text_num = 1;
    cnt_frame = 0;
    now_text_len = 0;
    is_draw_end = false;
    is_close = false;
    is_auto = false;
    is_skip = false;
    is_backlog = false;
    what_draw = STORY_DRAW_CHARA;
    chara_alpha = 0;
    backlog_pos = 1;
    is_fade = false;
}

//-----------------------------------------------------------
// �X�V
//-----------------------------------------------------------
void StoryState::update()
{
    int auto_time = 100;
    cnt_frame++;

    // �t�F�[�h��
    if (is_fade) {
        return;
    }
    // �X�L�b�v���[�h��
    if (is_skip) {
        // �`��I�����͎��̕���
        if (isDrawEnd()) {
            // ���̕�������Ȃ玟�̕���
            if (getNowStoryTextData()->getNextNum() != 0 && cnt_frame >= 5) {
                changeNextText();
            }
        }
        // �`�撆�Ȃ�S���\��
        else {
            fullText();
        }
    }
    // �`��I�����Ă��Ȃ��Ȃ�e�L�X�g�X�V
    if (what_draw == STORY_DRAW_TEXT && is_draw_end == false) {
        now_text_len += isJapaneseCharacter(getNowText()[now_text_len]);
        if (now_text_len >= (int)getNowText().length()) fullText();
    }
    // �L�����\����
    if (what_draw == STORY_DRAW_CHARA) {
        chara_alpha += 10;
        if (chara_alpha >= 255) {
            chara_alpha = 255;
            what_draw = STORY_DRAW_TEXT;
        }
    }
    // �I�[�g�̂Ƃ��A���̕��ɍs��������
    if (is_auto == true && is_draw_end == true && cnt_frame >= auto_time) {
        // ���̕�������Ȃ玟�̕���
        if (getNowStoryTextData()->getNextNum() != 0) {
            changeNextText();
        }
    }
}

//-----------------------------------------------------------
// �}�E�X���W�X�V
//-----------------------------------------------------------
void StoryState::updateMousePos(int x, int y)
{
    mouse_x = x;
    mouse_y = y;
}

//-----------------------------------------------------------
// ���{�ꂩ�ǂ���
//-----------------------------------------------------------
int StoryState::isJapaneseCharacter(unsigned char code)
{
    // shift_jis�Ȃ�1
    if ((code >= 0x81 && code <= 0x9F) ||
        (code >= 0xE0 && code <= 0xFC)) {
        return 2;
    }
    return 1;
}

//-----------------------------------------------------------
// �S���\��
//-----------------------------------------------------------
void StoryState::fullText()
{
    is_draw_end = true;
    cnt_frame = 0;
    now_text_len = getNowText().length();
    chara_alpha = 255;
    what_draw = STORY_DRAW_TEXT;
}

//-----------------------------------------------------------
// ���̃e�L�X�g��
//-----------------------------------------------------------
void StoryState::changeNextText()
{
    // �t�F�[�h�Ȃ�܂�
    if (getNowStoryTextData()->getFade() > 0 && is_fade == false) {
        is_fade = true;
        return;
    }
    now_text_num = getNowStoryTextData()->getNextNum();
    backlog_pos = now_text_num;
    now_text_len = 0;
    cnt_frame = 0;
    is_draw_end = false;
    what_draw = STORY_DRAW_CHARA;
    chara_alpha = 0;
    // �摜�E�ꏊ���ꏏ�Ȃ炻�̂܂�
    if (game_data->getAllStoryTextData()->isPreAllCharaEqual(now_text_num)) {
        what_draw = STORY_DRAW_TEXT;
        chara_alpha = 255;
    }
}

//-----------------------------------------------------------
// �w��e�L�X�g�ύX
//-----------------------------------------------------------
void StoryState::changeText(int n)
{
    now_text_num = n;
    backlog_pos = now_text_num;
    now_text_len = 0;
    cnt_frame = 0;
    is_draw_end = false;
    what_draw = STORY_DRAW_CHARA;
    chara_alpha = 0;
    // �摜�E�ꏊ���ꏏ�Ȃ炻�̂܂�
    if (game_data->getAllStoryTextData()->isPreAllCharaEqual(now_text_num)) {
        what_draw = STORY_DRAW_TEXT;
        chara_alpha = 255;
    }
}

//-----------------------------------------------------------
// �o�b�N���O
//-----------------------------------------------------------
bool StoryState::downBacklogPos()
{
    backlog_pos++;
    scrollBarAdjustment();
    if (backlog_pos > now_text_num) {
        backlog_pos = now_text_num;
        scrollBarAdjustment();
        return true;
    }
    return false;
}

void StoryState::upBacklogPos()
{
    if (backlog_pos <= 3) return;
    backlog_pos--;
    if (backlog_pos <= 3) backlog_pos = 3;
    scrollBarAdjustment();
}
// �o�b�N���O�����
void StoryState::closeBacklog()
{
    backlog_pos = now_text_num;
    setIsBacklog(false);
}
// �o�b�N���O���I�[�v��
void StoryState::openBacklog()
{
    backlog_pos = now_text_num;
    scrollBarAdjustment();
    setIsBacklog(true);
}

//-----------------------------------------------------------
// �X�N���[���o�[
//-----------------------------------------------------------
int StoryState::getScrollbarPos()
{
    return scrollbar_pos;
}
int StoryState::getScrollbarSize()
{
    if (now_text_num < 10) return 400;
    if (now_text_num < 20) return 300;
    return 50;
}
// �X�N���[���o�[�̒���
void StoryState::scrollBarAdjustment()
{
    if (now_text_num <= 3) return;
    int y = StoryData::STORY_SCROLLBAR_AREA_POS_Y;
    double rat = (double)(backlog_pos - 3) / (now_text_num - 3);
    int sz = StoryData::STORY_SCROLLBAR_AREA_SIZE_Y - getScrollbarSize() - 2;
    scrollbar_pos = (int)(y + sz * rat);
}

// �}�E�X���W�̈ʒu�ɃX�N���[���o�[�𒲐�
void StoryState::scrollBarAdjustmentMousePos()
{
    if (now_text_num <= 3) return;

    scrollbar_pos = mouse_y - getScrollbarSize() / 2;
    int max_pos = StoryData::STORY_SCROLLBAR_AREA_POS_Y + 1;
    max_pos += StoryData::STORY_SCROLLBAR_AREA_SIZE_Y - 3;
    max_pos -= getScrollbarSize();

    // ��ɍs���߂���
    if (scrollbar_pos <= StoryData::STORY_SCROLLBAR_AREA_POS_Y) {
        scrollbar_pos = StoryData::STORY_SCROLLBAR_AREA_POS_Y;
    }
    // ���ɍs���߂���
    if (scrollbar_pos >= max_pos) {
        scrollbar_pos = max_pos;
    }
    // �ʒu����
    int p1 = (scrollbar_pos - (StoryData::STORY_SCROLLBAR_AREA_POS_Y));
    int p2 = StoryData::STORY_SCROLLBAR_AREA_SIZE_Y - getScrollbarSize() - 2;
    if (p2 == 0) backlog_pos = 3;
    else backlog_pos = (int)((double)p1 / p2 * (now_text_num - 3)) + 3;
    if (backlog_pos < 3) backlog_pos = 3;
}

//-----------------------------------------------------------
// �e�L�X�g�f�[�^�擾
//-----------------------------------------------------------
std::string StoryState::getNowName()
{
    if (what_draw == STORY_DRAW_CHARA) return "";
    return getNowStoryTextData()->getName();
}
// �p�ꖼ
std::string StoryState::getNowEName()
{
    if (what_draw == STORY_DRAW_CHARA) return "";
    return getNowStoryTextData()->getEName();
}
std::string StoryState::getNowText1()
{
    int len1 = (int)getNowStoryTextData()->getText1().length();
    if (now_text_len >= len1) {
        return getNowStoryTextData()->getText1();
    }
    return getNowStoryTextData()->getText1().substr(0, now_text_len);
}
std::string StoryState::getNowText2()
{
    int len1 = (int)getNowStoryTextData()->getText1().length();
    int len2 = (int)getNowStoryTextData()->getText2().length();
    if (now_text_len >= len1 + len2) {
        return getNowStoryTextData()->getText2();
    }
    else if (now_text_len <= len1) {
        return "";
    }
    return getNowStoryTextData()->getText2().substr(0, now_text_len - len1);
}
std::string StoryState::getNowText3()
{
    int len1 = (int)getNowStoryTextData()->getText1().length();
    int len2 = (int)getNowStoryTextData()->getText2().length();
    int len3 = (int)getNowStoryTextData()->getText3().length();
    if (now_text_len >= len1 + len2 + len3) {
        return getNowStoryTextData()->getText3();
    }
    else if (now_text_len <= len1 + len2) {
        return "";
    }
    return getNowStoryTextData()->getText3().substr(0, now_text_len - len1 - len2);
}
int StoryState::getNowCharaNum() {
    return getNowStoryTextData()->getCharaNum();
}
int StoryState::getNowCharaPos(int n) {
    return getNowStoryTextData()->getCharaPos(n);
}
int StoryState::getNowCharaImage(int n) {
    return getNowStoryTextData()->getCharaImage(n);
}
int StoryState::getNowBack() {
    return getNowStoryTextData()->getBack();
}
// �O
int StoryState::getPreCharaNum() {
    return getPreStoryTextData()->getCharaNum();
}
int StoryState::getPreCharaPos(int n) {
    return getPreStoryTextData()->getCharaPos(n);
}
int StoryState::getPreCharaImage(int n) {
    return getPreStoryTextData()->getCharaImage(n);
}

//-----------------------------------------------------------
//  �{�^���̃N���b�N
//-----------------------------------------------------------
void StoryState::clickNone()
{
    // �E�B���h�E�����Ă��鎞
    if (isClose()) {
        setIsClose(false);
    }
    // �I�[�g���[�h��
    else if (isAuto()) {
        setIsAuto(false);
    }
    // �X�L�b�v���[�h��
    else if (isSkip()) {
        setIsSkip(false);
    }
    // �`��I�����͎��̕���
    else if (isDrawEnd()) {
        // ���̕�������Ȃ玟�̕���
        if (getNowStoryTextData()->getNextNum() != 0) {
            changeNextText();
        }
    }
    // �`�撆�Ȃ�S���\��
    else {
        fullText();
    }
}
// ����{�^���̃N���b�N
void StoryState::clickButtonClose()
{
    setIsClose(true);
}
// �I�[�g�{�^���̃N���b�N
void StoryState::clickButtonAuto()
{
    setIsAuto(true);
}
// �X�L�b�v�{�^���̃N���b�N
void StoryState::clickButtonSkip()
{
    setIsSkip(true);
}
// ���O�{�^���̃N���b�N
void StoryState::clickButtonLog()
{
    openBacklog();
}
// �R���t�B�O�{�^���̃N���b�N
void StoryState::clickButtonConf()
{

}
// �Z�[�u�{�^���̃N���b�N
void StoryState::clickButtonSave()
{

}
// ���[�h�{�^���̃N���b�N
void StoryState::clickButtonLoad()
{

}
// ��{�^��
void StoryState::clickBacklogButtonUp()
{
    upBacklogPos();
}
// ���{�^��
void StoryState::clickBacklogButtonDown()
{
    downBacklogPos();
}
// EXIT�{�^��
void StoryState::clickBacklogButtonExit()
{
    closeBacklog();
}

//-----------------------------------------------------------
// �}�E�X���W�̕��̎擾
//-----------------------------------------------------------
int StoryState::getMousePosObject()
{
    if (isPosButtonAuto() && !isClose() && !isAuto() && !isSkip() && !isBacklog())
        return STORY_OBJ_BUTTON_AUTO;
    if (isPosButtonSkip() && !isClose() && !isAuto() && !isSkip() && !isBacklog())
        return STORY_OBJ_BUTTON_SKIP;
    if (isPosButtonLog() && !isClose() && !isAuto() && !isSkip() && !isBacklog())
        return STORY_OBJ_BUTTON_LOG;
    if (isPosButtonConf() && !isClose() && !isAuto() && !isSkip() && !isBacklog())
        return STORY_OBJ_BUTTON_CONF;
    if (isPosButtonSave() && !isClose() && !isAuto() && !isSkip() && !isBacklog())
        return STORY_OBJ_BUTTON_SAVE;
    if (isPosButtonLoad() && !isClose() && !isAuto() && !isSkip() && !isBacklog())
        return STORY_OBJ_BUTTON_LOAD;
    if (isPosButtonClose() && !isClose() && !isAuto() && !isSkip() && !isBacklog())
        return STORY_OBJ_BUTTON_CLOSE;
    if (isPosBacklogButtonUp() && isBacklog()) return STORY_OBJ_BACKLOG_BUTTON_UP;
    if (isPosBacklogButtonDown() && isBacklog()) return STORY_OBJ_BACKLOG_BUTTON_DOWN;
    if (isPosBacklogButtonExit() && isBacklog()) return STORY_OBJ_BACKLOG_BUTTON_EXIT;
    if (isPosBacklogArea() && isBacklog()) return STORY_OBJ_BACKLOG_AREA;
    return STORY_OBJ_NONE;
}
bool StoryState::isPosButtonAuto() {
    int px = story_data->getPosButtonAutoX();
    int py = story_data->getPosButtonAutoY();
    int sx = StoryData::STORY_BUTTON_SIZE_X;
    int sy = StoryData::STORY_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosButtonSkip() {
    int px = story_data->getPosButtonSkipX();
    int py = story_data->getPosButtonSkipY();
    int sx = StoryData::STORY_BUTTON_SIZE_X;
    int sy = StoryData::STORY_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosButtonLog() {
    int px = story_data->getPosButtonLogX();
    int py = story_data->getPosButtonLogY();
    int sx = StoryData::STORY_BUTTON_SIZE_X;
    int sy = StoryData::STORY_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosButtonConf() {
    int px = story_data->getPosButtonConfX();
    int py = story_data->getPosButtonConfY();
    int sx = StoryData::STORY_BUTTON_SIZE_X;
    int sy = StoryData::STORY_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosButtonSave() {
    int px = story_data->getPosButtonSaveX();
    int py = story_data->getPosButtonSaveY();
    int sx = StoryData::STORY_BUTTON_SIZE_X;
    int sy = StoryData::STORY_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosButtonLoad() {
    int px = story_data->getPosButtonLoadX();
    int py = story_data->getPosButtonLoadY();
    int sx = StoryData::STORY_BUTTON_SIZE_X;
    int sy = StoryData::STORY_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosButtonClose() {
    int px = story_data->getPosButtonCloseX();
    int py = story_data->getPosButtonCloseY();
    int sx = StoryData::STORY_BUTTON_CLOSE_SIZE_X;
    int sy = StoryData::STORY_BUTTON_CLOSE_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosBacklogButtonUp() {
    int px = StoryData::STORY_SCROLLBAR_BUTTON_UP_POS_X;
    int py = StoryData::STORY_SCROLLBAR_BUTTON_UP_POS_Y;
    int sx = StoryData::STORY_SCROLLBAR_BUTTON_SIZE_X;
    int sy = StoryData::STORY_SCROLLBAR_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosBacklogButtonDown() {
    int px = StoryData::STORY_SCROLLBAR_BUTTON_DOWN_POS_X;
    int py = StoryData::STORY_SCROLLBAR_BUTTON_DOWN_POS_Y;
    int sx = StoryData::STORY_SCROLLBAR_BUTTON_SIZE_X;
    int sy = StoryData::STORY_SCROLLBAR_BUTTON_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosBacklogButtonExit() {
    int px = StoryData::STORY_BACKLOG_BUTTON_EXIT_POS_X;
    int py = StoryData::STORY_BACKLOG_BUTTON_EXIT_POS_Y;
    int sx = StoryData::STORY_BACKLOG_BUTTON_EXIT_SIZE_X;
    int sy = StoryData::STORY_BACKLOG_BUTTON_EXIT_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}
bool StoryState::isPosBacklogArea() {
    int px = StoryData::STORY_SCROLLBAR_AREA_POS_X;
    int py = StoryData::STORY_SCROLLBAR_AREA_POS_Y;
    int sx = StoryData::STORY_SCROLLBAR_AREA_SIZE_X;
    int sy = StoryData::STORY_SCROLLBAR_AREA_SIZE_Y;
    return (mouse_x >= px && mouse_x <= px + sx && mouse_y >= py && mouse_y <= py + sy);
}

//-----------------------------------------------------------
// �摜�擾
//-----------------------------------------------------------
int StoryState::getImageButtonAuto() {
    if (isAuto()) return 1;
    if (isSkip()) return 2;
    if (isPosButtonAuto()) return 1;
    return 0;
}
int StoryState::getImageButtonSkip() {
    if (isAuto()) return 2;
    if (isSkip()) return 1;
    if (isPosButtonSkip()) return 1;
    return 0;
}
int StoryState::getImageButtonLog() {
    if (isAuto()) return 2;
    if (isSkip()) return 2;
    if (isPosButtonLog()) return 1;
    return 0;
}
int StoryState::getImageButtonConf() {
    if (isAuto()) return 2;
    if (isSkip()) return 2;
    if (isPosButtonConf()) return 1;
    return 0;
}
int StoryState::getImageButtonSave() {
    if (isAuto()) return 2;
    if (isSkip()) return 2;
    if (isPosButtonSave()) return 1;
    return 0;
}
int StoryState::getImageButtonLoad() {
    if (isAuto()) return 2;
    if (isSkip()) return 2;
    if (isPosButtonLoad()) return 1;
    return 0;
}
int StoryState::getImageButtonClose() {
    if (isAuto()) return 0;
    if (isSkip()) return 0;
    if (isPosButtonClose()) return 1;
    return 0;
}
int StoryState::getImageBacklogButtonUp() {
    if (isPosBacklogButtonUp()) return 1;
    return 0;
}
int StoryState::getImageBacklogButtonDown() {
    if (isPosBacklogButtonDown()) return 1;
    return 0;
}
int StoryState::getImageBacklogButtonExit() {
    if (isPosBacklogButtonExit()) return 1;
    return 0;
}
//===========================================================
// setter
//===========================================================
void StoryState::setNowTextNum(int num) { now_text_num = num; }
void StoryState::setIsClose(bool n) { is_close = n; }
void StoryState::setIsAuto(bool n) { is_auto = n; }
void StoryState::setIsSkip(bool n) { is_skip = n; }
void StoryState::setIsBacklog(bool n) { is_backlog = n; }
void StoryState::setIsFade(bool n) { is_fade = n; }

//===========================================================
// getter
//===========================================================
int StoryState::getNowTextNum() { return now_text_num; }
StoryTextData *StoryState::getNowStoryTextData() {
    return game_data->getAllStoryTextData()->getStoryTextData(now_text_num);
}
StoryTextData *StoryState::getPreStoryTextData() {
    return game_data->getAllStoryTextData()->getStoryTextData(now_text_num - 1);
}
std::string StoryState::getNowText() {
    std::string s = getNowStoryTextData()->getText1();
    s += getNowStoryTextData()->getText2();
    s += getNowStoryTextData()->getText3();
    return s;
}
bool StoryState::isDrawEnd() { return is_draw_end; }
bool StoryState::isClose() { return is_close; }
bool StoryState::isAuto() { return is_auto; }
bool StoryState::isSkip() { return is_skip; }
bool StoryState::isBacklog() { return is_backlog; }
int StoryState::getWhatDraw() { return what_draw; }
int StoryState::getCharaAlpha() { return chara_alpha; }
int StoryState::getBacklogPos() { return backlog_pos; }
bool StoryState::isFade() { return is_fade; }