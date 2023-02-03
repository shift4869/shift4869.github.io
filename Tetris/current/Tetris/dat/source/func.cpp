//func.cpp
#include "../include/main.h"

//�t�B�[���h��񂩂�e�u���b�N�̍��W��ݒ肷��
//t���̂��̂̃x�[�X�_�̓t�B�[���h��(2,2)�̍��W�Ƃ���
bool FieldToBlk(TetriMino& t){
	int i=0;
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			if(t.field[x][y]){
				t.blk[i].x=t.x+BS*(x-2);
				t.blk[i].y=t.y+BS*(y-2);
				i++;
			}
		}
	}
	return (i==4);
}

//�e�g���~�m�ړ��֐�(x)
bool AddX(TetriMino& t,int add){

	//�G���[�`�F�b�N
	if(abs(add)%BS!=0)return false;

	//�x�[�X�_�ړ�
	t.x+=add;

	//blk����
	FieldToBlk(t);

	//����
	return true;
}

//�e�g���~�m�ړ��֐�(y)
bool AddY(TetriMino& t,int add){

	//�G���[�`�F�b�N
	if(abs(add)%BS!=0)return false;

	//�x�[�X�_�ړ�
	t.y+=add;

	//blk����
	FieldToBlk(t);

	//����
	return true;
}
