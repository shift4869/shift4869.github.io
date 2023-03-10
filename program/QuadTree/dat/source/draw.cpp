//draw.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//背景描画
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

//Mover描画
void drawTask(){
	for(list<Mover*>::iterator it=taskList.begin();
		it!=taskList.end();++it){
		(*it)->Draw();
	}
}

//情報描画
void drawInfo(){

	DrawFormatString(FMX+FX+20,FY,color[WHITE],"      M  range");

	//自機の情報を描画
	DrawCircle(FMX+FX+20,FY+40,bpp->r,color[WHITE],false);
	if(bpp!=NULL){
		DrawFormatString(FMX+FX+20,FY+40,color[WHITE],"     %2d   %d",bpp->cp->M,(int)(bpp->r));
	}

	//衝突している物体について描画
	DrawCircle(FMX+FX+20,FY+90,bpp->r,color[YELLOW],true);
	if(mpp!=NULL){
		DrawFormatString(FMX+FX+20,FY+80,color[WHITE],"     %2d   %d",mpp->cp->M,(int)(mpp->r));
	}

	//現在存在する物体の数
	DrawFormatString(FMX+FX,FY+120,color[WHITE],"now exist object num");
	DrawFormatString(FMX+FX,FY+140,color[WHITE]," = %3d/%d  step %d",bNum,B_MAX,B_NUM);

	//現在時間計測フレーム数
	DrawFormatString(FMX+FX,FY+160,color[WHITE],"now measure frame num");
	DrawFormatString(FMX+FX,FY+180,color[WHITE]," = %3d/%d",quadST.size(),F_NUM);

}

//描画メイン
void drawMain(){
	drawBack();

	drawInfo();

	drawTask();
}
