/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size()==0) return ""; 
        else if(strs.size()==1) return strs[0];
        
        string template_string = strs[0];
        for(int i=0; i<template_string.size(); ++i) {
            for(int j=1; j<strs.size(); ++j) {
                string reference_string = strs[j];
                if(reference_string.size()==0) return "";
                if(i>reference_string.size()-1) return prefix;
                if(reference_string.at(i)!=template_string.at(i)) return prefix;
            }
            prefix += template_string.at(i);
        }
        return prefix;
    }
};
