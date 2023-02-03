//draw.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//”wŒi•`‰æ
void drawBack(){
	DrawBox(FX,FY,FMX,FMY,color[RED],false);
	
	Rect r=Cell::base;
	Point p=r.GetLeftHigh();
	Point q=r.GetRightLow();
	DrawBox(p.x,p.y,q.x,q.y,color[YELLOW],false);

	const int CN=pow(2,N);
	CPoint<int> CS((q.x-p.x)/CN,(q.y-p.y)/CN);
	for(int i=1;i<CN;i++){
		DrawLine(p.x+CS.x*i,p.y,p.x+CS.x*i,q.y,color[WHITE]);
		DrawLine(p.x,p.y+CS.y*i,q.x,p.y+CS.y*i,color[WHITE]);
	}

}

//Mover•`‰æ
void drawTask(){
	for(list<Mover*>::iterator it=taskList.begin();
		it!=taskList.end();++it){
		(*it)->Draw();
	}
}

//î•ñ•`‰æ
void drawInfo(){

	DrawFormatString(FMX+FX+20,FY,color[WHITE],"      M  range");

	//©‹@‚Ìî•ñ‚ğ•`‰æ
	DrawCircle(FMX+FX+20,FY+40,bpp->r,color[WHITE],false);
	if(bpp!=NULL){
		DrawFormatString(FMX+FX+20,FY+40,color[WHITE],"     %2d   %d",bpp->cp->M,(int)(bpp->r));
	}

	//Õ“Ë‚µ‚Ä‚¢‚é•¨‘Ì‚É‚Â‚¢‚Ä•`‰æ
	DrawCircle(FMX+FX+20,FY+90,bpp->r,color[YELLOW],true);
	if(mpp!=NULL){
		DrawFormatString(FMX+FX+20,FY+80,color[WHITE],"     %2d   %d",mpp->cp->M,(int)(mpp->r));
	}

	//Œ»İ‘¶İ‚·‚é•¨‘Ì‚Ì”
	DrawFormatString(FMX+FX,FY+120,color[WHITE],"now exist object num");
	DrawFormatString(FMX+FX,FY+140,color[WHITE]," = %3d/%d  step %d",bNum,B_MAX,B_NUM);

	//Œ»İŠÔŒv‘ªƒtƒŒ[ƒ€”
	DrawFormatString(FMX+FX,FY+160,color[WHITE],"now measure frame num");
	DrawFormatString(FMX+FX,FY+180,color[WHITE]," = %3d/%d",quadST.size(),F_NUM);

}

//•`‰æƒƒCƒ“
void drawMain(){
	drawBack();

	drawInfo();

	drawTask();
}
