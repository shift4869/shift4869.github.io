
//���W�N���X
class Point{
public:
	float x,y;//���W

	Point(){x=y=0;}
	template<typename T,typename U>
	Point(T x,U y){this->x=(float)x;this->y=(float)y;}
};

//�ړ����̃N���X
class Mover : public Point{
public:
	float r;//�����蔼�a
	Mover(){r=0;}
};

//���[�U�[�N���X
class Lazer{
public:
	Point p[4];
};

//�}�N����`
#define PI 3.141592
#define RTOD(RAD) ((RAD)*(180/PI))
#define DTOR(DEG) ((DEG)*(PI/180))

//typedef�錾
typedef Point Vector;

//�x�N�g�������֐�
Vector CreateVector(const Point &p,const Point &q){
	return Vector(q.x-p.x,q.y-p.y);//p->q�x�N�g��
}

//�x�N�g���̓���
float InnerProduct(const Vector &a,const Vector &b){
	return (a.x*b.x+a.y*b.y);//a�Eb
}

//�x�N�g���̊O��
float OuterProduct(const Vector &a,const Vector &b){
	return (a.x*b.y-a.y*b.x);//a�~b
}

//�x�N�g���̒�����2��
float VectorLength2(const Vector &v){
	return InnerProduct(v,v);//v�Ev=|v|^2
}

//�~�Ɖ~�̐ڐG����
bool MoverCollision(const Mover &m1,const Mover &m2){
	float dx,dy,r;
	dx=m2.x-m1.x;
	dy=m2.y-m1.y;
	r =m2.r+m1.r;
	return ((dx*dx)+(dy*dy)<(r*r));//�������Ă�����true
}

//���[�U�[�̒[�_�Ƃ̐ڐG����
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

//���[�U�̊e��(����)�Ɖ~�̐ڐG����
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

//���[�U�[�����ɓ��荞��ł��Ȃ����̔���
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

//���[�U�[(�����`)�Ɖ~�̐ڐG����
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
