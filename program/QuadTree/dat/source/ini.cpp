//ini.cpp
//2013/12/08 written by shift
#include "../include/main.h"
#include <time.h>

//���\�[�X���[�h
extern void load();

void ini(){
	//�F�ݒ�
	color[RED]		=GetColor(255,0,0);
	color[GREEN]	=GetColor(0,255,0);
	color[PURPLE]	=GetColor(167,87,168);
	color[BLUE]		=GetColor(0,0,255);
	color[ORANGE]	=GetColor(255,183,76);
	color[YELLOW]	=GetColor(255,212,0);
	color[SKY]		=GetColor(144,215,236);
	color[WHITE]	=GetColor(255,255,255);
	color[BLACK]	=GetColor(0,0,0);

	//���\�[�X���[�h
	load();

	//�S�̃��[�v�t���Oon
	loopFlag=true;

	//�����평����
	srand((uint)time(NULL));

	//���@��z�肵���e(1�Α������1�̕�)
	float ang,spd;
	ang=Rand(0,360);
	spd=Rand(1,3);
	bpp=new ReflecBullet(Point(FCX,FCY),20,ang,spd,RED);
	taskList.push_back(bpp);


	/*ang=randTable.GetRand(0,360);
	spd=randTable.GetRand(1,3);
	Bullet *bp=new ReflecBullet(Point(FCX,FCY),randTable.GetRand(10,35),ang,spd,WHITE);
	taskList.push_front((Mover*)bp);
	bNum++;*/
}
