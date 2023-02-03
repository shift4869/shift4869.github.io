//ini.cpp
#include "../include/main.h"

//�摜�C���[�W�̃l�[���X�y�[�X���g�p����
using namespace IMG;

//����������
void ini(){
	
	//�w�i�{�[�h�摜�̃��[�h
	board[0]=LoadGraph("./dat/resource/board/board.png");
	board[1]=LoadGraph("./dat/resource/board/level.png");
	board[2]=LoadGraph("./dat/resource/board/vertical.png");

	//�u���b�N�摜�̃��[�h
	LoadDivGraph("./dat/resource/img/block.png",7,7,1,16,16,block);

	//�����摜�̃��[�h
	LoadDivGraph("./dat/resource/img/num.png",10,10,1,12,16,num);

	//�����e�g���~�m����
	cur=CreateTetriMino(Point(FX+BS*6,FY-BS*2),(BLK_COL)GetRand(BLK_KND_NUM-1));
	//��ʓ��L���t���O��true��
	cur.flag=true;

	//�l�N�X�g�u���b�N���X�g�ɏ[�U
	for(int i=0;i<5;i++){
		nextList.push_back(CreateTetriMino(Point(FX+BS*6,FY-BS*2),
								(BLK_COL)GetRand(BLK_KND_NUM-1)));
	}
}