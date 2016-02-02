/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.
Example
Input : 4
Output : True
as 2^2 = 4.
*/

#include <cmath>
#include <iostream>

bool Solution::isPower(int A) {
	int maxfactor = sqrt(A);
	vector<bool> isPrime(A+1, false);
    isPrime[2] = true; 
    isPrime[3] = true;
    
}


