//func.cpp
//2013/12/08 written by shift
#include "../include/main.h"

//int��x^y
int pow(int x,int y){
	return (int)pow(double(x),y);
}

//�u�x�v�p��sin
float sind(float deg){
	return sin(DTOR(deg));
}

//�u�x�v�p��cos
float cosd(float deg){
	return cos(DTOR(deg));
}

//�����擾[0~RAND_MAX)
int Rand(){
	return rand();
}

//�����擾[0~max)
int Rand(int max){
	return Rand()*max/(double)(RAND_MAX+1);
}

//�����擾[min~max)
int Rand(int min,int max){
	if(min>max)swap(min,max);
    return min+Rand(max-min);
}

//�����t��string�쐬(const char *�^��throw�����\��������)
string Format(const char *format, ...){
	va_list v;      //�ϒ������^
	int num=0,res=0;//�o�C�g��,�Ԃ�l
	char *buf=NULL; //�o�b�t�@
	string ret;     //�Ԃ�String�ϐ�

	va_start(v,format);         //�ϒ���������J�n

	num=_vscprintf(format,v)+1; //�����W�J��̃o�C�g���擾

	buf=new char[num];          //�o�b�t�@�������A���P�[�V����

	res=_vsnprintf_s(buf,num,num,format,v); //�o�b�t�@�ɏ����W�J��̕������ݒ�
	if(res<0)throw "_vsnprintf_s error";    //�����H

	ret=(string)buf;        //string�^�ɕϊ�

	va_end(v);      //�ϒ���������I��

	delete[] buf;   //�o�b�t�@���

	return ret;     //String��Ԃ�
}
