/*
If a=1, b=2, c=3,....z=26. Given a string, find all possible codes that string can generate.
Give a count as well as print the strings.

For example:

Input: "1123". You need to general all valid alphabet codes from this string.
Output List
aabc   //a = 1, a = 1, b = 2, c = 3
kbc    // since k is 11, b = 2, c= 3
alc    // a = 1, l = 12, c = 3
aaw    // a= 1, a =1, w= 23
kw     // k = 11, w = 23
*/

#include <bits/stdc++.h>

using namespace std;

void make_combinations(char* input, char* output, int start = 0, int depth = 0)
{
    if (start >= strlen(input)) {
        printf("%s\n", output);
        return;
    }

    // add one at a time
    if (input[start + 1] != '0') {
        output[depth] = (input[start] - '0' - 1 + 97);
        make_combinations(input, output, start + 1, depth + 1);
    }
    
    // add two at a time
    if (input[start + 1]) {
        // printf("inside if\n");
        int result = (input[start] - '0') * 10 + (input[start + 1] - '0') - 1;
        
        if (result <= 25)
            output[depth] = (result + 97);
        
        output[depth + 1] = '\0';
        make_combinations(input, output, start + 2, depth + 1);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // char input[] = "1123";
    char input[] = "1013";
    char output[50] = {'\0'};

    make_combinations(input, output);

    return 0;
}
