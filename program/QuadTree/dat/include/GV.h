//GV.h
//2013/12/08 written by shift

//���񃍁[�h���̂ݎ��Ԓ�`����
//�C���N���[�h�K�[�h
#ifdef _FIRST_LOADING_
#define E 
#else if
#define E extern
#endif

//�R���t�B�O�N���X
E Config config;

//�f�o�b�O�p�F�ϐ�
E int color[COLOR_MAX];

//�摜�n���h��
namespace IMG{

};

//�t�H���g�n���h��
E int font[2];

//��ԃ��X�g
E CellList cellList;

//�����̃^�X�N���X�g
E list<Mover*> taskList;

//���@�i���z�j
E Bullet* bpp;

//�Փ˂��Ă��镨��
E Bullet* mpp;

//�S�̃Q�[���J�E���^
E uint gameCnt;

//�������Ԍv���p
E vector<uint> allST;
E vector<uint> allCutST;
E vector<uint> quadST;

//���ݒe��
E uint bNum;

//���[�v�t���O
E bool loopFlag;
