#include <string>
#include <iostream>

using namespace std;

string lcs(string s1, string s2){
    int n = s1.length();
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = new int[n+1];
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    int index = dp[n][n];
    string res;
    res.resize(index+1);
    res[index] = '\0';
    
    int i = n, j = n;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            res[index-1] = s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    
    delete [] dp;
 
    return res;
}

int main(){
    string s1 = "ABAB";
    string s2 = "BABA";
    cout << lcs(s1, s2);
    return 0;
}
