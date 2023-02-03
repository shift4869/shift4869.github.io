//class.h
//2013/12/08 written by shift

//パッドクラス
class Pad{
public:
	int key[PAD_MAX];
	Pad(){memset(key,0,sizeof(int)*PAD_MAX);}
};

//コンフィグクラス
class Config{
public:
	//←,→,↑,↓,スタートキャンセル
	int left,right,up,down,start;
	Config():left(1) ,right(2),up(3)   ,down(0)  ,
			 start(13){}
};

//座標クラス
//テンプレートクラス
template<class T>
class CPoint{
public:
	T x,y;//座標(x,y)

private:
	//コピー関数
	template<class U,class V>
	inline void copy(U x,V y){
		this->x=static_cast<T>(x);
		this->y=static_cast<T>(y);
	}

public:
	//デフォルトコンストラクタ
	inline CPoint(){
		copy(0,0);
	}

	//2引数を取るコンストラクタ
	template<class U,class V>
	inline CPoint(U x,V y){
		copy(x,y);
	}

	//コピーコンストラクタ
	inline CPoint(const CPoint &p){
		copy(p.x,p.y);
	}

	//デストラクタ
	virtual ~CPoint(){}

	//代入演算子「=」
	CPoint &operator=(const CPoint &p){
		copy(p.x,p.y);
		return *this;
	}

	//関数呼び出し「()」
	//座標をイメージして代入
	template<class U,class V>
	CPoint &operator()(U x,V y){
		copy(x,y);
		return *this;
	}
	template<class U>
	CPoint &operator()(U p){
		copy(p.x,p.y);
		return *this;
	}

	//加算演算子「+」
	CPoint operator+(const CPoint &p){
		return CPoint(this->x+p.x,this->y+p.y);
	}

	//加算代入「+=」
	CPoint &operator+=(const CPoint &p){
		this->operator=(this->operator+(p));
		return *this;
	}

	//比較「==」
	//CPoint<int>以外はうまく働かない可能性あり
	bool operator==(const CPoint &p){
		return (this->x==p.x && this->y==p.y);
	}

	//比較「!=」
	//CPoint<int>以外はうまく働かない可能性あり
	bool operator!=(const CPoint &p){
		return !operator==(p);
	}

};
typedef CPoint<float> Point;

//矩形クラス
template<typename T>
class CRect{
public:
	T x,y,w,h;
private:
	CRect<T>& copy(T x,T y,T w,T h){
		this->x=x;
		this->y=y;
		this->w=w;
		this->h=h;
		return *this;
	}
public:
	//コンストラクタ
	CRect():x(0),y(0),w(0),h(0){}
	CRect(T X,T Y,T Width,T Height){
		copy(X,Y,Width,Height);
	}
	CRect(const CPoint<T>& LeftHigh,const CPoint<T>& RightLow){
		copy(LeftHigh.x,LeftHigh.y,RightLow.x-LeftHigh.x,RightLow.y-LeftHigh.y);
	}
	//デストラクタ
	virtual ~CRect(){}

	//矩形各4点取得関数(y座標は↓が大)
	CPoint<T> GetLeftHigh(){
		return CPoint<T>(x,y);
	}
	CPoint<T> GetRightHigh(){
		return CPoint<T>(x+w,y);
	}
	CPoint<T> GetRightLow(){
		return CPoint<T>(x+w,y+h);
	}
	CPoint<T> GetLeftLow(){
		return CPoint<T>(x,y+h);
	}
};
typedef CRect<float> Rect;

//動物体クラス
#include "./class/CMover.h"
//空間クラス
#include "./class/CCell.h"
//空間リストクラス
#include "./class/CCellList.h"
//動物体クラス
#include "./class/CBullet.h"
