//CBullet.cpp
//2013/12/08 written by shift
#include "../../include/main.h"

/*
//�e
class Bullet : public Mover{
public:
	//�p�x,���x
	float ang,spd;
	//�F,(���(����͔��a�����_���̉~))
	int col;
	//int knd;

	//�R���X�g���N�^
	Bullet();
	Bullet(Point p,float range,float angle,float speed,int color);

	//�f�X�g���N�^
	virtual ~Bullet();

protected:
	//�����o�ݒ�p�֐�
	virtual void setMember(float x,float y,float r,
							float angle,float speed,int color);

public:
	//�X�V
	virtual void Move();
	//�`��
	virtual void Draw();
};
*/

//�R���X�g���N�^
Bullet::Bullet(){
	setMember(0,0,0,0.0,0.0,RED);
}
Bullet::Bullet(Point p,float range,float angle,float speed,int color){
	setMember(p.x,p.y,range,angle,speed,color);
}
//�f�X�g���N�^
Bullet::~Bullet(){}

//�����o�ݒ�p�֐�
void Bullet::setMember(float x,float y,float r,
						float angle,float speed,int color){
	Mover::setMember(x,y,r);
	this->ang=angle;
	this->spd=speed;
	this->col=color;
}

//�X�V
void Bullet::Move(){
	x+=cosd(ang)*spd;
	y+=sind(ang)*spd;

	col=WHITE;

	Mover::Move();
}

//�`��
void Bullet::Draw(){
	bool f=this==bpp;
	DrawCircle(x,y,r,color[col],!f);
}



/*
//���˒e
class ReflecBullet : public Bullet{
public:
	static Rect base;

	//�R���X�g���N�^
	ReflecBullet();
	ReflecBullet(Point p,float range,float angle,float speed,int color);

	//�f�X�g���N�^
	virtual ~ReflecBullet();

	//�X�V
	virtual void Move();
	//�`��
	virtual void Draw();
};
*/

//���˂���͈͋�`
Rect ReflecBullet::base = Rect(FX,FY,FLX,FLY);
//�R���X�g���N�^
ReflecBullet::ReflecBullet():Bullet(){}
ReflecBullet::ReflecBullet(Point p,float range,float angle,float speed,int color):
Bullet(p,range,angle,speed,color)
{}
//�f�X�g���N�^
ReflecBullet::~ReflecBullet(){}

//�X�V
void ReflecBullet::Move(){
	//���ˏ���
	if(x-r<=base.x){
		ang=180-ang;
		x=base.x+r;
	}
	if(base.x+base.w<=x+r){
		ang=180-ang;
		x=base.x+base.w-r;
	}
	if(y-r<=base.y){
		ang=360-ang;
		y=base.y+r;
	}
	if(base.y+base.h<=y+r){
		ang=360-ang;
		y=base.y+base.h-r;
	}

	Bullet::Move();
}
