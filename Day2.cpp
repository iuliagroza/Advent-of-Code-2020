/*
    C++14. No external libraries used.
    Time Complexity: O(n*m), where n is the number of passwords and m is the biggest length of a password
    Space Complexity: O(m)
*/
#include <iostream>
#include <fstream>
#include <cstring>

int sol;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::ifstream fin("input.txt"); /// Default input file name

    char range[15];
    char chars[5];
    char password[105];
    int solution1 = 0;
    int solution2 = 0;

    while(fin >> range >> chars >> password) {

        char letter = chars[0]; /// The letter we are looking for in the password

        /// Converting from char to int the two numerical values
        int Min=0; /// First value of the range
        int i=0;

        while(range[i]!='-') {
            Min = Min*10+int(range[i]-'0');
            i++;
        }

        int Max=0; /// Second value of the range
        i++;
        while(i<strlen(range)) {
            Max = Max*10+int(range[i]-'0');
            i++;
        }

        /// 1st Part
        int frequency=0;
        for(int i=0; i<strlen(password); i++) {
            if(password[i]==letter) {
                frequency++;
            }
        }
        if(frequency >= Min && frequency <= Max) {
            solution1++;
        }

        /// 2nd Part
        if((password[Min-1]==letter && password[Max-1]!=letter) || (password[Min-1]!=letter && password[Max-1]==letter)) {
            solution2++;
        }
    }
    std::cout << "1st Part Solution: " << solution1 << '\n';
    std::cout << "2nd Part Solution: " << solution2 << '\n';
    return 0;
}
