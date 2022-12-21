class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int vsize = strs.size();
        if(vsize == 0){
            return "";
        }

        if(vsize == 1){
            return strs[0];
        }

        if(strs[0].length() == 0){
            return "";
        }

        for(int i = 0;;i++){
            char c = 0;
            for(string s : strs) {
                if(i+1 > s.length()){
                    if(i>0){
                        return strs[0].substr(0,i);
                    } else {
                        return "";
                    }
                }
                if(c == 0){
                    c = s[i];
                } else {
                    if(c != s[i]){
                        if(i>0){
                            return strs[0].substr(0,i);
                        } else {
                            return "";
                        }
                    }
                }
            }
        }
      
    }
};
