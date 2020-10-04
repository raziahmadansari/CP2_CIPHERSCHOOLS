// Questions:
/*
 * TCS - DIGITAL
 * Problem Name - Auction Number
 * 
 * Problem Description -
 * Codu is fond of vehicle numbers. Codu wants to compute the number of vehicles can be registered in his state. A vehicle normally has a
 * registration number like ST 01 AB 1234. Each registration number has four parts, separated by spaces. The first part has two letters
 * common for all cars in the state. The next two-digit number is the number of the district where the car is registered within the state.
 * It is always two digits, and may have a leading zero. After that, the next part consists of two letters (AB) denoting the series and the
 * last part is a 4 digit number (this will always be four digits, even if it has leading zeroes). The entire registration number is unique
 * to each vehicle. You have been given the number of districts in state and a range of letters and a set of digits that can be used for
 * forming a vehicle registration number. You need to find the maximum number of vehicles that can be registered in the state with non-special
 * numbers, subject to the rules.
 * 
 * The state has identified some numbers as special, and will not be issued normally, but will only be available by auction. In these plates,
 * the last part (consisting of four digits) has three or more repetitions of one digit such as 0001, 0000, 0100, 2212 ... so on. The output
 * should consist of the maximum number of vehicles that can be registered in the state with non-special numbers.
 * 
 * CONSTRAINTS -
 * 1 <= Number of districts < 100
 * A <= Range of alphabets <= Z
 * 0 <= Range of digits <= 9
 * 
 * INPUT -
 * The input has three lines
 * 
 * The first line contains an integer denoting the number of districts in the state.
 * 
 * The second line contains two space separated characters denoting the range of letters that can be used for the third part. For example,
 * if the input says B F, any of the letters B, C, D, E or F may be used in any combination for the third part.
 * 
 * The third line contains space separated integers denoting the range of digits that can be used in the fourth part. For example,
 * if the line contains 1 4, any of the digits 1, 2, 3 or 4 may be used in any order for the last part (repetitions are allowed, but no
 * special numbers may be counted)
 * 
 * OUTPUT -
 * Print the total number of vehicles that can be registered in the state with non-special numbers.
 * 
 * TIME LIMIT -
 * 1
 * 
 * EXPLANATION -
 * 
 * Example 1
 * Input
 * 1
 * A B
 * 0 1
 * 
 * Output
 * 24
 * 
 * Explanation
 * Here, only one district is present, Hence, number plate will start from ST 01 AA 0000, ST 01 AA 0001, etc. However, we need to exclude
 * auction-able numbers. After doing so, the overall count of non-special vehicle registration numbers remains 24. For example, 
 * ST 01 AA 0011, ST 01 AA 0110 ... so on.
 * 
 * 
 * Example 2
 * Input
 * 2
 * A C
 * 1 2
 * 
 * Output
 * 108
 * 
 * Explanation
 * Here, two districts are present. Number plate can start from ST 01 or ST 02. Hence, number plate will start from ST 01 AA 1111,
 * ST 01 AA 1112, etc. However, we need to exclude auction-able numbers. After doing so, the overall count of non-special vechicle
 * registration numbers remains 108. For example, ST 02 AC 2121, ST 02 BC 2112, ST 02 AA 1122 ... so on.
 * 
 */


// CODE
#include <bits/stdc++.h>

using namespace std;

void compute(string& str, vector<string>& combinations, int limit, string output="", int index = 0) {
    if (output.size() == limit) {
        combinations.push_back(output);
        return;
    }

    do {
        compute(str, combinations, limit, output + str[index]);
        index += 1;
    } while (index < str.size());

    return;
}

int eliminate(vector<string>& combinations) {
    int count_not_special = 0;

    for (auto str : combinations) {
        vector<int> count(256, 0);
        for (auto ch : str) {
            count[ch]++;
            
            if (count[ch] >= 3) {
                // cout << "special = " << str << endl;
                count_not_special++;
                break;
            }
        }
    }
    return count_not_special;
}

int main() {
    cout << "start...\n";

    // inputs
    int district;
    char a, b;
    int start, end;
    cin >> district;
    cin >> a >> b;
    cin >> start >> end;

    // series calculation
    string series = "";
    int s_start = a;
    int s_end = b;

    for (int i = s_start; i <= s_end; i++) {
        series += (char) i;
    }

    vector<string> series_combinations;
    compute(series, series_combinations, 2);
    
    int count_series = series_combinations.size();

    // number calculation
    string digits = "";
    for (int i = start; i <= end; i++) {
        digits += to_string(i);
    }

    vector<string> combinations;
    compute(digits, combinations, 4);

    // eliminate special numbers;
    int not_special = eliminate(combinations);

    int allowed_numbers = combinations.size() - not_special;
    
    cout << "Total numbers = " << (district * count_series * allowed_numbers) << endl;

    return 0;
}