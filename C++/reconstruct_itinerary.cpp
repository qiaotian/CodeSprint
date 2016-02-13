class Solution {
private:
    map<string, multiset<string>> targets; 
    vector<string> res;
    void visit(string airport) {
        while(targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        res.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(auto ticket : tickets) targets[ticket.first].insert(ticket.second);
        visit("JFK");
        //reverse(res.begin(), res.end());
        return vector<string>(res.rbegin(), res.rend());
    }
};

/**
 * WARN
 * 1. there might not be a circle in route or itinerary,
 *    which means the final destination might not be the initial departure.
 * 2. the circle and the curve might exists at the same itinerary, where the end of curve must the final arrival.
 * 
 * 3. Multiset is an associative container that contains a **sorted** set of objects of type Key. Unlike set, multiple keys with equivalent values are allowed. Sorting is done using the key comparison function Compare. Search, insertion, and removal operations have logarithmic complexity.
 * 
 * REFERENCE
 * https://leetcode.com/discuss/84659/short-ruby-python-java-c
 * */
