# The size of types

## 실험
실제 같은 크기의 데이터가 들어가는typedef struct 구조체를 생성,  
선언 type(맴버) 순서에 따라 메모리 배치 및 구조체 크기가 어떻게 다른가? 를 확인.

## 구조체 정의
```c
// 실제 기록되는 데이터 확인을 위함.
#define A 0x11
#define B 0xABCDEF1234567890LL
#define C 0x55

#define shorts 0x1111
#define ints 0x22222222

typedef struct {
    unsigned long long b;
    char a;
    char c;
} case1;

typedef struct {
    char a;
    unsigned long long b;
    char c;
} case2;

typedef struct {
    char a;
    char c;
	unsigned long long b;
} case3;

typedef struct {
    char a;
    char c;
	short shorts;
	int ints;
	unsigned long long b;
} caseSpecial;
```

## 확인하기
```sh
ls -hl | grep Case1
xxd case1.bin

ls -hl | grep Case2
xxd case2.bin

ls -hl | grep Case3
xxd case3.bin

ls -hl | grep CaseSpecial
xxd CaseSpecial.bin
```

```text
-rw-r--r--@ 1 ******  staff    16B Sep 29 16:20 Case1.bin
00000000: 9078 5634 12ef cdab 1155 0000 0000 0000  .xV4.....U......

-rw-r--r--@ 1 ******  staff    24B Sep 29 16:20 Case2.bin
00000000: 1100 0000 0000 0000 9078 5634 12ef cdab  .........xV4....
00000010: 5500 0000 0000 0000                      U.......

-rw-r--r--@ 1 ******  staff    16B Sep 29 16:20 Case3.bin
00000000: 1155 0000 0000 0000 9078 5634 12ef cdab  .U.......xV4....

-rw-r--r--@ 1 ******  staff    16B Sep 29 16:32 CaseSpecial.bin
00000000: 1155 1111 2222 2222 9078 5634 12ef cdab  .U.."""".xV4....
```

## 결론
구조체 내부의 멤버 선언 순서에 따라 컴파일러가 생성하는 Padding의 위치와 크기가 결정된다.  
따라서, 크기가 각각 다른 맴버들을 적절히 배치하면 불필요한 메모리 낭비를 방지하고 구조체 크기를 최적화할 수 있다.