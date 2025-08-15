//7^2 or 2^8
//

#include<stdio.h>
#include<math.h>

int main() {
	float a = pow(2,8) ;
	float b = pow(8,2); 

	if (a>b) {
		printf("2^8 is larger than 8^2");
}
else {
	printf("8^2 is larer than 2^8");
}

return 0 ;
}
