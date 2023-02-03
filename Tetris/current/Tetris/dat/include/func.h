//func.h

//fps.cpp//
//fps�\��
void fps();

//key.cpp//
//�L�[���͂��擾����֐�
int GetHitKeyStateAll_2();
//���ʂ�Ԃ��֐�
int CheckStateKey(int KeyCode);
//�p�b�h�L�[�ƃL�[�{�[�h�̗����̓��͂��`�F�b�N����֐�
int GetHitPadStateAll();
//�n���ꂽ�p�b�h�L�[�̌��ʂ�Ԃ��֐�
int CheckStatePad(int PadKeyCode);

//ini.cpp//
//����������
void ini();

//draw.cpp//
void DrawMain();

//CreateTetriMino.cpp//
TetriMino CreateTetriMino(const Point& p,const BLK_COL& k);

//func.cpp//
//�t�B�[���h��񂩂�e�u���b�N�̍��W��ݒ肷��
//t���̂��̂̃x�[�X�_�̓t�B�[���h��(2,2)�̍��W�Ƃ���
bool FieldToBlk(TetriMino& t);
//�e�g���~�m�ړ��֐�(x)
bool AddX(TetriMino& t,int add);
bool AddY(TetriMino& t,int add);

//control.cpp//
void Control();

//IsValid.cpp//
//�w�肳�ꂽ���W���t�B�[���h���ɂ��邩
//true->�t�B�[���h���ɂ��� false->�t�B�[���h���ɂȂ�
bool IsInField(const Point& p);
//�w�肳�ꂽ�e�g���~�m���t�B�[���h���ɂ��邩
//true->�t�B�[���h���ɂ��� false->�t�B�[���h���ɂȂ�
bool IsInField(const TetriMino& t);
//�w�肳�ꂽ�e�g���~�m�����ɂ���u���b�N�ɖ��܂��ĂȂ���
//true->���܂��Ă��� false->���܂��Ă��Ȃ�
bool IsBury();
//�e�g���~�m���L���Ȉʒu�ɂ��邩
//true->�L���ł��� false->�����ł���
bool IsValid(const TetriMino& t);

//Spin.cpp//
bool Spin(TetriMino& t,bool isLeft);

//DeleteLine.cpp//
//���C������
//�A��l�͏��������C����
int DeleteLine();
