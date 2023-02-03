#include "pack.h"

UINT dispack(string path){
	setlocale(LC_ALL,"japanese");

	//変数宣言
	vector<BYTE> src;
	string root;

	{//ルートフォルダ設定
		string::iterator ext=find(path.begin(),path.end(),'.');
		copy(path.begin(),ext,back_inserter(root));
	}

	//ルートフォルダ作成
	_mkdir(root.c_str());

	{//パックファイル読み込み
		ifstream fin(path.c_str(),ios::binary);
		if(fin.fail()){
			throw "ファイル読み込みエラー";
		}
		UINT size=fin.seekg(0,ios::end).tellg();

		src.resize(size);
		fin.seekg(0,ios::beg).read((char*)&src[0],size);
	}

	{//アーカイブ展開
		//変数宣言
		//挟み込みデータ取得イテレータ
		vector<BYTE>::iterator d1,d2;
		int flag=0;//データ種類のフラグ
		string buf;//データバッファ

		//イテレータ初期化
		d1=d2=src.begin();

		do{//パックファイル展開
			//次のデータ区切りへ
			d2=find(d1,src.end(),'\t');

			if(flag%2==0){//サイズ
				//バッファにサイズを入れる
				copy(d1,d2,back_inserter(buf));

				d1=d2+1;
				flag++;
			}
			else{//ファイル
				//変数宣言
				string fname,fpath;
				UINT size;

				//サイズをstringからUINTへキャスト
				istringstream(buf)>>size;
				//ファイル名取得
				copy(d1,d2,back_inserter(fname));
				//ファイルフルパス設定
				fpath=root+fname;

				//ファイルデータ部を2イテレータで挟む
				d2++;
				d1=d2+size;

				//ディレクトリヘッダーならば
				if(size==0 && fname.end()==find(fname.begin(),fname.end(),'.')){
					_mkdir(fpath.c_str());//新しいディレクトリを作成
				}
				else{//でなければ
					//変数宣言
					vector<BYTE> data(size);
					ofstream fout(fpath.c_str(),ios::binary);
					if(fout.fail()){
						throw "ファイル読み込みエラー";
					}

					//ファイルデータを保存する
					copy(d2,d1,data.begin());
					fout.write((char*)&data[0],size);
				}

				buf.clear();//バッファクリア
				flag++;
			}
		}while(d1!=src.end());//最後まで展開する
	}

	return 0;
}