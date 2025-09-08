void swap(int ***pp , int **p) {

    int *temp;
    temp = *pp; 
    *pp = *p; 
    *p = temp; 
}