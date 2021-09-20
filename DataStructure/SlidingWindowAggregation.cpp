template<class T>
class SWAG {
    class Node {
    public:
        T val,sum;
        Node(const T& val,const T& sum) : val(val),sum(sum) {}
    };

    std::stack<Node> front_stack,back_stack;
    function<T(T,T)> op;

public:
    SWAG(const function<T(T,T)> op) : op(op) {}

    bool empty() {
        return front_stack.empty() && back_stack.empty();
    }

    T fold_all() {
        assert(!empty());
        if(front_stack.empty()) {
            return back_stack.top().sum;
        }
        else if(back_stack.empty()) {
            return front_stack.top().sum;
        }
        else {
            return op(front_stack.top().sum,back_stack.top().sum);
        }
    }

    void push(T x) {
        if(back_stack.empty()) back_stack.emplace(x,x);
        else back_stack.emplace(x,op(back_stack.top().sum,x));
    }

    void pop() {
        assert(!empty());
        if(front_stack.empty()) {
            front_stack.emplace(back_stack.top().val,back_stack.top().val);
            back_stack.pop();
            while(!back_stack.empty()) {
                T tmp{op(back_stack.top().val,front_stack.top().sum)};
                front_stack.emplace(back_stack.top().val,tmp);
                back_stack.pop();
            }
        }
        front_stack.pop();
    }
};