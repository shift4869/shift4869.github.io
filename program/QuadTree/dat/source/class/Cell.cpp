//CCell.cpp
//2013/12/08 written by shift
#include "../../include/main.h"

/*
//空間クラス
class Cell{
public:
	//ルート空間
	static Rect base;
	//空間レベル,各レベルでのインデックス,
	//線形四分木におけるインデックス
	int L,I,M;
	//対象物体
	Mover* mp;
	//双方向リスト
	Cell *prev,*next;

	//コンストラクタ
	Cell();
	Cell(Mover* m);
	//デストラクタ
	virtual ~Cell();

	//双方向リストから抜ける
	void Remove();
	//衝突判定
	Mover* IsCollision();
	//上位探索
	Mover* UpperSearch();
	//下位探索
	Mover* LowerSearch(int nr);
	//L,IからMを求める
	static int GetIndex(int L,int I);
	//ビットを１つずつズラす
	static byte BitSlide(byte b);
	//大きさを持たない点からモートン符号を求める
	static int PointtoMorton(Point p);
	//大きさを持つ物体からモートン符号を求め、L,i<Mを設定する
	static void MovertoMorton(const Mover& m,int& L,int& I,int& r);

	//mpに合わせてモートン符号を更新する
	void Update();
};
*/
//ルート空間
Rect Cell::base = Rect(FX-FY,FY-FY,FLX+FY*2,FLY+FY*2);

//コンストラクタ
Cell::Cell():
L(-1),I(-1),M(-1),mp(NULL){
	next=prev=this;
}
Cell::Cell(Mover* m):
L(-1),I(-1),M(-1),mp(m){
	next=prev=this;
	MovertoMorton(*mp,L,I,M);
}
//デストラクタ
Cell::~Cell(){}

//上位探索
Mover* Cell::UpperSearch(){
	int m=M;
	Mover* mr=NULL;

	for(int i=L-1;i>=0;i--){
		m=(m-1)/4;

		mr=cellList.IsCollision(m,this->mp);
		if(mr!=NULL){
			return mr;
		}
	}

	return NULL;
}

//下位探索
Mover* Cell::LowerSearch(int nr){
	Mover* mr=NULL;
	mr=cellList.IsCollision(nr,this->mp);
	if(mr!=NULL){
		return mr;
	}

	nr=nr*4+1;

	for(int i=0,n=GetIndex(N+1,0);i<4;i++){
		if(nr+i < n){
			mr=LowerSearch(nr+i);
			if(mr!=NULL)return mr;
		}else break;
	}

	return NULL;
}

//ビットを１つずつズラす
byte Cell::BitSlide(byte b){
	b=(b|b<<2)&0x33;
	b=(b|b<<1)&0x55;
	return b;
}

//大きさを持たない点からモートン符号を求める
int Cell::PointtoMorton(Point p){
	const int CN=pow(2,N);
	Point a=base.GetLeftHigh();
	Point b=base.GetRightLow();
	CPoint<int> CS((b.x-a.x)/CN,(b.y-a.y)/CN);
	CPoint<int> m((p.x-a.x)/CS.x,(p.y-a.y)/CS.y);

	byte kx,ky;
	kx=BitSlide(m.x);
	ky=BitSlide(m.y);

	return kx|(ky<<1);
}

//大きさを持つ物体からモートン符号を求め、L,i->Mを設定する
void Cell::MovertoMorton(const Mover& m,int& L,int& I,int& M){
	Point a=Point(m.x-m.r/2,m.y-m.r/2);
	Point b=Point(m.x+m.r/2,m.y+m.r/2);

	int ma=PointtoMorton(a);
	int mb=PointtoMorton(b);

	int k=0;
	for(int m=ma^mb;m!=0;m>>=2,k++);

	L=N-k;
	I=mb>>(2*k);
	M=GetIndex(L,I);
}

//衝突判定
Mover* Cell::IsCollision(){
	Mover* mr=NULL;
	
	//同レベル探索
	mr=cellList.IsCollision(this->M,this->mp);
	if(mr!=NULL)return mr;

	//上方探索
	mr=UpperSearch();
	if(mr!=NULL)return mr;

	//下方探索
	mr=LowerSearch(M);

	return mr;
}

//双方向リストから抜ける
void Cell::Remove(){
	this->next->prev=this->prev;
	this->prev->next=this->next;
}

//L,IからMを求める
int Cell::GetIndex(int L,int I){
	return (pow(4,L)-1)/(4-1)+I;
}

//mpに合わせてモートン符号を更新する
void Cell::Update(){
	Remove();

	MovertoMorton(*mp,L,I,M);

	cellList.Push(this);

}
