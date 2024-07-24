#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h> // ntohs 함수가 정의된 헤더 파일

uint32_t change(uint32_t n) {
    uint16_t high = (n & 0xFFFF0000) >> 16;
    uint16_t low = n & 0x0000FFFF;

    high = ntohs(high);
    low = ntohs(low);

    return ((uint32_t)low << 16) | high;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 0;
    }

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (file1 == NULL || file2 == NULL)
    {
        printf("File open Error!\n");
        return 0;
    }

    uint32_t value1 = 0;
    uint32_t value2 = 0;

    size_t read1 = fread(&value1, sizeof(uint32_t), 1, file1);
    size_t read2 = fread(&value2, sizeof(uint32_t), 1, file2);

    if (read1 != 1 || read2 != 1)
    {
        printf("File read Error!\n");
        return 0;
    }

    value1 = change(value1);
    value2 = change(value2);

    int32_t sum = value1 + value2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", value1, value1, value2, value2, sum, sum);

    fclose(file1);
    fclose(file2);
    return 0;
}