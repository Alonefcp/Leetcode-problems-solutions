#include <sstream>
#include <string>

using namespace std;

/*
You are given a string sentence that consist of words separated by spaces. Each word consists of lowercase and uppercase letters only.
We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.) The rules of Goat Latin are as follows:

If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the end of the word.
For example, the word "apple" becomes "applema".
If a word begins with a consonant (i.e., not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end, and so on.
Return the final sentence representing the conversion from sentence to Goat Latin.

Example 1:

Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Example 2:

Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

Constraints:

1 <= sentence.length <= 150
sentence consists of English letters and spaces.
sentence has no leading or trailing spaces.
All the words in sentence are separated by a single space.
 */

string toGoatLatin(string sentence) {

    istringstream iss(sentence);
    string result;
    string word;

    int aToAdd = 1;
    while (iss >> word)
    {
        if (tolower(word[0]) == 'a' || tolower(word[0]) == 'e' || tolower(word[0]) == 'i' || tolower(word[0]) == 'o' || tolower(word[0]) == 'u')
        {
            word.push_back('m');
            word.push_back('a');
        }
        else
        {
            char firstLetter = word[0];
            word.erase(word.begin());
            word.push_back(firstLetter);
            word.push_back('m');
            word.push_back('a');
        }

        for (int i = 0; i < aToAdd; ++i)
        {
            word.push_back('a');
        }

        ++aToAdd;
        result += word + ' ';
    }
    result.pop_back(); //Remove white space
    return result;
}

int main()
{
    string sentence = "I speak Goat Latin";
    string result = toGoatLatin(sentence);

    return 0;
}