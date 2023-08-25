#include <stdio.h>
#define N 6

int table[] = {244, 74, 67, 198, 149, 127, 170, 108, 50, 171, 230, 155, 204, 163, 228, 150, 0, 78, 200, 4, 105, 251, 196, 144, 177, 199, 213, 46, 13, 207, 59, 214, 84, 34, 212, 247, 86, 253, 39, 103, 162, 233, 164, 71, 1, 109, 222, 60, 191, 116, 181, 72, 156, 182, 122, 77, 184, 37, 79, 211, 143, 88, 120, 98, 57, 174, 7, 250, 124, 126, 113, 48, 249, 186, 252, 248, 154, 167, 44, 240, 14, 220, 40, 11, 215, 205, 139, 54, 133, 195, 125, 117, 104, 20, 234, 27, 18, 65, 75, 158, 165, 208, 206, 53, 68, 15, 17, 66, 210, 218, 12, 179, 73, 29, 137, 217, 236, 97, 69, 185, 224, 110, 190, 38, 172, 115, 114, 192, 64, 188, 169, 119, 180, 136, 70, 6, 8, 134, 93, 35, 9, 242, 223, 159, 32, 216, 61, 243, 30, 28, 209, 80, 107, 227, 225, 232, 21, 10, 221, 42, 226, 45, 237, 202, 118, 47, 201, 36, 129, 89, 138, 130, 5, 101, 92, 31, 147, 100, 95, 94, 241, 194, 178, 135, 187, 76, 33, 111, 19, 235, 141, 43, 161, 153, 189, 245, 51, 25, 26, 142, 23, 151, 41, 231, 176, 152, 239, 52, 229, 145, 56, 148, 85, 166, 238, 121, 81, 255, 3, 102, 168, 146, 58, 87, 131, 160, 24, 183, 2, 99, 123, 91, 112, 49, 16, 90, 55, 140, 22, 63, 83, 246, 219, 173, 197, 96, 203, 132, 193, 62, 175, 82, 157, 128, 254, 106}; 
long long int B[N][N] = {
    {2, 6, 2, 0, 0, 1}, {9, 4, 2, 1, 0, 0}, {3, 5, 3, 2, 9, 6}, {6, 3, 4, 2, 7, 8}, {0, 1, 3, 3, 7, 7}, {0, 1, 9, 8, 3, 1}
};

void r_func5(unsigned long long (*arr)[6]) {
    unsigned char* ptr = (unsigned char*)arr;
    unsigned char temp;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            temp = ptr[i * N + j];
            ptr[i * N + j] = ptr[j * N + i];
            ptr[j * N + i] = temp;
        }
    }
}

void r_func4(unsigned long long (*arr)[6]) {
    unsigned char* ptr = (unsigned char*)arr;
    for(int i=35; i>=0; i--) {
        unsigned char bitoffset = (i + 1) % 36;
        unsigned char first = ptr[i % 36];
        unsigned char second = ptr[(i+2) % 36];
        
        int bit1 = (first >> bitoffset) & 1;
        int bit2 = (second >> bitoffset) & 1;
        if (bit1 != bit2) {
            ptr[i % 36] ^= (1 << bitoffset);
            ptr[(i+2) % 36] ^= (1 << bitoffset);
        }
    }
}

void r_func3(unsigned long long (*arr)[6]) {
    unsigned char* ptr = (unsigned char*)arr;
        for(int i=0; i<6; i++) {
            for(int j=0; j<6; j++) {
                ptr[6*i+j] ^= B[i][j];
            }
    }
}

void r_func2(unsigned long long (*arr)[6]) {
    unsigned char* ptr = (unsigned char*)arr;
    for(int i=0; i<36; i++) {
        for(int j=0; j<=255; j++) {
            if(table[j] == ptr[i]) {
                ptr[i] = j;
                break;
            }
        }
    }
}

void r_func1(unsigned long long (*arr)[6]) {
    unsigned char* ptr = (unsigned char*)arr;
    for(int i=0; i<36; i++) {
        unsigned char c = ptr[i];
        ptr[i] = (((c&0b10101010) >> 1) | ((c&0b01010101) << 1));
    }
}

void solve(unsigned char* ptr) {
    r_func5((long long unsigned int (*)[6])ptr);
    r_func4((long long unsigned int (*)[6])ptr);
    r_func3((long long unsigned int (*)[6])ptr);
    r_func2((long long unsigned int (*)[6])ptr);
    r_func1((long long unsigned int (*)[6])ptr);
}

int main() {
    unsigned char buf[] = {193, 29, 28, 185, 31, 122, 68, 26, 183, 188, 117, 184, 194, 157, 188, 111, 188, 212, 146, 185, 136, 29, 187, 69, 175, 100, 22, 191, 155, 105, 174, 72, 124, 179, 24, 136};
    solve(buf);
    write(1, buf, sizeof(buf));

    return 0;
}