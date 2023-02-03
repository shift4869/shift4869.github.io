//end.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//終了処理
void end(){
	for(list<Mover*>::iterator it=taskList.begin();
		it!=taskList.end();){
		delete (*it);
		it=taskList.erase(it);
	}

	//delete cellList;

	//DXライブラリ終了
	DxLib_End();
}
