template<typename T> // 1 + 2 + 3 + 4 + ... + n
T naturalSummatory(T n) { return n * (n + 1) / 2; }

template<typename T> // 1^2 + 2^2 + 3^2 + 4 ^2+ ... + n^2
T quadraticSummatory(T n) { return n * (n + 1) * ( 2 * n + 1) / 6; }


template<typename T>
T pow(T n, T e);

template <typename T>  // x^0 + x^1 + x^2 + x^3  + ... + x^n --> (x ^ (n + 1) - 1) / (x - 1)
T finiteGeometricSerie(T x, T n)
{
    if(x == 1)
        return n + 1;

    return (pow(x, n + 1) - 1) / (x - 1);
}

template<typename T>
T pow(T n, T e)
{
    T res { 1 };

    while(e > T(0))
    {
      if (e & 1)
        res = res * n;

      e >>= 1;
      n = n * n;
    }

    return res;
}

int main()
{

  return 0;
}
