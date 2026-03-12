#include <stdio.h>

struct A {
    int x;
};

// Function to increment values
void increment(struct A a, struct A* b) {
    a.x++;
  	b->x++;
	printf("Temporary a is %d\n", a.x);
}

int main() {
    struct A a  = { 10 };
  	struct A b  = { 10 };
  
  	// Passing a by value and b by pointer
  	increment(a, &b);
  
  	printf("a.x: %d \tb.x: %d", a.x, b.x);
    return 0;
}


 #include "stdio.h" 
 int main() 
 { 
	struct {int a[2];} 
	arr[] = {{1},{2}}; 
	printf("%d %d %d %d",arr[0].a[0],arr[0].a[1],arr[1].a[0],arr[1].a[1]);
	 return 0;
} 
