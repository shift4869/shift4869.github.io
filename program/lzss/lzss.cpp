#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//typedef宣言
typedef unsigned char BYTE;
typedef unsigned int UINT;

size_t lzss_encode(const String path){
    //ifstreamで日本語パスを認識するようにする
    setlocale(LC_ALL,"japanese");

    //変数宣言
    string fname=path;
    string::iterator it=find(fname.begin(),fname.end(),'.');
    vector<BYTE> src,press;
    UINT src_size=0;
    UINT src_it=0;

    {//ファイルを読み込む
        ifstream fin(fname.c_str(),ios::binary);

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

    {//圧縮データ作成
        int encode_code=0;
        int equal_num,max_equal,max_index;//一致数、最大一致数、一致インデックス

        //出現頻度が低い数値を求める--
        {
            int cnt[256]={0,};
            int *min=NULL;

            for(UINT i=0;i<src_size;i++){
                cnt[ src[i] ]++;//カウント
            }

            min=min_element(cnt,cnt+256);
            encode_code=min-cnt;
        }
        //----------------------------

        //ヘッダー作成
        press.push_back((BYTE)encode_code);
        copy(it,fname.end(),back_inserter(press));
        press.push_back('\t');

        //最後まで
        while(src_it<src_size){
            max_equal=-1;//最大一致数初期化
            max_index=-1;//インデックス初期化

            //256バイト前までパターンを探索
            for(int i=0;i<256;i++){
                //始めの位置より前は調べない
                if((int)(src_it-i)<0)break;

                //何バイト一致しているか調べる
                for(equal_num=0;equal_num<i;equal_num++){
                    //最後より後の位置は調べない
                    if(equal_num+src_it>=src_size)break;
                    //一致していなかったら抜ける
                    if(src[src_it+equal_num] != src[src_it-i+equal_num])break;
                }

                //4バイト以上一致していたら(それ以下だと圧縮にならない)
                if(equal_num>=4 && max_equal<equal_num){
                    //最大一致数設定
                    max_equal=equal_num;
                    //最大一致時のインデックス保存
                    max_index=i;
                }
            }

            //一致していなかったら
            if(max_index==-1){
                //そのまま出力
                press.push_back(src[src_it]);
                
                //エンコードコードと一致していたら
                if(src[src_it]==encode_code){
                    //二重に出力する
                    press.push_back(src[src_it]);
                }
                
                //元ファイルも進める
                src_it++;
            }
            else{//一致していたら
                //圧縮情報開始のコードを入れる(エンコードコード)
                press.push_back(encode_code);

                //「何バイト前から同じか」を入れる
                press.push_back(max_index);
                //もし圧縮情報の開始を示す数値と同じ場合、展開時に
                //『圧縮情報の開始を示す数値そのもの』と判断されて
                //しまうため、圧縮情報の開始を示す数値と同じかそれ以上の
                //場合は数値を +1 するというルールを使う。(展開時は逆に -1 にする)
                if(max_index>=encode_code)press[press.size()-1]++;

                //「何バイト同じか」を入れる
                press.push_back(max_equal);

                //同じだったバイト数分だけ元ファイルを進める
                src_it+=max_equal;
            }
        }
        //--------------------------------
    }

    {//圧縮データの保存
        //拡張子を上書き
        fname.replace(it,fname.end(),EXTENSION);

        ofstream fout(fname.c_str(),ios::binary);
        fout.write((char*)&press[0],press.size());
    }

    return press.size();
}

