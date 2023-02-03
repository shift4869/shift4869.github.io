//main.cpp
#define FIRST_LOADING
#include "../include/main.h"

//���[�v���̏���
bool ProcessLoop(){
	//���b�Z�[�W����
	if(ProcessMessage()!=0)			return false;
	//��ʂ��N���A
	if(ClearDrawScreen()!=0)		return false;
	//�L�[���͏�Ԃ�ۑ�
	if(GetHitKeyStateAll_2()!=0)	return false;
	//�p�b�h���͏�Ԃ�ۑ�
	if(GetHitPadStateAll()!=0)		return false;
	//ESC��������Ă��Ȃ�
	if(CheckStatePad(config.start)!=0)return false;
	return true;
}

//���C���֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

	ChangeWindowMode(TRUE);//�E�B���h�E���[�h
	if(DxLib_Init()==-1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//�������Ɨ���ʉ�

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