/**
Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.
*/

int search_in_sorted_array_interspersed_empty_strings(vector<string> strings, string target) {
    int ll = 0;
    int rr = strings.size();
    while(ll <= rr) {
        int mid = (ll+rr)/2;
        // find the first non-empty string from mid to right
        int cp = mid;
        if(strins[mid]=="") {
            while(strings[mid]=="" && mid<=rr) mid++;
        }
        // find the first non-empty string from right to left
        if(strings[mid]=="") {
            mid = cp;
            while(strings[mid]=="" && mid>=ll) mid--;
        }

        if(strings[mid] == target) {
            return mid;
        } else if(strings[mid] < target) {
            ll = mid+1;
        } else {
            rr = mid-1;
        }
    }
    return -1;
}

// 通过让right指向非空字符串，那么mid从左往右查找时一定可以找到非空字符串，可以避免mid左右往复搜索非空字符串。

int int search_in_sorted_array_interspersed_empty_strings(vector<string> strings, string target) {
    if(strings.size()==0 || target.empty()) return -1;
    if(target=="") {
        for(int i=0; i<strings.size(); i++) {
            if(strings[i]=="") return i;
        }
        return -1;
    }

    int ll = 0;
    int rr = strings.size();
    while(ll <= rr) {
        // make sure that right pointed to the non-empty string
        while(ll <= rr && strings[rr]=="") rr--;
        if(rr < ll) return -1; // the strings are all empty
        int mid = (ll+rr)>>1;
        while(strings[mid] == "") ++mid; // must can find some non-empty string
        if(strings[mid]==target) return mid;
        else if(strings[mid]>target) return rr = mid-1;
        else ll = mid+1;
    }
    return -1;
}
