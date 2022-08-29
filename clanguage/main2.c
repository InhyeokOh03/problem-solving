#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char message[] = "attack at dawn";
    char key[] = "lemonlemonlemo";
    int message_len = strlen(message);
    char en_result[1000] = { 0, }, de_result[1000] = { 0, };
    
    //encrypt
    for (int i = 0; i < message_len; i++) {
        if ((int)message[i] == ' ') en_result[i] = ' ';
        else {
            if ((int)message[i] + (int)key[i] - 97 < 122) {
                en_result[i] = (int)message[i] + (int)key[i] - 97;
            }
            if ((int)message[i] + (int)key[i] - 97 > 122) {
                en_result[i] = (int)message[i] + (int)key[i] - 97 - 26;
            }
        }
    }
    //decrypt
    for (int i = 0; i < message_len; i++) {
        if ((int)en_result[i] == ' ') de_result[i] = ' ';
        else {
            if ((int)en_result[i] - (int)key[i] >= 0) {
                de_result[i] = (int)en_result[i] - (int)key[i] + 97;
            }
            if ((int)en_result[i] - (int)key[i] < 0) {
                de_result[i] = (int)en_result[i] - (int)key[i] + 97 + 26;
            }
        }
    }
    printf("encrypted : %s\ndecrypted : %s\n", en_result, de_result);
}
