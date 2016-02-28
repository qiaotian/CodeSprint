// TLE 
// Need more memory to record status to reduce time expense)
/*
class Solution {
private:
    int helper(int n, int maxnum) {
        if(maxnum == 1) return n;
        if(n == 0) return 0;
        int sqr = min(maxnum, (int)floor(sqrt(n)));
        if(pow(sqr, 2) == n) return 1;
        
        int count = n;
        for(int i = sqr; i >= 1; i--) {
            count = min(count, helper(n - i*i, i));
        }
        return 1 + count;
    }
public:
    int numSquares(int n) {
        return helper(n, (int)floor(sqrt(n)));
    }
};
*/

// Dynamic Programming (428ms, beats 50%)
/*
class Solution {
public:
    int numSquares(int n) {
        if(n < 1) return 0;
        // cnt[i] = the least number of perfect square numbers 
        // which sum to i. Note that cnt[0] is 0.
        vector<int> cnt(n + 1, INT_MAX);
        cnt[0] = 0;
        for (int i = 1; i <= n; i++) {
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++)
                cnt[i] = min(cnt[i], cnt[i - j*j] + 1);
        }
        return cnt[n];
    }
};
*/

// Static Dynamic Programming (12ms, 85%)
class Solution {
public:
    int numSquares(int n) 
    {
        if (n < 1) return 0;

        // cnt[i] = the least number of perfect square numbers 
        // which sum to i. Since cnt is a static vector, if 
        // cnt.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cnt({0});

        // While cnt.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while (cnt.size() <= n) {
            int m = cnt.size();
            int sqr = INT_MAX;
            for (int i = 1; i*i <= m; i++) {
                sqr = min(sqr, cnt[m - i*i] + 1);
            }
            cnt.push_back(sqr);
        }

        return cnt[n];
    }
};

// Mathematical Solution: 4ms
class Solution 
{  
private:  
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n*sqrt_n == n);  
    }

public:
    // Based on Lagrange's Four Square theorem, there 
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n) 
    {  
        // If n is a perfect square, return 1.
        if(is_square(n)) 
        {
            return 1;  
        }

        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while ((n & 3) == 0) // n%4 == 0  
        {
            n >>= 2;  
        }
        if ((n & 7) == 7) // n%8 == 7
        {
            return 4;
        }

        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i*i)) 
            {
                return 2;  
            }
        }  

        return 3;  
    }  
}; 

// Breadth-First Search: 80ms
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }

        // perfectSquares contain all perfect square numbers which 
        // are smaller than or equal to n.
        vector<int> perfectSquares;
        // cntPerfectSquares[i - 1] = the least number of perfect 
        // square numbers which sum to i.
        vector<int> cntPerfectSquares(n);

        // Get all the perfect square numbers which are smaller than 
        // or equal to n.
        for (int i = 1; i*i <= n; i++)
        {
            perfectSquares.push_back(i*i);
            cntPerfectSquares[i*i - 1] = 1;
        }

        // If n is a perfect square number, return 1 immediately.
        if (perfectSquares.back() == n)
        {
            return 1;
        }

        // Consider a graph which consists of number 0, 1,...,n as
        // its nodes. Node j is connected to node i via an edge if  
        // and only if either j = i + (a perfect square number) or 
        // i = j + (a perfect square number). Starting from node 0, 
        // do the breadth-first search. If we reach node n at step 
        // m, then the least number of perfect square numbers which 
        // sum to n is m. Here since we have already obtained the 
        // perfect square numbers, we have actually finished the 
        // search at step 1.
        queue<int> searchQ;
        for (auto& i : perfectSquares)
        {
            searchQ.push(i);
        }

        int currCntPerfectSquares = 1;
        while (!searchQ.empty())
        {
            currCntPerfectSquares++;

            int searchQSize = searchQ.size();
            for (int i = 0; i < searchQSize; i++)
            {
                int tmp = searchQ.front();
                // Check the neighbors of node tmp which are the sum 
                // of tmp and a perfect square number.
                for (auto& j : perfectSquares)
                {
                    if (tmp + j == n)
                    {
                        // We have reached node n.
                        return currCntPerfectSquares;
                    }
                    else if ((tmp + j < n) && (cntPerfectSquares[tmp + j - 1] == 0))
                    {
                        // If cntPerfectSquares[tmp + j - 1] > 0, this is not 
                        // the first time that we visit this node and we should 
                        // skip the node (tmp + j).
                        cntPerfectSquares[tmp + j - 1] = currCntPerfectSquares;
                        searchQ.push(tmp + j);
                    }
                    else if (tmp + j > n)
                    {
                        // We don't need to consider the nodes which are greater ]
                        // than n.
                        break;
                    }
                }

                searchQ.pop();
            }
        }

        return 0;
    }
};

/**
 * WARNING
 * 1. MY DFS(TLE)
 * 实际codeing容易忽略1/2的实际值为0，应该用0.5代替；
 * 
 * 2. Static DP is much faster than DP
 * 
 * Static DP is equivalent to DP if you only call function once. 
 * However, if you call it several times, static vector would be reused and make whole test cases much faster.
 * 
 * If you define a non-static private class vector, 
 * each class instance will have a copy of the vector. 
 * It won't save you time if the test code creates a class instance for each test case.
 * But if you define a static vector within the class method, 
 * all class instances will share a single copy of the vector.
 * 
 * 
 * REFERENCE
 * https://leetcode.com/discuss/58056/summary-of-different-solutions-bfs-static-and-mathematics
 * /
