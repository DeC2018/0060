#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* getPermutation(int n, int k) {
    char* ans = malloc(sizeof(char)*(n+1));
    
    int possible = 1;
    for (int i = 2 ; i < n ; i++){
        possible *= i;
    }
    
    int m = n-1;
    bool* used = calloc(n+1, sizeof(bool));
    int point = 0;
    while(m > 0){
        int order = 1;
        while (possible * order < k){
            order++;
        }
        
        int input = 1;
        int count = 0;
        
        while (1){
            if (used[input] == false){  
                count++;
                if (count == order){    
                    used[input] = true;
                    ans[point] = input + '0';
                    point++;
                    k -= possible*(order-1);
                    possible /= m;
                    m--;
                    break;
                }
            }
            input++;
        }
    }
    for (int i = 1 ; i <= n ; i++){
        if (used[i] == false){
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
    // Test cases
    printf("Input: n = 3, k = 3\n");
    printf("Output: \"%s\"\n", getPermutation(3, 3));

    printf("Input: n = 4, k = 9\n");
    printf("Output: \"%s\"\n", getPermutation(4, 9));

    printf("Input: n = 3, k = 1\n");
    printf("Output: \"%s\"\n", getPermutation(3, 1));

    return 0;
}
