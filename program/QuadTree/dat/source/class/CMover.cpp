//CMover.cpp
//2013/12/08 written by shift
#include "../../include/main.h"

//������

//�R���X�g���N�^
Mover::Mover():cp(NULL){
	setMember(0.0,0.0,0.0);
}
Mover::Mover(const Point& p,float _r):cp(NULL){
	setMember(p.x,p.y,_r);
}
Mover::Mover(float _x,float _y,float _r):cp(NULL){
	setMember(_x,_y,_r);
}

//�f�X�g���N�^
Mover::~Mover(){
	if(cp!=NULL){
		cp->Remove();
		delete cp;
		cp=NULL;
	}
}

//�����o�ݒ�p�֐�
void Mover::setMember(float x,float y,float r){
	this->x=x;
	this->y=y;
	this->r=r;
	this->alive=true;
	if(this->cp==NULL){
		this->cp=new Cell(this);
	}
}

//�Փ˔���
Mover* Mover::IsCollision(/*const */Mover* m){
	float dx=m->x-x;
	float dy=m->y-y;
	float dr=m->r+r;
	return (((dx*dx)+(dy*dy)<(dr*dr))?m:NULL);
}

//�Փ˔���
Mover* Mover::IsCollision(){
	
	//���Ԍv���p
	uint s,e;
	Mover* am=NULL;

	//�S�T��
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

	//�S�T���i�r���Ō��������甲����j
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

	//�l���ؒT��
	s=GetNowHiPerformanceCount();
	Mover* cm=cp->IsCollision();
	e=GetNowHiPerformanceCount();
	quadST.push_back((uint)(e-s));

	if(cm!=NULL)mpp=dynamic_cast<Bullet*>(cm);
	else mpp=NULL;

	return cm;
}

//���g�𕢂���`
Rect Mover::GetRect() const{
	return Rect(x-r/2,y-r/2,2*r,2*r);
}

//�X�V
void Mover::Move(){
	if(x<FX-FY || FMX+FY<x || y<FY-FY || FMY+FY<y){
		alive=false;
		return ;
	}

	if(cp!=NULL){
		cp->Update();
	}
}

//�`��
void Mover::Draw(){
	DrawCircle(x,y,r,color[RED],true);
}

