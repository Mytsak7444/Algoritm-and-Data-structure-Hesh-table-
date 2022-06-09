#include "header.h"

void Print(DICTIONARY A) {
 celltype* current;
 for (int i = 0; i < DICT_SIZE; i++) {
 current = A[i];
 if(i)printf("\n");
 printf("%d:\t", i);
 while (current != nullptr) {
 printf("%s", current->element);
 if (current->next != nullptr)printf(", ");
 current = current->next;
 }
 }
 printf("\n");
}
char strings[][25] = { "Robert", "John", "Harry", "Peter", "Kevin", "Jack", "Konnor", 
"William", "Adam", "Adrian", "Bernard", "Caleb", "David", "Eric", "Scott"};
int main()
{
 DICTIONARY A;
 MAKENULL(A);
 for (int i = 0; i < 15; i++)
 INSERT(strings[i], A);
 Print(A);
 int index_to_delete = 0;
 if (MEMBER(strings[index_to_delete], A))printf("\n*** is member of dictionary ***\n\n", 
strings[index_to_delete]);
 
 DELETE(strings[index_to_delete], A);
 Print(A);
 if (!MEMBER(strings[index_to_delete], A))printf("\n*** isn't member of dictionary 
***\n", strings[index_to_delete]);
}
