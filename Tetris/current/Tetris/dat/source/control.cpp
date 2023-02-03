//control.cpp
#include "../include/main.h"

//�X�g�b�N�t���O
static bool stockFlag=false;

//�R���g���[��
void Control(){
	if(cur.flag){
		//���͏󋵂��擾
		int input[]={
			CheckStatePad(config.left),
			CheckStatePad(config.right),
			CheckStatePad(config.up),
			CheckStatePad(config.down),
			CheckStatePad(config.lspin),
			CheckStatePad(config.rspin),
			CheckStatePad(config.stock),
		};

		//���������̊Ԋu
		int interval=40;

		//��
		if(input[0]==1 || (input[0]>12 && input[0]%5==0)){
			AddX(cur,-BS);
			if(!IsValid(cur))AddX(cur,BS);
		}//�E
		else if(input[1]==1 || (input[1]>12 && input[1]%5==0)){
			AddX(cur,BS);
			if(!IsValid(cur))AddX(cur,-BS);
		}//��
		else if(input[2]==1){
			while(IsValid(cur)){
				AddY(cur,BS);
			}
			AddY(cur,-BS);
			cur.wait=60;
		}//��
		else if(input[3]){
			interval=5;
		}

		//��]
		if(input[4]==1){
			Spin(cur,true);
		}
		else if(input[5]==1){
			Spin(cur,false);
		}

		//�X�g�b�N
		if(input[6]==1){
			if(!stockFlag){//�A���X�g�b�N�łȂ����
				//�����ʒu�֖߂��Ă���
				cur.x=FX+BS*6;
				cur.y=FY-BS*2;
				cur.cnt=0;
				cur.wait=0;

				//�X�g�b�N�Ɠ���ւ�
				swap(cur,stock);

				//�X�g�b�N�t���Oon
				stockFlag=true;

				return ;
			}
		}

		//�h���b�v�V���h�E
		shadow=cur;
		//�s����Ƃ��܂ŗ��Ƃ�
		while(IsValid(shadow)){
			AddY(shadow,BS);
		}
		AddY(shadow,-BS);

		if(cur.cnt%interval==0){
			//��������
			AddY(cur,BS);
			if(!IsValid(cur)){
				AddY(cur,-BS);
				cur.wait++;
			}
		}
		
		//���n������
		if(cur.wait>0){
			cur.wait++;
		}

		//�P�\���Ԍo�߂�����
		if(cur.wait>60){
			//���n����
			cur.flag=false;

			//�ێ����Ă���blk���t�B�[���h�֒ǉ�
			for(int i=0;i<4;i++){
				blkList.push_back(cur.blk[i]);
			}

			//���C������
			DeleteLine();

			//�X�g�b�N�t���O��off��
			stockFlag=false;
		}

		//�J�E���g�A�b�v
		cur.cnt++;
	}
	else{
		//�擪�����o��
		cur=nextList.front();
		//�擪������
		nextList.pop_front();
		//�����ɒǉ�
		nextList.push_back(CreateTetriMino(Point(FX+BS*6,FY-BS*2),
								(BLK_COL)GetRand(BLK_KND_NUM-1)));
		//��ʓ��L���t���O��true��
		cur.flag=true;
	}
}