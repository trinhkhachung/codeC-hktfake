#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;
    int choice;
    printf("Moi nhap gia tri so hang (row) va so cot (col):\n");
    scanf("%d%d", &row, &col);

    if (row <= 0 || col <= 0) {
        printf("So hang va so cot phai lon hon 0.\n");
        return 0;
    }

    int numbers[row][col];
    int isInput = 0;

    do {
        printf("\n---------MENU---------\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In ra cac gia tri cua mang theo ma tran\n");
        printf("3. In ra cac phan tu duong bien va tinh tich\n");
        printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem 1 phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Moi nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri cac phan tu cua mang:\n");
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        printf("numbers[%d][%d] = ", i, j);
                        scanf("%d", &numbers[i][j]);
                    }
                }
                isInput = 1;
                break;

            case 2:
                if (!isInput) {
                    printf("Vui long nhap du lieu truoc.\n");
                    break;
                }
                printf("Ma tran:\n");
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        printf("%d\t", numbers[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3: {
                if (!isInput) {
                    printf("Vui long nhap du lieu truoc.\n");
                    break;
                }
                printf("Cac phan tu duong bien:\n");
                long long product = 1;
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                            printf("%d ", numbers[i][j]);
                            product *= numbers[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu duong bien: %lld\n", product);
                break;
            }

            case 4:
                if (!isInput) {
                    printf("Vui long nhap du lieu truoc.\n");
                    break;
                }
                if (row != col) {
                    printf("Chi ap dung voi ma tran vuong.\n");
                    break;
                }
                printf("Cac phan tu tren duong cheo chinh:\n");
                for (int i = 0; i < row; i++) {
                    printf("%d ", numbers[i][i]);
                }
                printf("\n");
                break;

            case 5:
                if (!isInput) {
                    printf("Vui long nhap du lieu truoc.\n");
                    break;
                }
                if (row != col) {
                    printf("Chi ap dung voi ma tran vuong.\n");
                    break;
                }
                printf("Cac phan tu tren duong cheo phu:\n");
                for (int i = 0; i < row; i++) {
                    printf("%d ", numbers[i][col - 1 - i]);
                }
                printf("\n");
                break;

            case 6:
                if (!isInput) {
                    printf("Vui long nhap du lieu truoc.\n");
                    break;
                }
                if (row != col) {
                    printf("Chi ap dung voi ma tran vuong.\n");
                    break;
                }
                int diagonal[row];
                for (int i = 0; i < row; i++) {
                    diagonal[i] = numbers[i][i];
                }
                for (int i = 0; i < row - 1; i++) {
                    for (int j = i + 1; j < row; j++) {
                        if (diagonal[i] > diagonal[j]) {
                            int temp = diagonal[i];
                            diagonal[i] = diagonal[j];
                            diagonal[j] = temp;
                        }
                    }
                }
                for (int i = 0; i < row; i++) {
                    numbers[i][i] = diagonal[i];
                }
                printf("Da sap xep duong cheo chinh tang dan.\n");
                break;

            case 7: 
			
                if (!isInput) {
                    printf("Vui long nhap du lieu truoc.\n");
                    break;
                }
                int value, found = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        if (numbers[i][j] == value) {
                            printf("Tim thay tai vi tri [%d][%d]\n", i, j);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu trong mang.\n");
                }
                break;
            

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 8);

    return 0;
}

