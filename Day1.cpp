/*
    C++14. No external libraries used.
    Time Complexity: O(n^2), where n is the number of processed integers
    Space Complexity: O(n)
*/
#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::ifstream fin("pc.in");

    int x;
    int length = 0;
    int a[205];
    bool ok[2025];
    std::fill(ok, ok+2020, false);

    while(fin >> x) {
        ok[x] = true;
        if(ok[2020-x]) {
            std::cout << "1st Part Solution: " << 1LL*x*(2020-x) << '\n';
        }
        a[++length] = x;
    }

    bool found = false;
    for(int i=1; i<length && !found; i++) {
        for(int j=i+1; j<=length && !found; j++) {
            if(a[i]+a[j] <= 2020) {
                if(ok[2020-a[i]-a[j]]) {
                    std::cout << "2nd Part Solution: " << 1LL*a[i]*a[j]*(2020-a[i]-a[j]) << '\n';
                    found = true; /// Stopping the search in order to amortize the complexity
                }
            }
        }
    }

    return 0;
}
