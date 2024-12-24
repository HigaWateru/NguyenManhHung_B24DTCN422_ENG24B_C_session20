#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char id[10];
    char name[100];
    char tg[100];
    int price;
}bookMark;
bookMark a[500];
void fgetC(char *a, int length){
    fgets(a,length,stdin);
    if(strlen(a)>0&&a[strlen(a)-1]=='\n')a[strlen(a)-1]='\0';
}
void swap(bookMark *ptr1, bookMark *ptr2){
    bookMark temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
void selectionSortG(bookMark *a,int size, int *c){
    for(int i=0;i<499;i++)if(c[i]){
        int x=i;
        for(int j=i+1;j<100;j++)if(c[j]&&a[j].price>a[x].price)x=j;
        swap(&a[i],&a[x]);
    }
}
void selectionSortT(bookMark *a,int size, int *c){
    for(int i=0;i<499;i++)if(c[i]){
        int x=i;
        for(int j=i+1;j<100;j++)if(c[j]&&a[j].price<a[x].price)x=j;
        swap(&a[i],&a[x]);        
    }
}
void inputArr(bookMark *a, int vt){
    printf("Ma sach %d: ",vt+1);
    fgetC(&a[vt].id,10);
    printf("Ten sach: ");
    fgetC(&a[vt].name,100);
    printf("Tac gia: ");
    fgetC(&a[vt].tg,100);
    printf("Gia tien: ");
    scanf("%d",&a[vt].price);
    getchar();
    printf("\n");
}
char name[50],ch;
int c[505],d,n,vt,tg;
int main(){
    do{
        printf("MENU\n1.Nhap so luong va thong tin sach\n2.Hien thi thong tin gia sach\n3.Them thong tin sach\n4.Xoa sach theo ma sach\n5.Cap nhat thong tin theo ma sach\n6.Sap xep sach theo gia\n7.Tim kiem thong tin theo ten sach\n8.Thoat\nLua chon cua ban: ");
        scanf("%d",&d);
        getchar();
        switch (d)
        {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d",&n);
                getchar();
                printf("\n");
                for(int i=0;i<n;i++){
                    inputArr(&a, i);
                    c[i]=1;
                }
                break;
            case 2:
                printf("            Thong tin sach\n");
                printf("STT  Ma sach          Ten sach            Tac gia     Gia tien\n");
                for(int i=0;i<500;i++)if(c[i])printf("%3d %8s %22s%15s     %4d\n",i+1,a[i].id,a[i].name,a[i].tg,a[i].price);
                break;
            case 3:
                printf("Them sach:\nNhap vi tri sach: ");
                scanf("%d",&vt);
                getchar();
                if(vt<=0||vt>500)printf("Vi tri khong ton tai trong danh sach!\n");
                else if(c[vt-1])printf("Vi tri da co thong tin sach!\n");
                else{
                    vt--;
                    c[vt]++;
                    inputArr(&a, vt);
                }
                break;
            case 4:
                printf("Nhap ma sach can xoa: ");
                tg=0;
                fgetC(name,50);
                for(int i=0;i<500;i++)if(strcmp(a[i].id,name)==0){
                    tg=1;
                    c[i]=0;
                    printf("Da xoa thong tin ma sach %s!\n",a[i].id);
                    break;
                }
                if(!tg)printf("Ma sach khong ton tai trong danh sach!\n");
                break;
            case 5:
                printf("Tim kiem thong tin theo ma sach: ");
                fgetC(name,50);
                tg=0;
                for(int i=0;i<500;i++)if(strcmp(a[i].id,name)==0&&c[i]){
                    tg=1;
                    vt=i;
                    break;
                }
                if(!tg)printf("Ma sach khong ton tai trong danh sach!\n");
                else{
                    printf("Cap nhat thong tin ma sach %s:\n",a[vt].id);
                    printf("Ten sach: ");
                    fgetC(a[vt].name,100);
                    printf("Tac gia: ");
                    fgetC(a[vt].name,100);
                    printf("Gia tien (kVND): ");
                    scanf("%d",&a[vt].price);
                    printf("Cap nhat thong tin thanh cong!\n");
                }
                break;
            case 6:
                do{
                    printf("a.Tang theo gia\nb.Giam theo gia\nLua chon cua ban: ");
                    scanf("%s",&ch);
                }while(ch!='a'&&ch!='b');
                if(ch=='a')selectionSortT(&a,500,&c);
                else selectionSortG(&a,500,&c);
                break;
            case 7:
                printf("Nhap ten sach muon tim kiem: ");
                fgetC(name,100);
                tg=0;
                for(int i=0;i<500;i++)if(strcmp(name,a[i].name)==0){
                    tg=1;
                    printf("Thong tin ten sach %s:\nMa sach: %s\nTac gia: %s\nGia tien: %dkVND\n",a[i].name,a[i].id,a[i].tg,a[i].price);
                    break;
                }
                if(!tg)printf("Khong co ten sach trong danh sach!\n");
                break;
        default:
            break;
        }
    }while(d!=8);
}
