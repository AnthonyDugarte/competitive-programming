// for a faster standar c++ input
# include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // avoid this if interactive I/O
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    /*
      * ... code here ...
      */
    return 0;
}


// creating a vector with no duplicates and ordered, eficiently
// just to use [] instead of iterators xD
# include <vector>
# include <unordered_set>
# include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t n; std::cin >> n;

    std::unordered_set<int> data;
    for(size_t i{}; i < n; ++i)
    {
        int d;
        std::cin >> d;

        data.insert(d);
    }

    std::vector<int> cuteData;
    cuteData.assign(data.begin(), data.end());
    std::sort(cuteData.begin(), cuteData.end());

    return 0;
}
