#include <stdio.h>


int main(){
	int n,adad=1;
	scanf("%d",&n);
	int i ;
	for (i=1;i<=n;i++){
		adad *= i;
	}
	printf("%d",adad);
	return 0;
	
}
