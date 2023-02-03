//GV.h
//2013/12/08 written by shift

//初回ロード時のみ実態定義する
//インクルードガード
#ifdef _FIRST_LOADING_
#define E 
#else if
#define E extern
#endif

//コンフィグクラス
E Config config;

//デバッグ用色変数
E int color[COLOR_MAX];

//画像ハンドル
namespace IMG{

};

//フォントハンドル
E int font[2];

//空間リスト
E CellList cellList;

//動物体タスクリスト
E list<Mover*> taskList;

//自機（仮想）
E Bullet* bpp;

//衝突している物体
E Bullet* mpp;

//全体ゲームカウンタ
E uint gameCnt;

//処理時間計測用
E vector<uint> allST;
E vector<uint> allCutST;
E vector<uint> quadST;

//現在弾数
E uint bNum;

//ループフラグ
E bool loopFlag;
