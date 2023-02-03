//key.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//�L�[�{�[�h�̓��͏�Ԃ��i�[����ϐ�
int key[BYTE_MAX];
//�p�b�h�̓��͏�Ԃ��i�[����ϐ�
Pad pad;

//�L�[�{�[�h�̓��͂��`�F�b�N����֐�
int GetHitKeyStateAll2(){
	char hitKeyState[BYTE_MAX];
	GetHitKeyStateAll( hitKeyState );
	for(int i=0;i<BYTE_MAX;i++){
		if(hitKeyState[i]==1)key[i]++;
		else                 key[i]=0;
	}
	return 0;
}

//�n���ꂽ�L�[�ԍ��̓��͏�Ԃ�Ԃ��B
//example:CheckStateKey(KEY_INPUT_ESCAPE);
int CheckStateKey(int handle){
	if(0<=handle && handle<BYTE_MAX){
		return key[handle];
	}
	else{
		throw "CheckStateKey�ɓn�����l���s���ł�";
		return -1;
	}
}

//�p�b�h�ƃL�[�{�[�h�̗����̓��͂��`�F�b�N����֐�
int GetHitPadStateAll(){
	//�p�b�h�̓��͏�Ԃ��擾
	int padInput=GetJoypadInputState(DX_INPUT_PAD1);
	
	//�ǂ̃p�b�h�L�[�������ꂽ���𒲂ׂ�
	for(int i=0,mul=1;i<16;i++,mul*=2){
		if(padInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
	}

	//�L�[��
	const int KEY_KND=5;
	int cknd[KEY_KND]={config.left,config.up,config.right,config.down,
					   config.start};

	int kknd[KEY_KND]={KEY_INPUT_LEFT,KEY_INPUT_UP,KEY_INPUT_RIGHT,KEY_INPUT_DOWN,
					   KEY_INPUT_ESCAPE};
	
	//�p�b�h�L�[�ƃL�[�{�[�h�̒l�ő傫�������p�b�h�̒l�Ƃ���
	for(int i=0;i<KEY_KND;i++){
		pad.key[cknd[i]]=max(pad.key[cknd[i]],CheckStateKey(kknd[i]));
	}

	return 0;
}

//�n���ꂽ�p�b�h�L�[�ԍ��̓��͏�Ԃ�Ԃ��B
//example:CheckStatePad(config.start);
int CheckStatePad(int handle){
	if(0<=handle && handle<PAD_MAX){
		return pad.key[handle];
	}
	else{
		throw "CheckStatePad�ɓn�����l���s���ł�";
		return -1;
	}
}