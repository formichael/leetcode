class Solution {
public:
    void stringToInts(string version, vector<int> &arr) {
        int n = 0;
        for (int i = 0; i < version.size(); i++) {
            if (version[i] != '.') {
                n = n * 10 + (version[i] - '0');
            }

            if (version[i] == '.' || i + 1 == version.size()) {
                arr.push_back(n);
                n = 0;
                continue;
            }
        }
    }

    int compareVersion(string version1, string version2) {
        vector<int> arr1, arr2;
        stringToInts(version1, arr1);
        stringToInts(version2, arr2);

        int i = 0;
        while (i < arr1.size() && i < arr2.size()) {
            if (arr1[i] > arr2[i])
                return 1;
            if (arr1[i] < arr2[i])
                return -1;
            
            ++i;
        }

        int j = i;
        while (j < arr1.size()) {
            if (arr1[j] != 0)
                return 1;
            ++j;
        }

        j = i;
        while (j < arr2.size()) {
            if (arr2[j] != 0)
                return -1;
            ++j;
        }

        return 0;
    }
};
