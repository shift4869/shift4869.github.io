//run.cpp
//2013/12/08 written by shift
#include "../include/main.h"
#include <numeric>

//���s���C��
void runMain(){
	//�^�X�N���X�g���s
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

	//���͎�t
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

	//�Փ˔���
	Mover* mp=bpp->IsCollision();
	if(mp!=NULL){
		dynamic_cast<Bullet*>(mp)->col=YELLOW;
	}

	
	/*
	//���Ԋu�Ń����_���ɒe�𐶐�����
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
	
	//�v���t���[�����ɂȂ�����
	if(allST.size()>=F_NUM){
		//���ϒl���擾
		uint aveAllST,aveAllCutST,aveQuadST;
		aveAllST=accumulate(allST.begin(),allST.end(),0)/allST.size();
		aveAllCutST=accumulate(allCutST.begin(),allCutST.end(),0)/allCutST.size();
		aveQuadST=accumulate(quadST.begin(),quadST.end(),0)/quadST.size();

		//�v���p�o�b�t�@�N���A
		allST.clear();
		allCutST.clear();
		quadST.clear();

		//�t�@�C���o��(.csv�t�@�C���`��)
		ofstream fout("./result.txt",ios::binary|ios::app);
		string str=Format("%d,%d,%d,%d",bNum,aveAllST,aveAllCutST,aveQuadST);
		fout<<str.c_str()<<endl;
		fout.close();

		//��ʓ��̒e�𑝂₷(B_MAX�܂�)
		float ang,spd;
		Bullet *bp;
		for(int i=0;i<B_NUM;i++,bNum++){
			ang=Rand(0,360);
			spd=Rand(1,3);
			bp=new ReflecBullet(Point(FCX,FCY),Rand(10,35),ang,spd,WHITE);
			taskList.push_front((Mover*)bp);
		}

		//�v���I��
		if(bNum>B_MAX){
			loopFlag=false;
		}
	}

	//�S�̃Q�[���J�E���^�A�b�v
	gameCnt++;
}
