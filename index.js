function now(){
	var dd= new Date();
	document.day.daytext.value="日時::"+dd.toLocaleString();
	window.setTimeout("now()",1000)
}

function last(){
	document.write("最終更新日::"+document.lastModified);
}

function jump(str){
	switch(str){
		case "home":location.href="./index.html";break;
		case "prof":location.href="./prof.html";break;
		case "blog":location.href="http://ginnnotuki.seesaa.net/";break;
		case "basic":location.href="./basic.html";break;
		case "cpp":location.href="./cpp/cpp_menu.html";break;
		case "program":location.href="./program/program_menu.html";break;
		case "tetris":location.href="./tetlec/tetlec_menu.html";break;
		case "tools":location.href="./tools.html";break;
		case "games":location.href="./games.html";break;
		case "journey":location.href="./journey/journey_menu.html";break;
		case "note":location.href="./note/note_menu.html";break;
		case "link":location.href="./link.html";break;
		case "menu":
		default:break;
	}
}
function tag_td(str){
	return "<td>"+str+"</td>";
}
function tag_tr(str){
	return "<tr>"+str+"</tr>";
}
function browser(){
	var ht="";		//出力htmlタグ変数
	ht+="<table>";	//テーブルを作る
	
	/*
	//navigatorオブジェクトの値を全て羅列するならこっち
	for(i in navigator){
		ht+=tag_tr(tag_td(i)+tag_td(navigator[i]));
	}
	*/
	
	bl=navigator.appName;		//ブラウザの種類
	ver=navigator.appVersion;	//ブラウザのバージョン
	
	//ブラウザの使用言語(IEとその他では有効なプロパティが違うので振り分ける)
	lang="";
	if(bl.indexOf("Microsoft")<0)	lang=navigator.language;
	else							lang=navigator.browserLanguage;
	
	plat=navigator.platform;	//プラットフォーム
	agent=navigator.userAgent;	//ユーザーエージェント
	
	//htmlタグ作成
	ht+=tag_tr(tag_td("使用ブラウザ")+tag_td(bl));
	ht+=tag_tr(tag_td("ブラウザバージョン")+tag_td(ver));
	ht+=tag_tr(tag_td("使用言語")+tag_td(lang));
	ht+=tag_tr(tag_td("プラットフォーム")+tag_td(plat));
	ht+=tag_tr(tag_td("ユーザーエージェント")+tag_td(agent));

	ht+="</table>";//テーブル完成
	document.write(ht);//書き込み
}

