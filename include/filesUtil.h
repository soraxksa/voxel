#ifndef FILESUTIL_H_
#define FILESUTIL_H_

#include <stdlib.h>
#include <string.h>

static char *load_file(const char *filename, size_t *plen)
{
	char *text;
	size_t len;
	FILE *f = fopen(filename, "r");
	if (f == 0) {
		fprintf(stderr, "could not open %s \n", filename);
	}
	fseek(f, 0, SEEK_END);
	len = (size_t) ftell(f);
	if (plen) *plen = len;
	text = (char *) malloc(len+1);
	if (text == 0) return 0;
	fseek(f, 0, SEEK_SET);
	fread(text, 1, len, f);
	fclose(f);
	text[len] = 0;
	return text;
}

#endif
