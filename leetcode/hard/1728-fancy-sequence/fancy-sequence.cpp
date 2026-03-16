class Fancy {
  long long add = 0;
  long long mul = 1;
  const long long mod = 1e9 + 7;
  vector<long long> arr;
  long long modPow(long long a, long long b) {
    long long res = 1;
    while (b) {
      if (b & 1) res = (res * a) % mod;
      a = (a * a) % mod;
      b >>= 1;
    }
    return res;
  }

  long long modInverse(long long x) { return modPow(x, mod - 2); }

 public:
  Fancy() {}

  void append(int val) {
    long long x = ((val - add) % mod + mod) % mod;
    x = (x * modInverse(mul)) % mod;
    arr.push_back(x);
  }

  void addAll(int inc) { add = (add + inc) % mod; }

  void multAll(int m) {
    mul = (mul * m) % mod;
    add = (add * m) % mod;
  }

  int getIndex(int idx) {
    if (idx >= arr.size()) return -1;

    long long val = arr[idx];
    val = (val * mul) % mod;
    val = (val + add) % mod;

    return val;
  }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */