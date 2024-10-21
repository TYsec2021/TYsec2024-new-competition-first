#include<stdio.h>
#include<stdlib.h>
void init(){
  setbuf(stdin, 0LL);
  setbuf(stdout, 0LL);
  setbuf(stderr, 0LL);
}

int main(){
    init();
	char v1[44];
	int v2;
	puts("What do you want to do?");
	v2 = 0;
	gets(v1);
	if(v2)
	{
		puts("you can do");
		system("/bin/sh");
	}
	return 0;
}

