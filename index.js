function now(){
	var dd= new Date();
	document.day.daytext.value="����::"+dd.toLocaleString();
	window.setTimeout("now()",1000)
}

function last(){
	document.write("�ŏI�X�V��::"+document.lastModified);
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
	var ht="";		//�o��html�^�O�ϐ�
	ht+="<table>";	//�e�[�u�������
	
	/*
	//navigator�I�u�W�F�N�g�̒l��S�ė��񂷂�Ȃ炱����
	for(i in navigator){
		ht+=tag_tr(tag_td(i)+tag_td(navigator[i]));
	}
	*/
	
	bl=navigator.appName;		//�u���E�U�̎��
	ver=navigator.appVersion;	//�u���E�U�̃o�[�W����
	
	//�u���E�U�̎g�p����(IE�Ƃ��̑��ł͗L���ȃv���p�e�B���Ⴄ�̂ŐU�蕪����)
	lang="";
	if(bl.indexOf("Microsoft")<0)	lang=navigator.language;
	else							lang=navigator.browserLanguage;
	
	plat=navigator.platform;	//�v���b�g�t�H�[��
	agent=navigator.userAgent;	//���[�U�[�G�[�W�F���g
	
	//html�^�O�쐬
	ht+=tag_tr(tag_td("�g�p�u���E�U")+tag_td(bl));
	ht+=tag_tr(tag_td("�u���E�U�o�[�W����")+tag_td(ver));
	ht+=tag_tr(tag_td("�g�p����")+tag_td(lang));
	ht+=tag_tr(tag_td("�v���b�g�t�H�[��")+tag_td(plat));
	ht+=tag_tr(tag_td("���[�U�[�G�[�W�F���g")+tag_td(agent));

	ht+="</table>";//�e�[�u������
	document.write(ht);//��������
}

