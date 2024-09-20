#include <stdio.h>
#include <stdlib.h>

typedef struct bookData{
   char name[30];
   float price;
   int pages;
   char language[30];
   float weight;
   int publYear;
} book;

int main() {
   printf("Hello, World!\n");
   return 0;
}

/*
Мета роботи - отримати початкові навички роботи з С

Створити додаток який виводить на екран інформацію про серію книг про Гарі Поттера.
Інформація о книгах повинна міститися в зв'язаному списку.

Що таке зв'язаний список
https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
https://www.programiz.com/dsa/linked-list

Кожен елемент повинен містити наступну інформацію:

    назва книги;
    ціна;
    число сторінок;
    мова;
    вага;
    рік видання.

Звіт виконання - додати:
1) посилання на додаток в вашому Git репозиторії
2) скріншот виконнання додатку.
*/
