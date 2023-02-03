
//インクルードファイル
#include <DxLib.h>

//pragma宣言
#pragma warning(disable:4244)//float->intの情報落ち警告を消す

//define定義
#define MAX_NUM 6

//減少率:定義
const float DOWN_RATE=(1-20/100.0f);//確率減少20%づつ

//各種数値の確率
float per[MAX_NUM];

//per配列の初期化
void init_per(){
	//初期の各確率は等しい
	memset(per,1.0f/(MAX_NUM),sizeof(float)*MAX_NUM);
}

//0～1までの乱数DXライブラリ:GetRand()使用
float randf(){
	return GetRand(100000)/100000.0f;
}

//確率を元に数値を返す
int GetRandNumber(){
	int ret=0;

	float r=randf();//0~1

	//ベルヌーイ試行によりperを確率として数値の決定-------
	float sum=0.0;
	for(int i=0;i<MAX_NUM;i++){
		if(sum<r && r<sum+per[i]){
			ret=i;
		}
		sum+=per[i];//最終的に1.0前後になるはず
	}
	//----------------------------------------------------

	//選定数値の次回抽選確率を減少させる------------------
	//それに伴い 選定数値以外の次回抽選確率を増加させる
	//減少率はDOWN_RATE
	for(int i=0;i<MAX_NUM;i++){
		if(i!=ret){per[i]+=(per[ret]*(1-DOWN_RATE))/(MAX_NUM);}
	}
	per[ret]*=DOWN_RATE;
	//----------------------------------------------------

	//今までのfloat計算の誤差の修正-----------------------
	//perの合計は1になるはず
	//その誤差を求める->gosa
	float diff=1-sum;
	for(int i=0;i<MAX_NUM;i++){
		per[i]+=diff/(MAX_NUM);//誤差を均等配分する
	}
	//----------------------------------------------------

	return ret;//選定数値を返す
}
