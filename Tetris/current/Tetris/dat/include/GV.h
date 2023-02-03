//GV.h
#ifdef FIRST_LOADING
#define E 
#else
#define E extern
#endif

//コンフィグクラス
E Config config;

//画像イメージ
namespace IMG{
	E int board[3];//背景画像
	E int block[7];//ブロック画像
	E int num[10]; //数字画像
};

//現在のテトリミノ
E TetriMino cur;

//フィールド上のブロック
E list<Block> blkList;

//ネクストブロックリスト
E list<TetriMino> nextList;

//ストック
E TetriMino stock;

//ドロップシャドウ
E TetriMino shadow;
