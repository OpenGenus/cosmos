
char ** a = malloc(10*sizeof(char*)); 
for(int i=0; i < 10; i++)
{
    a[i] = malloc(i+1);              //allocating memory for each element  
}
for (int i=0; i < 10; i++) 
{
    free(a[i]);                      //deleting each element's memory
}
free(a);                             //deleting the array