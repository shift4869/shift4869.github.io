//end.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//�I������
void end(){
	for(list<Mover*>::iterator it=taskList.begin();
		it!=taskList.end();){
		delete (*it);
		it=taskList.erase(it);
	}

	//delete cellList;

	//DX���C�u�����I��
	DxLib_End();
}
