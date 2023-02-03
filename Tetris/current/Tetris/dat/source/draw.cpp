//draw.cpp
#include "../include/main.h"

//�w�i�`��
void DrawBoard(){
	DrawGraph(0  ,0  ,IMG::board[2],true);
	DrawGraph(112,0  ,IMG::board[1],true);
	DrawGraph(112,448,IMG::board[1],true);
	DrawGraph(304,0  ,IMG::board[0],true);
}

//�f�o�b�O�`��
void DrawDebug(){
	for(int x=0;x<BMX;x++){
		for(int y=0;y<BMY;y++){
			DrawLine(FX+BS*x,FY     ,FX+BS*x  ,FY+BS*BMY,GetColor(255,255,255));
			DrawLine(FX     ,FY+BS*y,FX+BS*BMX,FY+BS*y  ,GetColor(255,255,255));
		}
	}
	DrawCircle(FX,FY,3,GetColor(255,0,0));
	DrawCircle(FMX,FMY,3,GetColor(255,0,0));
}

//�u���b�N�`��
void DrawBlock(){
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	//�t�B�[���h��ɂ���u���b�N�̕`��
	for(list<Block>::iterator it=blkList.begin();
		it!=blkList.end();++it){
		DrawGraph(it->x,it->y,IMG::block[(int)it->knd],true);
	}
	
	//���݃e�g���~�m�̕`��
	for(int i=0;i<4;i++){
		DrawGraph(cur.blk[i].x,cur.blk[i].y,IMG::block[(int)cur.blk[i].knd],true);
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);

	//�l�N�X�g�u���b�N���X�g�̕`��
	const Point sp[]={
		Point(320,16),//128-16=112
		Point(432,16),
		Point(544,16),
		Point(544,128),
		Point(544,240),
	};
	int i=0;
	for(list<TetriMino>::iterator it=nextList.begin();
		it!=nextList.end();++it){
		for(int x=0;x<5;x++){
			for(int y=0;y<5;y++){
				if(it->field[x][y]){
					DrawGraph(sp[i].x+BS*x,sp[i].y+BS*y,IMG::block[(int)it->blk[0].knd],true);
				}
			}
		}
		i++;
	}

	//�X�g�b�N�̕`��
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			if(stock.field[x][y]){
				DrawGraph(BS+BS*x,BS+BS*y,IMG::block[(int)stock.blk[0].knd],true);
			}
		}
	}

	//�h���b�v�V���h�E�̕`��
	SetDrawBlendMode(DX_BLENDMODE_ADD,128);
	for(int i=0;i<4;i++){
		DrawGraph(shadow.blk[i].x,shadow.blk[i].y,IMG::block[(int)shadow.blk[0].knd],true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}

//�`�惁�C��
void DrawMain(){
	
	//�f�o�b�O�`��
	//DrawDebug();
	
	//�u���b�N�`��
	DrawBlock();

	//�w�i�`��
	DrawBoard();

}