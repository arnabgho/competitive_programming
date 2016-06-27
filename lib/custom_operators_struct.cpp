bool operator <(const MyStruct& x, const MyStruct& y) {
    return std::tie(x.a, x.b, x.c) < std::tie(y.a, y.b, y.c);
}