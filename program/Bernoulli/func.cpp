
//インクルードファイル
#include <fstream>
#include <stdarg.h>
#include <algorithm>
#include <string>
using namespace std;

//define定義
#define MAX_NUM 6

//関数プロトタイプ宣言
string format(const char *format, ...);

//事象カウンタのextern宣言
extern int num[MAX_NUM];

//結果を保存する
void Preserve(int n){
	//出力ファイル名設定
	string outfile=format("result%02d.txt",n);
	ofstream fout(outfile.c_str());
	if(!fout)throw "file open error";

	int sum=0;//事象合計
	float per[MAX_NUM]={0,};//各事象確率

	//合計取得
	for(int i=0;i<MAX_NUM;i++){
		sum+=num[i];
	}
	//割合設定
	for(int i=0;i<MAX_NUM;i++){
		per[i]=num[i]/(float)sum;
	}

	//各事象と確率書き込み
	for(int i=0;i<MAX_NUM;i++){
		fout<<format("%d=%07d回:確率=%0.2f%%",i+1,num[i],per[i]*100).c_str()<<endl;
	}
	fout<<format("合計%07d回",sum).c_str()<<endl;//合計

	{//事象差書き込み
		int max,min;
		max=*max_element(num,num+MAX_NUM);//配列中の一番大きい数から
		min=*min_element(num,num+MAX_NUM);//配列中の一番小さい数を
		fout<<format("事象差%07d回",max-min).c_str()<<endl;//引く
	}

	{//割合差書き込み
		float max,min;
		max=*max_element(per,per+MAX_NUM);
		min=*min_element(per,per+MAX_NUM);
		fout<<format("割合差%0.2f%%",(max-min)*100).c_str()<<endl;
	}
}

//書式付きstring作成
string format(const char *format, ...){
	va_list v;
	int num=0,res=0;
	char *buf=NULL;
	string ret;

	va_start(v,format);

	num=_vscprintf(format,v)+1;
	buf=new char[num];
	res=_vsnprintf_s(buf,num,num,format,v);
	if(res<0)throw "_vsnprintf_s error";

	ret=buf;

	va_end(v);

	delete[] buf;

	return ret;
} 
