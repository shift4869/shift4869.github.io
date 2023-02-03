//class.h

//�p�b�h�N���X
class Pad{
public:
	int key[PAD_MAX];
	Pad(){memset(key,0,sizeof(int)*PAD_MAX);}
};

//�L�[�R���t�B�O�N���X
class Config{
public:
	int left,right,up,down;
	int lspin,rspin,stock,start;
	Config():left(1) ,right(2),up(3)   ,down(0),
			 lspin(4),rspin(5),stock(9),start(8){}
};

//���W�N���X
class Point{
public:
	//���W
	int x,y;

private:
	//�R�s�[�֐�
	template<class T,class U>
	void copy(const T& x,const U& y){
		this->x=static_cast<int>(x);
		this->y=static_cast<int>(y);
	}

public:
	//�R���X�g���N�^
	Point(){
		copy(0,0);
	}
	//�R�s�[�R���X�g���N�^
	Point(const Point& p){
		copy(p.x,p.y);
	}
	//2���������R���X�g���N�^
	template<class T,class U>
	Point(const T& x,const U& y){
		copy(x,y);
	}

	//[=]���Z�q�I�[�o�[���[�h
	Point& operator=(const Point& p){
		copy(p.x,p.y);
		return *this;
	}
	//[()]���Z�q�I�[�o�[���[�h
	template<class T,class U>
	Point& operator()(const T& x,const U& y){
		copy(x,y);
		return *this;
	}

	//�f�X�g���N�^
	virtual ~Point(){}

};

//�u���b�N�N���X
class Block : public Point{
public:
	//�F
	BLK_COL knd;

	//�R���X�g���N�^
	Block():Point(),knd(RED){}
	Block(const Point& p,BLK_COL k):Point(p),knd(k){}

	//�f�X�g���N�^
	virtual ~Block(){}
};

//�e�g���~�m�N���X
class TetriMino : public Point{
public:
	//�\������4�̃u���b�N
	Block blk[4];
	//�J�E���^�E���n���Ă���̗P�\����
	int cnt,wait;
	//��ʓ��L���t���O
	bool flag;
	//�t�B�[���h���W
	bool field[5][5];

	//�R���X�g���N�^
	TetriMino():cnt(0),wait(0),flag(false){
		memset(field,false,sizeof(bool)*5*5);
	}

	//�f�X�g���N�^
	virtual ~TetriMino(){}
};
