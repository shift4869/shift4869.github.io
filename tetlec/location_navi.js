var ad_table=new Array(
"はじめに	./00.html",
"全体の構成	./01.html",
"何もしない画面の作成	./02.html",
"fps表示	./03.html",
"キー入力	./04.html",
"テトリス全体の流れ	./05.html",
"リソースのロード	./06.html",
"画面の描画	./07.html",
"テトリミノの内部表現	./08.html",
"テトリミノの制御(1)	./09.html",
"テトリミノの制御(2)	./10.html",
"テトリミノの制御(3)	./11.html",
"テトリミノの回転(1)	./12.html",
"テトリミノの回転(2)	./13.html",
"着地後の猶予時間を設定する	./14.html",
"ネクストブロックリストの表示	./15.html",
"ストック機構	./16.html",
"ドロップシャドウ	./17.html",
"ライン消去	./18.html"
);

var MAX_NUM=ad_table.length;

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
