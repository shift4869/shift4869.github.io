#include <iostream>
using namespace std;

void main(){
	int num;
	
	cout<<"整数を入力"<<endl;	
	cin>>num;

	if(num>=10)cout<<"10以上の数が入力されました。"<<endl;
	if(num<10)cout<<"10未満の数が入力されました。"<<endl;
}