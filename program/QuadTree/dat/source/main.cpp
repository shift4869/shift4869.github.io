//main.cpp
//2013/12/08 written by shift

#define _FIRST_LOADING_
#include "../include/main.h"

//メインループ内で実行するプロシージャ
bool ProcessLoop(){
	if(ProcessMessage()!=0)			return false;
	if(ClearDrawScreen()!=0)		return false;
	if(GetHitKeyStateAll2()!=0)		return false;
	if(GetHitPadStateAll()!=0)		return false;
	if(CheckStatePad(config.start)!=0)return false;

	return loopFlag;
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

	ChangeWindowMode(TRUE);//ウィンドウモード
	SetAlwaysRunFlag( true );//バックグラウンドでも実行
	SetMainWindowText("QuadTreeSearch");

	if(DxLib_Init()==-1 || SetDrawScreen(DX_SCREEN_BACK)!=0)return -1;//初期化と裏画面化

	ini();

	try{
		while(ProcessLoop()){
			runMain();

			drawMain();
			
			fps();

			ScreenFlip();
		}
	}
	catch(const char *e){
		MessageBox(NULL,e,"error",NULL);
		end();
		return -1;
	}
	
	end();

	return 0;
}

