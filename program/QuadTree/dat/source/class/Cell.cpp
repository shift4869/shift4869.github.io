//CCell.cpp
//2013/12/08 written by shift
#include "../../include/main.h"

/*
//��ԃN���X
class Cell{
public:
	//���[�g���
	static Rect base;
	//��ԃ��x��,�e���x���ł̃C���f�b�N�X,
	//���`�l���؂ɂ�����C���f�b�N�X
	int L,I,M;
	//�Ώە���
	Mover* mp;
	//�o�������X�g
	Cell *prev,*next;

	//�R���X�g���N�^
	Cell();
	Cell(Mover* m);
	//�f�X�g���N�^
	virtual ~Cell();

	//�o�������X�g���甲����
	void Remove();
	//�Փ˔���
	Mover* IsCollision();
	//��ʒT��
	Mover* UpperSearch();
	//���ʒT��
	Mover* LowerSearch(int nr);
	//L,I����M�����߂�
	static int GetIndex(int L,int I);
	//�r�b�g���P���Y����
	static byte BitSlide(byte b);
	//�傫���������Ȃ��_���烂�[�g�����������߂�
	static int PointtoMorton(Point p);
	//�傫���������̂��烂�[�g�����������߁AL,i<M��ݒ肷��
	static void MovertoMorton(const Mover& m,int& L,int& I,int& r);

	//mp�ɍ��킹�ă��[�g���������X�V����
	void Update();
};
*/
//���[�g���
Rect Cell::base = Rect(FX-FY,FY-FY,FLX+FY*2,FLY+FY*2);

//�R���X�g���N�^
Cell::Cell():
L(-1),I(-1),M(-1),mp(NULL){
	next=prev=this;
}
Cell::Cell(Mover* m):
L(-1),I(-1),M(-1),mp(m){
	next=prev=this;
	MovertoMorton(*mp,L,I,M);
}
//�f�X�g���N�^
Cell::~Cell(){}

//��ʒT��
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

//���ʒT��
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

//�r�b�g���P���Y����
byte Cell::BitSlide(byte b){
	b=(b|b<<2)&0x33;
	b=(b|b<<1)&0x55;
	return b;
}

//�傫���������Ȃ��_���烂�[�g�����������߂�
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

//�傫���������̂��烂�[�g�����������߁AL,i->M��ݒ肷��
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

//�Փ˔���
Mover* Cell::IsCollision(){
	Mover* mr=NULL;
	
	//�����x���T��
	mr=cellList.IsCollision(this->M,this->mp);
	if(mr!=NULL)return mr;

	//����T��
	mr=UpperSearch();
	if(mr!=NULL)return mr;

	//�����T��
	mr=LowerSearch(M);

	return mr;
}

//�o�������X�g���甲����
void Cell::Remove(){
	this->next->prev=this->prev;
	this->prev->next=this->next;
}

//L,I����M�����߂�
int Cell::GetIndex(int L,int I){
	return (pow(4,L)-1)/(4-1)+I;
}

//mp�ɍ��킹�ă��[�g���������X�V����
void Cell::Update(){
	Remove();

	MovertoMorton(*mp,L,I,M);

	cellList.Push(this);

}
