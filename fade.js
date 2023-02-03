// <script type="text/javascript" src="java.js"></script>
// bodyƒ^ƒO‚É<body onload="settimer()">‚Æ‚·‚é

var rgbcolor="fedcba9876543210";
var rgbcolor2="0123456789abcdef";
var i=0;
var timer1;
var timer2;

function settimer(){
	timer1=setInterval("fadein()",100);
}

function fadein(){
	var r=rgbcolor.charAt(i);
	var g=rgbcolor.charAt(i);
	var b=rgbcolor.charAt(i);
	document.fgColor='#'+r+r+g+g+b+b;

	if(i>14){
		clearInterval(timer1);
		timer2=setInterval("fadeout()",100);
		i=0;
		return;
	}
	i++;
}

function fadeout(){
	var r=rgbcolor2.charAt(i);
	var g=rgbcolor2.charAt(i);
	var b=rgbcolor2.charAt(i);
	document.fgColor='#'+r+r+g+g+b+b;

	if(i>14){
		clearInterval(timer2);
		timer1=setInterval("fadein()",100);
		i=0;
		return;
	}
	i++;
}