#include <stdio.h>
#include <string.h>
#include "../include/book.h"

BookRetCode_t addbook(Book book[], int *count)
{
    Book b;

    if (*count > MAX_BOOKS)
    {
        return BOOK_ADD_FAILED_FULL;
    }

    b.id = *count + 1;
    printf("\n ===== ADD NEW BOOK =====\n");
    printf("Enter book title:");
    fgets(b.title, MAX_LENGTH_TITLE, stdin);
    b.title[strcspn(b.title, "\n")] = 0;
    printf("Enter author name:");
    fgets(b.author, MAX_LENGTH_AUTHOR_NAME, stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    b.avaiable = 1;
    book[(*count)++] = b;

    return BOOK_ADD_SUCCESSFULLY;
};

BookRetCode_t editBook(Book book[], int count)
{
    int id;
    char newTitle[MAX_LENGTH_TITLE];
    char newAuthor[MAX_LENGTH_AUTHOR_NAME];
    printf("Enter book ID to edit:");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < count; i++)
    {
        if (book[i].id == id) 
        {
            printf("\n ===== EDIT BOOK =====\n");
            printf("Book info:\n");
            printf("ID: %d\n", book[i].id);
            printf("Title: %s", book[i].title);
            printf("Author: %s", book[i].author);
            printf("Avaiable: %s", book[i].avaiable ? "YES" : "NO");
            printf("\n");
            printf("Enter new book title (left blank if no edit):");
            fgets(newTitle, MAX_LENGTH_TITLE, stdin);
            if (newTitle != "\n")
            {
                newTitle[strcspn(newTitle, "\n")] = 0;
                strcpy(book[i].title, newTitle);
            }
            printf("Enter new author name (left blank if no edit):");
            fgets(newAuthor, MAX_LENGTH_AUTHOR_NAME, stdin);
            if (newAuthor != "\n")
            {
                newAuthor[strcspn(newAuthor, "\n")] = 0;
                strcpy(book[i].author, newAuthor);
            }

            return BOOK_EDIT_SUCCESSFULLY;
        }
    }

    return BOOK_EDIT_FAILED_CANT_FIND;
}

BookRetCode_t deleteBook(Book book[], int *count)
{
    int id;
    printf("Enter book ID to delete:");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < *count; i++)
    {
        if (book[i].id == id) 
        {
            if (book[id].avaiable == 0)
            {       
                return BOOK_DELETE_FAILED_BOOK_NOT_AVAIABLE;
            } 
            else 
            {
                for (int j = i; j < *count; j++)
                {
                    book[j] = book[j + 1]; 
                }
                (*count)--;
                return BOOK_DELETE_SUCCESSFULLY;
            }
        }
    }
    
    return BOOK_DELETE_FAILED_WRONG_INPUT_TYPE;
}
