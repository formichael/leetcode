// Sieve of Eratosthenes
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (!primes[i])
                continue;

            for (int j = i * i; j < n; j += i)
                primes[j] = false;
        }
        
        return count(begin(primes), end(primes), true);
    }
};
