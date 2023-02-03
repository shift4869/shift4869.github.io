//CBullet.h
//2013/12/08 written by shift

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

//反射弾
class ReflecBullet : public Bullet{
public:
	//反射する範囲矩形
	static Rect base;

	//コンストラクタ
	ReflecBullet();
	ReflecBullet(Point p,float range,float angle,float speed,int color);

	//デストラクタ
	virtual ~ReflecBullet();

	//更新
	virtual void Move();
};
