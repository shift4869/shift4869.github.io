//draw.cpp
#include "../include/main.h"

//背景描画
void DrawBoard(){
	DrawGraph(0  ,0  ,IMG::board[2],true);
	DrawGraph(112,0  ,IMG::board[1],true);
	DrawGraph(112,448,IMG::board[1],true);
	DrawGraph(304,0  ,IMG::board[0],true);
}

//デバッグ描画
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

//ブロック描画
void DrawBlock(){
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	//フィールド上にあるブロックの描画
	for(list<Block>::iterator it=blkList.begin();
		it!=blkList.end();++it){
		DrawGraph(it->x,it->y,IMG::block[(int)it->knd],true);
	}
	
	//現在テトリミノの描画
	for(int i=0;i<4;i++){
		DrawGraph(cur.blk[i].x,cur.blk[i].y,IMG::block[(int)cur.blk[i].knd],true);
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);

	//ネクストブロックリストの描画
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

	//ストックの描画
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			if(stock.field[x][y]){
				DrawGraph(BS+BS*x,BS+BS*y,IMG::block[(int)stock.blk[0].knd],true);
			}
		}
	}

	//ドロップシャドウの描画
	SetDrawBlendMode(DX_BLENDMODE_ADD,128);
	for(int i=0;i<4;i++){
		DrawGraph(shadow.blk[i].x,shadow.blk[i].y,IMG::block[(int)shadow.blk[0].knd],true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}

//描画メイン
void DrawMain(){
	
	//デバッグ描画
	//DrawDebug();
	
	//ブロック描画
	DrawBlock();

	//背景描画
	DrawBoard();

}