/*
    C++14. No external libraries used.
    Time Complexity: O(10*n)~O(n), where n is the number of occupied seats
    Space Complexity: O(Max), where Max is the highest seat ID
*/
#include <iostream>
#include <fstream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::ifstream fin("input.txt");

    int solution1 = 0;
    char s[12];
    bool exists[861];
    std::fill(exists, exists+860, false);

    while(fin.getline(s, 11)) {
        int left = 0;
        int right = 127;
        for(int i=0; i<7; i++) {
            if(s[i]=='F') {
                right = (left+right)/2;
            }
            else {
                left = (left+right)/2+1;
            }
        }
        int row = left;

        left = 0;
        right = 7;
        for(int i=7; i<10; i++) {
            if(s[i]=='L') {
                right = (left+right)/2;
            }
            else {
                left = (left+right)/2+1;
            }
        }
        int column = left;
        int seat_ID = row*8+column;
        solution1 = std::max(solution1, seat_ID);
        exists[seat_ID] = true;
    }

    int solution2 = 0;
    for(int i=1; i<solution1; i++) {
        if(exists[i-1] && !exists[i] && exists[i+1]) { /// Using hashing for a better time complexity
            solution2 = i;
            break;
        }
    }
    std::cout << "1st Part Solution: " << solution1 << '\n';
    std::cout << "2nd Part Solution: " << solution2 << '\n';
    return 0;
}
