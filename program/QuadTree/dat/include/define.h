//define.h
//2013/12/08 written by shift

//メモリリーク検知用new
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

//バイト最大数
#define BYTE_MAX 256

//パッド最大数
#define PAD_MAX 16

//色最大数
#define COLOR_MAX 9
//色種類
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

//数学処理
#define PI (3.1415926)
#define DTOR(DEG) ((DEG)*PI/180)
#define RTOD(RAD) ((RAD)*180/PI)

//ボード座標系
#define FX 32
#define FY 16
#define FMX 416
#define FMY 464
#define FCX 224
#define FCY 240
#define FLX 384
#define FLY 448

//空間分割レベル
#define N 2

//時間計測フレーム数
#define F_NUM 300

//最大弾数
#define B_MAX 300
//1周期で増やす弾数
#define B_NUM 20

//0~F_NUMまで計測したら平均を記録して
//画面上の弾をB_NUM個増やす
//B_MAXを超えたら終了
