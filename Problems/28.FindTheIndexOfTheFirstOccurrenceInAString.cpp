
int strStr(string haystack, string needle) 
{
    int firstIndex = 0;

    for (int i = 0; i < haystack.size(); ++i)
    {
        string str = "";

        for (int j = i; j < i + needle.size(); j++)
        {
            if (j < haystack.size())
            {
                str += haystack[j];
            }
        }

        if (str == needle)
        {
            return i;
        }
    }

    return -1;
}