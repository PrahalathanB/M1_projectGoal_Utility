/**
 * @file Issuebook.c
 * @author your name (you@domain.com)
 * @brief function to issue the book to the student or the person recquired || the book must be availabe in order to issue
 *  
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "library_Managment_system.h"
test_values issuebook(int id)
{
    char name1[20];
    FILE *fp=NULL;
    fp = fopen("bookLibrary.dat","rb");
    if(fp==NULL)
    {
        printf("\nError while opening file in issuing book\\n"); // the book is not present or not yet added
        return fail;
    }
    else{

    scanf("%19s student name",name1);
    book *book_to_find=(book*)malloc(sizeof(book));
    while(fread(book_to_find,sizeof(book),1,fp))
    {
        if(book_to_find->book_id==id)
        {
            
            printf("\nBook_Id: %d\t\tBook_name: %s\t\tBook_Author: %s",book_to_find->book_id,book_to_find->book_name,book_to_find->author_name);
            printf("\n Book is issued to %s",name1);
            fclose(fp);
            free(book_to_find);
            return pass;
        }
    }
    
    fclose(fp);
    free(book_to_find);
    printf("\nSpecified book is not present\n"); // the book is either issued 
    
    return fail;
    }
}