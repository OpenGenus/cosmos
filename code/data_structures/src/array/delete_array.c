
int main()
{
int *a=malloc(10*sizeof(int)); //allocating array using malloc
free(a);                       //deleting array using free

char ** a = malloc(10*sizeof(char*));
for(int i=0; i < 10; i++)
{
    a[i] = malloc(i+1);        //allocating memory for each element
}
for (int i=0; i < 10; i++) 
{
    free(a[i]);                //freeing each element
}
free(a);                       //freeing the array pointer
return 0;
}