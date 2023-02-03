//CCell.h
//2013/12/08 written by shift

class Mover;

//空間クラス
class Cell{
public:
	//ルート空間
	static Rect base;
	//空間レベル,各レベルでのインデックス,
	//線形四分木におけるインデックス
	int L,I,M;
	//対象物体
	Mover* mp;
	//双方向リスト
	Cell *prev,*next;

	//コンストラクタ
	Cell();
	Cell(Mover* m);
	//デストラクタ
	virtual ~Cell();

private:
	//上位探索
	Mover* UpperSearch();
	//下位探索
	Mover* LowerSearch(int nr);
	//ビットを１つずつズラす
	static byte BitSlide(byte b);
	//大きさを持たない点からモートン符号を求める
	static int PointtoMorton(Point p);
	//大きさを持つ物体からモートン符号を求め、L,i->Mを設定する
	static void MovertoMorton(const Mover& m,int& L,int& I,int& r);

public:
	//衝突判定
	Mover* IsCollision();
	//双方向リストから抜ける
	void Remove();
	//L,IからMを求める
	static int GetIndex(int L,int I);

	//mpに合わせてモートン符号を更新する
	void Update();
};
