To make this program using C we must be using the OpenSSL library, here's a example of how the program should look.
```
#include <stdio.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

void Base64Decode(char* b64message, char** buffer, int* length) {
    BIO *bio, *b64;

    int decodeLen = strlen(b64message);
    *buffer = (char*)malloc(decodeLen);

    bio = BIO_new_mem_buf(b64message, -1);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    *length = BIO_read(bio, *buffer, decodeLen);

    BIO_free_all(bio);
}

int main() {
    char* base64EncodeOutput, *text;
    int len;

    Base64Decode("SGVsbG8gd29ybGQ=", &base64EncodeOutput, &len);

    text = (char*)malloc(len + 1);
    strncpy(text, base64EncodeOutput, len);
    text[len] = '\0';

    printf("Decoded: %s\n", text);

    free(base64EncodeOutput);
    free(text);

    return 0;
}
```
This code uses the OpenSSL library to decode a Base64-encoded string. The `Base64Decode` function takes a Base64-encoded string and a pointer to a buffer where the decoded data will be stored, as well as a pointer to an integer where the length of the decoded data will be stored. It creates a memory BIO from the input string, pushes a Base64 BIO onto it, and then reads from the BIO to decode the data. The decoded data is then copied into the buffer.

Please note that you need to install OpenSSL and link against it to compile this code. You can do this on a Debian-based system with `sudo apt-get install libssl-dev` and then compile with `gcc -o base64decode base64decode.c -lssl -lcrypto`.

Remember to always check the return values of functions in real code to ensure error conditions are handled correctly.

