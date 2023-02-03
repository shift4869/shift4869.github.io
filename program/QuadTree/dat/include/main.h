//main.h
//2013/12/08 written by shift

//「float->double時データ落ち」警告消し
#pragma warning(disable:4244)
#pragma warning(disable:4305)
//「signedとunsignedの比較」警告消し
#pragma warning(disable:4018)
//「int->bool強制設定」警告消し
#pragma warning(disable:4800)

//Dxライブラリインクルード
#include "DxLib.h"

//標準ヘッダーインクルード
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <assert.h>
using namespace std;

//定義インクルード
#include "define.h"

//typedef宣言インクルード
#include "typedef.h"

//クラスインクルード
#include "class.h"

//関数群インクルード
#include "func.h"

//グローバル変数インクルード
#include "GV.h"

