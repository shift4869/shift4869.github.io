
//�C���N���[�h�t�@�C��
#include <DxLib.h>
#include <time.h>

//typedef�錾
typedef unsigned int uint;

//define��`
#define MAX_NUM 6

//�֐��v���g�^�C�v�錾------
//GetRandNumber.cpp
void init_per();
int GetRandNumber();
//func.cpp
void Preserve(int n);
//--------------------------

//���ۃJ�E���^
int num[MAX_NUM];

//���C���֐�
int main(int argc,const char *argv[]){
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h

	if(DxLib_Init()==-1)return -1;//������

	//�e�헐��������
	srand((uint)time(NULL));
	SRand((int)time(NULL));
	init_per();

	try{//���s�J�n
		const uint TRYCNT=600;//���s��
		//3��̗��������@�Ŏ��s
		for(int i=0;i<3;i++){
			switch(i){
				case 0:
					for(uint j=0;j<TRYCNT;j++)num[GetRandNumber()]++;
					break;
				case 1:
					for(uint j=0;j<TRYCNT;j++)num[GetRand(MAX_NUM-1)]++;
					break;
				case 2:
					for(uint j=0;j<TRYCNT;j++)num[rand()%MAX_NUM]++;
					break;
				default:
					throw "switch error";
			}

			Preserve(i+1);//���ʂ�ۑ�
			memset(num,0,sizeof(int)*MAX_NUM);//���̎��s�̏���
		}
	}
	catch(const char *e){//�G���[!
		MessageBoxA(NULL,e,"error",NULL);
		DxLib_End();
	}

	DxLib_End();

	return 0;//�I��
}