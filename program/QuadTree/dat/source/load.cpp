//load.cpp
//2013/12/08 written by shift
#include "../include/main.h"

using namespace IMG;

//リソースロード
void load(){
	//フォントロード
	//「HGPｺﾞｼｯｸE」フォント
	font[0]=CreateFontToHandle("HGPｺﾞｼｯｸE",20,2,DX_FONTTYPE_ANTIALIASING_EDGE);
	font[1]=CreateFontToHandle("HGPｺﾞｼｯｸE",30,2,DX_FONTTYPE_ANTIALIASING_EDGE);
}

