typedef long long ll;

const ll MOD = 1e9 + 7;
const int base = 27;

int n;
ll h[ms], p[ms];
string s;

ll getkey(int l, int r){ // (l, r)
	int res = h[r];
	if(l > 0) res = ((res - p[r - l + 1] * h[l-1]) % MOD + MOD) % MOD;
	return res;
}

void build(){
	p[0] = 1;
	h[0] = s[0];
	for(int i = 1; i < n; ++i){
		p[i] = (p[i-1] * base) % MOD;
		h[i] = ((h[i-1] * base) + s[i]) % MOD;
	}
}
