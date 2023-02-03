//CMover.h
//2013/12/08 written by shift

class Cell;

//動物体
class Mover : public Point{
public:
	//生存フラグ
	bool alive;
	//半径
	float r;
	//所属空間
	Cell* cp;

	//コンストラクタ
	Mover();
	Mover(const Point& p,float _r);
	Mover(float _x,float _y,float _r);

	//デストラクタ
	virtual ~Mover();

protected:
	//メンバ設定用関数
	virtual void setMember(float x,float y,float r);

public:
	//衝突判定
	virtual Mover* IsCollision(/*const */Mover* m);
	//衝突判定
	virtual Mover* IsCollision();
	//自身を覆う矩形
	virtual Rect GetRect() const;

	//更新
	virtual void Move();
	//描画
	virtual void Draw();
};
