#include <stdio.h>
#include <stdlib.h>

typedef struct BookData { 
   char *name;
   float price;
   int pages;
   char *language;
   float weight;
   int publYear;
} book;


typedef struct LinkedList {
    book info;
    size_t nextP;
} list ;

list * listInit(char *name, float prise, int pages, char *language, float weight, int publYear);
list * addNode(list *lp, char *name, float prise, int pages, char *language, float weight, int publYear);

int main() {
    list* head;
    head = listInit("aaa", 200.0, 350, "ua", 1.34, 2002);
    head = addNode(head, "bbb", 222.0, 333, "en", 3.14, 1984);
    return 0;
}


list * listInit(char *name, float prise, int pages, char *language, float weight, int publYear) {
    list *lp;
    lp = malloc(sizeof(struct LinkedList));
    lp->info = (book){
        .name = name,
        .price = prise,
        .pages = pages,
        .language = language,
        .weight = weight,
        .publYear = publYear
    };
    lp->nextP = NULL;

    /*
    printf("ptr = %d,next = %d,name = %s,prise = %.2f,pages = %d,language = %s,weight = %.2f,pubYear = %d\n",
        lp,lp->nextP, 
        lp->info.name,
        lp->info.price,
        lp->info.pages,
        lp->info.language,
        lp->info.weight,
        lp->info.publYear
        );
    */
    return lp;
}

list * addNode(list *lp, char *name, float prise, int pages, char *language, float weight, int publYear) {
    struct LinkedList *nodeP;
    nodeP = malloc(sizeof(struct LinkedList));
    nodeP->info = (book){
        .name = name,
        .price = prise,
        .pages = pages,
        .language = language,
        .weight = weight,
        .publYear = publYear
    };
    nodeP->nextP = lp;
    /*
    printf("ptr = %d,next = %d,name = %s,prise = %.2f,pages = %d,language = %s,weight = %.2f,pubYear = %d\n",
        nodeP,
        nodeP->nextP, 
        nodeP->info.name,
        nodeP->info.price,
        nodeP->info.pages,
        nodeP->info.language,
        nodeP->info.weight,
        nodeP->info.publYear
        );
    */
    return nodeP;
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
