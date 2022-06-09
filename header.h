#include <string.h>
#include <stdio.h>
typedef char nametype[20];
struct celltype {
 nametype element;
 celltype* next;
};
const int DICT_SIZE = 5;
typedef celltype* DICTIONARY[DICT_SIZE];
int hash(nametype x) {
 int sum = 0;
 for (unsigned int i = 0; i < strlen(x); i++)sum += (int)x[i];
 return sum % (DICT_SIZE);
}
void MAKENULL(DICTIONARY A) {
 for (int i = 0; i < DICT_SIZE; i++)
 A[i] = nullptr;
}
bool MEMBER(nametype x, DICTIONARY A) {
 celltype* current;
 current = A[hash(x)];
 while (current != nullptr) {
 if (strcmp(current->element, x) == 0)return true;
 else current = current->next;
 }
 return false;
}
void INSERT(nametype x, DICTIONARY A) {
 int bucket;
 celltype* oldheader;
 if (!MEMBER(x, A)) {
 bucket = hash(x);
 oldheader = A[bucket];
 A[bucket] = new celltype;
 strcpy(A[bucket]->element, x);
 A[bucket]->next = oldheader;
 }
}
void DELETE(nametype x, DICTIONARY A) {
 int bucket = hash(x);
 if (A[bucket] != nullptr) {
 if (strcmp(A[bucket]->element, x) == 0)
 {
 celltype* element_to_delete = A[bucket];
 A[bucket] = A[bucket]->next;
 delete element_to_delete;
 }
 else {
 celltype* current = A[bucket];
 while (current->next != nullptr) {
 if (strcmp(current->next->element, x) == 0) {
 celltype* element_to_delete = current->next;
current->next = current->next->next;
 delete element_to_delete;
return;
 }
 else current = current->next;
 }
 }
 }
}

