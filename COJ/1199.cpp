#include <bits/stdc++.h>
using namespace std;

struct node{
    size_t val;
    node* l_node = nullptr;
    node* r_node = nullptr;
};

unsigned long long get_val(node* root)
{
    if(root == nullptr)
        return -1;
    
    unsigned long long l_res{ get_val(root->l_node) };
    unsigned long long r_res{ get_val(root->r_node) };
    
    if(l_res == -1)
        l_res = 1;
    if(r_res == -1)
        r_res = 0;
    
    return root->val * l_res + r_res;
}

node * build_from_preorder(vector<unsigned long long> v)
{
    if(v.size() == 0)
        return nullptr;
    
    vector<unsigned long long> l_v(v.begin() + 1, upper_bound(v.begin() + 1, v.end(), v[0]));

    vector<unsigned long long> r_v(upper_bound(v.begin() + 1, v.end(), v[0]), v.end());
    
    node* root = new node;
    root->val = v[0];
    root->l_node = build_from_preorder(l_v);
    root->r_node = build_from_preorder(r_v);
    
    return move(root);
}

void preorder_trans(node * root)
{
    if(root == nullptr)
        return;
    
    cout << root->val << "\n";
    preorder_trans(root->l_node);
    preorder_trans(root->r_node);
}

int main(){
    size_t t;
    cin >> t;

    while(--t != -1)
    {
        size_t n;
        cin >> n;

        vector<unsigned long long> vals(n);
        for(unsigned long long & val : vals)
            cin >> val;

        cout << get_val(build_from_preorder(vals)) << "\n";
    }

    return 0;
}