#include <expat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/names.h"
#include "../include/phonebook.h"
#define BUFFER_SIZE 100000
typedef struct read_buffer {
    size_t human_number;
    size_t phone_number;
    phonebook_t* book;
} read_buffer_t;
int comp (const void *a, const void *b) {
    human_t *h1 = (human_t *)a;
    human_t *h2 = (human_t *)b;
    return strcmp(h1->family_name, h2->family_name);
}
void str_parse(char* dest, const char* source, size_t length){
    unsigned int i;
    for (i = 0; i < length; i++)
        if (*source != ' ' && *source != '\t' && *source != 10)
            *dest= *source, dest++, source++;
    *dest = '\0';
}

void start_element(void* datav, const char *element, const char **attribute) {
    read_buffer_t* data = (read_buffer_t*) datav;
    char* tmp = (char *)malloc(800);
    int i;
    if (strcmp(element, "human") == 0){
        human_t human;
        human.phone_number = 0;
        (data->human_number)++;
	(data->phone_number) = 0;
	for(i = 0; i < 10; i++)
	    human.phones[i][0] = '\0';
        strcpy(tmp, attribute[1]);
        strcpy(human.name, strtok(tmp, " "));
        strcpy(human.middle_name, strtok(NULL, " "));
        strcpy(human.family_name, strtok(NULL, " "));
        push_back_human(data->book, &human);
    }
    free(tmp);
}
void end_element(void *datav, const char *element) {
    read_buffer_t* data = (read_buffer_t*) datav;
    if (strcmp(element, "phone") == 0) {
        (data->phone_number)++;
	data->book->humans[data->human_number].phone_number++;
    }
    if (strcmp(element, "human") == 0)
        data->phone_number = 0;
}
void handle_data(void *datav, const char *content, int length) {
    char* phone = (char*)malloc(length + 1);
    str_parse(phone, content, length);
    read_buffer_t* data = (read_buffer_t*) datav;
    //if(strlen(phone)) {
     //   strcpy(data->book->humans[data->human_number].phones[data->phone_number], phone);
        //data->book->humans[data->human_number].phone_number;
    //}
    if(strlen(phone)) {
	strcat(data->book->humans[data->human_number].phones[data->phone_number], phone);
	}
   // else {
//	strcpy(data->book->humans[data->human_number].phones[data->phone_number], phone);
//	}
    free(phone);
}
void init_read(read_buffer_t *data, phonebook_t *book) {
    data -> book = book;
    data -> human_number = -1;
    data -> phone_number = 0;
}
int load_phonebook_xml(const char* filename, phonebook_t* book){
    char buffer[BUFFER_SIZE];
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    read_buffer_t data;
    init_read(&data, book);
    XML_Parser parser = XML_ParserCreate(NULL);
    XML_SetElementHandler(parser, start_element, end_element);
    XML_SetCharacterDataHandler(parser, handle_data);
    XML_SetUserData(parser, &data);
    memset(buffer, 0, BUFFER_SIZE);
    size_t len = 0;
    int done = 0;
    do {
        len = fread(buffer, sizeof(char), BUFFER_SIZE, fp);
        done = len < BUFFER_SIZE;
        if (XML_Parse(parser, buffer, len, done) == XML_STATUS_ERROR) {
            printf("Error: %s\n", XML_ErrorString(XML_GetErrorCode(parser)));
            return 2;
        }
    } while (!done);
    XML_ParserFree(parser);
    fclose(fp);
    qsort(book->humans, book->size, sizeof(human_t), comp);
    return 0;
}
void push_back_human(phonebook_t *book, human_t *human){
    if (book->size >= book->capacity) {
        book->capacity *= 2;
        book->humans = (human_t *)realloc(book->humans, book->capacity * sizeof(human_t));
    }
    book->humans[book->size] = *human;
    (book->size)++;
}
void gen_phonebook(phonebook_t *book, size_t size) {
    free(book->humans);
    book->humans = (human_t *)malloc(sizeof(human_t));
    book->size = 0;
    book->capacity = 1;
    srand(time(NULL));
    unsigned int i, j, pn, len, k;
    human_t h;
    for(i = 0; i < size; i++) {
        strcpy(h.name, kNames[rand() % NAMES_CNT]);
        strcpy(h.family_name, kFamilyNames[rand() % FAMILY_NAMES_CNT]);
        strcpy(h.middle_name, kMiddleNames[rand() % MIDDLE_NAMES_CNT]);
        pn = rand() % 10 + 1;
        h.phone_number = pn;
        for(j = 0; j < pn; j++) {
            len = rand () % 15 + 6;
            for(k = 0; k < len; k++)
                h.phones[j][k] = '0' + rand () % 10;
            h.phones[j][k] = '\0';
        }
        push_back_human(book, &h);
    }
}
int save_phonebook_xml(const char *filename, phonebook_t *book) {
    FILE *f;
    unsigned int i, j;
    f = fopen(filename, "w");
    if (f == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    fprintf(f, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(f, "<phonebook>\n");
    for(i = 0; i < book->size; i++) {
        fprintf(f, "    <human name=\"%s %s %s\">\n", (book->humans[i]).name, (book->humans[i]).middle_name, (book->humans[i]).family_name);
        for(j = 0; j < (book->humans[i]).phone_number; j++)
            fprintf(f, "        <phone>%s</phone>\n", (book->humans[i]).phones[j]);
        fprintf(f, "    </human>\n");
    }
    fprintf(f, "</phonebook>\n");
    fclose(f);
    return 0;
}
void print_phonebook(phonebook_t *book){
    printf("%d\n", (int)book->size);
    unsigned int i, j;
    for (i = 0; i < book->size; i++){
        printf("name: %s\nmiddle name: %s\nfamily name: %s\n", (book->humans[i]).name,(book->humans[i]).middle_name,(book->humans[i]).family_name);
        for (j = 0; j < book->humans[i].phone_number; j++)
            printf("phone: %s\n", (book->humans[i]).phones[j]);
            printf("\n");
    }
}
void clear_phonebook(phonebook_t *book){
    free(book->humans);
    free(book);
}
int main(int argc, char **argv) {
    phonebook_t* book = (phonebook_t*)malloc(sizeof(phonebook_t));
    book->humans = (human_t *)malloc(sizeof(human_t));
    book->size = 0;
    book->capacity = 1;
    load_phonebook_xml(argv[1], book);
    print_phonebook(book);
    gen_phonebook(book, rand() % 90 + 7);
    save_phonebook_xml(argv[2], book);
    clear_phonebook(book);
    return 0;
}
