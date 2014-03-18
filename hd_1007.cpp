#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef struct point
{
	double x,y;
}Point;
const int N=100005;
const double eps=0.00001;
Point p[N];
int a[N];
int compX(const Point& p1,const Point&p2)
{
	return p1.x<p2.x;
}
int compY(const int& a,const int& b)
{
	return p[a].y<p[b].y;
}
inline double min(double d1,double d2)
{
	return (d1<d2?d1:d2);
}
double dis(const Point& p1,const Point& p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double closest(int low,int high)
{
	if(high-low==1)
		return dis(p[low],p[high]);
	if(high-low==2)
		return min(dis(p[low],p[high]),min(dis(p[low],p[low+1]),dis(p[low+1],p[high])));
	int i,j,cnt=0,m=(low+high)>>1;
	double dm=min(closest(low,m),closest(m+1,high));
	for(i=low;i<=high;++i)
		if(p[i].x>=p[m].x-dm && p[i].x<=p[m].x+dm)
			a[cnt++]=i;
	sort(a,a+cnt,compY);
	for(i=0;i<cnt;++i)
		for(j=i+1;j<cnt;++j)
		{
			if(p[a[j]].y-p[a[i]].y>=dm)
				break;
			dm=min(dm,dis(p[a[j]],p[a[i]]));
		}
	return dm;
}
int main()
{
	int n;
	double a,b;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&a,&b);
			p[i].x=a;p[i].y=b;
		}
		sort(p,p+n,compX);
		printf("%.2lf\n",closest(0,n-1)/2.0);
	}
	return 0;
}
