#include <stdio.h>

#define MAX_SIZE 100    //상수를 선언함

float sum1(float list[], int);  // float형(실수형) 함수 sum1을 선언(stack 영역에 변수를 선언함)
float sum2(float *list, int);   // float형(실수형) 함수 sum2을 선언(stack 영역에 변수를 선언함)
float sum3(int n, float *list); // float형(실수형) 함수 sum3을 선언(stack 영역에 변수를 선언함)

float input[MAX_SIZE], answer;  //stack 영역에 전역 변수를 생성
int i;  //for문에서 사용할 정수형 변수 i를 선언함
void main(void)
{   //메인 함수의 시작
    for(i=0; i < MAX_SIZE; i++) 
    input[i] = i;   //호출 시 주소가 sum 함수 list에 복사됨(input(=&input[0])은 주소 나타냄)

    /* for checking call by reference */ 
    printf("--------------------------------------\n"); //------------------------------------을 출력한 후 한 줄 띄움 
    printf(" sum1(input, MAX_SIZE) \n");    //sum1(input, MAX_SIZE)를 출력한 후 한 줄 띄움
    printf("--------------------------------------\n"); //------------------------------------을 출력한 후 한 줄 띄움
    printf("input \t= %p\n", input);    //input의 시작 주소를 출력

    answer = sum1(input, MAX_SIZE); //sum1(list[], int)에서 매개 변수는 배열, 따라서 input은 주소값을 나타냄
    printf("The sum is: %f\n\n", answer);   //sum1의 결과값을 출력

    printf("--------------------------------------\n"); //------------------------------------을 출력한 후 한 줄 띄움
    printf(" sum2(input, MAX_SIZE) \n");    //sum2(input, MAX_SIZE)를 출력한 후 한 줄 띄움
    printf("--------------------------------------\n"); //------------------------------------을 출력한 후 한 줄 띄움
    printf("input \t= %p\n", input);    //input의 시작 주소를 출력함

    answer = sum2(input, MAX_SIZE); //함수 sum2를 호출함
    printf("The sum is: %f\n\n", answer);   // sum2의 결과값을 출력함

    printf("--------------------------------------\n"); //------------------------------------을 출력한 후 한 줄 띄움
    printf(" sum3(MAX_SIZE, input) \n");    //sum3(MAX_SIZE, input)를 출력한 후 한 줄 띄움
    printf("--------------------------------------\n"); //------------------------------------을 출력한 후 한 줄 띄움 
    printf("input \t= %p\n", input);    //input의 시작 주소를 출력함

    answer = sum3(MAX_SIZE, input); //함수 sum3을 호출함
    printf("The sum is: %f\n\n", answer);   //sum3의 결과값을 출력함
}

float sum1(float list[], int n)     
{
    printf("list \t= %p\n", list);  // sum1 함수는 배열을 받아 합을 계산함, list[]은 배열의 시작주소(input의 시작 주소)
    printf("&list \t= %p\n\n", &list);  //함수 sum1으로 전달한 포인터 변수의 주소 출력(not list 배열의 시작 주소)

    int i;  //for문에서 사용할 정수형 변수 i 선언
    float tempsum = 0;  
    for(i = 0; i < n; i++)  
        tempsum += list[i]; // 배열 순환하며 합 계산
    return tempsum; 
}
float sum2(float *list, int n)  //함수 sum2는 포인터를 통해 합을 계산함
{
    printf("list \t= %p\n", list);  //포인터가 가리키는 곳의 주소를 출력함
    printf("&list \t= %p\n\n", &list);  //함수에 전달된 포인터 변수의 주소를 출력함

    int i;  //for문에서 사용할 정수형 변수 i를 선언
    float tempsum = 0;  
    for(i = 0; i < n; i++)  
        tempsum += *(list + i); // 포인터를 통해 배열 순환하며 합을 계산함
    return tempsum; 
}   

/* stack variable reuse test */
float sum3(int n, float *list)  //함수 sum3은 배열 크기, 포인터를 통해 합을 계산함
{
    printf("list \t= %p\n", list); 
    printf("&list \t= %p\n\n", &list);  //함수 sum3으로 전달된 포인터 변수 주소 출력(not list배열의 시작 주소)

    int i;  //for문에서 사용할 정수형 변수 i를 선언
    float tempsum = 0;  
    for(i = 0; i < n; i++)  
        tempsum += *(list + i);     //포인터를 통해 배열 순환하며 합을 걔산함
    return tempsum; 

printf("[---------[leeyesol]  [2023070002]---------]"); //이름과 학번을 출력

}   //메인 함수의 종료