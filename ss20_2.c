#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char msp[10];
    char name[100];
    int priceN;
    int priceX;
    int soLuong;
}sanpham;
void fgetC(char *a, int length){
    fgets(a,length,stdin);
    if(strlen(a)>0&&a[strlen(a)-1]=='\n')a[strlen(a)-1]='\0';
}
void inputArr(sanpham *a, int vt){
    printf("Ma san pham: ");
    fgetC(a[vt].msp,10);
    printf("Ten san pham: ");
    fgetC(a[vt].name,100);
    printf("Gia nhap(KVND): ");
    scanf("%d",&a[vt].priceN);
    printf("Gia ban(kVND): ");
    scanf("%d",&a[vt].priceX);
    printf("So luong: ");
    scanf("%d",&a[vt].soLuong);
    getchar();
    printf("\n");
}
void swap(sanpham *ptr1, sanpham *ptr2){
    sanpham temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
void selectionSortG(sanpham *a,int size, int *c){
    for(int i=0;i<49;i++)if(c[i]){
        int x=i;
        for(int j=i+1;j<50;j++)if(c[j]&&a[j].priceX>a[x].priceX)x=j;
        swap(&a[i],&a[x]);
    }
}
void selectionSortT(sanpham *a,int size, int *c){
    for(int i=0;i<49;i++)if(c[i]){
        int x=i;
        for(int j=i+1;j<50;j++)if(c[j]&&a[j].priceX<a[x].priceX)x=j;
        swap(&a[i],&a[x]);        
    }
}
sanpham a[50];
int doanhThu,d,n,tg,vt,soLuong,c[55];
char name[100],ch;
int main(){
    do{
        printf("MENU\n1.Nhap so luong va thong tin san pham\n2.Hien thi danh sach san pham\n3.Nhap san pham\n4.Cap nhat thong tin san pham\n5.Sap xep san pham theo gia\n6.Tim kiem san pham\n7.Ban san pham\n8.Doanh thu san pham\n9.Thoat\nLua chon cua ban: ");
        scanf("%d",&d);
        getchar();
        switch(d){
            case 1:
                printf("Nhap so luong: ");
                scanf("%d",&n);
                printf("Nhap thong tin san pham:\n");
                for(int i=0;i<n;i++){
                    printf("Nhap thong tin san pham %d:\n",i+1);
                    c[i]=1;
                    inputArr(&a,i);
                }
                break;
            case 2:
                printf("                Thong tin san pham\n");
                printf("STT     Ma san pham         Ten san pham            Gia nhap        Gia xuat        So luong\n");
                for(int i=0;i<n;i++)if(c[i])printf("%2d %10s %15s %5d %5d %3d\n",i+1,a[i].msp,a[i].name,a[i].priceN,a[i].priceX,a[i].soLuong);
                break;
            case 3:
                printf("Nhap san pham: ");
                printf("Nhap ma san pham: ");
                fgetC(name,100);
                for(int i=0;i<n;i++)if(strcmp(name,a[i].msp)==0){
                    tg=1;
                    vt=i;
                }
                if(!tg)printf("Ma san pham khong ton tai!\n");
                else{
                    printf("Nhap so luong nhap hang: ");
                    scanf("%d",&soLuong);
                    getchar();
                    if(soLuong*a[vt].priceN>doanhThu)printf("Gia nhap cao hon doanh thu!\n");
                    else{
                        doanhThu -= soLuong*a[vt].priceN;
                        a[vt].soLuong+=soLuong;
                        printf("Nhap hang thanh cong!\n");
                    }
                }
                break;
            case 4:
                printf("Cap nhat thong tin san pham:\nNhap ma san pham cap nhat: ");
                fgetC(name,100);
                for(int i=0;i<n;i++)if(strcmp(name,a[i].msp)==0){
                    tg=1;
                    vt=i;
                }
                if(!tg)printf("Ma san pham khong ton tai!\n");
                else {
                    inputArr(&a,vt);
                    printf("Cap nhat thong tin thanh cong!\n");
                }
                break;
            case 5:
                do{
                    printf("a.Tang theo gia ban\nb.Giam theo gia ban\nLua chon cua ban: ");
                    scanf("%s",&ch);
                }while(ch!='a'&&ch!='b');
                if(ch=='a')selectionSortT(&a,50,&c);
                else selectionSortG(&a,50,&c);
                break;
            case 6:
                printf("Tim kiem san pham theo ma san pham\nNhap ma san pham: ");
                printf("Cap nhat thong tin san pham:\nNhap ma san pham cap nhat: ");
                fgetC(name,100);
                for(int i=0;i<n;i++)if(strcmp(name,a[i].msp)==0){
                    tg=1;
                    vt=i;
                }
                if(!tg)printf("Ma san pham khong ton tai!\n");
                else printf("Thong tin san pham ma %s:\nTen san pham: %s\nGia nhap(kVND): %d\nGia ban(kVND): %d\nSo luong: %d\n",a[vt].msp,a[vt].name,a[vt].priceN,a[vt].priceX,a[vt].soLuong);
                break;
            case 7:
                printf("Ban san pham:\nNhap ma san pham can ban: ");
                fgetC(name,100);
                for(int i=0;i<n;i++)if(strcmp(name,a[i].msp)==0){
                    tg=1;
                    vt=i;
                }
                if(!tg)printf("Ma san pham khong ton tai!\n");
                else{
                    printf("Nhap so luong can ban: ");
                    scanf("%d",&soLuong);
                    getchar();
                    if(soLuong>a[vt].soLuong)printf("Khong du hang!\n");
                    else{
                        a[vt].soLuong-=soLuong;
                        doanhThu+=soLuong*a[vt].priceX;
                        printf("Da ban thanh cong!\n");
                    }
                }
                break;
            case 8:
                printf("Doanh thu hien tai: %d\n",doanhThu);
                break;
        }
    }while(d!=9);
}