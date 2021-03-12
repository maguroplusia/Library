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
pair<ll,ll> CRT(vector<ll> b,vector<ll> m) {
    ll retr = 0;
    ll retm = 1;
    for(int i = 0;i < (int)b.size();i++) {
        ll x,y;
        ll d = extgcd(retm,m.at(i),x,y);
        if((b.at(i) - retr) % d != 0) return make_pair(0,-1);
        ll tmp = (b.at(i) - retr) / d * x % (m.at(i) / d);
        retr += retm * tmp;
        retm *= m.at(i) / d;
    }
    return make_pair(mod(retr,retm),retm);
}
