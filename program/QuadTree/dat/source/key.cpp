//key.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//キーボードの入力状態を格納する変数
int key[BYTE_MAX];
//パッドの入力状態を格納する変数
Pad pad;

//キーボードの入力をチェックする関数
int GetHitKeyStateAll2(){
	char hitKeyState[BYTE_MAX];
	GetHitKeyStateAll( hitKeyState );
	for(int i=0;i<BYTE_MAX;i++){
		if(hitKeyState[i]==1)key[i]++;
		else                 key[i]=0;
	}
	return 0;
}

//渡されたキー番号の入力状態を返す。
//example:CheckStateKey(KEY_INPUT_ESCAPE);
int CheckStateKey(int handle){
	if(0<=handle && handle<BYTE_MAX){
		return key[handle];
	}
	else{
		throw "CheckStateKeyに渡した値が不正です";
		return -1;
	}
}

//パッドとキーボードの両方の入力をチェックする関数
int GetHitPadStateAll(){
	//パッドの入力状態を取得
	int padInput=GetJoypadInputState(DX_INPUT_PAD1);
	
	//どのパッドキーが押されたかを調べる
	for(int i=0,mul=1;i<16;i++,mul*=2){
		if(padInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
	}

	//キー数
	const int KEY_KND=5;
	int cknd[KEY_KND]={config.left,config.up,config.right,config.down,
					   config.start};

	int kknd[KEY_KND]={KEY_INPUT_LEFT,KEY_INPUT_UP,KEY_INPUT_RIGHT,KEY_INPUT_DOWN,
					   KEY_INPUT_ESCAPE};
	
	//パッドキーとキーボードの値で大きい方をパッドの値とする
	for(int i=0;i<KEY_KND;i++){
		pad.key[cknd[i]]=max(pad.key[cknd[i]],CheckStateKey(kknd[i]));
	}

	return 0;
}

//渡されたパッドキー番号の入力状態を返す。
//example:CheckStatePad(config.start);
int CheckStatePad(int handle){
	if(0<=handle && handle<PAD_MAX){
		return pad.key[handle];
	}
	else{
		throw "CheckStatePadに渡した値が不正です";
		return -1;
	}
}