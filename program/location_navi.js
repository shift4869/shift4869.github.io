var ad_table=new Array(
"1.エルミート曲線軌道	./hermite.html",
"2.ベジェ曲線軌道	./bezier.html",
"3.ライブラリ制作の薦め	./library.html",
" .Fileクラスの実装	./library2.html",
" .GreatNumberクラスの実装	./library3.html",
"4.Lzss圧縮法	./lzss.html",
" .Lzss解凍法	./dislzss.html",
"5.ファイルパッキング	./packing.html",
" .パッキングの展開	./dispacking.html",
"6.暗号化	./cipher.html",
"7.座標回転	./spin.html",
"8.長方形と円の当たり判定	./collision.html",
"9.より精度の高いサイコロを目指して	./BernoulliTest.html",
"10.可変長引数	./VariableArg.html",
"11.マクロ	./macro.html",
"12.へにょりレーザー	./CurveLazer.html",
"13-1.メモリアロケーターとBoundaryTag アルゴリズム	./MemoryAllocator1.html",
"13-2.TLSFメモリアロケータ（理論編）	./MemoryAllocator2.html",
"13-3.TLSFメモリアロケータ（実装編）	./MemoryAllocator3.html",
"14-1.四分木探索（理論編）	./QuadTree1.html",
"14-2.四分木探索（実装編）	./QuadTree2.html",
"14-3.四分木探索（拡張編）	./QuadTree3.html",
"15-1.補間（パラメータ）	./Interpolation1.html",
"15-2.補間（曲線）	./Interpolation2.html",
"16.逆ポーランド記法とテンパズル	./ReversePolishNotation.html",
"17-1.boostの薦め（導入編）	./boost1.html",
"17-2.boostの薦め（紹介編）	./boost2.html");

var MAX_NUM=ad_table.length;

var menu="./program_menu.html";

function fbutton(number){
	facter=ad_table[number].split("\t");
	html="<input type='button' value='";
	html+=facter[0]+"' ";
	html+="onclick='";
	html+='location.href="'+facter[1]+'";';
	html+="' >";
	return html;
}

function write_locate(number){
	number--;
	next=number+1;
	prev=number-1;
	
	html="<form>";
	
	if(prev>=0){
		html+=fbutton(prev);
		html+="へ戻る　　";
	}
	else{
		//html+="　　　　　";
	}
	
	html+="<input type='button' value='";
	html+="プログラミングメニューに戻る"+"' ";
	html+="onclick='";
	html+='location.href="'+menu+'";';
	html+="' >"+"　　";
	
	if(next<MAX_NUM){
		html+=fbutton(next);
		html+="へ進む";
	}
	else{
		//html+="         ";
	}
	
	html+="</form>";
	document.write(html);
}
