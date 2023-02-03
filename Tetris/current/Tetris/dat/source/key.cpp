//key.cpp
#include "../include/main.h"

//�L�[���͂�ێ�����ϐ�
int Key[BYTE_MAX];

//�L�[���͂��擾����֐�
int GetHitKeyStateAll_2(){
	char GetHitKeyStateAll_Key[BYTE_MAX];
	GetHitKeyStateAll( GetHitKeyStateAll_Key );
	for(int i=0;i<BYTE_MAX;i++){
		if(GetHitKeyStateAll_Key[i]==1)	Key[i]++;
		else							Key[i]=0;
	}
	return 0;
}

//�n���ꂽ�L�[�R�[�h�̌��ʂ�Ԃ��֐�
int CheckStateKey(int KeyCode){
	if(KeyCode<0 || BYTE_MAX<=KeyCode)return -1;
	else return Key[KeyCode];
}

//�p�b�h���͂�ێ�����ϐ�
Pad pad;

//�p�b�h�L�[�ƃL�[�{�[�h�̗����̓��͂��`�F�b�N����֐�
int GetHitPadStateAll(){
	//�p�b�h�̏�Ԃ��擾
	int padInput=GetJoypadInputState(DX_INPUT_PAD1);

	//�ǂ̃L�[��������Ă��邩���ׂ�
	for(int i=0,mul=1;i<PAD_MAX;i++,mul*=2){
		if(padInput & mul)	pad.key[i]++;
		else				pad.key[i]=0;
	}

	//�p�b�h�L�[�̎�ޑ���
	const int KEY_KND=8;
	//�p�b�h�L�[��
	int cknd[KEY_KND]={	config.left ,config.right,config.up   ,config.down,
						config.lspin,config.rspin,config.stock,config.start};
	//�L�[�{�[�h��
	int kknd[KEY_KND]={	KEY_INPUT_LEFT,KEY_INPUT_RIGHT,KEY_INPUT_UP,KEY_INPUT_DOWN,
						KEY_INPUT_Z	  ,KEY_INPUT_X    ,KEY_INPUT_S ,KEY_INPUT_ESCAPE};

	//�ǂ��炪�傫�������ׂĐݒ�
	for(int i=0;i<KEY_KND;i++){
		pad.key[cknd[i]]=max(pad.key[cknd[i]],CheckStateKey(kknd[i]));
	}

	return 0;
}

//�n���ꂽ�p�b�h�L�[�̌��ʂ�Ԃ��֐�
int CheckStatePad(int PadKeyCode){
	if(PadKeyCode<0 || PAD_MAX<=PadKeyCode)return -1;
	else return pad.key[PadKeyCode];
}
