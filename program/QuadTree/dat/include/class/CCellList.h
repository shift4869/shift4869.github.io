//CCellList.h
//2013/12/08 written by shift

//�O���錾
class Mover;
class Cell;

//��ԃ��X�g�N���X
class CellList{
public:
	//���`��ԃ��X�g
	Cell* cpList;

	//�R���X�g���N�^
	CellList();
	//�f�X�g���N�^
	virtual ~CellList();

	//���X�g�ɒǉ�
	void Push(Cell* cp);
	//�Փ˔���
	Mover* IsCollision(int index,Mover* m);
};
