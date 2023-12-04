#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CD 100

struct CD {
    int id;
    char name[50];
    float duration;
    char content[100];
    bool status;
};

void printCDList(struct CD cdList[], int count) {
    printf("Danh sach CD:\n");
    for (int i = 0; i < count; i++) {
        printf("CD %d:\n", i + 1);
        printf("ID: %d\n", cdList[i].id);
        printf("Name: %s\n", cdList[i].name);
        printf("Duration: %.2f\n", cdList[i].duration);
        printf("Content: %s\n", cdList[i].content);
        printf("Status: %s\n", cdList[i].status ? "Tim thay" : "Khong tim thay");
        printf("-----------------------\n");
    }
}

void addCD(struct CD cdList[], int *count) {
    struct CD newCD;
    printf("Nhap thong tin CD moi:\n");
    printf("ID: ");
    scanf("%d", &newCD.id);
    printf("Name: ");
    scanf("%s", newCD.name);
    printf("Duration: ");
    scanf("%f", &newCD.duration);
    printf("Content: ");
    scanf("%s", newCD.content);
    printf("Status (1: Tim thay, 0: Khong tim thay): ");
    scanf("%d", &newCD.status);

    cdList[*count] = newCD;
    (*count)++;
}

void updateCD(struct CD cdList[], int count) {
    char searchName[50];
    printf("Nhap ten CD can chinh sua: ");
    scanf("%s", searchName);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(cdList[i].name, searchName) == 0) {
            printf("Nhap thong tin CD moi:\n");
            printf("ID: ");
            scanf("%d", &cdList[i].id);
            printf("Name: ");
            scanf("%s", cdList[i].name);
            printf("Duration: ");
            scanf("%f", &cdList[i].duration);
            printf("Content: ");
            scanf("%s", cdList[i].content);
            printf("Status (1: Available, 0: Not Available): ");
            scanf("%d", &cdList[i].status);

            printf("Da cap nhat thong tin cho CD co ten %s\n", searchName);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay CD co ten %s\n", searchName);
    }
}

void deleteCD(struct CD cdList[], int *count) {
    char searchName[50];
    printf("Nhap ten CD can xoa: ");
    scanf("%s", searchName);

    bool found = false;
    for (int i = 0; i < *count; i++) {
        if (strcmp(cdList[i].name, searchName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                cdList[j] = cdList[j + 1];
            }
            (*count)--;
            printf("Da xoa CD co ten %s\n", searchName);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay CD co ten %s\n", searchName);
    }
}

void insertionSort(struct CD cdList[], int count) {
    for (int i = 1; i < count; i++) {
        struct CD key = cdList[i];
        int j = i - 1;
        while (j >= 0 && cdList[j].duration > key.duration) {
            cdList[j + 1] = cdList[j];
            j--;
        }
        cdList[j + 1] = key;
    }
}

int binarySearch(struct CD cdList[], int count, char searchName[]) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = strcmp(cdList[mid].name, searchName);

        if (result == 0) {
            return mid;
        } else if (result < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


int main() {
    struct CD cdList[MAX_CD];
    int cdCount = 2;

    struct CD cd1 = {1, "CD1", 4.5, "Music", true};
    struct CD cd2 = {2, "CD2", 3.2, "Movie", false};
    cdList[0] = cd1;
    cdList[1] = cd2;

    int choice;
    do {
        printf("************************MENU**************************\n");
		printf("1. In toan bo danh sach cd cos trong mang cdList\n");
		printf("2. Thuc hien chuc nang them moi cd vao vi tri cuoi cung cua cdList\n");
		printf("3. Thuc hien chua nang cap nhap thong tin cau mot cd. Nhap vao vao ten cua cd can chinh sua \n");
		printf("4. Thuc hien chuc nang xoa mot cd. Nhap vao ten cd muon xoa\n");
		printf("5. Thuc hien chuc nang sap xep , in ra danh sach cdList da duoc sap xep tang dan\n");
		printf("6. Thuc hien chuc nang tim kiem vaf in ra thong tin cua cd\n");
		printf("7. Thuc hhien chuc nang tim kiem va in ra toan bo thong tin cua cac cd theo status\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printCDList(cdList, cdCount);
                break;
            case 2:
                addCD(cdList, &cdCount);
                break;
            case 3:
                updateCD(cdList, cdCount);
                break;
            case 4:
                deleteCD(cdList, &cdCount);
                break;
            case 5:
                insertionSort(cdList, cdCount);
                printf("Danh sach CD sau khi sap xep:\n");
                printCDList(cdList, cdCount);
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}