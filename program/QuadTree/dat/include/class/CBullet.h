//CBullet.h
//2013/12/08 written by shift

//�e
class Bullet : public Mover{
public:
	//�p�x,���x
	float ang,spd;
	//�F,(���(����͔��a�����_���̉~))
	int col;
	//int knd;

	//�R���X�g���N�^
	Bullet();
	Bullet(Point p,float range,float angle,float speed,int color);

	//�f�X�g���N�^
	virtual ~Bullet();

protected:
	//�����o�ݒ�p�֐�
	virtual void setMember(float x,float y,float r,
							float angle,float speed,int color);

public:
	//�X�V
	virtual void Move();
	//�`��
	virtual void Draw();
};

//���˒e
class ReflecBullet : public Bullet{
public:
	//���˂���͈͋�`
	static Rect base;

	//�R���X�g���N�^
	ReflecBullet();
	ReflecBullet(Point p,float range,float angle,float speed,int color);

	//�f�X�g���N�^
	virtual ~ReflecBullet();

	//�X�V
	virtual void Move();
};
