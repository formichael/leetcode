class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        if(x == -2147483648)
        {
            return 0;
        }
        else if(x < 0)
        {
            flag = -1;
            x = -x;
        }
        
        int y = 0;
        for(;;)
        {
            if(x < 10)
            {
                if(y > 214748364 or (y == 214748364 && x > 7))
                {
                    y = 0;
                }
                else
                {
                    y = 10 * y + x;
                }
                break;
            }
            else
            {
                y = 10 * y + x % 10;
                x = int(x / 10);
            }
        }
        
        if(flag == -1)
        {
            return -y;
        }
        else 
        {
            return y;
        }
    }
};
