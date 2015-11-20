//-----------------------------------------------------------
// StoryState.h
// �X�g�[���[�̏��
// ����� 2015.03.17
// ����� motumotu
//-----------------------------------------------------------
#pragma once
#include "GameData.h"

class StoryState {
public:
    static const int STORY_OBJ_NONE;
    static const int STORY_OBJ_BUTTON_AUTO;
    static const int STORY_OBJ_BUTTON_SKIP;
    static const int STORY_OBJ_BUTTON_LOG;
    static const int STORY_OBJ_BUTTON_CONF;
    static const int STORY_OBJ_BUTTON_SAVE;
    static const int STORY_OBJ_BUTTON_LOAD;
    static const int STORY_OBJ_BUTTON_CLOSE;
    static const int STORY_OBJ_BACKLOG_BUTTON_UP;
    static const int STORY_OBJ_BACKLOG_BUTTON_DOWN;
    static const int STORY_OBJ_BACKLOG_BUTTON_EXIT;
    static const int STORY_OBJ_BACKLOG_AREA;

    static const int STORY_DRAW_CHARA; // �L�����`�撆
    static const int STORY_DRAW_TEXT;  // �e�L�X�g�`�撆

private:
    GameData *game_data;       // �Q�[���f�[�^
    StoryData *story_data;
    int mouse_x;               // �}�E�X�ʒux
    int mouse_y;               // �}�E�X�ʒuy
    int now_text_num;          // ���݂̃e�L�X�g�ԍ�
    int cnt_frame;             // �o�߃t���[��
    int now_text_len;          // ���݂̃e�L�X�g��
    bool is_draw_end;          // �`��I�����Ă邩
    bool is_close;             // �E�B���h�E�����Ă��邩
    bool is_auto;              // �I�[�g����
    bool is_skip;              // �X�L�b�v����
    bool is_backlog;           // �o�b�N���O����
    int what_draw;             // ����`�撆��
    int chara_alpha;           // �L���������x
    int backlog_pos;           // �o�b�N���O�̈ʒu
    int scrollbar_pos;         // �X�N���[���o�[�̈ʒu
    bool is_fade;              // �t�F�[�h����
public:
    StoryState(GameData*);     // �R���X�g���N�^
    ~StoryState();             // �f�X�g���N�^
    void init();               // ������
    void update();             // �X�V
    void updateMousePos(int, int); // �}�E�X���W
    int isJapaneseCharacter(unsigned char); // ���{�ꂩ
    void fullText();           // �S���\��
    void changeNextText();     // ���̃e�L�X�g
    void changeText(int);      // �e�L�X�g�ύX

    // �o�b�N���O
    bool downBacklogPos();      // �o�b�N���O������
    void upBacklogPos();        // �o�b�N���O�����
    void openBacklog();         // �o�b�N���O�I�[�v��
    void closeBacklog();        // �o�b�N���O�����
    int getScrollbarPos();      // �X�N���[���o�[�̈ʒu�擾
    int getScrollbarSize();     // �X�N���[���o�[�T�C�Y�擾
    void scrollBarAdjustment(); // �X�N���[���o�[����
    void scrollBarAdjustmentMousePos(); // 

    // �N���b�N����
    void clickNone();          // �����Ȃ��Ƃ�����N���b�N
    void clickButtonClose();   // ����{�^���̃N���b�N
    void clickButtonAuto();    // �I�[�g�{�^���̃N���b�N
    void clickButtonSkip();    // �X�L�b�v�{�^���̃N���b�N
    void clickButtonLog();     // ���O�{�^���̃N���b�N
    void clickButtonConf();    // �R���t�B�O�{�^���̃N���b�N
    void clickButtonSave();    // �Z�[�u�{�^���̃N���b�N
    void clickButtonLoad();    // ���[�h�{�^���̃N���b�N
    void clickBacklogButtonUp(); // �o�b�N���O�̏�{�^���N���b�N
    void clickBacklogButtonDown(); // �o�b�N���O�̉��{�^���N���b�N
    void clickBacklogButtonExit(); // �o�b�N���O��EXIT�{�^���N���b�N


    // �e�L�X�g�f�[�^�擾
    std::string getNowName();  // ���݂̖��O�擾
    std::string getNowEName(); // �p�ꖼ�擾
    std::string getNowText1(); // ���݂̃e�L�X�g�P�擾
    std::string getNowText2(); // ���݂̃e�L�X�g�Q�擾
    std::string getNowText3(); // ���݂̃e�L�X�g�R�擾
    int getNowCharaNum();      // ���݂̃L�������擾
    int getNowCharaPos(int);   // �L�����ʒu�擾
    int getNowCharaImage(int); // �L�����摜�擾
    int getNowBack();          // ���݂̔w�i�擾
    // �O
    int getPreCharaNum();      // �O�̃L�������擾
    int getPreCharaPos(int);   // �O�̃L�����ʒu�擾
    int getPreCharaImage(int); // �O�̃L�����摜�擾

    // �I�u�W�F�N�g
    int getMousePosObject(); // �}�E�X�̍��W�̕��̎擾
    bool isPosButtonAuto();  // �I�[�g�{�^��
    bool isPosButtonSkip();  // �X�L�b�v�{�^��
    bool isPosButtonLog();   // ���O�{�^��
    bool isPosButtonConf();  // �R���t�B�O�{�^��
    bool isPosButtonSave();  // �Z�[�u�{�^��
    bool isPosButtonLoad();  // ���[�h�{�^��
    bool isPosButtonClose(); // ����{�^��
    bool isPosBacklogButtonUp();   // ���
    bool isPosBacklogButtonDown(); // ����
    bool isPosBacklogButtonExit(); // EXIT�{�^��
    bool isPosBacklogArea();       // �o�b�N���O�G���A

    // �摜�f�[�^�擾
    int getImageButtonAuto();
    int getImageButtonSkip();
    int getImageButtonLog();
    int getImageButtonConf();
    int getImageButtonSave();
    int getImageButtonLoad();
    int getImageButtonClose();
    int getImageBacklogButtonUp();   // �o�b�N���O��{�^���̉摜�擾
    int getImageBacklogButtonDown(); // �o�b�N���O���{�^���̉摜�擾
    int getImageBacklogButtonExit(); // EXIT�{�^���̉摜�擾

    //---- setter
    void setNowTextNum(int);   // ���݂̃e�L�X�g�ԍ��Z�b�g
    void setIsClose(bool);     // ���Ă��邩��ݒ�
    void setIsAuto(bool);      // �I�[�g�����Z�b�g
    void setIsSkip(bool);      // �X�L�b�v�����Z�b�g
    void setIsBacklog(bool);   // �o�b�N���O�����Z�b�g
    void setIsFade(bool);

    //---- getter
    int getNowTextNum();       // ���݂̃e�L�X�g�ԍ��擾
    StoryTextData *getNowStoryTextData(); // ���݂̃e�L�X�g�f�[�^�擾
    StoryTextData *getPreStoryTextData(); // �O�̃e�L�X�g�f�[�^�擾
    std::string StoryState::getNowText(); // ���݂̃e�L�X�g�擾
    bool isDrawEnd();          // �`��I�����Ă邩
    bool isClose();            // ���Ă��邩
    bool isAuto();             // �I�[�g����
    bool isSkip();             // �X�L�b�v����
    bool isBacklog();          // �o�b�N���O�����擾
    int getWhatDraw();
    int getCharaAlpha();
    int getBacklogPos();       // �o�b�N���O�̈ʒu
    bool isFade();
};