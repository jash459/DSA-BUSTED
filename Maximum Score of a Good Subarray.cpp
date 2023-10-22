 long long mod = 1e9 + 7;

long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long numberOfPaths(long long m, long long n) {
    long long N = m + n - 2;
    long long R = min(m - 1, n - 1);
    
    long long numerator = 1;
    long long denominator = 1;

    for (long long i = 0; i < R; i++) {
        numerator = (numerator * (N - i)) % mod;
        denominator = (denominator * (i + 1)) % mod;
    }
    
    long long inverseDenominator = modPow(denominator, mod - 2, mod);
    
    return (numerator * inverseDenominator) % mod;
}
