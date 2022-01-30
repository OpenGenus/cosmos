int *a=malloc(10*sizeof(int));  //allocating memory to an array
free(a);                        //freeing the array pointer


char ** a = malloc(10*sizeof(char*));
for(int i=0; i < 10; i++)
{
    a[i] = malloc(i+1);      //allocating memory for each array element


}
for (int i=0; i < 10; i++) 
{
    free(a[i]);              //freeing each element before deleting the array.
}
free(a);                     //freeing the array pointer
