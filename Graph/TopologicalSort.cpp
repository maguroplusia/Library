std::vector<int> topological_sort(int n, std::vector<std::vector<int>> graph) {
    std::vector<int> indegree(n);
    for(auto& x: graph) {
        for(auto& y: x) {
            indegree[y]++;
        }
    }

    std::stack<int> st;
    for(int i = 0;i < n;i++) {
        if(indegree[i] == 0) {
            st.push(i);
        }
    }

    std::vector<int> res;
    while(not st.empty()) {
        int v = st.top();
        st.pop();
        res.push_back(v);
        for(auto& x: graph[v]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                st.push(x);
            }
        }
    }
    return res;
}

long long counting(int n,std::vector<std::vector<int>> graph) {
    std::vector<int> outdegree(n);
    for(int i = 0;i < n;i++) {
        for(auto& x: graph[i]) {
            outdegree[i] += (1 << x);
        }
    }

    std::vector<long long> dp(1 << n);
    dp[0] = 1;
    for(int i = 0;i < (1 << n);i++) {
        for(int j = 0;j < n;j++) {
            if(!(i & (1 << j)) && !(i & outdegree[j])) {
                dp[i | (1 << j)] += dp.at(i);
            }
        }
    }
    return dp[(1 << n) - 1];
}
