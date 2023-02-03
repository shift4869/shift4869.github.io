//CellList.cpp
//2013/12/08 written by shift
#include "../../include/main.h"

/*
//空間リストクラス
class CellList{
public:
	//線形空間リスト
	Cell* cpList;

	//コンストラクタ
	CellList();
	//デストラクタ
	virtual ~CellList();

	//リストに追加
	void Push(Cell* cp);
	//衝突判定
	Mover* IsCollision(int index,Mover* m);
};
*/

//コンストラクタ
CellList::CellList(){
	cpList=new Cell[Cell::GetIndex(N+1,0)];
}

//デストラクタ
CellList::~CellList(){
	/*Cell* cp=NULL;
	for(int i=0,s=Cell::GetIndex(N,0);i<s;i++){
		cp=cpList[i].next;
		for(Cell* np=NULL;cp!=&cpList[i];cp=np){
			np=cp->next;
			if(cp!=NULL){
				delete cp;
				cp=NULL;
			}
		}
	}*/
	delete[] cpList;
}

//リストに追加
void CellList::Push(Cell* cp){
	int m=cp->M;
	int iMax=Cell::GetIndex(N+1,0);

	assert(0<=m && m<iMax);

	cp->next=cpList[m].next;
	cp->prev=&cpList[m];
	cp->next->prev=cp->prev->next=cp;
}

//衝突判定(指定されたインデックスの空間内にある物体と判定)
Mover* CellList::IsCollision(int index,Mover* m){
	Mover* mp=NULL;
	for(Cell *cp=cpList[index].next,*np=NULL;
		cp!=&cpList[index];){
		np=cp->next;

		mp=m->IsCollision(cp->mp);
		if(mp!=NULL && m!=mp){
			return mp;
		}

		cp=np;
	}

	return NULL;
}
