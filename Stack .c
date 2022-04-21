#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_STACK 5

typedef struct {
	int top;
	char data[5][5];
} STACK;

STACK tumpuk;

void inisialisasi() {
  tumpuk.top = -1;
}
int IsFull(){
	if(tumpuk.top == MAX_STACK -1) 
	return 1;
	else
	return 0;
}

void push(char d[5]) {
	tumpuk.top++;
	strcpy(tumpuk.data[tumpuk.top],d);
}

int isEmpty() {
	if(tumpuk.top == -1)
		return 1;
	else 
		return 0;
}

void pop() {
	printf("data yang diambil = %s\n", tumpuk.data[tumpuk.top]);
	tumpuk.top--;
}

void tampilstack() {
	int i;
	for(i=tumpuk.top; i>=0; i--)
	{
		printf("data : %s\n", tumpuk.data[i]);
	}
}

void bersihkan () {
	tumpuk.top = -1;
}

int main () {
	int pil;
	inisialisasi();
	char dt[5];
	do
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Cetak isi array stack!\n");
		printf("4. hapus isi array stack!\n");
		printf("5. keluar\n");
		printf("pilihan anda");
		scanf("%d", &pil);
		
		switch(pil)
		{
			case 1: if(IsFull() != 1)
			{
				printf("data yang ingin diinputkan = ");
				scanf("%s", dt);
				push(dt);
			}
			else
			{
				printf("stack penuh");
			}
			break;
			
			case 2: if(isEmpty() != 1)
			{
				pop();
			}
			else {
				printf("stack masih kosong");
			}
			break;
			
			case 3: if(isEmpty() != 1)
					tampilstack();
					else 
						printf("\n tidak ada data");
					break;
			
			case 4: bersihkan();
					printf("data sudah dihapus\n");
					break;
					
						
		}
		getch();
	}
	while(pil !=5);
	printf("keluar program\n");
	getch();
}
