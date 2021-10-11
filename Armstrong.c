//Armstrong number is a number that is equal to the sum of cubes of its digits. 
//For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
#include<stdio.h>
int main(){
	int n,r,sum=0,temp;
	printf("Enter the number : ");
	//taking number from user
	scanf("%d",&n);
	temp = n;
	while(n>0){
		//last digit of number
		r = n%10;
		//adding the cube of the last digit of number
		sum = sum + (r*r*r);
		//removing last digit from number
		n = n/10;
	}
	if(temp==sum){
		printf("armstrong number");
	}else{
		printf("not armstrong number");
	}
}
