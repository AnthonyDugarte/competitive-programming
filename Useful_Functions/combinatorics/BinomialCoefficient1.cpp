// Binomial coefficients -> source: https://en.wikipedia.org/wiki/Recurrence_relation

using type_t = long long;

// https://stackoverflow.com/questions/35226781/finding-binomial-coefficient-for-large-n-and-k-modulo-m

constexpr type_t mod { 1000003 };

// Extended Euclidean algorithm
// Time Complexity: O(log(min(a, b)))
type_t xGCD(type_t a, type_t b, type_t &x, type_t &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    type_t x1, y1, gcd{ xGCD(b, a % b, x1, y1) };
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// factorial of n modulo mod
// O(n)
type_t modfact(type_t n) {
    type_t result = 1;
    while (n > 1) {
        (result *= n) %= mod;
        --n;
    }
    return result;
}

// inverse of a modulo mod
// Time Complexity: O(log(min(a, mod))) + O(1)
type_t inverse(type_t a) {
    type_t x, y;
    xGCD(a, mod, x, y);
    
    return (x % mod + mod) % mod; 
}

// O(n) + O(k) + O(log(min(k, mod))) + O(n - k) + O(log(min(n - k, mod))) + O(1)
// Time Complexity: O(n) -> factorial, optimize factorial
type_t binomialCoeff(type_t n, type_t k)
{
    return modfact(n) * inverse(modfact(k)) * inverse(modfact(n - k)) % mod;
}