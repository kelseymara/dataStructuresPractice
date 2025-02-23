# Codewars challenges on strings
Contains challenges did on Codewars about strings

## Split Strings
Complete the solution so that it splits the string into pairs of two characters. If the string contains an odd number of characters then it should replace the missing second character of the final pair with an underscore ('_').

Examples:

* 'abc' =>  ['ab', 'c_']
* 'abcdef' => ['ab', 'cd', 'ef']

### Brainstorming
- to find if string has an odd number of characters do: string.length()%2 != 0 
- need to increase index by 2 (i+=2) because looping through pairs 
- have to use substring to get 

### My solution
```C++
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s)
{
    using namespace std;
    vector<string> result;

    // Loop through the string in pairs of characters
    for (size_t i = 0; i < s.length(); i += 2) {
        // If the length is even OR odd and not last character, add a pair of characters
        if (s.length() % 2 == 0 || (s.length()%2 !=0 && i!=s.length()-1)) {
            result.push_back(s.substr(i, 2));
        } 
        // If the length is odd and we're at the last character, add character and underscore
        else{
            result.push_back(s.substr(i, 1) + "_"); 
        } 
    }
    return result;
}
```S