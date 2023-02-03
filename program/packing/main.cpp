#include "pack.h"

int main(int argc,char *argv[]){
	
	if(argc<2){
		cout<<"�t�@�C�����h���b�O�h���b�v���Ă�������"<<endl;
		getchar();
	}

	try{
		string path=argv[1];
		string ext;
		string::iterator it=find(path.begin(),path.end(),'.');

		copy(it,path.end(),back_inserter(ext));

		if(it==path.end()){//�f�B���N�g���Ȃ�
			pack(path);
		}
		else if(ext==EXT){//".pak"�t�@�C���Ȃ�
			dispack(path);
		}
		else{
			cout<<"�f�B���N�g�� �܂��� \".pak\"�t�@�C����"<<endl;
			cout<<"�h���b�O�h���b�v���Ă�������"<<endl;
			getchar();
		}
	}
	catch(const char *e){
		cout<<e<<endl;
		getchar();
	}

	return 0;
}