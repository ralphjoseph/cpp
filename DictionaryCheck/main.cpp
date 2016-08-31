#include <iostream>
#include <set>
#include <string>


using namespace std;

class Dictonary
{
    set<string> dict;
public:
    add(string word)
    {
        dict.insert(word);
    }

    bool contains(string word)
    {
        return dict.count(word);
    }
};

Dictonary dict;

bool wordbreak(string word)
{
    //cout<<"Enter word:"<<word<<endl;
    int size = word.size();
    if (size ==0)
        return true;
    //try for all combinations
    for (int i=1; i<=size; i++)
    {
        //cout<<" substr: "<<word.substr(i,size-i)<<":"<<size-i<<endl;
        if (dict.contains(word.substr(0,i)) && wordbreak(word.substr(i,size-i)) )
        {
            //cout<<"Matched:"<<word.substr(0,i)<<endl;
            return true;
        }
    }
    return false;
}

int main()
{
    dict.add("hello");
    dict.add("there");
    dict.add("i");
    dict.add("am");

    cout<<"wordbreak(\"helloiamthere\"): "<<wordbreak("helloiamthere")<<endl;
    cout<<"wordbreak(\"helloiamhere\"): "<<wordbreak("helloiamhere")<<endl;
    return 0;
}
