#include <stdio.h>
#include <stdint.h>

#define MAX_ASCI 122
#define MAX(x,y) (x)>(y)?(x):(y)

uint8_t size(uint8_t *table)
{
    uint8_t i = 32;
    uint8_t size = 0;
    while (MAX_ASCI-1 >= i){
        if (0 < table[i]) size++;
        i++;
    }

    return size;
}

// int lengthOfLongestSubstring(char * s)
// {
//     uint8_t ASCI[MAX_ASCI] = {0};
//     int i = 0, j = 0, maxCnt = 0;
//     while(s[j] != '\0'){     
//         ASCI[(uint8_t)s[j]]++;   
//         // Calculation's happen's here
//         // -----------------------------------------------
//         if(size(ASCI) == j - i + 1){
//             maxCnt = MAX(maxCnt, j - i + 1);
//             j++;
//         }
//         // ----------------------------------------------
//         else if(size(ASCI) < j - i + 1){
//             while(size(ASCI) < j - i + 1){
//                 // remove calculation for i
//                 ASCI[(uint8_t)s[i]]--;
//                 i++;
//             }
//             j++;
//         }
//     }
//     return maxCnt;
// }

int lengthOfLongestSubstring(char * s)
{
    int res = 0;
    char *end = s + strlen(s);
    int chars[128] = { 0 };
    char *substart = s;
    char *subend = s;
    
    while (subend < end)
    {
        chars[*subend]++;
        
        if (chars[*subend] == 1)
        {
            if (res < subend - substart + 1) res = subend - substart + 1;
        }
        else
        {
            while (chars[*subend] > 1)
            {
                chars[*substart]--;
                substart++;
            }
        }
        subend++;
    }
    
    return res;
}


int main (void)
{
    #define TEST_COUNTER 5
    char *testParameters[TEST_COUNTER] = {
        "pwwkew",
        "abcabcbb",
        "bbbbbb",
        " ",
        "dvdf"
    };

    for (int i = 0; i < TEST_COUNTER; i++)
    {
        printf("Input: \"%s\" \t\tOutput: %d\n", testParameters[i], lengthOfLongestSubstring(testParameters[i]));
    }
    

    return 0;
}