#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define Maxn 502

int mark[Maxn][Maxn],d[Maxn][Maxn];
queue<int> q;

void bfs() {
        int kk;
        while(!q.empty())
                q.pop();
        q.push(1);
        while(!q.empty()) {
                kk=q.front();
                q.pop();
                if(kk==12) {
                        puts("Yes.");
                        return;
                }
                for(int i=0;i<27;i++)
                        if(!mark[kk][i] && d[kk][i]) {
                                mark[kk][i]=1;
                                q.push(i);
                        }
        }
        puts("No.");
}

int main() {
        //freopen("k","r",stdin);
        int len,a,b,k,k2;
        char s[101];
        //printf("%d %d\n",'b'-'a','m'-'a');
        while(scanf("%s",s)==1) {        //要多组测试，少了会WA
                if(s[0]=='0')
                        continue;
                k=0;k2=0;
                memset(d,0,sizeof(d));
                memset(mark,0,sizeof(mark));
                while(1) {
                        scanf("%s",s);
                        if(s[0]=='0')
                                break;
                        len=strlen(s);
                        a=s[0]-'a';b=s[len-1]-'a';
                        if(a==1)
                                k=1;
                        if(b==12)
                                k2=1;
                        d[a][b]=1;
                }
                if(k==0 || k2==0)
                        puts("No.");
                else
                        bfs();
        }
        return 0;
}