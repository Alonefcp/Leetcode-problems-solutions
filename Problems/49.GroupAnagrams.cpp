
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{

    unordered_map<string, vector<string>> anagramsOcurrence = unordered_map<string, vector<string>>();

    for (string s : strs)
    {
        string orderedWord = s;
        sort(orderedWord.begin(), orderedWord.end());
        anagramsOcurrence[orderedWord].push_back(s);
    }

    vector<vector<string>> groupedAnamgrams = vector<vector<string>>();

    for (pair<string, vector<string>> p : anagramsOcurrence)
    {
        groupedAnamgrams.push_back(p.second);
    }

    return groupedAnamgrams;

}