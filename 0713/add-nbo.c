#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    uint32_t num;

    if (file == NULL) {
        printf("File %s not found!\n", filename);
        return -1;
    }

    fread(&num, sizeof(uint32_t), 1, file);
    fclose(file);

    return ntohl(num);  // convert network byte order to host byte order
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("syntax : add-nbo <file1> <file2>\n");
        printf("sample : add-nbo a.bin b.bin\n");
        return -1;
    }

    uint32_t num1 = read_file(argv[1]);
    uint32_t num2 = read_file(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}

