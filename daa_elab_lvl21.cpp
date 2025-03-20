#include <stdio.h> 
#include <string.h> 
int count(char *s,int n) { 
int steps = 0; 
for (int i = 0, j = n - 1; i < j; i++, j--) { 
if (s[i] != s[j]) { 
steps++; 
} 
} 
return steps; 
} 
int main() { 
char s[5001]; 
scanf("%s", s); 
int n = strlen(s); 
printf("%d\n", count(s, n)); 
return 0; 
}