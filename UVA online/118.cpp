#include <bits/stdc++.h>

using namespace std;

int main() {

    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int r, c;
    char pos;
    char steps[1000];
    char pre[100][100] = {};

    while(scanf("%d %d %c", &r, &c, &pos) == 3) {

        scanf("%s", steps);
        int flag = 0;

        for(int i = 0 ; steps[i]; i++) {
            if(steps[i] == 'F') {
                switch(pos) {
                    case 'N':c++;break;
                    case 'E':r++;break;
                    case 'W':r--;break;
                    case 'S':c--;break;
                }
            }
            else if (steps[i] == 'R') {
                switch (pos) {
                    case 'N':pos = 'E';break;
                    case 'E':pos = 'S';break;
                    case 'W':pos = 'N';break;
                    case 'S':pos = 'W';break;
                }
            }
            else{
                switch(pos) {
                    case 'N':pos = 'W';break;
                    case 'E':pos = 'N';break;
                    case 'W':pos = 'S';break;
                    case 'S':pos = 'E';break;
                }
            }

            if(r < 0 || c < 0 || r > rows || c > cols) {
                switch(pos) {
                    case 'N':c--;break;
                    case 'E':r--;break;
                    case 'W':r++;break;
                    case 'S':c++;break;
                }
                if(pre[r][c] == 1)
                    continue;
                flag = 1;
                pre[r][c] = 1;
                break;
            }
        }

        if(!flag)
            printf("%d %d %c\n", r, c, pos);
        else {
            printf("%d %d %c LOST\n", r, c, pos);
        }
    }


    return 0;
}
