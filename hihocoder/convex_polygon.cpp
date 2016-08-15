/*

Time Limit:10000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
给定一个凸多边形的N个顶点。你需要在凸多边形内找到M个点，使得这M个点也围成一个凸多边形，并且围成的面积尽可能大。

Input
第一行包含两个整数N和M，意义如前文所述。

接下来N行，每行两个整数Ai和Bi，表示按照逆时针顺序排列的凸多边形顶点坐标。

对于30%的数据，满足N<=5

对于100%的数据，满足N<=100

对于100%的数据，满足3<=M<N, |Ai|,|Bi|<=10000

Output
输出新凸多边形最大的面积，保留两位小数。

Sample Input
4 3
0 0
1 0
1 1
0 1
Sample Output
0.50

*/
