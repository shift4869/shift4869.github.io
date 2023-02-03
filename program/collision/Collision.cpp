
//座標クラス
class Point{
public:
	float x,y;//座標

	Point(){x=y=0;}
	template<typename T,typename U>
	Point(T x,U y){this->x=(float)x;this->y=(float)y;}
};

//移動物体クラス
class Mover : public Point{
public:
	float r;//当たり半径
	Mover(){r=0;}
};

//レーザークラス
class Lazer{
public:
	Point p[4];
};

//マクロ定義
#define PI 3.141592
#define RTOD(RAD) ((RAD)*(180/PI))
#define DTOR(DEG) ((DEG)*(PI/180))

//typedef宣言
typedef Point Vector;

//ベクトル生成関数
Vector CreateVector(const Point &p,const Point &q){
	return Vector(q.x-p.x,q.y-p.y);//p->qベクトル
}

//ベクトルの内積
float InnerProduct(const Vector &a,const Vector &b){
	return (a.x*b.x+a.y*b.y);//a・b
}

//ベクトルの外積
float OuterProduct(const Vector &a,const Vector &b){
	return (a.x*b.y-a.y*b.x);//a×b
}

//ベクトルの長さの2乗
float VectorLength2(const Vector &v){
	return InnerProduct(v,v);//v・v=|v|^2
}

//円と円の接触判定
bool MoverCollision(const Mover &m1,const Mover &m2){
	float dx,dy,r;
	dx=m2.x-m1.x;
	dy=m2.y-m1.y;
	r =m2.r+m1.r;
	return ((dx*dx)+(dy*dy)<(r*r));//当たっていたらtrue
}

//レーザーの端点との接触判定
bool LazerCollision1(const Lazer &laz,const Mover &m){
	Mover t;
	
	for(int i=0;i<4;i++){
		t.x=laz.p[i].x;	t.y=laz.p[i].y;
		if(MoverCollision(t,m)){
			return true;
		}
	}
	
	return false;
}

//レーザの各辺(線分)と円の接触判定
bool LazerCollision2(const Lazer &laz,const Mover &m){
	Vector pq,pm;
	float inner,k,pqd2,pmd2,phd2,d2;

	const int n[][4]={{0,1,3,2},{1,3,2,0}};
	for(int i=0;i<4;i++){
		pq=CreateVector(laz.p[n[0][i]],laz.p[n[1][i]]);//0.1.3.2:1.3.2.0
		pm=CreateVector(laz.p[n[0][i]],(Point)m);

		inner=InnerProduct(pq,pm);
		pqd2 =VectorLength2(pq);
		pmd2 =VectorLength2(pm);

		k=inner/pqd2;
		if(k<0 || 1<k)continue;
		phd2=inner*k;

		d2=pmd2-phd2;

		if(d2<m.r*m.r)return true;
	}
	
	return false;
}

//レーザー内部に入り込んでいないかの判定
bool LazerCollision3(const Lazer &laz,const Mover &m){
	Vector pp,pm;
	float inner,outer,theta[2];

	for(int i=0;i<2;i++){
		pp=CreateVector(laz.p[i*3],laz.p[1+i]);//0.1:3.2
		pm=CreateVector(laz.p[i*3],(Point)m);

		inner=InnerProduct(pp,pm);
		outer=OuterProduct(pp,pm);

		theta[i]=RTOD(atan2(outer,inner));
	}

	if(0<=theta[0] && theta[0]<=90 &&
	   0<=theta[1] && theta[1]<=90){
			return true;
	}

	return false;
}

//レーザー(長方形)と円の接触判定
bool LazerCollision(const Lazer &laz,const Mover &m){
	bool(*lazer_collision[])(const Lazer &laz,const Mover &m)={
		LazerCollision1,
		LazerCollision2,
		LazerCollision3,
	};

	for(int i=0;i<3;i++){
		if((*lazer_collision[i])(laz,m)){
			return true;
		}
	}
	return false;
}
