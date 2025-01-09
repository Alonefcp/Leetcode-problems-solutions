#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> splitString(const string& str, char delimiter)
{
    vector<std::string> tokens;
    stringstream ss(str);
    string token;

    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int isPrefixOfWord(string sentence, string searchWord)
{
    vector<string> words = splitString(sentence, ' ');

    for (int i = 0; i < words.size(); ++i)
    {
        if (words[i].find(searchWord) == 0)
        {
            return i + 1;
        }
    }

    return -1;
}

int main()
{
    string sentence = "i love eating burger";
    string searchWord = "burg";
    int result = isPrefixOfWord(sentence, searchWord);

    return 0;
}