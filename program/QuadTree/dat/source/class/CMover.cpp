//CMover.cpp
//2013/12/08 written by shift
#include "../../include/main.h"

//動物体

//コンストラクタ
Mover::Mover():cp(NULL){
	setMember(0.0,0.0,0.0);
}
Mover::Mover(const Point& p,float _r):cp(NULL){
	setMember(p.x,p.y,_r);
}
Mover::Mover(float _x,float _y,float _r):cp(NULL){
	setMember(_x,_y,_r);
}

//デストラクタ
Mover::~Mover(){
	if(cp!=NULL){
		cp->Remove();
		delete cp;
		cp=NULL;
	}
}

//メンバ設定用関数
void Mover::setMember(float x,float y,float r){
	this->x=x;
	this->y=y;
	this->r=r;
	this->alive=true;
	if(this->cp==NULL){
		this->cp=new Cell(this);
	}
}

//衝突判定
Mover* Mover::IsCollision(/*const */Mover* m){
	float dx=m->x-x;
	float dy=m->y-y;
	float dr=m->r+r;
	return (((dx*dx)+(dy*dy)<(dr*dr))?m:NULL);
}

//衝突判定
Mover* Mover::IsCollision(){
	
	//時間計測用
	uint s,e;
	Mover* am=NULL;

	//全探索
	s=GetNowHiPerformanceCount();
	for(list<Mover*>::iterator it=taskList.begin();
		it!=taskList.end();++it){
		am=this->IsCollision(*it);
		if(am!=NULL && am!=this){
			//return am;
			//break;
		}
	}
	e=GetNowHiPerformanceCount();
	allST.push_back((uint)(e-s));

	//全探索（途中で見つかったら抜ける）
	s=GetNowHiPerformanceCount();
	for(list<Mover*>::iterator it=taskList.begin();
		it!=taskList.end();++it){
		am=this->IsCollision(*it);
		if(am!=NULL && am!=this){
			//return am;
			break;
		}
	}
	e=GetNowHiPerformanceCount();
	allCutST.push_back((uint)(e-s));

	//四分木探索
	s=GetNowHiPerformanceCount();
	Mover* cm=cp->IsCollision();
	e=GetNowHiPerformanceCount();
	quadST.push_back((uint)(e-s));

	if(cm!=NULL)mpp=dynamic_cast<Bullet*>(cm);
	else mpp=NULL;

	return cm;
}

//自身を覆う矩形
Rect Mover::GetRect() const{
	return Rect(x-r/2,y-r/2,2*r,2*r);
}

//更新
void Mover::Move(){
	if(x<FX-FY || FMX+FY<x || y<FY-FY || FMY+FY<y){
		alive=false;
		return ;
	}

	if(cp!=NULL){
		cp->Update();
	}
}

//描画
void Mover::Draw(){
	DrawCircle(x,y,r,color[RED],true);
}

