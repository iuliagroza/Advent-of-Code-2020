/*
    C++14. No external libraries used.
    Time Complexity: O(n*m) for processing the input, O(n) for calculating the result
    Space Complexity: O(n*m)
*/
#include <iostream>
#include <fstream>
#include <cstring>

int tree_count(int x, int y, int n, int m, bool a[350][35]) {
    int i = 1+x;
    int j = 1+y;
    int trees = 0;
    while(i <= n) {
        if(a[i][j]) {
            trees++;
        }
        i+=x;
        j = ((j+y)%m == 0) ? m : (j+y)%m;
    }
    return trees;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::ifstream fin("input.txt");

    char s[35];
    bool a[350][35];
    int m;
    int n = 0;

    while(fin >> s) {
        n++;
        m=strlen(s);
        for(int i=0; i<m; i++) { /// Creating a bool matrix based on the input
            if(s[i]=='.') {
                a[n][i+1]=false;
            } else {
                a[n][i+1]=true;
            }
        }
    }

    long long result = 0;
    int A = tree_count(1, 1, n, m, a);
    int B = tree_count(1, 3, n, m, a); /// 1st Part
    int C = tree_count(1, 5, n, m, a);
    int D = tree_count(1, 7, n, m, a);
    int E = tree_count(2, 1, n, m, a);
    result = 1LL*A*B*C*D*E; /// 2nd Part

    std::cout << "1st Part Solution: " << B << '\n';
    std::cout << "2nd Part Solution: " << result << '\n';
    return 0;
}
