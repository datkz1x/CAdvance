#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 100
#define MAX_LENGTH_TITLE 100
#define MAX_LENGTH_AUTHOR_NAME 70


typedef enum 
{
    BOOK_ADD_SUCCESSFULLY,
    BOOK_ADD_FAILED_FULL,
    BOOK_EDIT_SUCCESSFULLY,
    BOOK_EDIT_FAILED_WRONG_INPUT_TYPE,
    BOOK_EDIT_FAILED_CANT_FIND,
    BOOK_DELETE_SUCCESSFULLY,
    BOOK_DELETE_FAILED_EMPTY_LIBRARY,
    BOOK_DELETE_FAILED_WRONG_INPUT_TYPE,
    BOOK_DELETE_FAILED_BOOK_NOT_AVAIABLE,
} BookRetCode_t;

typedef struct 
{
    int id;
    char title[MAX_LENGTH_TITLE];
    char author[MAX_LENGTH_AUTHOR_NAME];
    int avaiable;
} Book;

BookRetCode_t addBook(Book book[], int *count);
BookRetCode_t editBook(Book book[], int count);
BookRetCode_t deleteBook(Book book[], int *count);

#endif