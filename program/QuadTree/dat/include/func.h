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
//描画メイン
void drawMain();

//run.cpp
//実行メイン
void runMain();

//end.cpp
void end();

//func.cpp
//int版x^y
int pow(int x,int y);
//「度」用のsin
float sind(float deg);
//「度」用のcos
float cosd(float deg);
//乱数取得[0~RAND_MAX)
int Rand();
//乱数取得[0~max)
int Rand(int max);
//乱数取得[min~max)
int Rand(int min,int max);
//書式付きstring作成(const char *型がthrowされる可能性がある)
string Format(const char *format, ...);
