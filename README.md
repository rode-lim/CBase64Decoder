# CBase64Decoder

## Explanation

This code uses the OpenSSL library to decode a Base64-encoded string. The Base64Decode function takes a Base64-encoded string and a pointer to a buffer where the decoded data will be stored, as well as a pointer to an integer where the length of the decoded data will be stored. It creates a memory BIO from the input string, pushes a Base64 BIO onto it, and then reads from the BIO to decode the data. The decoded data is then copied into the buffer.

## HOW TO USE!!!

FIND THE LINE:
```
  Base64Decode("SGVsbG8gd29ybGQ=", &base64EncodeOutput, &len);
```
Replace the "" with the base 64 that was given to you!
Please note that you need to install OpenSSL and link against it to compile this code. You can do this on a Debian-based system with ´sudo apt-get install libssl-dev´ and then compile with ´gcc -o base64decode base64decode.c -lssl -lcrypto´.

Remember to always check the return values of functions in real code to ensure error conditions are handled correctly.
