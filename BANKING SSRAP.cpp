#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 
typedef struct Bank { 
 
// typedef eijnno use korchi karon amrader jno struct Bank barbar likha na lage
// struct Bank er jaygay node likhlei hbe
 
    char name[100];
    char lastName[100];
    int savingNumber;
    char profession[100];
    char address[1000];
    int balance;
    int fix;
    int ac;
    struct Bank* next; // next node er adrs store korar jnno
} node;
 
node* start = NULL;  // head node initially null thake
 
node* createnode() {
    node* n;
    n = (node*)malloc(sizeof(node)); // ei createnode function e mainly memory allocate korchi
    return (n); // allocate kora memory return kore dichi ekhan theke
}
 
void printStars(int numStars) {
    // ei function ta just single line e star printing er jnno implement korchi
    // for design purpose
    for (int i = 0; i < numStars; i++) {
        printf("*");
    }
    printf("\n");
}
 
void printIndentedText(const char* text) {
    printf("\t\t%s", text); // tab printing
}
 
void insert() {
    node* temp, * prev;
    temp = createnode();
    int value1;
 
    // prothom e account er detail gula input nichi
    // amra jdi bank er node create korte cai amdr name, acc no, atm esb lagbe
 
    printStars(50);
    printf("REGISTER AN ACCOUNT\n");
    printStars(50);
 
    printIndentedText("Enter the first name: ");
    scanf("%s", temp->name);
 
    printIndentedText("Enter the last name: ");
    scanf("%s", temp->lastName);
 
    printIndentedText("Enter the Savings number: ");
    scanf("%d", &value1);
 
    int flag = 0;
    node* search;
    search = start;
 
    // amra prothom e cheak korbo already saving id ta eist kore kina
    if (start == NULL) { // ekhane cheak korchi list ta empty kina
        flag = 0; // empty hole flag = 0 kore dichi jate pore bujhte pari list is empty
    } else {
        // 
        while (search != NULL) { // jotokkhm na search null hoy loop colbe
            if (value1 == search->savingNumber) {
                flag = 1;
                printIndentedText("ID already exists\n");
                break;
            } else {
                search = search->next;
            }
        }
    }
 
    // ekhane flag 0  hole new acc create kora jabe
    // ekhn account info gula input nibo
    if (flag == 0) {
        temp->savingNumber = value1;
        fflush(stdin);
        printIndentedText("Enter your profession: ");
        scanf("%s", temp->profession);
        fflush(stdin);
        printIndentedText("Enter your address: ");
        scanf("%s", temp->address);
        fflush(stdin);
 
        printIndentedText("Do you want a credit or debit card? (1 for Yes, 2 for No): ");
        int option;
        scanf("%d", &option);
 
        if (option == 1) {
            printIndentedText("Initially 100 Taka deposited in this account\n");
            temp->fix = 100;
            temp->balance = 0;
        } else {
            temp->balance = 0;
            temp->fix = 0;
        }
 
 
        int acc = rand() % 1000009; // ekhane random ekta acc number generate korchi 
        printIndentedText("Unique bank account ID is ");
        printf("%d\n", acc);
        temp->ac = acc;
        temp->next = NULL;
        // search kore list er ekebare sesh e jabo karon amra newnode always ist er sesh e add kori
        if (start == NULL) {
            start = temp;
        } else {
            node* t;
            t = start;
            while (t->next != NULL)
                t = t->next;
            t->next = temp;
        }
        printStars(50);
    }
}
 
void widraw() {
    int value1;
    printStars(50);
    printf("WITHDRAW MONEY\n");
    printStars(50);
 
    printIndentedText("Enter the Savings number: ");
    scanf("%d", &value1);
 
    int flag = 0;
    node* search;
    search = start;
 
    // ekhane search krbo je amra jei account theke taka widrew korbo seita kon node
    // niche mainly search er code use kora hoiche saving no ta find korte
    if (start == NULL) {
        flag = 0;
    } else {
        while (search != NULL) {
            if (value1 == search->savingNumber) {
                flag = 1;
                break;
            } else {
                search = search->next;
            }
        }
    }
 
    // jdi flag = 1 hoy tar mane saving no exist kore ekhn amr taka withdrew korte hbe
 
    if (flag == 1) {
        node* t = search;
        int limit;
        printIndentedText("Enter the amount: "); // joto taka withdrw korbo seta input nici
        scanf("%d", &limit);
        if (limit > 0 && limit <= t->balance) { // ceak korlam balance withdrew takar ceye besi kina
            t->balance -= limit; // taka ta bad diye dilam karo ei taka ta withddraw kora hoice
            printIndentedText("Amount debited from account no.");
            printf(" %d\n", t->ac);
            printIndentedText("Your current balance is ");
            printf("%d taka\n", t->balance); // withdra korar por current balance koto seta print korlam
        } else {
            printIndentedText("Enter a valid limit\n");
        }
    } else {
        printIndentedText("No ID exists\n");
    }
    printStars(50);
}
 
void deposit() {
    int value1;
    printStars(50);
    printf("DEPOSIT MONEY\n");
    printStars(50);
 
    printIndentedText("Enter the Savings number: ");
    scanf("%d", &value1);
 
    int flag = 0;
    node* search;
    search = start;
 
    // ekhaneo search kore ager moto acc no find korchi
 
    if (start == NULL) {
        flag = 0;
    } else {
        while (search != NULL) {
            if (value1 == search->savingNumber) {
                flag = 1;
                break;
            } else {
                search = search->next;
            }
        }
    }
 
    if (flag == 1) {
        node* t = search;
        int limit;
        printIndentedText("Enter the amount: "); // toto taka diposit krbo inout nichi
        scanf("%d", &limit);
        if (limit > 0) {
            t->balance += limit; /// main balance er sathe add kore dichi
            printIndentedText("Amount credited in account no");
            printf(" %d\n", t->ac);
            printIndentedText("Your current balance is ");
            printf("%d taka\n", t->balance);
        } else {
            printIndentedText("Enter a valid limit\n");
        }
    } else {
        printIndentedText("No ID exists\n");
    }
    printStars(50);
}
 
void fix() { // ekhaneo diposit er same code just ekhane fix variable er sathe add koro
    int value1;
    printStars(50);
    printf("FIXED DEPOSIT\n");
    printStars(50);
 
    printIndentedText("Enter the Savings number: ");
    scanf("%d", &value1);
 
    int flag = 0;
    node* search;
    search = start;
    if (start == NULL) {
        flag = 0;
    } else {
        while (search != NULL) {
            if (value1 == search->savingNumber) {
                flag = 1;
                break;
            } else {
                search = search->next;
            }
        }
    }
 
    if (flag == 1) {
        node* t = search;
        int limit;
        printIndentedText("Enter the amount: ");
        scanf("%d", &limit);
        if (limit > 0) {
            t->fix += limit;
            printIndentedText("Amount deposited in account no");
            printf(" %d\n", t->ac);
        } else {
            printIndentedText("Enter a valid limit\n");
        }
    } else {
        printIndentedText("No ID exists\n");
    }
    printStars(50);
}
 
void viewlist() { // display function
    node* view;
    int count = 1;
 
    printStars(50);
    printf("VIEW ALL ACCOUNTS\n");
    printStars(50);
 
    if (start == NULL) {
        printIndentedText("List is empty.\n");
    } else {
        view = start;
        while (view != NULL) {
            printStars(50);
            printf("[-----Information of Client no. %d-----]\n", count);
            printIndentedText("Name: ");
            printf("%s %s\n", view->name, view->lastName);
            printIndentedText("Savings No.: ");
            printf("%d\n", view->savingNumber);
            printIndentedText("Account number: ");
            printf("%d\n", view->ac);
            printIndentedText("Profession: ");
            printf("%s\n", view->profession);
            printIndentedText("Address: ");
            printf("%s\n", view->address);
            printIndentedText("Balance: ");
            printf("%d\n", view->balance);
            printIndentedText("Fixed Deposit: ");
            printf("%d\n", view->fix);
            printIndentedText("Total amount with Balance and Fixed Deposit: ");
            printf("%d taka\n\n", view->fix + view->balance);
            count++;
            view = view->next;
        }
        count--;
        printStars(50);
        printIndentedText("Number of accounts = ");
        printf("%d\n", count);
    }
}
 
void view() { // search kore just oi node er info ta print kore deya
    int value1;
 
    printStars(50);
    printf("VIEW ACCOUNT\n");
    printStars(50);
 
    printIndentedText("Enter the Savings number: ");
    scanf("%d", &value1);
 
    int flag = 0;
    node* search;
    search = start;
    if (start == NULL) {
        flag = 0;
    } else {
        while (search != NULL) {
            if (value1 == search->savingNumber) {
                flag = 1;
                printIndentedText("ID already exists\n");
                break;
            } else {
                search = search->next;
            }
        }
    }
 
    if (flag == 1) {
        node* view = search;
        printStars(50);
        printIndentedText("Name: ");
        printf("%s %s\n", view->name, view->lastName);
        printIndentedText("Savings Number: ");
        printf("%d\n", view->savingNumber);
        printIndentedText("Account number: ");
        printf("%d\n", view->ac);
        printIndentedText("Profession: ");
        printf("%s\n", view->profession);
        printIndentedText("Address: ");
        printf("%s\n", view->address);
        printIndentedText("Balance: ");
        printf("%d\n", view->balance);
        printIndentedText("Fixed Deposit: ");
        printf("%d\n", view->fix);
        printIndentedText("Total amount with Balance and Fixed Deposit: ");
        printf("%d taka\n", view->fix + view->balance);
        printStars(50);
    } else {
        printIndentedText("No account exists\n");
    }
    printStars(50);
}
 
void close() { // delete er application
    int value1;
 
    printStars(50);
    printf("CLOSE ACCOUNT\n");
    printStars(50);
 
    printIndentedText("Enter the Savings number: ");
    scanf("%d", &value1);
 
    int flag = 0;
    node* search;
    search = start;
    if (start == NULL) {
        printIndentedText("No account exists\n");
    } else if (start->savingNumber == value1) {
        node* t;
        t = start;
        if (start->next == NULL)
            start = NULL;
        else
            start = start->next;
        free(t);
        printIndentedText("Account deleted\n");
    } else {
        node* prev, * t;
        t = start->next;
        while (t != NULL && t->savingNumber != value1) {
            prev = t;
            t = t->next;
        }
        if (t->next == NULL) {
            printIndentedText("No account exists\n");
        } else {
            node* link;
            link = t->next;
 
            if (t->next == NULL) {
                prev->next = NULL;
            } else {
                prev->next = link;
            }
            free(t);
            printIndentedText("Account deleted\n");
        }
    }
    printStars(50);
}
 
int menu() {
    int choice;
 
    printStars(50);
    printf("DIU BANKING SYSTEM MENU\n");
    printStars(50);
 
    printIndentedText("1: Register an account\n");
    printIndentedText("2: Withdraw money\n");
    printIndentedText("3: Deposit money\n");
    printIndentedText("4: Fixed Deposit\n");
    printIndentedText("5: Close account\n");
    printIndentedText("6: Get statements (account)\n");
    printIndentedText("7: View All accounts\n");
    printIndentedText("0: Close application\n");
    printStars(50);
    printIndentedText("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);
    return (choice);
}
 
int main() {
    printStars(50);
    printf("WELCOME TO DIU BANKING SYSTEM\n");
    printf("DEVELOPED BY SHOWROV, SADMAN, AZIM, RASHED, AND PRITU\n");
    printStars(50);
 
    while (1) {
        switch (menu()) {
            case 1:
                insert();
                break;
            case 2:
                widraw();
                break;
            case 3:
                deposit();
                break;
            case 4:
                fix();
                break;
            case 5:
                close();
                break;
            case 6:
                view();
                break;
            case 7:
                viewlist();
                break;
            case 0:
                printStars(50);
                printIndentedText("Project by Sadman Shakib, Showrov Azam, Rashed, Azim, Pritu\n");
                printStars(50);
                exit(1);
                break;
            default:
                printStars(50);
                printIndentedText("ENTER A VALID CHOICE\n");
                printStars(50);
        }
    }
    return 0;
}
