//CMover.h
//2013/12/08 written by shift

class Cell;

//������
class Mover : public Point{
public:
	//�����t���O
	bool alive;
	//���a
	float r;
	//�������
	Cell* cp;

	//�R���X�g���N�^
	Mover();
	Mover(const Point& p,float _r);
	Mover(float _x,float _y,float _r);

	//�f�X�g���N�^
	virtual ~Mover();

protected:
	//�����o�ݒ�p�֐�
	virtual void setMember(float x,float y,float r);

public:
	//�Փ˔���
	virtual Mover* IsCollision(/*const */Mover* m);
	//�Փ˔���
	virtual Mover* IsCollision();
	//���g�𕢂���`
	virtual Rect GetRect() const;

	//�X�V
	virtual void Move();
	//�`��
	virtual void Draw();
};
