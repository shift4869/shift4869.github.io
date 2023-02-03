var url=document.URL;
var max=11;//Å‘å‹L–”::include func‚à•Ï‚¦‚Ä
var sr="./0";

function include(){
url=document.URL;
max=11;
sr="./0";
}

function back(){
	include();
	for(i=2;i<=max;i++){
		if(i<10){
			sr="00"+i.toString();
			if(url.indexOf(sr)!=-1){
			location.href="./00"+(i-1).toString()+".html";
			return;
			}
		}
		else if(i==10){
			sr="0"+i.toString();
			if(url.indexOf(sr)!=-1){
			location.href="./00"+(i-1).toString()+".html";
			return;
			}
		}
		else{
			sr="0"+i.toString();
			if(url.indexOf(sr)!=-1){
			location.href="./0"+(i-1).toString()+".html";
			return;
			}
		}
	}
	alert("No Back");
}

function next(){
	include();
	for(i=1;i<max;i++){
		if(i<9){
			sr="00"+i.toString();
			if(url.indexOf(sr)!=-1){
			location.href="./00"+(i+1).toString()+".html";
			return;
			}
		}
		else if(i==9){
			sr="00"+i.toString();
			if(url.indexOf(sr)!=-1){
			location.href="./0"+(i+1).toString()+".html";
			return;
			}
		}
		else{
			sr="0"+i.toString();
			if(url.indexOf(sr)!=-1){
			location.href="./0"+(i+1).toString()+".html";
			return;
			}
		}
	}
	alert("No Next");
}
/*
<form name="F1">
<input onclick="back()" type="button" value="//back" name="B1">&nbsp; 
<input onclick="location.href='../index.html'" type="button" value="//home// " name="B2">&nbsp; 
<input onclick="next()" type="button" value="next//" name="B3"> 
</form>
*/