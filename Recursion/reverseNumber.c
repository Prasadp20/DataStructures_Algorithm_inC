#include<stdio.h>

int reverseNum(int num, int reverse)
{
	if(num == 0){
	
		return reverse;
	}

	//reverse = (reverse * 10) + (num % 10);
	return reverseNum(num/10, (reverse * 10) + (num % 10));
}

void main()
{
        int num;
        int retNum = 0;

        printf("Enter the number : ");
        scanf("%d", &num);

        if(num >= 0 && num <= 9){

                retNum = num;
        } else{

                retNum = reverseNum(num, retNum);
        }

        printf("Reverse number of %d is : %d\n", num, retNum);
}
