#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//typedef�錾
typedef unsigned char BYTE;
typedef unsigned int UINT;

size_t lzss_decode(string path){
    //ifstream�œ��{��p�X��F������悤�ɂ���
    setlocale(LC_ALL,"japanese");

    //�ϐ��錾
    vector<BYTE> src,dest;
    UINT src_size=0,src_it=0;
    int encode_code=0;
    string ext;

    {//�t�@�C����ǂݍ���
        ifstream fin(path.c_str(),ios::binary);
        
        if(fin.fail()){
            throw "�t�@�C���ǂݍ��݃G���[";
        }

        //�Ō�Ɉړ����ăT�C�Y�擾
        src_size=fin.seekg(0,ios::end).tellg();
        //�x�N�^�[�����������T�C�Y���m��
        src.resize(src_size);
        //�n�߂ɖ߂���vector�ɑS�ēǂݍ���
        fin.seekg(0,ios::beg).read((char*)&src[0],src.size());
    }

    {//�w�b�_�[����ǂݍ���
        //�G���R�[�h�R�[�h
        encode_code=src[src_it];
        src_it++;

        //���̊g���q�擾
        vector<BYTE>::iterator it=find(src.begin()+1,src.end(),'\t');
        copy(src.begin()+1,it,back_inserter(ext));

        //�w�b�_�[���͌�X�ז��Ȃ̂ō폜
        src.erase(src.begin(),it+1);
        src_size=src.size();
        src_it=0;
    }

    {//��
        int index,equal_num;
        while(src_it<src_size){
            //�G���R�[�h�R�[�h�ƈ�v���Ă�����
            if(src[src_it]==encode_code){
                src_it++;
                //�G���R�[�h�R�[�h���̂��̂Ȃ�
                if(src[src_it]==encode_code){
                    //���̂܂܏o��
                    dest.push_back(src[src_it]);
                    src_it++;
                }
                else{//���k���̊J�n�Ȃ�
                    //���o�C�g�O���瓯����--------------------
                    index=src[src_it];
                    src_it++;
                    if(index>=encode_code)index--;
                    //----------------------------------------

                    //���o�C�g������--------------------------
                    equal_num=src[src_it];
                    src_it++;
                    //----------------------------------------

                    //index���O�̈ʒu����equal_num�����������R�s�[--
                    UINT dest_it=dest.size();
                    for(int i=0;i<equal_num;i++){
                        dest.push_back(dest[dest_it-index+i]);
                    }
                    //----------------------------------------------
                }
            }
            else{
                //���̂܂܏o��
                dest.push_back(src[src_it]);
                src_it++;
            }
        }
    }

    {//�t�@�C���ۑ�
        string::iterator it=find(path.begin(),path.end(),'.');
        ofstream fout(path.replace(it,path.end(),ext).c_str(),ios::binary);
        fout.write((char*)&dest[0],dest.size());
    }

    return dest.size();
}