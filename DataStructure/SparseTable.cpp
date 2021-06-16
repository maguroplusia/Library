template <typename T>
class SparseTable {
    vector<vector<T>> table;
    vector<int> lookup;

public:

    SparseTable(vector<T> v) {
        int b = 0;

        while((1 << b) <= v.size()) {
            b++;
        }

        table.resize(b,vector<T>(1 << b));

        for(int i = 0;i < v.size();i++) {
            table[0][i] = v[i];
        }

        for(int i = 1;i < b;i++) {
            for(int j = 0;j + (1 << i) <= (1 << b);j++) {
                table[i][j] = min(table[i - 1][j],table[i - 1][j + (1 << (i - 1))]);
            }
        }

        lookup.resize(v.size() + 1);
        
        for(int i = 2;i < lookup.size();i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    //query(l,r) = 区間[l,r)の最小値を返す
    T query(int l,int r) {
        int b = lookup[r - l];
        return min(table[b][l],table[b][r - (1 << b)]);
    }
};
