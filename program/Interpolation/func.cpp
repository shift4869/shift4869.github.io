//func.cpp
//2013/12/23 written by shift
#include "../include/main.h"
/*
//重み
float coff(float t){
	float r=0;

	if(-2<=t && t<=2){
		float d=abs(t)-2;
		r=-d*d*d/6;
	}
	if(-1<=t && t<=1){
		float d=abs(t);
		r=(3*d*d*d-6*d*d+4)/6;
	}

	return r;
}

//3次Bスプライン
Point BSplineInterpolate(const Point& startP,const Point& c1,
	const Point& c2,const Point& endV,int nowCnt,int ts){
	const int N=4;
	Point p[N]={startP,c1,c2,endV};
	float t=::LinearInterpolate(-1.0f,(float)N+1,nowCnt,ts);
	float r;
	int k;
	Point m(0,0);

	for(int i=-2;i<=N+2;i++){
		k=i;
		if(i<0)k=0;
		if(i>N-1)k=N-1;
		r=coff(t-i);
		m.x+=p[k].x*r;
		m.y+=p[k].y*r;
	}

	return m;
}
*/

//速度一定ベジェ
/*
Point LinearBezierInterpolate(const Point& startP,const Point& c1,
									const Point& c2,const Point& endV,int nowCnt,int ts){
	int N=ts;
	double ni=1/(double)N;
	double tt=0;
	Point p(startP),q;
	double x,t=nowCnt/(double)ts;
	double *dd=new double[N+1];

	const int G=1000000;
	dd[0]=0;
	for(int i=1;i<N+1;i++){
		tt+=ni;
		q=::BezierCurveInterpolate(startP,c1,c2,endV,tt*ts*G,ts*G);
		dd[i]=dd[i-1]+Distance(p,q);
		p=q;
	}

	x=1/dd[N];
	for(int i=1;i<N+1;i++){
		dd[i]*=x;
	}

	int k=0;
	for(int i=0;i<N;i++,k++){
		if(dd[i]<=t && t<=dd[i+1])break;
	}

	//InnerPoint
	//(n*p.x+m*q.x)/(m+n)

	x=dd[k+1]-dd[k];
	x=(t-dd[k])/x;
	x=(k*(1-x)+(1+k)*x)*ni;

	delete[] dd;

	return ::BezierCurveInterpolate(startP,c1,c2,endV,x*ts*G,ts*G);
}
*/