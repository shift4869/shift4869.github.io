#include "pack.h"

int main(int argc,char *argv[]){
	
	if(argc<2){
		cout<<"ファイルをドラッグドロップしてください"<<endl;
		getchar();
	}

	try{
		string path=argv[1];
		string ext;
		string::iterator it=find(path.begin(),path.end(),'.');

		copy(it,path.end(),back_inserter(ext));

		if(it==path.end()){//ディレクトリなら
			pack(path);
		}
		else if(ext==EXT){//".pak"ファイルなら
			dispack(path);
		}
		else{
			cout<<"ディレクトリ または \".pak\"ファイルを"<<endl;
			cout<<"ドラッグドロップしてください"<<endl;
			getchar();
		}
	}
	catch(const char *e){
		cout<<e<<endl;
		getchar();
	}

	return 0;
}