//func.h
//2013/12/08 written by shift

//key.cpp
int GetHitKeyStateAll2();
int CheckStateKey(int handle);
int GetHitPadStateAll();
int CheckStatePad(int handle);

//fps.cpp
void fps();

//ini.cpp
void ini();

//draw.cpp
//�`�惁�C��
void drawMain();

//run.cpp
//���s���C��
void runMain();

//end.cpp
void end();

//func.cpp
//int��x^y
int pow(int x,int y);
//�u�x�v�p��sin
float sind(float deg);
//�u�x�v�p��cos
float cosd(float deg);
//�����擾[0~RAND_MAX)
int Rand();
//�����擾[0~max)
int Rand(int max);
//�����擾[min~max)
int Rand(int min,int max);
//�����t��string�쐬(const char *�^��throw�����\��������)
string Format(const char *format, ...);
