//CCell.h
//2013/12/08 written by shift

class Mover;

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

private:
	//��ʒT��
	Mover* UpperSearch();
	//���ʒT��
	Mover* LowerSearch(int nr);
	//�r�b�g���P���Y����
	static byte BitSlide(byte b);
	//�傫���������Ȃ��_���烂�[�g�����������߂�
	static int PointtoMorton(Point p);
	//�傫���������̂��烂�[�g�����������߁AL,i->M��ݒ肷��
	static void MovertoMorton(const Mover& m,int& L,int& I,int& r);

public:
	//�Փ˔���
	Mover* IsCollision();
	//�o�������X�g���甲����
	void Remove();
	//L,I����M�����߂�
	static int GetIndex(int L,int I);

	//mp�ɍ��킹�ă��[�g���������X�V����
	void Update();
};
