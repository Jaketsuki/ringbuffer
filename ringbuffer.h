#define MAX_BUFFER 10
#include <stdint.h>
#include <stdio.h>


struct buffer_type
{
	uint8_t *head;
	uint8_t *tail;
	uint8_t *buffer;
};
enum {OK, BUFFER_EMPTY, BUFFER_OVERRUN, BUFFER_HEAD_AT_TAIL, BUFFER_OUT, BUFFER_HEAD_END};




void init_buffer(struct buffer_type *b, uint8_t *buffer);
void empty_buffer(struct buffer_type *b);
void make_buffer(uint8_t message[]);
int16_t get_buffer_status(struct buffer_type b, int16_t *err);
int16_t add_char_to_buffer(struct buffer_type *b, uint8_t c, int16_t *err);
uint8_t get_char_from_buffer(struct buffer_type *b, int16_t *err);
int16_t print16_t_buffer(struct buffer_type b, int16_t *err);
int16_t add_string_to_buffer(struct buffer_type *b, uint8_t *s, int16_t *err);
int16_t  get_string_from_buffer(struct buffer_type *b, uint8_t *dest, int16_t len, int16_t *err);
