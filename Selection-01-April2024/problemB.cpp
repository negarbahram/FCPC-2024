#include<stdio.h>
#include <math.h>



int main(){
	
	int n;
	
	scanf("%d" , &n );
	
	int number , remain = 0;
	int sum = 0;
	int i; 
	for( i = 0 ; i < n ; i++ ){
		scanf("%d" , &number );
		remain = number % 10;
		number /= 10;
		sum += pow (number , remain);
	}
	printf("%d",sum);
	
	
}

