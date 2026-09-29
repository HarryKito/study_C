#include <stdio.h>
#include <stddef.h>

#define A 0x11
#define B 0xABCDEF1234567890LL
#define C 0x55

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

int save_struct(const char *filename, const void *data, size_t size)
{
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        perror(filename);
        return 0;
    }

    size_t written = fwrite(data, 1, size, file);

    if (fclose(file) != 0 || written != size) {
        perror(filename);
        return 0;
    }

    return 1;
}

int main() {
	puts("Hello 2");

	printf("Case1:   %zu bytes\n", sizeof(case1));
	printf("Case2:   %zu bytes\n", sizeof(case2));
	printf("Case3:   %zu bytes\n", sizeof(case3));
	printf("CaseSpecial:   %zu bytes\n", sizeof(caseSpecial));
	case1 c1 = {
        	.a = A,
        	.b = B,
        	.c = C
    	};

    	case2 c2 = {
        	.a = A,
        	.b = B,
        	.c = C
    	};

    	case3 c3 = {
        	.a = A,
        	.b = B,
        	.c = C
    	};

    	caseSpecial cSpecial = {
        	.a = A,
        	.b = B,
        	.c = C,
        	.shorts = 0x1111,
        	.ints = 0x22222222
    	};

	if(!save_struct("Case1.bin", &c1, sizeof c1)) {
        	return 1;
    	}

	if(!save_struct("Case2.bin", &c2, sizeof c2)) {
		return 1;
	}

	if(!save_struct("Case3.bin", &c3, sizeof c3)) {
		return 1;
	}

	if(!save_struct("CaseSpecial.bin", &cSpecial, sizeof cSpecial)) {
		return 1;
	}

	return 0;
}
