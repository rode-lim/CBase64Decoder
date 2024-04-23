/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprogram.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:51:55 by rode-lim          #+#    #+#             */
/*   Updated: 2024/04/23 16:51:55 by rode-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
// YOU MUST ALTER THE "SGVsbG8gd29ybGQ=" TO THE BASE64 STRING YOU WANT TO DECODE!!!!
	Base64Decode("SGVsbG8gd29ybGQ=", &base64EncodeOutput, &len);

	text = (char*)malloc(len + 1);
	strncpy(text, base64EncodeOutput, len);
	text[len] = '\0';

	printf("Decoded: %s\n", text);

	free(base64EncodeOutput);
	free(text);

	return 0;
}