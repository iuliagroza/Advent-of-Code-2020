/*
    C++14. No external libraries used.
    Time Complexity: O(n*m) for processing the input, O(n) for calculating the result
    Space Complexity: O(n*m)
*/
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::ifstream fin("pc.in");

    std::string s;
    int check_count1 = 0;
    int check_count2 = 0;
    int solution1 = 0;
    int solution2 = 0;

    while(getline(fin, s)) {
        if(s == "") {
            check_count1 = 0;
            check_count2 = 0;
        }

        if(std::regex_search(s, std::regex("byr:"))) {
            check_count1++;
        }
        if(std::regex_search(s, std::regex("iyr:"))) {
            check_count1++;
        }
        if(std::regex_search(s, std::regex("eyr:"))) {
            check_count1++;
        }
        if(std::regex_search(s, std::regex("hgt:"))) {
            check_count1++;
        }
        if(std::regex_search(s, std::regex("hcl:"))) {
            check_count1++;
        }
        if(std::regex_search(s, std::regex("ecl:"))) {
            check_count1++;
        }
        if(std::regex_search(s, std::regex("pid:"))) {
            check_count1++;
        }
        if(check_count1 == 7) {
            solution1++;
            check_count1 = 0;
        }

        if(std::regex_search(s, std::regex("byr:(19[2-9][0-9]|200[0-2])"))) {
            check_count2++;
        }
        if(std::regex_search(s, std::regex("iyr:(201[0-9]|2020)"))) {
            check_count2++;
        }
        if(std::regex_search(s, std::regex("eyr:(202[0-9]|2030)"))) {
            check_count2++;
        }
        if(std::regex_search(s, std::regex("hgt:((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in)"))) {
            check_count2++;
        }
        if(std::regex_search(s, std::regex("hcl:#[0-9a-f]{6}"))) {
            check_count2++;
        }
        if(std::regex_search(s, std::regex("ecl:(amb|blu|brn|gry|grn|hzl|oth)"))) {
            check_count2++;
        }
        if(std::regex_search(s, std::regex("pid:[0-9]{9}"))) { /// +word boundaries
            check_count2++;
        }

        if(check_count2 == 7) {
            solution2++;
            check_count2 = 0;
        }
    }
    solution2--;

    std::cout << "1st Part Solution: " << solution1 << '\n';
    std::cout << "2nd Part Solution: " << solution2 << '\n';
    return 0;
}
