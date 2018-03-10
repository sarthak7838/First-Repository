#include<bits/stdc++.h>
using namespace std;
typedef long double db;
db p[3][2], q[3], s[3];
db ct[3][3]; db c[3][2];
void tf(db a[][3],db b[][2]){
    for(int i=0;i<3;++i){
        for(int j=0;j<2;++j){
            c[i][j]=0;
            for(int k=0;k<3;++k){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(8);

    int t;
    cin >> t;
    while(t--){
            cin >> s[0] >> s[1] >> s[2];
            for(int i=0;i<2;++i){
                cin >> p[0][i] >> p[1][i] >> p[2][i];
                p[0][i]-=s[0];
                p[1][i]-=s[1];
                p[2][i]-=s[2];
            }
            db x1=p[0][0], y1=p[1][0], z1=p[2][0];
            db x2=p[0][1], y2=p[1][1], z2=p[2][1];
            db u, v, w, m;
            u=z2*y1-z1*y2;
            v=z1*x2-x1*z2;
            w=x1*y2-x2*y1;
            if(u*s[0]+v*s[1]+w*s[2]<=0){
                u=-u;
                v=-v;
                w=-w;
            }
            // cout << u << ' ' << v << ' ' << w << '\n';

            m=sqrt(u*u + v*v + w*w);
            db l=hypot(v,w);
            ct[0][0]=l/m; ct[0][1]=-u*v/l/m; ct[0][2]=-u*w/l/m;
            ct[1][0]=0; ct[1][1]=w/l; ct[1][2]=-v/l;
            ct[2][0]=u/m; ct[2][1]=v/m; ct[2][2]=w/m;

            tf(ct,p);
            for(int i=0;i<3;++i){
                p[i][0]=c[i][0];
                p[i][1]=c[i][1];
            }
            db xx=1;
            db dv=.5l;
            x1=p[0][0], y1=p[1][0];
            x2=p[0][1], y2=p[1][1];
            // if(abs(p[2][1])<1e-6 and abs(p[2][0])<1e-6) cout << "yras\n";
//            cout << __LINE__ << ' ' << (x1+y1)/xx << ' ' << (y1-x1)/xx << '\n';
//            cout << __LINE__ << ' ' << (x2-y2)/xx << ' ' << (x2+y2)/xx << '\n';

            q[0]=(x1+y1+x2-y2)*dv;
            q[1]=(y1-x1+x2+y2)*dv;
            q[2]=0;


            for(int i=0;i<3;++i){
                for(int j=0;j<i;++j){
                    swap(ct[i][j],ct[j][i]);
                }
            }
            for(int i=0;i<3;++i){
                p[i][0]=p[i][1]=q[i];
            }
            tf(ct,p);
            for(int i=0;i<3;++i){
                q[i]=c[i][0]+s[i];
            }
            cout << q[0] << ' ' << q[1] << ' ' << q[2] << '\n';
    }
    return 0;
}
