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

bool isEmpty(struct Trie *root)
{
    for(int i = 0; i < 26; i++)
    {
        if(root->child[i] != NULL)
        {
            return false;
        }
    }

    return true;
}

struct Trie* deleteStr(struct Trie *root, string s, int k)
{
    // cout << s[k] << endl;
    if(root == NULL)
    {
        return root;
    }

    if(k == s.length())
    {
        root->isEnd = false;

        if(isEmpty(root))
        {
            cout << "true";
            delete (root);
            root = NULL;
        }

        return root;
    }

    int index = s[k] - 'a';
    root->child[index] = deleteStr(root->child[index], s, k + 1);

    if(isEmpty(root) && root->isEnd == false)
    {
        delete (root);
        root = NULL;
    }

    return root;
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
    // cout << find(root, "a") << endl;
    // cout << find(root, "there") << endl;
    // cout << find(root, "answer") << endl;
    // cout << find(root, "any") << endl;
    // cout << find(root, "by") << endl;
    // cout << find(root, "bye") << endl;
    // cout << find(root, "their") << endl;
    // cout << find(root, "ther") << endl;

    deleteStr(root, "the", 0);
    cout << find(root, "the") << endl;
    cout << find(root, "there") << endl;
}