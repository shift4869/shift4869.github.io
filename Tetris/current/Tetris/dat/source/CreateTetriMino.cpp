//CreateTetriMino.cpp
#include "../include/main.h"

//テトリミノ生成関数
TetriMino CreateTetriMino(const Point& p,const BLK_COL& k){
	TetriMino t;

	//tそのもののベース点
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

	//(2,2),(2,3)は必ず存在する地点
	t.field[2][2]=true;
	t.field[2][3]=true;

	//指定された種類(色)に応じて振り分け
	switch(k){
		case RED:	//赤
			t.field[3][1]=true;
			t.field[3][2]=true;
			break;
		case GREEN:	//緑
			t.field[1][1]=true;
			t.field[1][2]=true;
			break;
		case PURPLE://紫(T字)
			t.field[1][2]=true;
			t.field[3][2]=true;
			break;
		case BLUE:	//青(逆L字)
			t.field[2][1]=true;
			t.field[1][3]=true;
			break;
		case ORANGE://橙(L字)
			t.field[2][1]=true;
			t.field[3][3]=true;
			break;
		case YELLOW://黄(■)
			t.field[1][2]=true;
			t.field[1][3]=true;
			break;
		case SKY:	//空(｜)
			t.field[2][0]=true;
			t.field[2][1]=true;
			break;
		default:	//不明->エラー
			throw "int CreateTetriMino()::k error";
			break;
	}

	//blkのkndを設定する
	for(int i=0;i<4;i++)t.blk[i].knd=k;

	//FieldToBlk
	//フィールド情報から各ブロックの座標を設定する
	//tそのもののベース点はフィールドの(2,2)の座標とする
	FieldToBlk(t);

	//設定したtを返す
	return t;
}