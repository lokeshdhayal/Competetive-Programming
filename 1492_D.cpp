#include <iostream>
#include <cstdio>
using namespace std;

int a[30];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    if (a == 0 && k) {
        printf("No\n");
        return 0;
    }
    if (b == 1) {
        if (k) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
            printf("1");
            for (int i = 0; i < a; ++i) printf("0");
            printf("\n");
            printf("1");
            for (int i = 0; i < a; ++i) printf("0");
        }
    }
    else {
        if (k > a + b - 2) {
            printf("No");
        }
        else {
            printf("Yes\n");
            for (int i = 0; i < b; ++i) {
                printf("1");
            }
            for (int i = 0; i < a; ++i) {
                printf("0");
            }
            printf("\n");
            if (k <= a) {
                for (int i = 0; i < b - 1; ++i) {
                    printf("1");
                }
                for (int i = 0; i < k; ++i) {
                    printf("0");
                }
                printf("1");
                for (int i = 0; i < a - k; ++i) {
                    printf("0");
                }
            }
            else {
                int temp = k - a;
                printf("1");
                for (int i = 0; i < b - 2 - temp; ++i) {
                    printf("1");
                }
                if (a) printf("0");
                for (int i = 0; i < temp; ++i) {
                    printf("1");
                }
                for (int i = 0; i < a - 1; ++i) {
                    printf("0");
                }
                printf("1\n");
            }
        }
    }
}