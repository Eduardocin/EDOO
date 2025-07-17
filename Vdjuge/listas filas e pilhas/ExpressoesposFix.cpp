#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

enum class Color {
    RED,
    YELLOW,
    GREEN
};

bool isValidColor(int color1, int color2) {
    return color1 != color2;
}

bool isValidRow(int colors[3]) {
    return isValidColor(colors[0], colors[1]) && 
           isValidColor(colors[1], colors[2]);
}

bool canBeAdjacent(int row1[3], int row2[3]) {
    return isValidColor(row1[0], row2[0]) && 
           isValidColor(row1[1], row2[1]) && 
           isValidColor(row1[2], row2[2]);
}

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int count = 0;
    int colors[3];
    
    // Try all possible colorings for the first row
    for (int c1 = 0; c1 < 3; c1++) {
        for (int c2 = 0; c2 < 3; c2++) {
            for (int c3 = 0; c3 < 3; c3++) {
                colors[0] = c1;
                colors[1] = c2;
                colors[2] = c3;
                
                if (isValidRow(colors)) {
                    count++;
                }
            }
        }
    }
    
    if (n == 1) {
        cout << count << endl;
        return 0;
    }

    vector<vector<int>> validColorings;
    for (int c1 = 0; c1 < 3; c1++) {
        for (int c2 = 0; c2 < 3; c2++) {
            for (int c3 = 0; c3 < 3; c3++) {
                colors[0] = c1;
                colors[1] = c2;
                colors[2] = c3;
                
                if (isValidRow(colors)) {
                    validColorings.push_back({c1, c2, c3});
                }
            }
        }
    }
    
    vector<vector<long long>> dp(n, vector<long long>(validColorings.size(), 0));
    
    for (int i = 0; i < validColorings.size(); i++) {
        dp[0][i] = 1;
    }
    
    for (int row = 1; row < n; row++) {
        for (int prev = 0; prev < validColorings.size(); prev++) {
            for (int curr = 0; curr < validColorings.size(); curr++) {
                if (canBeAdjacent(validColorings[prev].data(), validColorings[curr].data())) {
                    dp[row][curr] = (dp[row][curr] + dp[row-1][prev]) % MOD;
                }
            }
        }
    }
    
    long long result = 0;
    for (int i = 0; i < validColorings.size(); i++) {
        result = (result + dp[n-1][i]) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}