//IsValid.cpp
#include "../include/main.h"

//�w�肳�ꂽ���W���t�B�[���h���ɂ��邩
//true->�t�B�[���h���ɂ��� false->�t�B�[���h���ɂȂ�
bool IsInField(const Point& p){
	return ((FX<=p.x) && (p.x<FMX) && 
			/*(FY<=p.y) && */(p.y<FMY));
}

//�w�肳�ꂽ�e�g���~�m���t�B�[���h���ɂ��邩
//true->�t�B�[���h���ɂ��� false->�t�B�[���h���ɂȂ�
bool IsInField(const TetriMino& t){
	for(int i=0;i<4;i++){
		if(!IsInField((Point)t.blk[i]))return false;
	}
	return true;
}

//�w�肳�ꂽ�e�g���~�m�����ɂ���u���b�N�ɖ��܂��ĂȂ���
//true->���܂��Ă��� false->���܂��Ă��Ȃ�
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

//�e�g���~�m���L���Ȉʒu�ɂ��邩
//true->�L���ł��� false->�����ł���
bool IsValid(const TetriMino& t){
	return ( IsInField(t) && !IsBury(t) );
}

