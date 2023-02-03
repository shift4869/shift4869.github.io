//CBullet.cpp
//2013/12/08 written by shift
#include "../../include/main.h"

/*
//弾
class Bullet : public Mover{
public:
	//角度,速度
	float ang,spd;
	//色,(種類(今回は半径ランダムの円))
	int col;
	//int knd;

	//コンストラクタ
	Bullet();
	Bullet(Point p,float range,float angle,float speed,int color);

	//デストラクタ
	virtual ~Bullet();

protected:
	//メンバ設定用関数
	virtual void setMember(float x,float y,float r,
							float angle,float speed,int color);

public:
	//更新
	virtual void Move();
	//描画
	virtual void Draw();
};
*/

//コンストラクタ
Bullet::Bullet(){
	setMember(0,0,0,0.0,0.0,RED);
}
Bullet::Bullet(Point p,float range,float angle,float speed,int color){
	setMember(p.x,p.y,range,angle,speed,color);
}
//デストラクタ
Bullet::~Bullet(){}

//メンバ設定用関数
void Bullet::setMember(float x,float y,float r,
						float angle,float speed,int color){
	Mover::setMember(x,y,r);
	this->ang=angle;
	this->spd=speed;
	this->col=color;
}

//更新
void Bullet::Move(){
	x+=cosd(ang)*spd;
	y+=sind(ang)*spd;

	col=WHITE;

	Mover::Move();
}

//描画
void Bullet::Draw(){
	bool f=this==bpp;
	DrawCircle(x,y,r,color[col],!f);
}



/*
//反射弾
class ReflecBullet : public Bullet{
public:
	static Rect base;

	//コンストラクタ
	ReflecBullet();
	ReflecBullet(Point p,float range,float angle,float speed,int color);

	//デストラクタ
	virtual ~ReflecBullet();

	//更新
	virtual void Move();
	//描画
	virtual void Draw();
};
*/

//反射する範囲矩形
Rect ReflecBullet::base = Rect(FX,FY,FLX,FLY);
//コンストラクタ
ReflecBullet::ReflecBullet():Bullet(){}
ReflecBullet::ReflecBullet(Point p,float range,float angle,float speed,int color):
Bullet(p,range,angle,speed,color)
{}
//デストラクタ
ReflecBullet::~ReflecBullet(){}

//更新
void ReflecBullet::Move(){
	//反射処理
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
