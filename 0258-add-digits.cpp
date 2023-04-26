class Solution {
public:
    int addDigits(int num) {
        if (num < 10)
            return num;

        return addDigits(addDigits(num/10) + num%10);
    }
};

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

/*
origin : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
offset : 0 1 2 3 4 5 6 7 8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 
mod    : 0 1 2 3 4 5 6 7 8  0  1  2  3  4  5  6  7  8  0  1  2  3  4  5  6  7  8  0  1  2  
digroot: 1 2 3 4 5 6 7 8 9  1  2  3  4  5  6  7  8  9  1  2  3  4  5  6  7  8  9  1  2  3
*/
