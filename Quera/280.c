#include <stdio.h>


int main(){
	int n1,n2,n3;
	scanf("%d",&n1);
	scanf("%d",&n2);
	scanf("%d",&n3);
	
	n1 *= n1;
	n2 *= n2;
	n3 *= n3;
	if (n1 + n2 == n3 || n1 + n3 == n2 || n2 + n3 == n1){
		printf("YES");
	}
	else{
	printf("NO");
	}
	return 0;
	
}
