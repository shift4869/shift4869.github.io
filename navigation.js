var html="";
var map;

function get_file(url){
	url=url.substr(url.lastIndexOf("/")+1,url.length);
	return url;
}

function topic(str,path){
	if(str!="index"){
		document.write("-->");
	}
	document.write(str.link(path));
}

function write_navi(){
	title=document.title;
	url=location.href;
	file=get_file(url);
	//alert(file);
	
	//map[file]=[title];
	
	html="<a href="+url+">"+title+"</a><br>";
	document.write(html);
}
