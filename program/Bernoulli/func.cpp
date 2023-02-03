
//�C���N���[�h�t�@�C��
#include <fstream>
#include <stdarg.h>
#include <algorithm>
#include <string>
using namespace std;

//define��`
#define MAX_NUM 6

//�֐��v���g�^�C�v�錾
string format(const char *format, ...);

//���ۃJ�E���^��extern�錾
extern int num[MAX_NUM];

//���ʂ�ۑ�����
void Preserve(int n){
	//�o�̓t�@�C�����ݒ�
	string outfile=format("result%02d.txt",n);
	ofstream fout(outfile.c_str());
	if(!fout)throw "file open error";

	int sum=0;//���ۍ��v
	float per[MAX_NUM]={0,};//�e���ۊm��

	//���v�擾
	for(int i=0;i<MAX_NUM;i++){
		sum+=num[i];
	}
	//�����ݒ�
	for(int i=0;i<MAX_NUM;i++){
		per[i]=num[i]/(float)sum;
	}

	//�e���ۂƊm����������
	for(int i=0;i<MAX_NUM;i++){
		fout<<format("%d=%07d��:�m��=%0.2f%%",i+1,num[i],per[i]*100).c_str()<<endl;
	}
	fout<<format("���v%07d��",sum).c_str()<<endl;//���v

	{//���ۍ���������
		int max,min;
		max=*max_element(num,num+MAX_NUM);//�z�񒆂̈�ԑ傫��������
		min=*min_element(num,num+MAX_NUM);//�z�񒆂̈�ԏ���������
		fout<<format("���ۍ�%07d��",max-min).c_str()<<endl;//����
	}

	{//��������������
		float max,min;
		max=*max_element(per,per+MAX_NUM);
		min=*min_element(per,per+MAX_NUM);
		fout<<format("������%0.2f%%",(max-min)*100).c_str()<<endl;
	}
}

//�����t��string�쐬
string format(const char *format, ...){
	va_list v;
	int num=0,res=0;
	char *buf=NULL;
	string ret;

	va_start(v,format);

	num=_vscprintf(format,v)+1;
	buf=new char[num];
	res=_vsnprintf_s(buf,num,num,format,v);
	if(res<0)throw "_vsnprintf_s error";

	ret=buf;

	va_end(v);

	delete[] buf;

	return ret;
} 
