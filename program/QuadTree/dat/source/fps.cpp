//fps.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//fps
const int FLAME=60;

int fps_cnt;
int f[FLAME];
double ave=16.6;

void fps(){
	static int t=0;

	f[fps_cnt]=GetNowCount()-t;//‚PŽü‚µ‚½ŽžŠÔ‚ð‹L˜^
	t=GetNowCount();

	//•½‹ÏŒvŽZ
	if(fps_cnt==FLAME-1){
		ave=0;
		for(int i=0;i<FLAME;i++)
			ave+=f[i];
		ave/=FLAME;
	}

	fps_cnt=(++fps_cnt)%FLAME;

	//F‘I’è
	int col=color[WHITE];
	float fps=1000.0/ave;
	if(fps<50.0)col=color[YELLOW];
	if(fps<30.0)col=color[RED];

	DrawFormatString(555,460,col,"[%.1f]fps",1000.0/ave);
}

