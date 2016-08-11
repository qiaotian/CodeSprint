/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
    int romanToInt(string s) {
        /*
        int result = 0;
        int predigit = 'I';
        for(int i=s.size()-1; i>=0; --i) {
            switch(s.at(i)) {
                case 'I':{
                    result+=(predigit=='I')?1:-1;
                    break;
                }
                case 'V':{
                    result+=(predigit=='I'||predigit=='V')?5:-5;
                    break;
                }
                case 'X':{
                    result+=(predigit=='I'||predigit=='V'||predigit=='X')?10:-10;
                    break;
                }
                case 'L':{
                    result+=(predigit=='I'||predigit=='V'||predigit=='X'||predigit=='L')?50:-50;
                    break;
                }
                case 'C':{
                    result+=(predigit=='I'||predigit=='V'||predigit=='X'||predigit=='L'||predigit=='C')?100:-100;
                    break;
                }
                case 'D':{
                    result+=(predigit=='I'||predigit=='V'||predigit=='X'||predigit=='L'||predigit=='C'||predigit=='D')?500:-500;
                    break;
                }
                case 'M':{
                    result+=1000;
                    break;
                }
                default:{
                    break;
                }
            }
            predigit=s.at(i);
        }
        return result;
        */
        int result = 0;
        
        int mp[100];
        mp['I'] = 1; 
        mp['V'] = 5; 
        mp['X'] = 10; 
        mp['L'] = 50; 
        mp['C'] = 100; 
        mp['D'] = 500; 
        mp['M'] = 1000;

        for(int i=s.size()-1; i>=0; --i) {
            if(i==s.size()-1) {
                result+=mp[s.at(i)];
                continue;
            }
            result+=mp[s.at(i)]>=mp[s.at(i+1)]?mp[s.at(i)]:-mp[s.at(i)];
        }
        return result;
    }
};
