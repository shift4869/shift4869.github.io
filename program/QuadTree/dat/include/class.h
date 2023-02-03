//class.h
//2013/12/08 written by shift

//�p�b�h�N���X
class Pad{
public:
	int key[PAD_MAX];
	Pad(){memset(key,0,sizeof(int)*PAD_MAX);}
};

//�R���t�B�O�N���X
class Config{
public:
	//��,��,��,��,�X�^�[�g�L�����Z��
	int left,right,up,down,start;
	Config():left(1) ,right(2),up(3)   ,down(0)  ,
			 start(13){}
};

//���W�N���X
//�e���v���[�g�N���X
template<class T>
class CPoint{
public:
	T x,y;//���W(x,y)

private:
	//�R�s�[�֐�
	template<class U,class V>
	inline void copy(U x,V y){
		this->x=static_cast<T>(x);
		this->y=static_cast<T>(y);
	}

public:
	//�f�t�H���g�R���X�g���N�^
	inline CPoint(){
		copy(0,0);
	}

	//2���������R���X�g���N�^
	template<class U,class V>
	inline CPoint(U x,V y){
		copy(x,y);
	}

	//�R�s�[�R���X�g���N�^
	inline CPoint(const CPoint &p){
		copy(p.x,p.y);
	}

	//�f�X�g���N�^
	virtual ~CPoint(){}

	//������Z�q�u=�v
	CPoint &operator=(const CPoint &p){
		copy(p.x,p.y);
		return *this;
	}

	//�֐��Ăяo���u()�v
	//���W���C���[�W���đ��
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

	//���Z���Z�q�u+�v
	CPoint operator+(const CPoint &p){
		return CPoint(this->x+p.x,this->y+p.y);
	}

	//���Z����u+=�v
	CPoint &operator+=(const CPoint &p){
		this->operator=(this->operator+(p));
		return *this;
	}

	//��r�u==�v
	//CPoint<int>�ȊO�͂��܂������Ȃ��\������
	bool operator==(const CPoint &p){
		return (this->x==p.x && this->y==p.y);
	}

	//��r�u!=�v
	//CPoint<int>�ȊO�͂��܂������Ȃ��\������
	bool operator!=(const CPoint &p){
		return !operator==(p);
	}

};
typedef CPoint<float> Point;

//��`�N���X
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
	//�R���X�g���N�^
	CRect():x(0),y(0),w(0),h(0){}
	CRect(T X,T Y,T Width,T Height){
		copy(X,Y,Width,Height);
	}
	CRect(const CPoint<T>& LeftHigh,const CPoint<T>& RightLow){
		copy(LeftHigh.x,LeftHigh.y,RightLow.x-LeftHigh.x,RightLow.y-LeftHigh.y);
	}
	//�f�X�g���N�^
	virtual ~CRect(){}

	//��`�e4�_�擾�֐�(y���W�́�����)
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

//�����̃N���X
#include "./class/CMover.h"
//��ԃN���X
#include "./class/CCell.h"
//��ԃ��X�g�N���X
#include "./class/CCellList.h"
//�����̃N���X
#include "./class/CBullet.h"
