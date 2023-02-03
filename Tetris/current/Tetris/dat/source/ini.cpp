//ini.cpp
#include "../include/main.h"

//画像イメージのネームスペースを使用する
using namespace IMG;

//初期化処理
void ini(){
	
	//背景ボード画像のロード
	board[0]=LoadGraph("./dat/resource/board/board.png");
	board[1]=LoadGraph("./dat/resource/board/level.png");
	board[2]=LoadGraph("./dat/resource/board/vertical.png");

	//ブロック画像のロード
	LoadDivGraph("./dat/resource/img/block.png",7,7,1,16,16,block);

	//数字画像のロード
	LoadDivGraph("./dat/resource/img/num.png",10,10,1,12,16,num);

	//初期テトリミノ生成
	cur=CreateTetriMino(Point(FX+BS*6,FY-BS*2),(BLK_COL)GetRand(BLK_KND_NUM-1));
	//画面内有効フラグをtrueに
	cur.flag=true;

	//ネクストブロックリストに充填
	for(int i=0;i<5;i++){
		nextList.push_back(CreateTetriMino(Point(FX+BS*6,FY-BS*2),
								(BLK_COL)GetRand(BLK_KND_NUM-1)));
	}
}