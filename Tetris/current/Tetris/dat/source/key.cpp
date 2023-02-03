//key.cpp
#include "../include/main.h"

//キー入力を保持する変数
int Key[BYTE_MAX];

//キー入力を取得する関数
int GetHitKeyStateAll_2(){
	char GetHitKeyStateAll_Key[BYTE_MAX];
	GetHitKeyStateAll( GetHitKeyStateAll_Key );
	for(int i=0;i<BYTE_MAX;i++){
		if(GetHitKeyStateAll_Key[i]==1)	Key[i]++;
		else							Key[i]=0;
	}
	return 0;
}

//渡されたキーコードの結果を返す関数
int CheckStateKey(int KeyCode){
	if(KeyCode<0 || BYTE_MAX<=KeyCode)return -1;
	else return Key[KeyCode];
}

//パッド入力を保持する変数
Pad pad;

//パッドキーとキーボードの両方の入力をチェックする関数
int GetHitPadStateAll(){
	//パッドの状態を取得
	int padInput=GetJoypadInputState(DX_INPUT_PAD1);

	//どのキーが押されているか調べる
	for(int i=0,mul=1;i<PAD_MAX;i++,mul*=2){
		if(padInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
	}

	//パッドキーの種類総数
	const int KEY_KND=8;
	//パッドキー側
	int cknd[KEY_KND]={	config.left ,config.right,config.up   ,config.down,
						config.lspin,config.rspin,config.stock,config.start};
	//キーボード側
	int kknd[KEY_KND]={	KEY_INPUT_LEFT,KEY_INPUT_RIGHT,KEY_INPUT_UP,KEY_INPUT_DOWN,
						KEY_INPUT_Z	  ,KEY_INPUT_X    ,KEY_INPUT_S ,KEY_INPUT_ESCAPE};

	//どちらが大きいか調べて設定
	for(int i=0;i<KEY_KND;i++){
		pad.key[cknd[i]]=max(pad.key[cknd[i]],CheckStateKey(kknd[i]));
	}

	return 0;
}

//渡されたパッドキーの結果を返す関数
int CheckStatePad(int PadKeyCode){
	if(PadKeyCode<0 || PAD_MAX<=PadKeyCode)return -1;
	else return pad.key[PadKeyCode];
}
