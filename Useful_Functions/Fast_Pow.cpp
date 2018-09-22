// pow formula source: from a book sended by Juan Diego Morón
// Time complexity: O(ln n)
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
