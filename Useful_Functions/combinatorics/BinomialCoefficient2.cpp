// Binomial coefficients -> source: https://en.wikipedia.org/wiki/Recurrence_relation

using namespace std;

using type_t = unsigned long long;

// https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
// Time Complexity: O(k)
// Auxiliary Space: O(1)
type_t binomialCoeff(type_t n, type_t k) 
{
    type_t res = 1;
  
    // Since C(n, k) = C(n, n-k) 
    if(k > n - k)
        k = n - k; 
  
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (type_t i = 0; i < k; ++i) 
    {
        res *= (n - i); 
        res /= (i + 1);
    }

    return res; 
}