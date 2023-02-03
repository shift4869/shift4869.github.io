//func.cpp
#include "../include/main.h"

//フィールド情報から各ブロックの座標を設定する
//tそのもののベース点はフィールドの(2,2)の座標とする
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

//テトリミノ移動関数(x)
bool AddX(TetriMino& t,int add){

	//エラーチェック
	if(abs(add)%BS!=0)return false;

	//ベース点移動
	t.x+=add;

	//blk同期
	FieldToBlk(t);

	//成功
	return true;
}

//テトリミノ移動関数(y)
bool AddY(TetriMino& t,int add){

	//エラーチェック
	if(abs(add)%BS!=0)return false;

	//ベース点移動
	t.y+=add;

	//blk同期
	FieldToBlk(t);

	//成功
	return true;
}
