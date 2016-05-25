// 用4个数组分别记录A C G T上一次出现的index，这样可以将时间复杂度降为O(M+S)，缺点是空间复杂度O(4*S)

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector<int> ans(P.size(), 0);
    //unordered_map<char, int> dict;
    //dict.insert({A, 1});
    //dict.insert({C, 2});
    //dict.insert({G, 3});
    //dict.insert({T, 4});

    vector<int> A(S.size(), -1); // index of last A occurs
    vector<int> C(S.size(), -1); // index of last C occurs
    vector<int> G(S.size(), -1); // index of last G occurs
    vector<int> T(S.size(), -1); // index of last T occurs

    for(int i=0; i<S.size(); i++) {
        if(S[i]=='A') {
            A[i] = i;
            if(i==0) continue;
            C[i] = C[i-1];
            G[i] = G[i-1];
            T[i] = T[i-1];
        } else if(S[i]=='C') {
            C[i] = i;
            if(i==0) continue;
            A[i] = A[i-1];
            G[i] = G[i-1];
            T[i] = T[i-1];
        } else if(S[i]=='G') {
            G[i] = i;
            if(i==0) continue;
            A[i] = A[i-1];
            C[i] = C[i-1];
            T[i] = T[i-1];
        } else {
            T[i] = i;
            if(i==0) continue;
            A[i] = A[i-1];
            C[i] = C[i-1];
            G[i] = G[i-1];
        }
    }

    for(int i=0; i<P.size(); i++) {
        if(A[Q[i]]>=P[i]) {
            ans[i] = 1;
            continue;
        }
        if(C[Q[i]]>=P[i]) {
            ans[i] = 2;
            continue;
        }
        if(G[Q[i]]>=P[i]) {
            ans[i] = 3;
            continue;
        }
        if(T[Q[i]]>=P[i]) {
            ans[i] = 4;
            continue;
        }
    }
    return ans;
}
