#include <stdio.h>
#include <stdlib.h>

void main() //메인 함수의 시작
{
    int list[5];    //int타입(정수형) 데이터를 5개 담을 수 있는 배열 생성(선언), 초기화를 안 했기 때문에 쓰레기값이 저장됨
    int *plist[5] = {NULL,};    //int타입(정수형)을 가리키는 주소 5개를 담을 수 있는 배열 생성(선언), NULL로 초기화

    plist[0] = (int *)malloc(sizeof(int));  //plist 첫번째에 malloc을 통해 heap 영역의 4바이트짜리(int형) 동적 메모리 하나를 할당받음

    list[0] = 1;    //list[0]에 1이라는 값을 저장
    list[1] = 100;  //list[1]에 100이라는 값을 저장

    *plist[0] = 200;    //plist[0]이 가리키는 메모리(동적으로 할당받은 메모리)에 200이라는 값을 저장

    //list라는 배열과 plist라는 배열의 주소 및 값을 출력
    printf("list[0] = %d\n", list[0]);    //list[0](배열에서 0만큼 떨어져있는 곳)의 값을 출력 (11열에서 1을 저장했으므로 1이 출력됨)
    printf("&list[0] = %p\n", &list[0]); //list[0](배열에서 0만큼 떨어져있는 곳)의 주소 출력(000000000061FE00)
    printf("list = %p\n", list); //list라는 배열의 값을 출력(배열의 값은 주소와 같으므로 000000000061FE00)
    printf("&list = %p\n", &list);    //list의 주소 출력(000000000061FE00) / &list[0]은 &list와 같음

    printf("----------------------------------------\n\n"); //---------------------------------------- 출력 후 한 줄 띄움
    printf("list[1] = %d\n", list[1]);  //list[1]의 값 출력(배열에서 int 1만큼=4bytes만큼 떨어져있는 곳의 값 출력, 12열에서 100을 저장했으므로 100이 출력됨)
    printf("&list[1] = %p\n", &list[1]); //list[1]의 주소 출력(&list에서 4bytes만큼 떨어져있는 곳의 주소 출력, 000000000061FE04)
    printf("*(list+1) = %d\n", *(list + 1));  // 역참조 연산자로 list[1]의 값을 출력함
    printf("list+1 = %p\n", list+1);   //list+1의 주소 출력(list[0]에서 int 1만큼=4bytes만큼 떨어져있는 곳의 주소 출력, 000000000061FE04)

    printf("----------------------------------------\n\n"); //---------------------------------------- 출력 후 한 줄 띄움

    printf("*plist[0] = %d\n", *plist[0]);    //plist[0]이 가리키는(포인터)곳의 값 출력, 14열에서 200을 저장했으므로 200이 출력됨
    printf("&plist[0] = %p\n", &plist[0]);    //plst[0]의 주소 출력(000000000061FDD0)
    printf("&plist = %p\n", &plist);    //plist 배열의 주소 출력 = plist[0]의 주소 출력(000000000061FDD0)
    printf("&plist = %p\n", plist);    //plist(배열의 시작 주소) 출력 
    printf("plist[0]  = %p\n", plist[0]); //plist[0](동적으로 할당받은 heap영역)의 주소 출력=00000000006D1430
    printf("plist[1]            = %p\n", plist[1]); //plist[0]을 뺀 나머지는 NULL로 초기화 했으므로=0000000000000000
    printf("plist[2]            = %p\n", plist[2]); 
    printf("plist[3]            = %p\n", plist[3]); 
    printf("plist[4]            = %p\n", plist[4]); 

    free(plist[0]); //동적으로 할당받았던 메모리를 free하여 해제함

    printf("[---------[leeyesol]  [2023070002]---------]"); //이름과 학번 출력

}   //메인 함수의 종료