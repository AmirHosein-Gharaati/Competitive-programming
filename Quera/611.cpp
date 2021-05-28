#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int a,m;
    char ch;
    cin >> a>> m;

    int **x;
    x=new int *[a];
    for(int i=0;i<a;i++)
        x[i]=new int [a];



    for(int i=0;i<a;i++)
        for(int j=0;j<a;j++)
            x[i][j]=0;

    int i=0;int j=((a-1)/2);

    for(int k=m;k<=m+a*a-1;k++){
        if(i>=a)
        i=i-a;

        if(j>=a)
            j=j-a;

        if(i<0)
            i=i+a;

        if(j<0)
            j=j+a;

        //////////////////////

        if(x[i][j]!=0){
            i=i+2;
            j++;

        }

        ///////////////////////

        if(i>=a)
            i=i-a;

        if(j>=a)
            j=j-a;

        if(i<0)
            i=i+a;

        if(j<0)
            j=j+a;

        ///////////////////////
        x[i][j]=k;
        i--;
        j--;

    }
 
    for(int i=0;i<a;i++){
        for(int j=a-1;j>=0;j--)
            cout<<x[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
 
}