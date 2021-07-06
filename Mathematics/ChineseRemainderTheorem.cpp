//extgcd(a,b,x,y):ax+by=gcd(a,b)を満たす(x,y)が格納される　返り値はgcd(a,b)
long long extgcd(long long a,long long b,long long &x,long long &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b,a % b,y,x);
    y -= a / b * x;
    return d;
}

//CRT(b,m):n次合同方程式を解く。答えは x = R (mod M)の形で表される（解が無い場合は(0,-1)の形で表される）
pair<long long,long long> CRT(vector<long long> r,vector<long long> m) {
    if(r.empty() || m.empty()) return {0,1};
    long long R = r.front();
    long long M = m.front();
    for(int i = 1;i < (int)r.size();i++) {
        long long x,y;
        long long d = extgcd(M,m.at(i),x,y);
        if((r.at(i) - R) % d != 0) return {0,-1};
        long long tmp = (r.at(i) - R) / d % (m.at(i) / d) * x % (m.at(i) / d);
        R += M * tmp;
        M *= m.at(i) / d;
    }
    R %= M;
    if(R < 0) R += M;
    return {R,M};
}
