#include <bits/stdc++.h>

using namespace std;


int main(){
    map<string,int> names_and_moneys;
    vector<string> names;
    string line, temp,name,temp_name;
    int n,amount_of_spent_money,number_of_people;
    bool firstLine = true;

    while (cin >> n){

        cin.ignore();
        getline(cin,line);
        stringstream l(line);
        while (l >> temp){
            names.push_back(temp);
        }

        for (auto a: names){
            names_and_moneys[a] = 0;
        }
        
        
        int i,j;
        for(i=0 ; i < n ;i++){
            cin >> name >> amount_of_spent_money >> number_of_people;
            if(number_of_people > 0){
                for (j = 0; j < number_of_people; j++){
                    cin >> temp_name;
                    names_and_moneys[temp_name] += amount_of_spent_money / number_of_people;
                }
                names_and_moneys[name] -= (amount_of_spent_money / number_of_people) * number_of_people;
            }


            
        }
        
        if (!firstLine) cout << endl; firstLine = false;
        for (auto b: names){
            cout << b << " " << names_and_moneys[b] << endl;
        }

        names.clear();
        names_and_moneys.clear();
        
    }
    return 0;
}
