#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* getPermutation(int n, int k) {
    char* ans = (char*)malloc(sizeof(char) * (n + 1));
    
    int possible = 1;
    for (int i = 2; i < n; i++) {
        possible *= i;
    }
    
    int m = n - 1;
    bool* used = (bool*)calloc(n + 1, sizeof(bool));
    int point = 0;
    while (m > 0) {
        int order = 1;
        while (possible * order < k) {
            order++;
        }
        
        int input = 1;
        int count = 0;
        
        while (1) {
            if (used[input] == false) {  
                count++;
                if (count == order) {    
                    used[input] = true;
                    ans[point] = input + '0';
                    point++;
                    k -= possible * (order - 1);
                    possible /= m;
                    m--;
                    break;
                }
            }
            input++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (used[i] == false) {
            ans[point] = i + '0';
            point++;
            break;
        }
    }
    free(used);
    ans[point] = '\0';
    return ans;
}

int main() {
    int n1 = 3, k1 = 3;
    printf("Input: n = %d, k = %d\n", n1, k1);
    char* result1 = getPermutation(n1, k1);
    printf("Output: \"%s\"\n", result1);
    free(result1);

    int n2 = 4, k2 = 9;
    printf("Input: n = %d, k = %d\n", n2, k2);
    char* result2 = getPermutation(n2, k2);
    printf("Output: \"%s\"\n", result2);
    free(result2);

    int n3 = 3, k3 = 1;
    printf("Input: n = %d, k = %d\n", n3, k3);
    char* result3 = getPermutation(n3, k3);
    printf("Output: \"%s\"\n", result3);
    free(result3);

    return 0;
}
