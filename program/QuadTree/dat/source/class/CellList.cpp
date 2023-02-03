//CellList.cpp
//2013/12/08 written by shift
#include "../../include/main.h"

/*
//��ԃ��X�g�N���X
class CellList{
public:
	//���`��ԃ��X�g
	Cell* cpList;

	//�R���X�g���N�^
	CellList();
	//�f�X�g���N�^
	virtual ~CellList();

	//���X�g�ɒǉ�
	void Push(Cell* cp);
	//�Փ˔���
	Mover* IsCollision(int index,Mover* m);
};
*/

//�R���X�g���N�^
CellList::CellList(){
	cpList=new Cell[Cell::GetIndex(N+1,0)];
}

//�f�X�g���N�^
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

//���X�g�ɒǉ�
void CellList::Push(Cell* cp){
	int m=cp->M;
	int iMax=Cell::GetIndex(N+1,0);

	assert(0<=m && m<iMax);

	cp->next=cpList[m].next;
	cp->prev=&cpList[m];
	cp->next->prev=cp->prev->next=cp;
}

//�Փ˔���(�w�肳�ꂽ�C���f�b�N�X�̋�ԓ��ɂ��镨�̂Ɣ���)
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
