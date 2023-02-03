//IsValid.cpp
#include "../include/main.h"

//指定された座標がフィールド内にあるか
//true->フィールド内にある false->フィールド内にない
bool IsInField(const Point& p){
	return ((FX<=p.x) && (p.x<FMX) && 
			/*(FY<=p.y) && */(p.y<FMY));
}

//指定されたテトリミノがフィールド内にあるか
//true->フィールド内にある false->フィールド内にない
bool IsInField(const TetriMino& t){
	for(int i=0;i<4;i++){
		if(!IsInField((Point)t.blk[i]))return false;
	}
	return true;
}

//指定されたテトリミノが既にあるブロックに埋まってないか
//true->埋まっている false->埋まっていない
bool IsBury(const TetriMino& t){
	class TBListFunctor{
	public:
		Point p;
		TBListFunctor(Block blk){
			p.x=blk.x;
			p.y=blk.y;
		}
		bool operator()(Block blk){
			return (p.x==blk.x && p.y==blk.y);
		}
	};

	list<Block>::iterator it=blkList.begin();
	for(int i=0;i<4;i++){
		it=find_if(blkList.begin(),blkList.end(),TBListFunctor(t.blk[i]));
		if(it!=blkList.end()){
			return true;
		}
	}

	return false;
}

//テトリミノが有効な位置にいるか
//true->有効である false->無効である
bool IsValid(const TetriMino& t){
	return ( IsInField(t) && !IsBury(t) );
}

