#include<stdio.h>

int main() {
	unsigned char s3[15] = "000000000000000";
        unsigned char s4[15] = {176, 164, 104, 194, 206, 132, 162, 210, 154, 132, 222, 106, 152, 82, 110};
        for(int i = 0; i < 15; i++)
        {
                s3[i] = s4[i];
                s3[i] = ((s3[i] ^ 12) + 6) & 0xff;
                s3[i] = ((s3[i] << 7) | (s3[i] >> 1) & 0xff);
        }
        printf("%s", s3);
        return 0;
}
