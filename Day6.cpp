/*
    C++14. No external libraries used.
    Time Complexity: O(n*m), where n is the number of passengers and m is the maximum number of questions a passenger has answered to
    Space Complexity: O(ALPHA), where ALPHA = 26, the length of the alphabet
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::ifstream fin("pc.in");

    char s[30];
    int solution1 = 0;
    int solution2 = 0;
    int group_solution = 0;
    int aux = 0;
    int passengers = 0;
    int exists[30] = {0};

    while(fin.getline(s, 27)) {
        if(!strcmp(s, "")) { /// A new group appearing
            passengers = 0;
            aux = 0;
            std::fill(exists, exists+29, 0); /// Reinitializing frequency array
        } else {
            passengers++;
        }

        for(int i=0; i<strlen(s); i++) {
            if(exists[s[i]-'a'] == 0) {
                solution1++; /// First appearance of the character
            }
            exists[s[i]-'a']++;
        }
        group_solution = 26; /// Supposing all the passengers have the same questions in common
        for(int i=0; i<26; i++) {
            if(exists[i] != passengers) {
                group_solution--; /// Constantly updating
            }
        }
        solution2 += group_solution-aux; /// Subtract the previous group_solution and add the new one
        aux = group_solution;
    }

    std::cout << "1st Part Solution: " << solution1 << '\n';
    std::cout << "2nd Part Solution: " << solution2 << '\n';
    return 0;
}
