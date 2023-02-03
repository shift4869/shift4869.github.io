//Spin.cpp
#include "../include/main.h"

//�e�g���~�m�̉�]����
bool Spin(TetriMino& t,bool isLeft){

	//���F�͉�]���Ȃ�
	if(t.blk[0].knd==YELLOW)return true;

	//�L���b�V��
	TetriMino n=t;
	//�L���b�V����field���N���A
	memset(n.field,false,sizeof(bool)*5*5);
	//�P�\���ԃ��Z�b�g
	n.wait=0;
	
	//��]��̈ʒu�ɂ���L���b�V����field��true��
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			if(t.field[x][y]){
				if(isLeft)	n.field[y][4-x]=true;//����]
				else		n.field[4-y][x]=true;//�E��]
			}
		}
	}

	//blk����
	FieldToBlk(n);

	//�ǏR�菈��
	const int TEST_NUM=2;	//���s��
	int moveCnt=1;			//�ړ��񐔃J�E���^
	int tCnt=0;				//�����J�E���^
	TetriMino tk=n;			//���s�p�e�g���~�m�L���b�V��

	//�L���Ȉʒu�ɂ��Ȃ����
	while(!IsValid(tk)){
		tk=n;//�L���b�V�����Z�b�g
		switch(tCnt){//����
			case 0://���ɂ��炵�Ă݂�
				AddX(tk,-BS*moveCnt);
				break;
			case 1://�E�ɂ��炵�Ă݂�
				AddX(tk,BS*moveCnt);
				break;
			case 2://��ɂ��炵�Ă݂�
				AddY(tk,-BS);
				AddY(n,-BS);//�����ɂ��炷
				moveCnt++;	//���s1��I��
				break;
			default://�G���[
				throw "bool Spin()::tCnt error";
				break;
		}
		tCnt=(++tCnt)%3;//�����J�E���^�A�b�v

		//���s�񐔂𒴂����狭���I��
		if(moveCnt>TEST_NUM)return false;
	}

	//�L���b�V����t�ɔ��f
	t=tk;

	//��]�I��
	return true;
}