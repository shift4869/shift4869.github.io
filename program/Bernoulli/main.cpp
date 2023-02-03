
//インクルードファイル
#include <DxLib.h>
#include <time.h>

//typedef宣言
typedef unsigned int uint;

//define定義
#define MAX_NUM 6

//関数プロトタイプ宣言------
//GetRandNumber.cpp
void init_per();
int GetRandNumber();
//func.cpp
void Preserve(int n);
//--------------------------

//事象カウンタ
int num[MAX_NUM];

//メイン関数
int main(int argc,const char *argv[]){
	ChangeWindowMode(TRUE);//ウィンドウモード

	if(DxLib_Init()==-1)return -1;//初期化

	//各種乱数初期化
	srand((uint)time(NULL));
	SRand((int)time(NULL));
	init_per();

	try{//試行開始
		const uint TRYCNT=600;//試行回数
		//3種の乱数生成法で試行
		for(int i=0;i<3;i++){
			switch(i){
				case 0:
					for(uint j=0;j<TRYCNT;j++)num[GetRandNumber()]++;
					break;
				case 1:
					for(uint j=0;j<TRYCNT;j++)num[GetRand(MAX_NUM-1)]++;
					break;
				case 2:
					for(uint j=0;j<TRYCNT;j++)num[rand()%MAX_NUM]++;
					break;
				default:
					throw "switch error";
			}

			Preserve(i+1);//結果を保存
			memset(num,0,sizeof(int)*MAX_NUM);//次の試行の準備
		}
	}
	catch(const char *e){//エラー!
		MessageBoxA(NULL,e,"error",NULL);
		DxLib_End();
	}

	DxLib_End();

	return 0;//終了
}