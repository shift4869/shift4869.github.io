
//�C���N���[�h�t�@�C��
#include <DxLib.h>

//pragma�錾
#pragma warning(disable:4244)//float->int�̏�񗎂��x��������

//define��`
#define MAX_NUM 6

//������:��`
const float DOWN_RATE=(1-20/100.0f);//�m������20%�Â�

//�e�퐔�l�̊m��
float per[MAX_NUM];

//per�z��̏�����
void init_per(){
	//�����̊e�m���͓�����
	memset(per,1.0f/(MAX_NUM),sizeof(float)*MAX_NUM);
}

//0�`1�܂ł̗���DX���C�u����:GetRand()�g�p
float randf(){
	return GetRand(100000)/100000.0f;
}

//�m�������ɐ��l��Ԃ�
int GetRandNumber(){
	int ret=0;

	float r=randf();//0~1

	//�x���k�[�C���s�ɂ��per���m���Ƃ��Đ��l�̌���-------
	float sum=0.0;
	for(int i=0;i<MAX_NUM;i++){
		if(sum<r && r<sum+per[i]){
			ret=i;
		}
		sum+=per[i];//�ŏI�I��1.0�O��ɂȂ�͂�
	}
	//----------------------------------------------------

	//�I�萔�l�̎��񒊑I�m��������������------------------
	//����ɔ��� �I�萔�l�ȊO�̎��񒊑I�m���𑝉�������
	//��������DOWN_RATE
	for(int i=0;i<MAX_NUM;i++){
		if(i!=ret){per[i]+=(per[ret]*(1-DOWN_RATE))/(MAX_NUM);}
	}
	per[ret]*=DOWN_RATE;
	//----------------------------------------------------

	//���܂ł�float�v�Z�̌덷�̏C��-----------------------
	//per�̍��v��1�ɂȂ�͂�
	//���̌덷�����߂�->gosa
	float diff=1-sum;
	for(int i=0;i<MAX_NUM;i++){
		per[i]+=diff/(MAX_NUM);//�덷���ϓ��z������
	}
	//----------------------------------------------------

	return ret;//�I�萔�l��Ԃ�
}
