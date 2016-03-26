// If car starts at A and can not reach B.
// Any station between A and B can not reach B.(B is the first station that A can not reach.)
// If the total number of gas is bigger than the total number of cost. There must be a solution.
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<gas.size();i++) {
            if((tank=tank+gas[i]-cost[i])<0) {
                // i是start第一个无法到达的站点，即
                // start无法到达到i但可以到达start与i之间的所有站
                // 而中间站也无法到达i
                start=i+1;
                total+=tank;
                tank=0;
            }
        }
        return (total+tank<0)? -1:start;
    }
};
