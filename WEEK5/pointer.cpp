void update(int *a,int *b) {
    // Complete this function 
    int c= *a+*b;
    int d=*a-*b;   
    *a= c;
    *b=abs(d);
}
