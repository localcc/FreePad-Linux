#ifndef WAV_FILE_H_
#define WAV_FILE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct WaveFile {
	uint8_t channels_count;
	uint16_t rate;
	uint8_t format;
	unsigned char* buf_pointer;
} WaveFile;

struct WaveFile* read_file(const char* path) {
	return NULL;
}

#endif // WAV_FILE_H_
