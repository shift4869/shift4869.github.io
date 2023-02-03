//DeleteLine.cpp
#include "../include/main.h"

//ライン消去
//帰り値は消したライン数
int DeleteLine(){
	//y座標だけを比較するファンクタ
	class BlkLineFunctor{
	public:
		int y;
		BlkLineFunctor(int Y){
			y=Y;
		}
		bool operator()(Block blk){
			return (y==blk.y);
		}
	};
	
	//1行内のブロックの個数・消去したライン数
	int num=0,delLine=0;
	//一番下の行から探索
	for(int y=BMY+1;y>=0;y--){
		//その行にあるブロックの個数を取得
		num=count_if(blkList.begin(),blkList.end(),BlkLineFunctor(y*BS));
		
		//1行全て埋まっていたら
		if(num==BMX){
			//その行の全てのブロックを消す
			blkList.remove_if(BlkLineFunctor(y*BS));
			
			//その行より上にあるブロックを一段下ろす
			for(list<Block>::iterator it=blkList.begin();
				it!=blkList.end();++it){
				if(it->y<y*BS){
					it->y+=BS;
				}
			}

			//消去ライン数カウント
			delLine++;

			//同じところから探索再開
			y++;

		}//何もなければ探索終了
		else if(num==0){
			break;
		}
	}

	//消去したライン数を返す
	return delLine;
}