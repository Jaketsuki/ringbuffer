#include "ringbuffer.h"

extern uint8_t data_table[MAX_BUFFER];
extern uint8_t data_table_pos;

void init_buffer(struct buffer_type *b,uint8_t *buffer){
	b->head= buffer;
    b->tail= buffer;
    b->buffer= buffer;
}

void empty_buffer(struct buffer_type *b){
	b->tail=b->head;
}

int16_t get_buffer_status(struct buffer_type b,int16_t *err){
int16_t i;
*err=OK;
if(b.head<b.buffer){
	*err=BUFFER_OUT;
	return -1;
}
if((b.head>=b.buffer)&&(b.head<=(b.buffer+(MAX_BUFFER)))){
	if((b.head==b.tail-1)||((b.head==b.buffer+MAX_BUFFER)&&(b.tail==b.buffer))){
		*err=BUFFER_HEAD_AT_TAIL;
		return -3;
	}
	if(b.head==b.buffer+MAX_BUFFER){
		*err=BUFFER_HEAD_END;
		return -4;
	}
	if((b.head>=b.buffer)&&(b.head>b.tail))return (b.head-b.buffer);
	if((b.head>=b.buffer)&&(b.head<b.tail))return (b.tail-b.head);
	else
	*err=BUFFER_EMPTY;
	return -1;
}
else
	*err=BUFFER_OVERRUN;
	return -1;
}//TARKISTA EHTOJA

int16_t add_char_to_buffer(struct buffer_type *b, uint8_t c, int16_t *err){
int16_t i;
*b->head=c;
b->head++;
do{
	i=get_buffer_status(*b,err);
	printf("\n%x %d %x",b->head,i,b->tail);
if(i==-3){
	get_string_from_buffer(b,data_table,5, err);
	}
if(i==-4){
	b->head=b->buffer;
	}
if(i==-1)return -1;
}while(i<0);
return i;
}

uint8_t get_char_from_buffer(struct buffer_type *b, int16_t *err){
uint8_t i;
	i=*b->tail;
	*b->tail='\0';
	b->tail++;
	if(b->tail==b->buffer+MAX_BUFFER)b->tail=b->buffer;
	if(b->tail==b->tail)*err=BUFFER_EMPTY;
	return i;
}

int16_t print16_t_buffer(struct buffer_type b, int16_t *err){
uint8_t i;
	while(b.tail<b.head){
	i=get_char_from_buffer(&b,err);
	printf(" %c ",i);
	}
	printf("\n");
	return *err;
}

int16_t add_string_to_buffer(struct buffer_type *b, uint8_t *s, int16_t *err){
	uint8_t j,k;
	for(j=0;((s[j]!='\0'));j++){
		add_char_to_buffer(b,s[j],err);
	}
	return *err;
}

int16_t  get_string_from_buffer(struct buffer_type *b, uint8_t *dest, int16_t len, int16_t *err){
	uint16_t i;
	uint8_t j,k;
	dest+=data_table_pos;
	for(j=0;j<=len;j++){
		k=get_char_from_buffer(b,err);
		*dest=k;
		dest++;
		data_table_pos++;
	}
	if(data_table_pos==MAX_BUFFER+10)data_table_pos=0;
	return i;
}

void make_buffer(uint8_t message[]){
	uint8_t i;
	for(i=0;i<=(MAX_BUFFER+10);i++){
		
		message[i]=i+1;
	}
	
}