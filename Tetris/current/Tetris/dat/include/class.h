//class.h

//パッドクラス
class Pad{
public:
	int key[PAD_MAX];
	Pad(){memset(key,0,sizeof(int)*PAD_MAX);}
};

//キーコンフィグクラス
class Config{
public:
	int left,right,up,down;
	int lspin,rspin,stock,start;
	Config():left(1) ,right(2),up(3)   ,down(0),
			 lspin(4),rspin(5),stock(9),start(8){}
};

//座標クラス
class Point{
public:
	//座標
	int x,y;

private:
	//コピー関数
	template<class T,class U>
	void copy(const T& x,const U& y){
		this->x=static_cast<int>(x);
		this->y=static_cast<int>(y);
	}

public:
	//コンストラクタ
	Point(){
		copy(0,0);
	}
	//コピーコンストラクタ
	Point(const Point& p){
		copy(p.x,p.y);
	}
	//2引数を取るコンストラクタ
	template<class T,class U>
	Point(const T& x,const U& y){
		copy(x,y);
	}

	//[=]演算子オーバーロード
	Point& operator=(const Point& p){
		copy(p.x,p.y);
		return *this;
	}
	//[()]演算子オーバーロード
	template<class T,class U>
	Point& operator()(const T& x,const U& y){
		copy(x,y);
		return *this;
	}

	//デストラクタ
	virtual ~Point(){}

};

//ブロッククラス
class Block : public Point{
public:
	//色
	BLK_COL knd;

	//コンストラクタ
	Block():Point(),knd(RED){}
	Block(const Point& p,BLK_COL k):Point(p),knd(k){}

	//デストラクタ
	virtual ~Block(){}
};

//テトリミノクラス
class TetriMino : public Point{
public:
	//構成する4つのブロック
	Block blk[4];
	//カウンタ・着地してからの猶予時間
	int cnt,wait;
	//画面内有効フラグ
	bool flag;
	//フィールド座標
	bool field[5][5];

	//コンストラクタ
	TetriMino():cnt(0),wait(0),flag(false){
		memset(field,false,sizeof(bool)*5*5);
	}

	//デストラクタ
	virtual ~TetriMino(){}
};
