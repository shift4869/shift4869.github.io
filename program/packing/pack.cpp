#include "pack.h"

void search(string path,vector<BYTE> &buf);
string root;

//�t�@�C���i�f�B���N�g���j���p�b�N����
UINT pack(string path){
	setlocale(LC_ALL,"japanese");

	//�ϐ��錾
	//�t�@�C���f�[�^
	vector<BYTE> buf;
	string outpath=path+EXT;

	root=path;

	search(path,buf);

	ofstream fout(outpath.c_str(),ios::binary);
	fout.write((char*)&buf[0],buf.size());

	return 0;
}

void search(string path,vector<BYTE> &buf){

	FIND find;
	FIND_IT find_it;

	//�p�X�̍Ōオ'\'�ŏI����ĂȂ�������t������
	if(*(path.end()-1)!='\\'){
		path+='\\';
	}

	//��������
	find_it=_findfirst((path+"*.*").c_str(),&find);
	if(find_it==-1){
		throw "�p�X�������ł�";
	}

	//�S�~�f�[�^�ǂݔ�΂�
	_findnext(find_it,&find);

	//�T�[�`
	for(;_findnext(find_it,&find)==0;){
		if(find.attrib & _A_SUBDIR){//�T�u�f�B���N�g��
			//�f�B���N�g���w�b�_�[������
			string direct,h;
			ostringstream trans;
			direct=path;
			direct=direct.replace(0,root.length(),"")+find.name;
			
			trans<<"0\t"<<direct<<"\t";
			h=trans.str();

			//�o�b�t�@�Ƀw�b�_�[����������
			copy(h.begin(),h.end(),back_inserter(buf));

			search(path+find.name,buf);//�ċA
		}
		else{//�t�@�C��
			//�ϐ��錾
			string file,h;
			ostringstream tranc;
			UINT size=0;

			//�t�@�C����
			file=path+string(find.name);
			//�t�@�C���I�[�v��
			ifstream fin(file.c_str(),ios::binary);

			if(fin.fail()){//�G���[�`�F�b�N
				throw "�t�@�C���ǂݍ��݃G���[";
			}
			//�t�@�C���̃T�C�Y���擾
			size=fin.seekg(0,ios::end).tellg();

			string direct=path;
			direct=direct.replace(0,root.length(),"")+find.name;
			//UINT�^��string�ɕϊ����邽��
			//�X�g�����O�X�g���[���Ƀw�b�_�[���l�ߍ���('\t'�^�u��؂�)
			tranc<<size<<"\t"<<direct<<"\t";
			//�w�b�_�[��string�Ŏ擾
			h=tranc.str();
			//�o�b�t�@�Ƀw�b�_�[����������
			copy(h.begin(),h.end(),back_inserter(buf));

			//�o�b�t�@�̃��������m��
			buf.resize(buf.size()+size);
			//�t�@�C���f�[�^���o�b�t�@�ɏ�������
			fin.seekg(0,ios::beg).read((char*)&buf[buf.size()-size],size);
		}
	}

	//�����I��
	_findclose(find_it);

}
