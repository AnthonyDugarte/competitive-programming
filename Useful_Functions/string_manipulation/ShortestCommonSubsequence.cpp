// source: David Cédres

#include <iostream>
#include <string>
#include <map>
#include <utility>

std::string SCS(std::string a_str, std::string b_str, std::map<std::pair<const std::string, const std::string>, std::string> &mem)
{
    auto search { mem.find({ a_str, b_str }) };
    if(search != mem.end())
        return (*search).second;

    if(a_str.empty())
        return b_str;

    if(b_str.empty())
        return a_str;

    if(a_str[0] == b_str[0])
        return a_str[0] + SCS(a_str.substr(1), b_str.substr(1), mem);

    std::string case_a = a_str[0] + SCS(a_str.substr(1), b_str, mem);
    std::string case_b = b_str[0] + SCS(a_str, b_str.substr(1), mem);

    return mem[{ a_str, b_str }] = case_a.size() <= case_b.size() ? case_a : case_b;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string a, b;
    while(std::cin >> a >> b)
    {
        std::map<std::pair<const std::string, const std::string>, std::string> mem;

        std::cout << SCS(a, b, mem) << "\n";
    }

    return 0;
}
