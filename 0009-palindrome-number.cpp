class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        
        int y = 0;
        int z = x;
        
        for(;;)
        {
            if(x < 10)
            {
                y = 10 * y + x;
                break;
            }
            else
            {
                y = 10 * y + x % 10;
                x = int(x / 10);
            }
        }
        return z == y;
    }
};
