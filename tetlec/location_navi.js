var ad_table=new Array(
"�͂��߂�	./00.html",
"�S�̂̍\��	./01.html",
"�������Ȃ���ʂ̍쐬	./02.html",
"fps�\��	./03.html",
"�L�[����	./04.html",
"�e�g���X�S�̗̂���	./05.html",
"���\�[�X�̃��[�h	./06.html",
"��ʂ̕`��	./07.html",
"�e�g���~�m�̓����\��	./08.html",
"�e�g���~�m�̐���(1)	./09.html",
"�e�g���~�m�̐���(2)	./10.html",
"�e�g���~�m�̐���(3)	./11.html",
"�e�g���~�m�̉�](1)	./12.html",
"�e�g���~�m�̉�](2)	./13.html",
"���n��̗P�\���Ԃ�ݒ肷��	./14.html",
"�l�N�X�g�u���b�N���X�g�̕\��	./15.html",
"�X�g�b�N�@�\	./16.html",
"�h���b�v�V���h�E	./17.html",
"���C������	./18.html"
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
		html+="�֖߂�@�@";
	}
	else{
		//html+="�@�@�@�@�@";
	}
	
	if(next<MAX_NUM){
		html+=fbutton(next);
		html+="�֐i��";
	}
	else{
		//html+="         ";
	}
	
	html+="</form>";
	document.write(html);
}
