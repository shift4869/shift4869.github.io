//Spin.cpp
#include "../include/main.h"

//テトリミノの回転処理
bool Spin(TetriMino& t,bool isLeft){

	//黄色は回転しない
	if(t.blk[0].knd==YELLOW)return true;

	//キャッシュ
	TetriMino n=t;
	//キャッシュのfieldをクリア
	memset(n.field,false,sizeof(bool)*5*5);
	//猶予時間リセット
	n.wait=0;
	
	//回転後の位置にあるキャッシュのfieldをtrueに
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			if(t.field[x][y]){
				if(isLeft)	n.field[y][4-x]=true;//左回転
				else		n.field[4-y][x]=true;//右回転
			}
		}
	}

	//blk同期
	FieldToBlk(n);

	//壁蹴り処理
	const int TEST_NUM=2;	//試行回数
	int moveCnt=1;			//移動回数カウンタ
	int tCnt=0;				//方向カウンタ
	TetriMino tk=n;			//試行用テトリミノキャッシュ

	//有効な位置にいなければ
	while(!IsValid(tk)){
		tk=n;//キャッシュリセット
		switch(tCnt){//方向
			case 0://左にずらしてみる
				AddX(tk,-BS*moveCnt);
				break;
			case 1://右にずらしてみる
				AddX(tk,BS*moveCnt);
				break;
			case 2://上にずらしてみる
				AddY(tk,-BS);
				AddY(n,-BS);//基準も上にずらす
				moveCnt++;	//試行1回終了
				break;
			default://エラー
				throw "bool Spin()::tCnt error";
				break;
		}
		tCnt=(++tCnt)%3;//方向カウンタアップ

		//試行回数を超えたら強制終了
		if(moveCnt>TEST_NUM)return false;
	}

	//キャッシュをtに反映
	t=tk;

	//回転終了
	return true;
}