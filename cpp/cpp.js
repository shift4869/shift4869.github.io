var max=4;//現在記事最大数

function move(go){
	var url=document.location.toString();//現在の絶対URL
	var n=url.lastIndexOf(".");			//.の位置を取得

	var str=new String;
	str=url.substring(n-3,n);			//.の前3文字分を格納
	
	var num=parseInt(str);				//数値変換
	
	num+=go;							//移動
	
	if(num>=10){						
		var value=num;
		for(i=1;value>10;i++){
			str="0"+i+(value%10);
			value-=10;
		}
	}
	else{
		str="00"+num;					//文字列に変換
	}
	
	//有効範囲内ならロケーションで移動
	if(0<num && num<=max)document.location="./"+str+".html";
}

function write(){
	document.write("<form>");
	document.write("<input type='button' value='back' onclick='move(-1);'>");
	document.write("<input type='button' value='home' onclick='document.location=\"./cpp_menu.html\" ;'>");
	document.write("<input type='button' value='next' onclick='move(1);'>");
	document.write("</form>");
}
