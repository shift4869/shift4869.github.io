#include "pack.h"

UINT dispack(string path){
	setlocale(LC_ALL,"japanese");

	//�ϐ��錾
	vector<BYTE> src;
	string root;

	{//���[�g�t�H���_�ݒ�
		string::iterator ext=find(path.begin(),path.end(),'.');
		copy(path.begin(),ext,back_inserter(root));
	}

	//���[�g�t�H���_�쐬
	_mkdir(root.c_str());

	{//�p�b�N�t�@�C���ǂݍ���
		ifstream fin(path.c_str(),ios::binary);
		if(fin.fail()){
			throw "�t�@�C���ǂݍ��݃G���[";
		}
		UINT size=fin.seekg(0,ios::end).tellg();

		src.resize(size);
		fin.seekg(0,ios::beg).read((char*)&src[0],size);
	}

	{//�A�[�J�C�u�W�J
		//�ϐ��錾
		//���ݍ��݃f�[�^�擾�C�e���[�^
		vector<BYTE>::iterator d1,d2;
		int flag=0;//�f�[�^��ނ̃t���O
		string buf;//�f�[�^�o�b�t�@

		//�C�e���[�^������
		d1=d2=src.begin();

		do{//�p�b�N�t�@�C���W�J
			//���̃f�[�^��؂��
			d2=find(d1,src.end(),'\t');

			if(flag%2==0){//�T�C�Y
				//�o�b�t�@�ɃT�C�Y������
				copy(d1,d2,back_inserter(buf));

				d1=d2+1;
				flag++;
			}
			else{//�t�@�C��
				//�ϐ��錾
				string fname,fpath;
				UINT size;

				//�T�C�Y��string����UINT�փL���X�g
				istringstream(buf)>>size;
				//�t�@�C�����擾
				copy(d1,d2,back_inserter(fname));
				//�t�@�C���t���p�X�ݒ�
				fpath=root+fname;

				//�t�@�C���f�[�^����2�C�e���[�^�ŋ���
				d2++;
				d1=d2+size;

				//�f�B���N�g���w�b�_�[�Ȃ��
				if(size==0 && fname.end()==find(fname.begin(),fname.end(),'.')){
					_mkdir(fpath.c_str());//�V�����f�B���N�g�����쐬
				}
				else{//�łȂ����
					//�ϐ��錾
					vector<BYTE> data(size);
					ofstream fout(fpath.c_str(),ios::binary);
					if(fout.fail()){
						throw "�t�@�C���ǂݍ��݃G���[";
					}

					//�t�@�C���f�[�^��ۑ�����
					copy(d2,d1,data.begin());
					fout.write((char*)&data[0],size);
				}

				buf.clear();//�o�b�t�@�N���A
				flag++;
			}
		}while(d1!=src.end());//�Ō�܂œW�J����
	}

	return 0;
}