#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

void matchSubstring(string text, string pattern)
{
    if (pattern.length() > text.length())
        return;

    unordered_set<string> myset;
    unordered_set<string>::hasher hash_fn= myset.hash_function();

    int start_pos =0;
    int end_pos = text.length();
    while (end_pos-start_pos >= pattern.length())
    {
        //cout<<"start_pos:"<<start_pos<<endl;
        if (hash_fn(text.substr(start_pos,pattern.length())) == hash_fn(pattern) )
        {
            //do actual check here for resolving clash
            for (int i=0; i<pattern.length(); i++)
            {
                if (text[start_pos+i] != pattern[i])
                {
                    break;
                }
            }
        cout<<"pattern found at position "<<start_pos<<endl;
        }
        start_pos++;
    }

}
int main()
{
    matchSubstring("abcdabcabceeeeabcd","abc");
    return 0;
}

