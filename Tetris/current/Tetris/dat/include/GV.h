//GV.h
#ifdef FIRST_LOADING
#define E 
#else
#define E extern
#endif

//�R���t�B�O�N���X
E Config config;

//�摜�C���[�W
namespace IMG{
	E int board[3];//�w�i�摜
	E int block[7];//�u���b�N�摜
	E int num[10]; //�����摜
};

//���݂̃e�g���~�m
E TetriMino cur;

//�t�B�[���h��̃u���b�N
E list<Block> blkList;

//�l�N�X�g�u���b�N���X�g
E list<TetriMino> nextList;

//�X�g�b�N
E TetriMino stock;

//�h���b�v�V���h�E
E TetriMino shadow;
