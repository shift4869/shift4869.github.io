#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//typedef宣言
typedef unsigned char BYTE;
typedef unsigned int UINT;

size_t lzss_decode(string path){
    //ifstreamで日本語パスを認識するようにする
    setlocale(LC_ALL,"japanese");

    //変数宣言
    vector<BYTE> src,dest;
    UINT src_size=0,src_it=0;
    int encode_code=0;
    string ext;

    {//ファイルを読み込む
        ifstream fin(path.c_str(),ios::binary);
        
        if(fin.fail()){
            throw "ファイル読み込みエラー";
        }

        //最後に移動してサイズ取得
        src_size=fin.seekg(0,ios::end).tellg();
        //ベクター内メモリをサイズ分確保
        src.resize(src_size);
        //始めに戻ってvectorに全て読み込む
        fin.seekg(0,ios::beg).read((char*)&src[0],src.size());
    }

    {//ヘッダー情報を読み込む
        //エンコードコード
        encode_code=src[src_it];
        src_it++;

        //元の拡張子取得
        vector<BYTE>::iterator it=find(src.begin()+1,src.end(),'\t');
        copy(src.begin()+1,it,back_inserter(ext));

        //ヘッダー分は後々邪魔なので削除
        src.erase(src.begin(),it+1);
        src_size=src.size();
        src_it=0;
    }

    {//解凍
        int index,equal_num;
        while(src_it<src_size){
            //エンコードコードと一致していたら
            if(src[src_it]==encode_code){
                src_it++;
                //エンコードコードそのものなら
                if(src[src_it]==encode_code){
                    //そのまま出力
                    dest.push_back(src[src_it]);
                    src_it++;
                }
                else{//圧縮情報の開始なら
                    //何バイト前から同じか--------------------
                    index=src[src_it];
                    src_it++;
                    if(index>=encode_code)index--;
                    //----------------------------------------

                    //何バイト同じか--------------------------
                    equal_num=src[src_it];
                    src_it++;
                    //----------------------------------------

                    //index分前の位置からequal_num分メモリをコピー--
                    UINT dest_it=dest.size();
                    for(int i=0;i<equal_num;i++){
                        dest.push_back(dest[dest_it-index+i]);
                    }
                    //----------------------------------------------
                }
            }
            else{
                //そのまま出力
                dest.push_back(src[src_it]);
                src_it++;
            }
        }
    }

    {//ファイル保存
        string::iterator it=find(path.begin(),path.end(),'.');
        ofstream fout(path.replace(it,path.end(),ext).c_str(),ios::binary);
        fout.write((char*)&dest[0],dest.size());
    }

    return dest.size();
}