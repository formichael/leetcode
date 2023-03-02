class Solution {
public:
    bool checkEqualMaps(const map<string, int> &l, const map<string, int> &r)
    {
        return l.size() == r.size() &&
                std::equal(l.begin(), l.end(), r.begin(),
                            [](auto &a, auto &b){return a.first == b.first && a.second == b.second;});
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> out;

        map<string, int> wordsDict;
        for (const auto &word : words) {
            wordsDict[word] += 1;
        }

        int wordLen = words[0].size();
        int wordsCnt = words.size();
        int subLen = wordLen * wordsCnt;

        for (int i = 0; i < (int)s.size() - subLen + 1; ++i) {
            map<string, int> subDict;

            for (int j = 0; j < subLen; j += wordLen) {
                subDict[s.substr(i + j, wordLen)] += 1;
            }

            if (checkEqualMaps(wordsDict, subDict)) {
                out.push_back(i);
            }
        }

        return out;
    }
};
