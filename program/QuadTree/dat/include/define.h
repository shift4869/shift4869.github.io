//define.h
//2013/12/08 written by shift

//���������[�N���m�pnew
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

//�o�C�g�ő吔
#define BYTE_MAX 256

//�p�b�h�ő吔
#define PAD_MAX 16

//�F�ő吔
#define COLOR_MAX 9
//�F���
enum COLOR_KND{
	RED=0,
	GREEN,
	PURPLE,
	BLUE,
	ORANGE,
	YELLOW,
	SKY,
	WHITE,
	BLACK,
};

//���w����
#define PI (3.1415926)
#define DTOR(DEG) ((DEG)*PI/180)
#define RTOD(RAD) ((RAD)*180/PI)

//�{�[�h���W�n
#define FX 32
#define FY 16
#define FMX 416
#define FMY 464
#define FCX 224
#define FCY 240
#define FLX 384
#define FLY 448

//��ԕ������x��
#define N 2

//���Ԍv���t���[����
#define F_NUM 300

//�ő�e��
#define B_MAX 300
//1�����ő��₷�e��
#define B_NUM 20

//0~F_NUM�܂Ōv�������畽�ς��L�^����
//��ʏ�̒e��B_NUM���₷
//B_MAX�𒴂�����I��
