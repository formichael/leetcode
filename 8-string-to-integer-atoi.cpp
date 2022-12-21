class Solution {
public:
    int myAtoi(string str) {
        bool sign = false;
        bool start = false;
        long value = 0;

        for(int i = 0; i < str.size(); i++) {
            //" "
            if(!start && str[i] == 32) {
                continue;
            }
            //"-"
            if(!start && str[i] == 45) {
                start = true;
                sign = true;
                continue;
            }
            //"+"
            if(!start && str[i] == 43) {
                start = true;
                continue;
            }
            if(str[i] < 48 || str[i] > 57) {
                break;
            }
            if(!start && 48 <= str[i] && str[i] <= 57) {
                start = true;
            }

            if(sign) {
                value = value*10-(str[i] - 48);
                if(value <= INT_MIN) {
                    value = INT_MIN;
                    break;
                }
            } else {
                value = value*10+(str[i] - 48);
                if(value >= INT_MAX) {
                    value = INT_MAX;
                    break;
                }
            }
        }

        return value;
    }
};
