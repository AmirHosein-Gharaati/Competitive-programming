#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main(){

    string input;
    int count=0;

    while (getline(cin,input)){
        for (int i = 0; i < input.size(); i++){
            if(input.at(i) == '"'){
                if(count % 2 == 0){
                    input.at(i) = '`';
                    input.insert((input.begin() + i), '`');
                    count++;
                }

                else{
                    input.at(i) = '\'';
                    input.insert((input.begin()+i),'\'');
                    count++ ;
                }
                
            }
        }
        cout << input << '\n';
        
    }
    

   

    return 0;
}