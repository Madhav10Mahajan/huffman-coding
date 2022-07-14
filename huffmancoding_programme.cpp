#include <bits/stdc++.h>
using namespace std;
template <typename T>
class huffmannode
{
public:
    char data;
    int freq;
    huffmannode<char> *right;
    huffmannode<char> *left;
    huffmannode(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        this->right = NULL;
        this->left = NULL;
    }
};
vector<pair<char, int>> findfreq(string str)
{
    vector<pair<char, int>> ans;
    unordered_map<char, int> ourmap;
    for (int i = 0; i < str.size(); i++)
    {
        ourmap[str[i]]++;
    }
    unordered_map<char, int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        pair<char, int> p;
        p.first = it->first;
        p.second = it->second;
        ans.push_back(p);
        it++;
    }
    return ans;
}
class compare
{
public:
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        if (a.second > b.second)
        {
            return true;
        }
        return false;
    }
};
priority_queue<pair<char, int>, vector<pair<char, int>>, compare> sortfreq(vector<pair<char, int>> ans)
{
    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> minheap;
    for (int i = 0; i < ans.size(); i++)
    {
        minheap.push(ans[i]);
    }

    return minheap;
}
class compare2
{
public:
    bool operator()(huffmannode<char> *a, huffmannode<char> *b)
    {
        if (a->freq > b->freq)
        {
            return true;
        }
        return false;
    }
};
huffmannode<char> *maketree(priority_queue<pair<char, int>, vector<pair<char, int>>, compare> &minheap)
{
    if (minheap.size() == 0)
    {
        return NULL;
    }
    priority_queue<huffmannode<char> *, vector<huffmannode<char> *>, compare2> q;
    while (minheap.size() != 0)
    {
        pair<char, int> p = minheap.top();
        minheap.pop();
        huffmannode<char> *newnode = new huffmannode<char>(p.first, p.second);
        q.push(newnode);
    }
    // while (q.size() != 0)
    // {
    //     huffmannode<char> *node = q.top();
    //     q.pop();
    //     cout << node->data << " " << node->freq << endl;
    // }

    while (q.size() > 1)
    {
        huffmannode<char> *node1 = q.top();
        q.pop();
        huffmannode<char> *node2 = q.top();
        q.pop();
        huffmannode<char> *newnode = new huffmannode<char>('.', node1->freq + node2->freq);
        q.push(newnode);
        newnode->left = node1;
        newnode->right = node2;
    }
    huffmannode<char> *root = q.top();
    return root;
}
void getvalues(huffmannode<char> *root, string s, vector<pair<char, string>> &values)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data != '.')
    {
        values.push_back(make_pair(root->data, s));
        return;
    }
    else
    {
        getvalues(root->left, s + "0", values);
        getvalues(root->right, s + "1", values);
    }
}
int main()
{
    string str;
    cin >> str;
    vector<pair<char, int>> ans = findfreq(str);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    cout << endl;
    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> minheap = sortfreq(ans);
    // while (minheap.size() != 0)
    // {
    //     pair<char, int> p = minheap.top();
    //     cout << p.first << " " << p.second << endl;
    //     minheap.pop();
    // }
    huffmannode<char> *root = maketree(minheap);
    vector<pair<char, string>> values;
    getvalues(root, " ", values);
    string temp = "";
    unordered_map<char, int> ourmap;
    for (int i = 0; i < str.size(); i++)
    {
        ourmap[str[i]]++;
    }
    int size = 0;
    for (int i = 0; i < values.size(); i++)
    {
        pair<char, string> p = values[i];
        cout << p.first << " " << p.second << endl;
        int freq = ourmap[p.first];
        for (int i = 0; i < freq; i++)
        {
            temp += p.second;
        }
    }
    cout << endl;
    cout << "************************************************************************************************************************************************************" << endl;
    cout << temp << endl;
    cout << "original size: " << 8 * str.size() << endl;
    cout << "new size: " << temp.size() - str.size() << endl;
    return 0;
}