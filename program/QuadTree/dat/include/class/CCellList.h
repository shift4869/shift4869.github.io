//CCellList.h
//2013/12/08 written by shift

//前方宣言
class Mover;
class Cell;

//空間リストクラス
class CellList{
public:
	//線形空間リスト
	Cell* cpList;

	//コンストラクタ
	CellList();
	//デストラクタ
	virtual ~CellList();

	//リストに追加
	void Push(Cell* cp);
	//衝突判定
	Mover* IsCollision(int index,Mover* m);
};
