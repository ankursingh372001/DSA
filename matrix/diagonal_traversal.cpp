#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int &b) {

    int temp = a;
    a = b;
    b = a;
}

vector<int> findDiagonalOrder(vector<int> matrix[], int m, int n) {

    vector<int> ans;

    int r = 0;
    int c = 0;
    int dr = -1;
    int dc = +1;

    while(r < m && c < n) {

        ans.push_back(matrix[r][c]);

        int R = r + dr;
        int C = c + dc;

        if(R < 0 || R == m || C < 0 || C == n) {

            if(dr == -1 && dc == 1) {

                R = r;
                C = c + 1;

                if(C < 0 || C == n) {

                    R = r + 1;
                    C = c;
                }
            }
            else {

                R = r + 1;
                C = c;

                if(R < 0 || R == m) {

                    R = r;
                    C = c + 1;
                }
            }

            swap(dr, dc);
        }

        r = R;
        c = C;
    }

    return ans;
}

// https://leetcode.com/problems/diagonal-traverse/description/