// Codeforces Round #527
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


size_t n, m;
size_t p{ 0 }, ss{ 0 };
string s;

using p_si = pair<string, size_t>;
vector<p_si> words;
vector<int> types;

void endf()
{
    for(const size_t & i : types)
        std::cout << (i == 0 ? "P" : "S");
    std::cout << "\n";
}

bool s_match_prevs(const string & s_ab)
{
    for(size_t i{ 0 }; i < m; ++i)
    {
        if(types[words[i].second] == -1)
            continue;
        if(types[words[i].second] == 0) // prefix
        {
            for(size_t j{ 0 }; j < words[i].first.size(); ++j)
                if(s_ab[j] != words[i].first[j])
                    return false;
        }
        else if(types[words[i].second] == 1) // suffix
        {
            for(
                string::const_reverse_iterator s_ab_rit = { s_ab.rbegin() }, word_rit = { words[i].first.rbegin() };
                word_rit != words[i].first.rend(); 
                ++word_rit, ++ s_ab_rit
            )
                if(*s_ab_rit != *word_rit)
                    return false;
        }
    }

    return true;
}

bool fun()
{
    if(p + ss == m)
        return p == ss;
    
    for(size_t i{ 0 }; i < m; ++i)
    {
        if(types[words[i].second] == -1)
        {
            bool different{ false };

            for(size_t j{ 0 }; j < words[i].first.size(); ++j)
            {
                if(s[j] != words[i].first[j])
                {
                    different = true;
                    break;
                }
            }

            if(!different)
            {
                types[words[i].second] = 0;
                ++p;
                if(fun())
                    return true;
                --p;
            }

            different = false;

            for(
                string::const_reverse_iterator s_rit { s.rbegin() }, word_rit { words[i].first.rbegin() };
                word_rit != words[i].first.rend(); 
                ++word_rit, ++ s_rit
            )
                if(*s_rit != *word_rit)
                    return false;

            if(!different)
            {
                types[words[i].second] = 1;
                ++ss;
                if(fun())
                    return true;
                --ss;
            }

            types[words[i].second] = -1;
        }
    }
    
    return false;
}

int main()
{
    cin >> n;
    m = (n * 2) - 2;

    words = vector<p_si>(m);
    types = vector<int>(m, -1);

    size_t c{ 0 };
    for(auto & p : words)
    {
        cin >> p.first;
        p.second = c;
        ++c;
    }

    sort(words.begin(), words.end(), [](p_si& a, p_si& b)->bool{
        if(a.first.size() == b.first.size())
            return a.first < b.first;
        return a.first.size() >= b.first.size();
    });

    s = string(n, 'a');


    for(size_t i{ 0 }; i < m; i += 2)
    {
        if(words[i].first == words[i + 1].first)
        {
            string & sec_s{ words[i].first };

            for(
                string::reverse_iterator s_rit { s.rbegin() }, word_rit { words[i].first.rbegin() };
                word_rit != words[i].first.rend(); 
                ++word_rit, ++ s_rit
            )
                *s_rit = *word_rit;
            
            for(size_t j{ 0 }; j < sec_s.size(); ++j)
                s[j] = sec_s[j];

            ++p;
            ++ss;

            types[words[i].second] = 0;
            types[words[i + 1].second] = 1;
        }
    }

    // all c of s equals some letter d
    if(p + ss == m)
    {
        endf();
        return 0;
    }
    
    string &a { words[0].first }, &b { words[1].first };


    string s_ab { *a.begin() + b };
    if(a + *b.rbegin() == s_ab)
    {
        bool broken { false };
        
        if(p > 0) // if prefix and suffix already established, check for them
            broken = !s_match_prevs(s_ab);

        if(!broken)
        {
            ++p;
            ++ss;
            types[words[0].second] = 0;
            types[words[1].second] = 1;
            
            string s_aux{ s };
            s = s_ab;

            if(fun())
            {
                endf();
                return 0;
            }
            --p;
            --ss;

            types[words[0].second] = -1;
            types[words[1].second] = -1;
            s = s_aux;
        }
    }

    s_ab =  *b.begin() + a;
    if(b + *a.rbegin() == s_ab)
    {
        bool broken { false };
        
        if(p > 0) // if prefix and suffix already established, check for them
            broken = !s_match_prevs(s_ab);
        
        if(!broken)
        {
            ++p;
            ++ss;
            types[words[0].second] = 1;
            types[words[1].second] = 0;
            
            string s_aux{ s };
            s = s_ab;

            if(fun())
            {
                endf();
                return 0;
            }
            --p;
            --ss;

            types[words[0].second] = -1;
            types[words[1].second] = -1;
            s = s_aux;
        }
    }

    return 0;
}