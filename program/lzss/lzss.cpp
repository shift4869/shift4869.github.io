#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//typedef�錾
typedef unsigned char BYTE;
typedef unsigned int UINT;

size_t lzss_encode(const String path){
    //ifstream�œ��{��p�X��F������悤�ɂ���
    setlocale(LC_ALL,"japanese");

    //�ϐ��錾
    string fname=path;
    string::iterator it=find(fname.begin(),fname.end(),'.');
    vector<BYTE> src,press;
    UINT src_size=0;
    UINT src_it=0;

    {//�t�@�C����ǂݍ���
        ifstream fin(fname.c_str(),ios::binary);

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

    {//���k�f�[�^�쐬
        int encode_code=0;
        int equal_num,max_equal,max_index;//��v���A�ő��v���A��v�C���f�b�N�X

        //�o���p�x���Ⴂ���l�����߂�--
        {
            int cnt[256]={0,};
            int *min=NULL;

            for(UINT i=0;i<src_size;i++){
                cnt[ src[i] ]++;//�J�E���g
            }

            min=min_element(cnt,cnt+256);
            encode_code=min-cnt;
        }
        //----------------------------

        //�w�b�_�[�쐬
        press.push_back((BYTE)encode_code);
        copy(it,fname.end(),back_inserter(press));
        press.push_back('\t');

        //�Ō�܂�
        while(src_it<src_size){
            max_equal=-1;//�ő��v��������
            max_index=-1;//�C���f�b�N�X������

            //256�o�C�g�O�܂Ńp�^�[����T��
            for(int i=0;i<256;i++){
                //�n�߂̈ʒu���O�͒��ׂȂ�
                if((int)(src_it-i)<0)break;

                //���o�C�g��v���Ă��邩���ׂ�
                for(equal_num=0;equal_num<i;equal_num++){
                    //�Ō����̈ʒu�͒��ׂȂ�
                    if(equal_num+src_it>=src_size)break;
                    //��v���Ă��Ȃ������甲����
                    if(src[src_it+equal_num] != src[src_it-i+equal_num])break;
                }

                //4�o�C�g�ȏ��v���Ă�����(����ȉ����ƈ��k�ɂȂ�Ȃ�)
                if(equal_num>=4 && max_equal<equal_num){
                    //�ő��v���ݒ�
                    max_equal=equal_num;
                    //�ő��v���̃C���f�b�N�X�ۑ�
                    max_index=i;
                }
            }

            //��v���Ă��Ȃ�������
            if(max_index==-1){
                //���̂܂܏o��
                press.push_back(src[src_it]);
                
                //�G���R�[�h�R�[�h�ƈ�v���Ă�����
                if(src[src_it]==encode_code){
                    //��d�ɏo�͂���
                    press.push_back(src[src_it]);
                }
                
                //���t�@�C�����i�߂�
                src_it++;
            }
            else{//��v���Ă�����
                //���k���J�n�̃R�[�h������(�G���R�[�h�R�[�h)
                press.push_back(encode_code);

                //�u���o�C�g�O���瓯�����v������
                press.push_back(max_index);
                //�������k���̊J�n���������l�Ɠ����ꍇ�A�W�J����
                //�w���k���̊J�n���������l���̂��́x�Ɣ��f�����
                //���܂����߁A���k���̊J�n���������l�Ɠ���������ȏ��
                //�ꍇ�͐��l�� +1 ����Ƃ������[�����g���B(�W�J���͋t�� -1 �ɂ���)
                if(max_index>=encode_code)press[press.size()-1]++;

                //�u���o�C�g�������v������
                press.push_back(max_equal);

                //�����������o�C�g�����������t�@�C����i�߂�
                src_it+=max_equal;
            }
        }
        //--------------------------------
    }

    {//���k�f�[�^�̕ۑ�
        //�g���q���㏑��
        fname.replace(it,fname.end(),EXTENSION);

        ofstream fout(fname.c_str(),ios::binary);
        fout.write((char*)&press[0],press.size());
    }

    return press.size();
}

