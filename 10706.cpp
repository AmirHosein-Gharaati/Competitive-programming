#include <bits/stdc++.h>

using namespace std;

#define MAX 35000

int number;
vector<long long> lens(1,0);
int binarySearch(int start, int end ){

    int mid = (start+end)/2;


    if(lens.at(mid) == number){
        return mid-1;
    }

    if(start >= end){
        while(lens.at(start) >= number) start--;
        return start;
    }

    if(lens.at(mid) > number)
        return binarySearch(start, mid-1);

    if(lens.at(mid) < number)
        return binarySearch(mid+1, end);

    return -1;
}


void generate_lens(){
    int total_len=0;
    
    for(int i=1;i<MAX;i++){
        int len = (int)log10(i)+1;
        total_len += len;
        
        lens.push_back(total_len+lens.back());
    }
}

int main(){
    generate_lens();

    int tt, result;
    int len;
    int temp;
    scanf("%d", &tt);
    for(int i = 0 ; i < tt ; i++){
        scanf("%d", &temp);
        number = temp;
        result = binarySearch(1, lens.size()-1);
        
        len = temp - lens.at(result);
        
        int n = 1;
        stringstream ss;
        string str = "";
        while(ss.str().length() < len){
            ss << n;
            n = n + 1;
        }

        str = ss.str();
        cout << str[len-1] << endl;
    }



    return 0;
}