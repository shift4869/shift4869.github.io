//func.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//int版x^y
int pow(int x,int y){
	return (int)pow(double(x),y);
}

//「度」用のsin
float sind(float deg){
	return sin(DTOR(deg));
}

//「度」用のcos
float cosd(float deg){
	return cos(DTOR(deg));
}

//乱数取得[0~RAND_MAX)
int Rand(){
	return rand();
}

//乱数取得[0~max)
int Rand(int max){
	return Rand()*max/(double)(RAND_MAX+1);
}

//乱数取得[min~max)
int Rand(int min,int max){
	if(min>max)swap(min,max);
    return min+Rand(max-min);
}

//書式付きstring作成(const char *型がthrowされる可能性がある)
string Format(const char *format, ...){
	va_list v;      //可変長引数型
	int num=0,res=0;//バイト数,返り値
	char *buf=NULL; //バッファ
	string ret;     //返すString変数

	va_start(v,format);         //可変長引数操作開始

	num=_vscprintf(format,v)+1; //書式展開後のバイト数取得

	buf=new char[num];          //バッファメモリアロケーション

	res=_vsnprintf_s(buf,num,num,format,v); //バッファに書式展開後の文字列を設定
	if(res<0)throw "_vsnprintf_s error";    //成功？

	ret=(string)buf;        //string型に変換

	va_end(v);      //可変長引数操作終了

	delete[] buf;   //バッファ解放

	return ret;     //Stringを返す
}
