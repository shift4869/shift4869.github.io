#include "pack.h"

void search(string path,vector<BYTE> &buf);
string root;

//ファイル（ディレクトリ）をパックする
UINT pack(string path){
	setlocale(LC_ALL,"japanese");

	//変数宣言
	//ファイルデータ
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

	//パスの最後が'\'で終わってなかったら付け足す
	if(*(path.end()-1)!='\\'){
		path+='\\';
	}

	//検索準備
	find_it=_findfirst((path+"*.*").c_str(),&find);
	if(find_it==-1){
		throw "パスが無効です";
	}

	//ゴミデータ読み飛ばし
	_findnext(find_it,&find);

	//サーチ
	for(;_findnext(find_it,&find)==0;){
		if(find.attrib & _A_SUBDIR){//サブディレクトリ
			//ディレクトリヘッダーを入れる
			string direct,h;
			ostringstream trans;
			direct=path;
			direct=direct.replace(0,root.length(),"")+find.name;
			
			trans<<"0\t"<<direct<<"\t";
			h=trans.str();

			//バッファにヘッダーを書き込む
			copy(h.begin(),h.end(),back_inserter(buf));

			search(path+find.name,buf);//再帰
		}
		else{//ファイル
			//変数宣言
			string file,h;
			ostringstream tranc;
			UINT size=0;

			//ファイル名
			file=path+string(find.name);
			//ファイルオープン
			ifstream fin(file.c_str(),ios::binary);

			if(fin.fail()){//エラーチェック
				throw "ファイル読み込みエラー";
			}
			//ファイルのサイズを取得
			size=fin.seekg(0,ios::end).tellg();

			string direct=path;
			direct=direct.replace(0,root.length(),"")+find.name;
			//UINT型をstringに変換するため
			//ストリングストリームにヘッダーを詰め込む('\t'タブ区切り)
			tranc<<size<<"\t"<<direct<<"\t";
			//ヘッダーをstringで取得
			h=tranc.str();
			//バッファにヘッダーを書き込む
			copy(h.begin(),h.end(),back_inserter(buf));

			//バッファのメモリを確保
			buf.resize(buf.size()+size);
			//ファイルデータをバッファに書き込む
			fin.seekg(0,ios::beg).read((char*)&buf[buf.size()-size],size);
		}
	}

	//検索終了
	_findclose(find_it);

}
