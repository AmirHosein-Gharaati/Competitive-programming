#include <bits/stdc++.h>

using namespace std;

int main(){
    char c;
    list<char> str;
    auto position = str.begin();

    while ((c=getchar())!= EOF){
        if (c == '['){
            position = str.begin();
        }
        else if (c == ']'){
            position = str.end();
        }
        else if (c == '\n'){
            for(auto a = str.begin(); a!= str.end();a++){
                printf("%c",*a);
            }
            printf("\n");
            str.clear();
            position = str.begin();
        }
        else{
            str.insert(position,c);
        }
    }
    for(auto a = str.begin(); a!= str.end();a++){
        printf("%c",*a);
    }
    
    return 0;
}