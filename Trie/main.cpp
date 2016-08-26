#include <iostream>

using namespace std;
#define MAX_SIZE 26
class TrieNode {
public:
    TrieNode* children[MAX_SIZE];
    bool isLeaf;

    TrieNode() {
        for (int i=0;i<MAX_SIZE;i++)
        {
            children[i]=nullptr;
        }
        isLeaf = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode;
    }

    void insert(string word)
    {
        TrieNode* runner = root;

        for (auto i : word)
        {
            int index= tolower(i) -'a';
            if (runner->children[index] == nullptr)
                runner->children[index] = new TrieNode();

            runner = runner->children[index];
        }
        runner->isLeaf = true;
    }

    bool search(string word)
    {
        TrieNode* runner = root;

        for (auto i : word)
        {
            int index= tolower(i) -'a';
            if (runner->children[index] == nullptr)
                return false;
            runner = runner->children[index];
        }
        return runner && runner->isLeaf;
    }

    bool startsWith(string word)
    {
        TrieNode* runner = root;

        for (auto i : word)
        {
            int index= tolower(i) -'a';
            if (runner->children[index] == nullptr)
                return false;
            runner = runner->children[index];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("abc");
    trie.insert("abcdef");
    cout<<"inserted abc, abcdef"<<endl;

    cout<<"trie.search(\"abc\"):"<<trie.search("abc")<<endl;
    cout<<"trie.search(\"ab\"):"<<trie.search("ab")<<endl;
    cout<<"trie.search(\"ABC\"):"<<trie.search("ABC")<<endl;
    cout<<"trie.search(\"abcdef\"):"<<trie.search("abcdef")<<endl;
    cout<<"trie.search(\"abcde\"):"<<trie.search("abcde")<<endl;

    cout<<"trie.startsWith(\"a\"):"<<trie.startsWith("a")<<endl;
    cout<<"trie.startsWith(\"ab\"):"<<trie.startsWith("ab")<<endl;
    cout<<"trie.startsWith(\"abc\"):"<<trie.startsWith("abc")<<endl;
    cout<<"trie.startsWith(\"f\"):"<<trie.startsWith("f")<<endl;
    return 0;
}
