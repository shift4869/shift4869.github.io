//run.cpp
//2013/12/08 written by shift
#include "../include/main.h"
#include <numeric>

//実行メイン
void runMain(){
	//タスクリスト実行
	for(list<Mover*>::iterator it=taskList.begin();
		it!=taskList.end();){
		(*it)->Move();
		if((*it)->alive){
			++it;
		}
		else{
			delete (*it);
			it=taskList.erase(it);
		}
	}

	//入力受付
	int input[PAD_MAX]={
		CheckStatePad(config.left),
		CheckStatePad(config.right),
		CheckStatePad(config.up),
		CheckStatePad(config.down),
		CheckStatePad(config.start),
	};
	const float spd=5;
	if(input[0]==1 || (input[0]>0 && input[0]%5==1)){
		bpp->x-=spd;
		if(bpp->x<FX+bpp->r/2)bpp->x=FX+bpp->r/2;
	}
	if(input[1]==1 || (input[1]>0 && input[1]%5==1)){
		bpp->x+=spd;
		if(bpp->x>FMX-bpp->r/2)bpp->x=FMX-bpp->r/2;
	}
	if(input[2]==1 || (input[2]>0 && input[2]%5==1)){
		bpp->y-=spd;
		if(bpp->y<FY+bpp->r/2)bpp->y=FY+bpp->r/2;
	}
	if(input[3]==1 || (input[3]>0 && input[3]%5==1)){
		bpp->y+=spd;
		if(bpp->y>FMY-bpp->r/2)bpp->y=FMY-bpp->r/2;
	}

	//衝突判定
	Mover* mp=bpp->IsCollision();
	if(mp!=NULL){
		dynamic_cast<Bullet*>(mp)->col=YELLOW;
	}

	
	/*
	//一定間隔でランダムに弾を生成する
	if(gameCnt%60==0){
		Bullet* bp=NULL;
		const int NUM=9;
		float ang,bAng,spd;
		bAng=randTable.GetRand(360);
		for(int i=0;i<NUM;i++){
			ang=LinearInterpolate(bAng,bAng+360,i,NUM);
			spd=LinearInterpolate(1.0,3.5,i,NUM);
			bp=new Bullet(Point(FCX,FCY),randTable.GetRand(10,35),ang,spd,WHITE);
			taskList.push_front((Mover*)bp);
		}
	}
	*/
	
	//計測フレーム数になったら
	if(allST.size()>=F_NUM){
		//平均値を取得
		uint aveAllST,aveAllCutST,aveQuadST;
		aveAllST=accumulate(allST.begin(),allST.end(),0)/allST.size();
		aveAllCutST=accumulate(allCutST.begin(),allCutST.end(),0)/allCutST.size();
		aveQuadST=accumulate(quadST.begin(),quadST.end(),0)/quadST.size();

		//計測用バッファクリア
		allST.clear();
		allCutST.clear();
		quadST.clear();

		//ファイル出力(.csvファイル形式)
		ofstream fout("./result.txt",ios::binary|ios::app);
		string str=Format("%d,%d,%d,%d",bNum,aveAllST,aveAllCutST,aveQuadST);
		fout<<str.c_str()<<endl;
		fout.close();

		//画面内の弾を増やす(B_MAX個まで)
		float ang,spd;
		Bullet *bp;
		for(int i=0;i<B_NUM;i++,bNum++){
			ang=Rand(0,360);
			spd=Rand(1,3);
			bp=new ReflecBullet(Point(FCX,FCY),Rand(10,35),ang,spd,WHITE);
			taskList.push_front((Mover*)bp);
		}

		//計測終了
		if(bNum>B_MAX){
			loopFlag=false;
		}
	}

	//全体ゲームカウンタアップ
	gameCnt++;
}
