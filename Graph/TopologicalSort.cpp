int N;
vector<int> graph[200010];
int indegree[200010];
int outdegree[200010];

vector<int> topological_sort() {
    for(int i = 0;i < N;i++) {
        indegree[i] = 0;
    }
    for(auto x:graph) {
        for(auto y:x) {
            indegree[y]++;
        }
    }
    stack<int> st;
    for(int i = 0;i < N;i++) {
        if(indegree[i] == 0) {
            st.push(i);
        }
    }
    vector<int> res;
    while(!st.empty()) {
        int i = st.top();
        st.pop();
        res.push_back(i);
        for(auto x:graph[i]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                st.push(x);
            }
        }
    }
    return res;
}

//トポロジカルソートする方法、ただしN<=
ll counting() {
    for(int i = 0;i < N;i++) {
        outdegree[i] = 0;
    }
    for(int i = 0;i < N;i++) {
        for(auto x:graph[i]) {
            outdegree[i] += (1 << x);
        }
    }
    vector<ll> dp(1 << N);
    dp.at(0) = 1;
    for(int i = 0;i < (1 << N);i++) {
        for(int j = 0;j < N;j++) {
            if(!(i & (1 << j)) && !(i & outdegree[j])) {
                dp.at(i | (1 << j)) += dp.at(i);
            }
        }
    }
    return dp.at((1 << V) - 1);
}
