//CBezierLazer.cpp
//2010/08/14

void BezierLazer::Move(){
	Point cp[4]={p1,c1,c2,p2};
    
	float k=(float)cnt/endTime;
	float m=k,n=1.0-k;
	Point s1[3];
	Point s2[2];
	Point mp;

	//1回目の内分点取得
	for(int i=0;i<3;i++){
		s1[i]=InnerPoint(cp[i],cp[i+1],m,n);
	}
	//2回目の内分点取得
	for(int i=0;i<2;i++){
		s2[i]=InnerPoint(s1[i],s1[i+1],m,n);
	}

	//3回目の内分点(現在点)取得
	mp=InnerPoint(s2[0],s2[1],m,n);

	//現在の座標設定
	x=mp.x;
	y=mp.y;

	if(trail.size()>height || cnt>endTime){
		trail.pop_front();
	}

	if(cnt<=endTime){
		trail.push_back(mp);
	}

	cnt++;

	if(trail.empty())alive=false;
}

void BezierLazer::Draw(){
	int i=0,index=0,n=trail.size();
	const float WIDTH2=width/2.0;

	SetDrawBlendMode(DX_BLENDMODE_ADD,255);
	list<Point>::iterator it1,it2;
	for(it1=it2=trail.begin(),++it2;
		it2!=trail.end();++it1,++it2){
		drawAng=Deg360(GetAngle(*it1,*it2)+90);
		if(i==0){
			p[0].x=it1->x-cosd(drawAng)*WIDTH2;
			p[0].y=it1->y-sind(drawAng)*WIDTH2;
			p[1].x=it1->x+cosd(drawAng)*WIDTH2;
			p[1].y=it1->y+sind(drawAng)*WIDTH2;
		}
		else{
			p[0]=p[3];
			p[1]=p[2];
		}
		p[2].x=it2->x+cosd(drawAng)*WIDTH2;
		p[2].y=it2->y+sind(drawAng)*WIDTH2;
		p[3].x=it2->x-cosd(drawAng)*WIDTH2;
		p[3].y=it2->y-sind(drawAng)*WIDTH2;

		index=(int)((LAZ_DIVIDE_NUM-1)*(float)i/n);
		DrawModiGraphF(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y,p[3].x,p[3].y,
			IMG::lazerPiece[index][col],true);
		i++;

	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);

}

bool BezierLazer::IsCollision(const Mover& m){

	const float WIDTH2=width/2.0;

	list<Point>::iterator it1,it2;
	for(it1=it2=trail.begin(),++it2;
		it2!=trail.end();++it1,++it2){
		drawAng=Deg360(GetAngle(*it1,*it2)+90);

		LazerBase laz(*it1,0,0,drawAng,width,Distance(*it1,*it2),0,1.0,1.0,RED,0,0,60);

		if(laz.IsCollision(m)){
			return true;
		}

	}

	return false;
}