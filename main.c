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
list * printList(list *lp);
void listDel(list *lp);

int main() {
    list* head;
    head = listInit("Harry Potter and the Philosopher's Stone",       200.45, 350, "ua", 1.34, 1997);
    head = addNode(head, "Harry Potter and the Chamber of Secrets",   222.50, 333, "eng", 3.14, 1998);
    head = addNode(head, "Harry Potter and the Prisoner of Azkaban",  333.15, 434, "ger", 2.00, 1999);
    head = addNode(head, "Harry Potter and the Goblet of Fire",       123.45, 222, "eng", 1.98, 2000);
    head = addNode(head, "Harry Potter and the Order of the Phoenix", 321.01, 444, "eng", 1.11, 2003);
    printList(head);
    listDel(head);
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
    
    return nodeP;
}

void listDel(list *lp) {
    while(1) {
        size_t nodeP = lp->nextP;
        //printf("ptr=%d  next=%d\n", lp, lp->nextP);
        free(lp);
        lp = nodeP;
        if(!lp) {
            break;
        }
    }
}

list * printList(list *lp) {
    size_t firstNode = lp;
    while(lp) {
        printf("name = %s\nprise = %.2f\npages = %d\nlanguage = %s\nweight = %.2f\npubYear = %d\n",
            lp->info.name,
            lp->info.price,
            lp->info.pages,
            lp->info.language,
            lp->info.weight,
            lp->info.publYear
        );
        lp = lp->nextP;
        printf("\n");
    }
    return firstNode;
}
