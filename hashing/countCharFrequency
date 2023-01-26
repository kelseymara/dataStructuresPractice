/*
program to count the occurences of a char in a string using an unordered map
*/ 

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<char,int> myMap;
    string str="banana";
    
    for(char c:str)
    {
        myMap[c]++;
    }

    for(auto itr:myMap)
    {
        cout << "Character: " << itr.first << " count: " << itr.second << endl;
    }
    
    
    return 0;
}
