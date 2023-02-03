//CreateTetriMino.cpp
#include "../include/main.h"

//�e�g���~�m�����֐�
TetriMino CreateTetriMino(const Point& p,const BLK_COL& k){
	TetriMino t;

	//t���̂��̂̃x�[�X�_
	t.x=p.x;
	t.y=p.y;

	/*
			0	1	2	3	4
		0					
		
		1					
		
		2			t		
		
		3			t		
		
		4					
	*/

	//(2,2),(2,3)�͕K�����݂���n�_
	t.field[2][2]=true;
	t.field[2][3]=true;

	//�w�肳�ꂽ���(�F)�ɉ����ĐU�蕪��
	switch(k){
		case RED:	//��
			t.field[3][1]=true;
			t.field[3][2]=true;
			break;
		case GREEN:	//��
			t.field[1][1]=true;
			t.field[1][2]=true;
			break;
		case PURPLE://��(T��)
			t.field[1][2]=true;
			t.field[3][2]=true;
			break;
		case BLUE:	//��(�tL��)
			t.field[2][1]=true;
			t.field[1][3]=true;
			break;
		case ORANGE://��(L��)
			t.field[2][1]=true;
			t.field[3][3]=true;
			break;
		case YELLOW://��(��)
			t.field[1][2]=true;
			t.field[1][3]=true;
			break;
		case SKY:	//��(�b)
			t.field[2][0]=true;
			t.field[2][1]=true;
			break;
		default:	//�s��->�G���[
			throw "int CreateTetriMino()::k error";
			break;
	}

	//blk��knd��ݒ肷��
	for(int i=0;i<4;i++)t.blk[i].knd=k;

	//FieldToBlk
	//�t�B�[���h��񂩂�e�u���b�N�̍��W��ݒ肷��
	//t���̂��̂̃x�[�X�_�̓t�B�[���h��(2,2)�̍��W�Ƃ���
	FieldToBlk(t);

	//�ݒ肵��t��Ԃ�
	return t;
}