//define.h

//パッドキーの最大数
#define PAD_MAX 16

//1byteの最大数
#define BYTE_MAX 256

//ブロックの色
enum BLK_COL{
	RED=0,
	GREEN,
	PURPLE,
	BLUE,
	ORANGE,
	YELLOW,
	SKY,
};

//ブロックの色の数
#define BLK_KND_NUM 7

//ブロックサイズ
#define BS 16

//ゲーム画面内に並ぶブロック数
#define BMX 12
#define BMY 26

//ゲーム画面左上座標
#define FX 112
#define FY 32

//ゲーム画面右下座標
#define FMX 304
#define FMY 448
