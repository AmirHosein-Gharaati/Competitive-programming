#include <bits/stdc++.h>

using namespace std;

int main() {

    string name1, name2;
    string result = "";

    int index1 = 0, index2 = 0;

    cin >> name1 >> name2;

    while(index1 < name1.size() || index2 < name2.size()) {
        if(index1 < name1.size() && name1[index1] < name2[index2]) {
            result += name1[index1++];
        } else if(index2 < name2.size() && name2[index2] < name1[index1]) {
            result += name2[index2++];
        } else {
            if(index1 < name1.size())
                result += name1[index1++];
            else
                result += name2[index2++];
        }
    }

    cout << result;

    return 0;
}