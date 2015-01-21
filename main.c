//
//  main.c
//  caesar_cipher
//
//  Created by Phil on 11/01/15.
//  Copyright (c) 2015 Daniel Phillips. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void cipher(int key, char * to_cipher);

int main(int argc, char * argv[])
{
    if (argc != 3)
        printf("%s\n","Ya done goofed, Usage is ./program key plaintext");
    int key = atoi(argv[1]);
    if (key < 0){
        key = key % 26;
        key += 26;
    }
    cipher(key, argv[2]);
    printf("%s", argv[2]);
    
    return 0;
}

/* function to cipher given input */
void cipher(int key, char * to_cipher)
{
    int size;
    for (size = 0; to_cipher[size] != '\0'; size++);
    
    for (int i = 0; i < size; i++){
        if (!isalnum(to_cipher[i])) {
            continue;
        }else {
            if (!isnumber(to_cipher[i])){
                if (isupper(to_cipher[i])){
                    to_cipher[i] = ((to_cipher[i] - 65) + key) % 26 + 65;
                }else if (islower(to_cipher[i])){
                    to_cipher[i] = ((to_cipher[i] - 97) + key) % 26 + 97;
                }
            }else if (isnumber(to_cipher[i])) {
                to_cipher[i] = ((to_cipher[i] - 48) + key) % 26 + 48;
            }
        }
    }
}