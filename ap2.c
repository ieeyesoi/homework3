#include <stdio.h> 
#include <stdlib.h>

void main() 
{   // 메인 함수의 시작
    int list[5];    //int타입(정수형) 데이터를 5개 담을 수 있는 배열 생성(선언), 초기화하지 않았기 때문에 쓰레기값이 저장됨
    int *plist[5];  //int타입(정수형)을 가리키는 주소 5개를 담을 수 있는 포인터 배열 생성(선언)
    list[0] = 10;   //list[0]에 10이라는 값을 저장
    list[1] = 11;   //list[1]에 11이라는 값을 저장

    plist[0] = (int*)malloc(sizeof(int));   //plist 첫번째에 malloc을 통해 heap 영역의 4바이트짜리(int형) 동적 메모리 하나를 할당받음

    printf("list[0] \t= %d\n", list[0]); //list[0]의 값을 출력 (8열에서 10을 저장했으므로 10이 출력됨)
    printf("list \t\t= %p\n", list);    //list라는 배열의 시작 주소를 출력(000000000061FE00 출력)
    printf("&list[0] \t= %p\n", &list[0]);  //list[0]의 주소 출력(000000000061FE00) = list 출력
    printf("list + 0 \t= %p\n", list+0);    //list의 시작 주소에서 0 int만큼 떨어진 곳의 주소 출력(=list[0]의 주소, 000000000061FE00)
    printf("list + 1 \t= %p\n", list+1);    //list에서 int만큼 떨어져있는 곳의 주소 출력(4bytes만큼 떨어져있는 곳의 주소, 000000000061FE04)
    printf("list + 2 \t= %p\n", list+2);    //list에서 int*2만큼 떨어져있는 곳의 주소 출력(4*2=8bytes만큼 떨어져있는 곳의 주소, 000000000061FE08)
    printf("list + 3 \t= %p\n", list+3);    //list에서 int*3만큼 떨어져있는 곳의 주소 출력(4*3=12bytes만큼 떨어져있는 곳의 주소, 16진수 이므로 000000000061FE0C)
    printf("list + 4 \t= %p\n", list+4);    //list에서 int*4만큼 떨어져있는 곳의 주소 출력(4*4=16bytes만큼 떨어져있는 곳의 주소, 16진수이므로 000000000061FE10)
    printf("&list[4] \t= %p\n", &list[4]);  //list[4]의 주소 출력(list에서 int*4만큼 떨어져있으므로 20열과 같은 값이 출력됨, 000000000061FE10)

    free(plist[0]); //동적으로 할당받았던 메모리를 free하여 해제함

    printf("[---------[leeyesol]  [2023070002]---------]"); //학번과 이름 출력

}   //메인 함수의 종료