//DeleteLine.cpp
#include "../include/main.h"

//���C������
//�A��l�͏��������C����
int DeleteLine(){
	//y���W�������r����t�@���N�^
	class BlkLineFunctor{
	public:
		int y;
		BlkLineFunctor(int Y){
			y=Y;
		}
		bool operator()(Block blk){
			return (y==blk.y);
		}
	};
	
	//1�s���̃u���b�N�̌��E�����������C����
	int num=0,delLine=0;
	//��ԉ��̍s����T��
	for(int y=BMY+1;y>=0;y--){
		//���̍s�ɂ���u���b�N�̌����擾
		num=count_if(blkList.begin(),blkList.end(),BlkLineFunctor(y*BS));
		
		//1�s�S�Ė��܂��Ă�����
		if(num==BMX){
			//���̍s�̑S�Ẵu���b�N������
			blkList.remove_if(BlkLineFunctor(y*BS));
			
			//���̍s����ɂ���u���b�N����i���낷
			for(list<Block>::iterator it=blkList.begin();
				it!=blkList.end();++it){
				if(it->y<y*BS){
					it->y+=BS;
				}
			}

			//�������C�����J�E���g
			delLine++;

			//�����Ƃ��납��T���ĊJ
			y++;

		}//�����Ȃ���ΒT���I��
		else if(num==0){
			break;
		}
	}

	//�����������C������Ԃ�
	return delLine;
}