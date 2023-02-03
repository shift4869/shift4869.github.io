//main.cpp
#define FIRST_LOADING
#include "../include/main.h"

//ループ時の処理
bool ProcessLoop(){
	//メッセージ処理
	if(ProcessMessage()!=0)			return false;
	//画面をクリア
	if(ClearDrawScreen()!=0)		return false;
	//キー入力状態を保存
	if(GetHitKeyStateAll_2()!=0)	return false;
	//パッド入力状態を保存
	if(GetHitPadStateAll()!=0)		return false;
	//ESCが押されていない
	if(CheckStatePad(config.start)!=0)return false;
	return true;
}

//メイン関数
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

	ChangeWindowMode(TRUE);//ウィンドウモード
	if(DxLib_Init()==-1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初期化と裏画面化

	try{
		ini();

		while(ProcessLoop()){

			Control();

			DrawMain();

			fps();

			ScreenFlip();
		}
	}
	catch(const char* e){
		MessageBox(NULL,e,"error",NULL);
		DxLib_End();
		return -1;
	}

	DxLib_End();
	return 0;
}