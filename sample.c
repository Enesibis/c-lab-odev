#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* next;
};

typedef struct Ogrenci Ogrenci;

Node* ekle1(Node* head, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

Node* ekle(Node* head, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = head;
    return newNode;
}
void sirala(Node* head) {
    Node* current = head;
    Node* index = NULL;
    int temp;

    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data < index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void listele1(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* tekCiftEkle(Node* head, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (num % 2 == 1) {
        newNode->next = head;
        return newNode;
    } else {
        temp->next = newNode;
        return head;
    }
}

void random(){
  Node* head = NULL;

    for (int i = 0; i < 100; ++i) {
        int rastgeleSayi = rand() % 1000; 
        head = ekle(head, rastgeleSayi);
    }

    printf("Sıralanmamış Liste:\n");
    listele1(head);

    sırala(head);

    printf("Sıralı Liste:\n");
    listele(head);
}

void addFrontorEnd(){
  Node* head = NULL;
    int num;
    printf("Sayilari girin (-1 cikis icin):\n");
    do {
        scanf("%d", &num);
        if (num != -1) {
            head = tekCiftEkle(head, num);
        }
    } while (num != -1);

    printf("Liste: ");
    listele1(head);
}

Ogrenci* ekle(Ogrenci* head, int numara, char isim[], int yas) {
    Ogrenci* yeniOgrenci = (Ogrenci*)malloc(sizeof(Ogrenci));
    yeniOgrenci->numara = numara;
    strcpy(yeniOgrenci->isim, isim);
    yeniOgrenci->yas = yas;
    yeniOgrenci->next = head;
    return yeniOgrenci;
}

void listele(Ogrenci* head) {
    Ogrenci* current = head;
    while (current != NULL) {
        printf("Numara: %d, Isim: %s, Yas: %d\n", current->numara, current->isim, current->yas);
        current = current->next;
    }
}

Ogrenci* ara(Ogrenci* head, char isim[]) {
    Ogrenci* current = head;
    while (current != NULL) {
        if (strcmp(current->isim, isim) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Ogrenci* sil(Ogrenci* head, char isim[]) {
    Ogrenci* current = head;
    Ogrenci* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->isim, isim) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            printf("%s adli ogrenci silindi.\n", isim);
            return head;
        }
        prev = current;
        current = current->next;
    }
    printf("%s adli ogrenci bulunamadi.\n", isim);
    return head;
}

void enUzunIsim(Ogrenci* head) {
    Ogrenci* current = head;
    int maxUzunluk = 0;
    char* enUzunIsim;
    while (current != NULL) {
        int uzunluk = strlen(current->isim);
        if (uzunluk > maxUzunluk) {
            maxUzunluk = uzunluk;
            enUzunIsim = current->isim;
        }
        current = current->next;
    }
    printf("En uzun isim: %s\n", enUzunIsim);
}

int main() {
    Ogrenci* head = NULL;
    int secim, numara, yas;
    char isim[50];

    do {
        printf("\n1- Ogrenci ekle\n");
        printf("2- Ogrencileri listele\n");
        printf("3- Ogrenci ara\n");
        printf("4- Ogrenci sil\n");
        printf("5- En uzun ismi yazdir\n");
        printf("6-Listeye Sayi Ekleme.\n");
        printf("0- Cikis\n");
        printf("Secim yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Ogrenci numarasi girin: ");
                scanf("%d", &numara);
                printf("Ogrenci ismi girin: ");
                scanf("%s", isim);
                printf("Ogrenci yasi girin: ");
                scanf("%d", &yas);
                head = ekle(head, numara, isim, yas);
                break;
            case 2:
                sirala(head);
                listele(head);
                break;
            case 3:
                printf("Aranacak ogrenci ismini girin: ");
                scanf("%s", isim);
                Ogrenci* aranan = ara(head, isim);
                if (aranan != NULL) {
                    printf("Numara: %d, Isim: %s, Yas: %d\n", aranan->numara, aranan->isim, aranan->yas);
                } else {
                    printf("Ogrenci bulunamadi.\n");
                }
                break;
            case 4:
                printf("Silinecek ogrenci ismini girin: ");
                scanf("%s", isim);
                head = sil(head, isim);
                break;
            case 5:
                enUzunIsim(head);
                break;
            case 6:
                addFrontorEnd();
                break;
            case 7:

                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } while (secim != 0);

    Ogrenci* current = head;
    while (current != NULL) {
        Ogrenci* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
