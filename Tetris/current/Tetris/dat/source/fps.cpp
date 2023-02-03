//fps.cpp
#include "../include/main.h"

//fps�\��
void fps(){
	const int FRAME=60;
	static int t,ave,cnt,f[FRAME];

	f[cnt%FRAME]=GetNowCount()-t;
	t=GetNowCount();

	cnt++;

	if(cnt%FRAME==FRAME-1){
		ave=0;
		for(int i=0;i<FRAME;i++)ave+=f[i];
		ave/=FRAME;
		cnt=0;
	}
	if(ave!=0){
		float s=1000/(float)ave;		//fps
		int col=GetColor(255,255,255);	//��

		if(50>s && s>=30)	col=GetColor(255,255,0);//��
		else if(30>s)		col=GetColor(255,0,0);	//��

		//fps�\��
		DrawFormatString(555,460,col,"[%.1f]fps",s);
	}

	return;
}