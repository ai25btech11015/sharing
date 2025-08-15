////<C-ScrollWheelDown>The number of illiterate persons in a country decreased from 150 lakhs to 100 lakhs
//in 10 years. What is the percentage of decrease?
//

#include<stdio.h>

int main() {
int initial_val = 150 ;
int final_val = 100 ;
float percentage = (initial_val - final_val)*100/initial_val;

printf("%f",percentage);
return 0;
}
