#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cerr << #x << " is " << x << endl;
#define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
#define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<lli,lli> point;

point conv[50100];
point ul;

lli dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
int isleft(point t, point a, point b) {
    lli res = (a.y-t.y)*(b.x-t.x)-(b.y-t.y)*(a.x-t.x);
    if (res < 0) return 1; // left
    else if (res > 0) return 0; // right
    else return 2;
}

bool slope(point a, point b) {
    if (isleft(ul, a, b) == 2) return dist(ul, a) < dist(ul, b);
    else return isleft(ul, a, b);
}

bool cmp (point a, point b){
    if (a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

point s[50100];
int top = 0;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld %lld", &conv[i].x, &conv[i].y);
    }
    sort(conv+1, conv+n+1, cmp); // find upperleft
    ul = conv[1];
    sort(conv+2, conv+n+1, slope);

    //for(int i = 1; i <= n; i++) cerr << conv[i].x << ' ' << conv[i].y << endl;

    s[++top] = ul;
    s[++top] = conv[2];

    for(int i = 3; i <= n; i++) {
        while (top > 1 && (isleft(s[top-1], s[top], conv[i])==0 || isleft(s[top-1], s[top], conv[i])==2)) top--;
        s[++top] = conv[i];
    }

    if(isleft(s[top-1], s[top], conv[1])==0 || isleft(s[top-1], s[top], conv[1])==2) top--;

    printf("%d\n", top);
    for(int i = 1; i <= top; i++) {
        printf("%lld %lld\n", s[i].x, s[i].y);
    }

    return 0;
}