#include <bits/stdc++.h>

using namespace std;

string s;

bool isPalindrome(int first, int last){

    while(first < last)
        if(s[first++] != s[last--])
            return false;
    return true;
}


bool isAlindrome(){

    int len = s.length();

    for(int i = 0 ; i < len-1; i++){
        bool temp1 = isPalindrome(0, i);
        bool temp2 = isPalindrome(i+1, len-1);

        if(temp1 && temp2)
            return true;
    }

    return false;

}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--){
        cin >> s;
        int len = s.length();

        if(isAlindrome())
            cout << "alindrome" << endl;
        else if(isPalindrome(0, len-1))
            cout << "palindrome" << endl;
        else
            cout << "simple" << endl;
    }


    return 0;
}