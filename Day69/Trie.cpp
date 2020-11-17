#include <iostream>
#include <vector>

using namespace std;

struct Trie
{
    struct Trie *child[26];
    bool isEnd;
};

struct Trie* getNode() 
{
    struct Trie* node = new Trie();
    for(int i = 0; i < 26; i++)
    {
        node->child[i] = NULL;
    }

    node->isEnd = false;

    return node;
}

void insert(struct Trie* root, string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        int index = (s[i] - 'a');
        if(root->child[index] == NULL)
        {
            root->child[index] = getNode();
        }
        root = root->child[index];
    }

    root->isEnd = true;
}

bool find(struct Trie *root, string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        int index = (s[i] - 'a');
        if(root->child[index] == NULL)
        {
            return false;
        }
        root = root->child[index];
    }

    return root->isEnd == true;
}

int main()
{
    string arr[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Trie *root = getNode();

    for(int i = 0; i < n; i++)
    {
        insert(root, arr[i]);
    }

    cout << find(root, "the") << endl;
    cout << find(root, "a") << endl;
    cout << find(root, "there") << endl;
    cout << find(root, "answer") << endl;
    cout << find(root, "any") << endl;
    cout << find(root, "by") << endl;
    cout << find(root, "bye") << endl;
    cout << find(root, "their") << endl;
    cout << find(root, "ther") << endl;
}