//extgcd(a,b,x,y):ax+by=gcd(a,b)を満たす(x,y)が格納される　返り値はgcd(a,b)
ll extgcd(ll a,ll b,ll &x,ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extgcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}

//CRT(b,m):n次合同方程式を解く。答えは x = retr(mod retm)の形で表される（解が無い場合は(0,-1)の形で表される）
pair<ll,ll> CRT(vector<ll> r,vector<ll> m) {
    if(r.empty() || m.empty()) return make_pair(0,1);
    ll R = r.front();
    ll M = m.front();
    for(int i = 1;i < (int)r.size();i++) {
        ll x,y;
        ll d = extgcd(M,m.at(i),x,y);
        if((r.at(i) - R) % d != 0) return make_pair(0,-1);
        ll tmp = (r.at(i) - R) / d % (m.at(i) / d) * x % (m.at(i) / d);
        R += M * tmp;
        M *= m.at(i) / d;
    }
    R %= M;
    if(R < 0) R += M;
    return make_pair(R,M);
}
