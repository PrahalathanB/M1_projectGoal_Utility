/**
 * @file Deletebook.c
 * @author your name (you@domain.com)
 * @brief Delete the book from the base using book id || the book must be added already in order to be removed
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "library_Managment_system.h"
test_values deletebook(int id)
{
    
    
    
    FILE *fp=NULL;
    FILE *ft=NULL;
    fp = fopen("bookLibrary.dat","rb");
    ft = fopen("temp.dat","wb");
    
    if(fp==NULL || ft==NULL)
        {
            printf("\nError: While opening file:\n"); // book is not added or already deleted
            return fail;
        }
    else{
        rewind(fp);
        
        book *discarded_book = (book*)malloc(sizeof(book));
    while(fread(discarded_book,sizeof(book),1,fp)==1)
    {
        if(id != discarded_book->book_id)
        {
            
            fwrite(discarded_book,sizeof(book),1,ft);
            
            
        }
        
        
        

    }
    fclose(fp);
    fclose(ft);
    free(discarded_book); // deletes the book
  
   remove("bookLibrary.dat");
    rename("temp.dat","bookLibrary.dat");
    
    return pass;
    
    
        }

}