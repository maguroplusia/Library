template<typename F>
struct FixPoint : F {
    template<typename G>
    FixPoint(G&& g) : F{std::forward<G>(g)} {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return F::operator()(*this,std::forward<Args>(args)...);
    }
};

#if defined(__cpp_deduction_guides)
template<typename F>
FixPoint(F&&) -> FixPoint<std::decay_t<F>>;
#endif

template<typename F>
inline FixPoint<std::decay_t<F>> fix(F&& f) {
    return std::forward<std::decay_t<F>>(f);
}