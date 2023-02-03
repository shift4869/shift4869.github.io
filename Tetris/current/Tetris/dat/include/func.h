//func.h

//fps.cpp//
//fps表示
void fps();

//key.cpp//
//キー入力を取得する関数
int GetHitKeyStateAll_2();
//結果を返す関数
int CheckStateKey(int KeyCode);
//パッドキーとキーボードの両方の入力をチェックする関数
int GetHitPadStateAll();
//渡されたパッドキーの結果を返す関数
int CheckStatePad(int PadKeyCode);

//ini.cpp//
//初期化処理
void ini();

//draw.cpp//
void DrawMain();

//CreateTetriMino.cpp//
TetriMino CreateTetriMino(const Point& p,const BLK_COL& k);

//func.cpp//
//フィールド情報から各ブロックの座標を設定する
//tそのもののベース点はフィールドの(2,2)の座標とする
bool FieldToBlk(TetriMino& t);
//テトリミノ移動関数(x)
bool AddX(TetriMino& t,int add);
bool AddY(TetriMino& t,int add);

//control.cpp//
void Control();

//IsValid.cpp//
//指定された座標がフィールド内にあるか
//true->フィールド内にある false->フィールド内にない
bool IsInField(const Point& p);
//指定されたテトリミノがフィールド内にあるか
//true->フィールド内にある false->フィールド内にない
bool IsInField(const TetriMino& t);
//指定されたテトリミノが既にあるブロックに埋まってないか
//true->埋まっている false->埋まっていない
bool IsBury();
//テトリミノが有効な位置にいるか
//true->有効である false->無効である
bool IsValid(const TetriMino& t);

//Spin.cpp//
bool Spin(TetriMino& t,bool isLeft);

//DeleteLine.cpp//
//ライン消去
//帰り値は消したライン数
int DeleteLine();
