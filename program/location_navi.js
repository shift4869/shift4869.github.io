var ad_table=new Array(
"1.�G���~�[�g�Ȑ��O��	./hermite.html",
"2.�x�W�F�Ȑ��O��	./bezier.html",
"3.���C�u��������̑E��	./library.html",
" .File�N���X�̎���	./library2.html",
" .GreatNumber�N���X�̎���	./library3.html",
"4.Lzss���k�@	./lzss.html",
" .Lzss�𓀖@	./dislzss.html",
"5.�t�@�C���p�b�L���O	./packing.html",
" .�p�b�L���O�̓W�J	./dispacking.html",
"6.�Í���	./cipher.html",
"7.���W��]	./spin.html",
"8.�����`�Ɖ~�̓����蔻��	./collision.html",
"9.��萸�x�̍����T�C�R����ڎw����	./BernoulliTest.html",
"10.�ϒ�����	./VariableArg.html",
"11.�}�N��	./macro.html",
"12.�ւɂ�背�[�U�[	./CurveLazer.html",
"13-1.�������A���P�[�^�[��BoundaryTag �A���S���Y��	./MemoryAllocator1.html",
"13-2.TLSF�������A���P�[�^�i���_�ҁj	./MemoryAllocator2.html",
"13-3.TLSF�������A���P�[�^�i�����ҁj	./MemoryAllocator3.html",
"14-1.�l���ؒT���i���_�ҁj	./QuadTree1.html",
"14-2.�l���ؒT���i�����ҁj	./QuadTree2.html",
"14-3.�l���ؒT���i�g���ҁj	./QuadTree3.html",
"15-1.��ԁi�p�����[�^�j	./Interpolation1.html",
"15-2.��ԁi�Ȑ��j	./Interpolation2.html",
"16.�t�|�[�����h�L�@�ƃe���p�Y��	./ReversePolishNotation.html",
"17-1.boost�̑E�߁i�����ҁj	./boost1.html",
"17-2.boost�̑E�߁i�Љ�ҁj	./boost2.html");

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
		html+="�֖߂�@�@";
	}
	else{
		//html+="�@�@�@�@�@";
	}
	
	html+="<input type='button' value='";
	html+="�v���O���~���O���j���[�ɖ߂�"+"' ";
	html+="onclick='";
	html+='location.href="'+menu+'";';
	html+="' >"+"�@�@";
	
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
