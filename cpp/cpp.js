var max=4;//���݋L���ő吔

function move(go){
	var url=document.location.toString();//���݂̐��URL
	var n=url.lastIndexOf(".");			//.�̈ʒu���擾

	var str=new String;
	str=url.substring(n-3,n);			//.�̑O3���������i�[
	
	var num=parseInt(str);				//���l�ϊ�
	
	num+=go;							//�ړ�
	
	if(num>=10){						
		var value=num;
		for(i=1;value>10;i++){
			str="0"+i+(value%10);
			value-=10;
		}
	}
	else{
		str="00"+num;					//������ɕϊ�
	}
	
	//�L���͈͓��Ȃ烍�P�[�V�����ňړ�
	if(0<num && num<=max)document.location="./"+str+".html";
}

function write(){
	document.write("<form>");
	document.write("<input type='button' value='back' onclick='move(-1);'>");
	document.write("<input type='button' value='home' onclick='document.location=\"./cpp_menu.html\" ;'>");
	document.write("<input type='button' value='next' onclick='move(1);'>");
	document.write("</form>");
}
