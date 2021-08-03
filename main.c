#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

HANDLE wHnd;
HANDLE rHnd;

struct entry {
    char brand[20], productName[50];
    float price;
    int stock;

};

struct nod {
    struct entry data;
    struct nod *urm;
};

int initialized = 0;
struct nod *first = NULL, *last = NULL;
int nrElem = 0;

void menu() {
    if (initialized == 0) {
        struct entry tempEntry;

        char key;

    printf("╔══════════════════════════════════════════════════╗\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║         We'll start by adding one entry          ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║        Press any key to start the program        ║\n");
    printf("╚══════════════════════════════════════════════════╝\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        for(;;)
           if (kbhit())
                {key = getch();break;}
        system("CLS");

        printf("Add a first entry:\n");
        printf("Brand:");
        //scanf("%s", &tempEntry.brand);
        gets(tempEntry.brand);
        printf("Product Name:");
        //scanf("%s", &tempEntry.productName);
        gets(tempEntry.productName);
        printf("Price:");
        scanf("%f", &tempEntry.price);
        printf("Products in stock: ");
        scanf("%d", &tempEntry.stock);

        struct nod *p = (struct nod *) malloc(sizeof(struct nod));
        p->data = tempEntry;
        p->urm = NULL;
        first = p;
        last = p;
        last->urm = NULL;
        nrElem++;
        initialized = 1;
    }
    system("CLS");
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║                   1. Add entry                   ║\n");
    printf("║                  2. Remove entry                 ║\n");
    printf("║            3. Print current entry list           ║\n");
    printf("║           4. Write the list into a file          ║\n");
    printf("║             5. Remove background color           ║\n");
    printf("║                     6. Info                      ║\n");
    printf("║                     7. Exit                      ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║Press the key corresponding to your desired action║\n");
    printf("╚══════════════════════════════════════════════════╝\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    return;

}

void addFirst() {
    system("CLS");
    struct entry tempEntry;
    printf("Brand:");
    //scanf("%s", &tempEntry.brand);
    gets(tempEntry.brand);
    printf("Product Name:");
    //scanf("%s", &tempEntry.productName);
    gets(tempEntry.productName);
    printf("Price:");
    scanf("%f", &tempEntry.price);
    printf("Products in stock: ");
    scanf("%d", &tempEntry.stock);
    struct nod *p = (struct nod *) malloc(sizeof(struct nod));
    p->data = tempEntry;
    p->urm = first;
    first = p;
}

void addLast() {
    system("CLS");
    struct entry tempEntry;
    printf("Brand:");
    //scanf("%s", &tempEntry.brand);
    gets(tempEntry.brand);
    printf("Product Name:");
    //scanf("%s", &tempEntry.productName);
    gets(tempEntry.productName);
    printf("Price:");
    scanf("%f", &tempEntry.price);
    printf("Products in stock: ");
    scanf("%d", &tempEntry.stock);
    struct nod *p = (struct nod *) malloc(sizeof(struct nod));
    p->data = tempEntry;
    p->urm = NULL;
    last->urm = p;
    last = p;
}

void addPosition() {
    int index, i = 1;

    printf("Which position should the entry be placed after?[0-%d]\n", nrElem);
    //scanf("%d", &index);

    for(;;)
           if (kbhit())
                {index = getch();
                break;}
        index = (int)index-48;


    if (index < 0 || index > nrElem) {
        printf("Invalid Choice");
        getch();
    } else {
        if (index == 0)
            addFirst();
        else if (index == nrElem)
            addLast();
        else {
            struct nod *p = first;
            while (i < index) {
                p = p->urm;
                i++;
            }
            struct entry tempEntry;

            printf("Brand:");
            //scanf("%s", &tempEntry.brand);
            gets(tempEntry.brand);
            printf("Product Name:");
            //scanf("%s", &tempEntry.productName);
            gets(tempEntry.productName);
            printf("Price:");
            scanf("%f", &tempEntry.price);
            printf("Products in stock: ");
            scanf("%d", &tempEntry.stock);

            struct nod *q = (struct nod *) malloc(sizeof(struct nod));
            q->data = tempEntry;
            q->urm = p->urm;
            p->urm = q;
        }

    }
}

void adaugare() {
    system("CLS");
    int choice;


    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║         Where should the entry be added?         ║\n");
    printf("║               1. As the first entry              ║\n");
    printf("║               2. As the last entry               ║\n");
    printf("║               3. After index X                   ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║Press the key corresponding to your desired action║\n");
    printf("╚══════════════════════════════════════════════════╝\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    //scanf("%d", &choice);
    for(;;)
           if (kbhit())
                {choice = getch();
                break;}
        choice = (int)choice-48;
        fflush(stdin);

    switch (choice) {
        case 1:
            addFirst();
            nrElem++;
            break;
        case 2:
            addLast();
            nrElem++;
            break;
        case 3:
            addPosition();
            nrElem++;
            break;

        default:
            printf("Invalid Choice");
            getch();
            getch();
            return;
    }

}

void afisare() {
    int i = 0;
    system("CLS");
    struct nod *p = first;
    printf("Current entry list: \n\n");
    while (p != NULL) {
        printf("%d. %s, %s, %f, %d\n", ++i, p->data.brand, p->data.productName, p->data.price, p->data.stock);
        p = p->urm;
    }
    getch();
}

void stergPrim() {
    if (nrElem == 0) return;
    if (first != NULL)
        nrElem--;
    struct nod *p = first;
    first = first->urm;
    free(p);
}

void stergUlt() {
    if (nrElem == 0) return;

    if (nrElem == 1)
        {stergPrim();
         }

    else{
        if (last != NULL)
            nrElem--;
        struct nod *p = first;
        while (p->urm != last) {
            p = p->urm;
        }
    //hangs up here
        struct nod *q = last;
        p->urm = NULL;
        last = p;
        free(q);

}
}
void stergPosi() {
    if (nrElem == 0) return;
    system("CLS");
    int index;
    printf("Insert the index of the entry you wish removed [1-%d]:\n", nrElem);
    //scanf("%d", &index);

    for(;;)
           if (kbhit())
                {index = getch();
                break;}
        index = (int)index-48;

    if (index < 1 || index > nrElem) {
        printf("Invalid Choice");
        getch();
    } else {
        if (index == 1)
            stergPrim();
        else if (index == nrElem)
            stergUlt();
        else {
            int i = 1;
            struct nod *p = first;
            while (i < index - 1) {
                i++;
                p = p->urm;
            }
            struct nod *q = p->urm;
            p->urm = p->urm->urm;
            free(q);
            nrElem--;
        }

    }
}

void stergX() {
    if (nrElem == 0) return;
    system("CLS");
    printf("Enter the name of the product to be removed (CaSe SeNsItIvE)\n");
    char tempName[50];
    //scanf("%s", &tempName);
    //getch();
    gets(tempName);
    struct nod *p = first;
    if (strcmp(p->data.productName, tempName) == 0)
        stergPrim();
    else {
        while (p->urm != NULL && strcmp(p->data.productName, tempName) != 0)
            p = p->urm;
        if (p->urm == NULL) {
            printf("Product not found");
            getch();
            return;
        } else {
            struct nod *q = p->urm->urm;
            free(p->urm);
            p->urm = q;
            nrElem--;
        }

    }
}

void stergere() {
    system("CLS");
    int choice;

    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║           Which entry should be removed?         ║\n");
    printf("║                 1. First entry                   ║\n");
    printf("║                 2. Last entry                    ║\n");
    printf("║                 3. Entry at index X              ║\n");
    printf("║                 4. Product named X               ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║Press the key corresponding to your desired action║\n");
    printf("╚══════════════════════════════════════════════════╝\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    //scanf("%d", &choice);

    for(;;)
           if (kbhit())
                {choice = getch();
                break;}
        choice = (int)choice-48;

    switch (choice) {
        case 1:
            stergPrim();
            break;
        case 2:
            stergUlt();
            break;
        case 3:
            stergPosi();
            break;
        case 4:
            stergX();
            break;
        default:
            printf("Invalid Choice");
            getch();
            return;
    }

}


void printToFile()
{
    // Have fun
    system("CLS");
    FILE *fileptr;
    fileptr = fopen("output.txt","w");

    int i = 0;
    struct nod *p = first;
    fprintf(fileptr,"Current entry list: \n\n");
    while (p != NULL) {
        fprintf(fileptr,"%d. %s, %s, %f, %d\n", ++i, p->data.brand, p->data.productName, p->data.price, p->data.stock);
        p = p->urm;
    }
    fclose(fileptr);

    printf("Done");
    Sleep(1000);
}

void info()
{   char key;

    system("CLS");
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║           In this project you can find:          ║\n");
    printf("║                 1. Structs                       ║\n");
    printf("║                 2. Linked lists                  ║\n");
    printf("║                 3. Malloc / pointers             ║\n");
    printf("║                 4. Use of windows.h              ║\n");
    printf("║                 5. Console edits                 ║\n");
    printf("║                 6. Customized executable file    ║\n");
    printf("║                 7. File usage                    ║\n");
    printf("║                 8. Custom console UI             ║\n");
    printf("║                 9. Keypress detection            ║\n");
    printf("║                10. Nested function calls         ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║   The code can be found on both of our githubs   ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║   If you encounter any error, let us know ASAP   ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║         Press any key to leave this page         ║\n");
    printf("╚══════════════════════════════════════════════════╝\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    for(;;)
           if (kbhit())
                {key = getch();break;}
        system("CLS");

}

int main() {
    int choice;
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleTitle("                                          Practice Stage Project");
    SMALL_RECT windowSize = {0, 0, 53, 40};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    system ("color 8B");

    while (1) {
        menu();

        for(;;)
           if (kbhit())
                {choice = getch();
                break;}
        choice = (int)choice-48;
        fflush(stdin);

        //scanf("%d", &choice);
        switch (choice) {
            case 1:
                adaugare();
                break;
            case 2:
                stergere();
                break;
            case 3:
                afisare();
                break;
            case 4:
                printToFile();
                break;
            case 5:
                system ("color B");
                break;
            case 6:
                info();
                break;
            case 7:
                system("CLS");
                printf("Application will now close");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                return 0;
            default:
                printf("Alegere invalida");
                getch();
        }
    }
}
