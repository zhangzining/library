/*
func.c
this file is main functions of system.
author:zzn;
date:2018/05/31

*/
#include "main.h"
#define N 100

void showmain(){                //show the menu
    clearscreen();
    printf("\t    Welcome to use library system    \t\n");
    printf("\t|-------[1]BOOK INFO INPUT----------|\t\n");
    printf("\t|-------[2]BOOK INFO BROWSE---------|\t\n");
    printf("\t|-------[3]BOOK INFO SEARCH---------|\t\n");
    printf("\t|-------[4]BOOK INFO CHANGE---------|\t\n");
    printf("\t|-------[5]BOOK INFO DELETE---------|\t\n");
    printf("\t|-------[6]DELETE FILE--------------|\t\n");
    printf("\t|-------[0]EXIT SYSTEM--------------|\t\n");
    printf("\n\t\t--PLEASE CHOOSE--\n");
    input =0;
    scanf("%d",&input);
    switch(input){
        case 1 :bookinput();break;
        case 2 :bookbrowse();break;
        case 3 :booksearch();break;
        case 4 :bookchange();break;
        case 5 :bookdelete();break;
        case 6 :RM();break;
        case 0 :exitsystem();break;
        default:inputerror();break;
    }
    return;
}


void clearscreen(){

    system("clear");
    return;
}
//file deal
void INIT(){
    /*FILE *fp2;   //here used file operating
    if((fp2=fopen("library.txt","wb"))==NULL){
        printf("FILE OPEN ERROR!\n");
        exit(0);
    }
    fclose(fp2);
    */
    system("touch library.txt");
    fileexist=1;
    return;
}
void READ(){
    FILE *fp1;
    int i;
    if((fp1=fopen("library.txt","rb"))==NULL){
        printf("FILE OPEN ERROR!\n");
        printf("\tWould you build a new file?\n");
        yesorno();
        if(input){
            INIT();
        }else{
            return;
        }
    }
    if(fileexist){
        fp1=fopen("library.txt","rb");
    }
    //for(i=1;!feof(fp1);i++){
    //    fread(&book[i],sizeof(book[i]),1,fp1);
    //}
    
    i=0;
    do{
        
        fread(&book[i],sizeof(book[i]),1,fp1);
        i++;
    }while(!feof(fp1));

    sum=i-1;

    fclose(fp1);
    fileexist=1;
    return;
}
void WRITE(){
    FILE *fp3;
    int j;
    if((fp3=fopen("library.txt","wb"))==NULL){
        printf("FILE WRITE ERROR!\n");
        exit(0);
    }
    //for(j=1;j<sum;j++){
    //    fwrite(&book[j],sizeof(book[j]),1,fp3);
    //}
    j=0;
    
    do{
        
        fwrite(&book[j],sizeof(book[j]),1,fp3);
        j++;
    }while(j<sum);
    
    //for(j=0;j<sum+0;j++){
    //    fwrite(&book[j],sizeof(book[j]),1,fp3);
    //}
    fclose(fp3);
    return;
}

//main functions
void bookinput(){
    READ();
    clearscreen();
    input=1;
    while(input){
        
        printf("\n\t    BOOK INPUT FUNCTION    \t\n");
        printf("\t There are %d books in system",sum);
        
        printf("\n\tplease input book num:");
        scanf("%d",&book[sum].booknum);
        printf("\n\tplease input book name:");
        scanf("%s",book[sum].bookname);
        printf("\n\tplease input auther's name:");
        scanf("%s",book[sum].auther);
        printf("\n\tplease input publisher:");
        scanf("%s",book[sum].publisher);
        printf("\n\tplease input publishtime:");
        scanf("%s",book[sum].publishtime);
        printf("\n\tplease input book price:");
        scanf("%s",book[sum].price);
        printf("\n \t Would you continue input infor?\n");
        sum++;
        WRITE();
        yesorno();
    }
    return;
}
void bookbrowse(){
    READ();
    clearscreen();
    int i=0;
    printf("\n\t    BOOK BROWSE FUNCTION   \t\n");
    printf("\t There are %d books in system\n",sum);
    for(i=0;i<sum;i++){
        printf("\n\tbook number:%d\n",book[i].booknum);
        printf("\tbook name:%s\n",book[i].bookname);
        printf("\tbook auther:%s\n",book[i].auther);
        printf("\tbook publisher:%s\n",book[i].publisher);
        printf("\tbook publishtime:%s\n",book[i].publishtime);
        printf("\tbook price:%s\n\n",book[i].price);
    }
    do{
    printf("\t|-------[0]RETURN MENU----------|\t\n");
    scanf("%d",&input);
    }while(input);
        
    return;
}
void booksearch(){
    READ();
    clearscreen();
    int i=0;
    int temp=0;
    while(input){
        clearscreen();
        printf("\n\t    BOOK SEARCH FUNCTION   \t\n");
        printf("\t There are %d books in system\n",sum);
        printf("\n\tplease input which item would you use\t\n");
        printf("\t|----------[1]BOOK NUMBER-----------|\t\n");
        printf("\t|----------[2]BOOK NAME-------------|\t\n");
        printf("\t|----------[3]BOOK AUTHOR-----------|\t\n");
        printf("\t|----------[4]BOOK PUBLISHER--------|\t\n");
        printf("\t|----------[5]BOOK PUBLISHTIME------|\t\n");
        printf("\t|----------[6]BOOK PRICE------------|\t\n");
        printf("\n\t\t--PLEASE CHOOSE--\n");
        input =0;
        scanf("%d",&input);
        printf("\tplease input your keyword:");
        if(input==1){
            scanf("%d",&temp);
        }else{
            scanf("%s",keywords);
        }
        for(i=0;i<sum;i++){
        switch(input){
            case 1 :if(temp==book[i].booknum)showbook(i);break;
            case 2 :if(strcmp(keywords,book[i].bookname)==0)showbook(i);break;
            case 3 :if(strcmp(keywords,book[i].auther)==0)showbook(i);break;
            case 4 :if(strcmp(keywords,book[i].publisher)==0)showbook(i);break;
            case 5 :if(strcmp(keywords,book[i].publishtime)==0)showbook(i);break;
            case 6 :if(strcmp(keywords,book[i].price)==0)showbook(i);break;
            default:printf("error!");break;
            }        
        }   
        printf("\n \t Would you continue search infor?\n");        
        yesorno();
    }
    return;
}
void showbook(int a){
        printf("\n\tbook number:%d\n",book[a].booknum);
        printf("\tbook name:%s\n",book[a].bookname);
        printf("\tbook auther:%s\n",book[a].auther);
        printf("\tbook publisher:%s\n",book[a].publisher);
        printf("\tbook publishtime:%s\n",book[a].publishtime);
        printf("\tbook price:%s\n\n",book[a].price);    
    return;
}
void bookchange(){
    READ();
    clearscreen();
    int i=0;
    int j=0;
    int temp=0;
    while(input){
        clearscreen();
        printf("\n\t    BOOK CHANGE FUNCTION   \t\n");
        printf("\t There are %d books in system\n",sum);
        printf("\n\tplease input booknumber:");
        scanf("%d",&i);
        for(j=0;j<sum;j++){
            if(book[j].booknum==i){
                i=j;
                break;
            }
        }
        showbook(i);
        printf("\n\tplease input which item would you change\t\n");
        printf("\t|----------[1]BOOK NUMBER-----------|\t\n");
        printf("\t|----------[2]BOOK NAME-------------|\t\n");
        printf("\t|----------[3]BOOK AUTHOR-----------|\t\n");
        printf("\t|----------[4]BOOK PUBLISHER--------|\t\n");
        printf("\t|----------[5]BOOK PUBLISHTIME------|\t\n");
        printf("\t|----------[6]BOOK PRICE------------|\t\n");
        printf("\n\t\t--PLEASE CHOOSE--\n");
        input =0;
        scanf("%d",&input);
        printf("\tplease input what you want to insert:");
        if(input==1){
            scanf("%d",&temp);
        }else{
            scanf("%s",keywords);
        }
        switch(input){
            case 1:book[i].booknum=temp;break;
            case 2:strcpy(book[i].bookname,keywords);break;
            case 3:strcpy(book[i].auther,keywords);break;
            case 4:strcpy(book[i].publisher,keywords);break;
            case 5:strcpy(book[i].publishtime,keywords);break;
            case 6:strcpy(book[i].price,keywords);break;
            default:break;
        } 
        WRITE();  
        printf("\n \t Would you continue change infor?\n");        
        yesorno();
    }
    return;
}
void bookdelete(){
    READ();
    clearscreen();
    int i=0;
    int j=0;
    int k=0;
    int temp=0;
    while(input){
        clearscreen();
        printf("\n\t    BOOK DELETE FUNCTION   \t\n");
        printf("\t There are %d books in system\n",sum);
        printf("\n\tplease input booknumber:");
        scanf("%d",&i);
        k=i;
        for(j=0;j<sum;j++){
            if(book[j].booknum==i){
                i=j;
                showbook(i);
                printf("\n\tAre you sure to delete NO:%d book??\t\n",k);
                yesorno();
                if(input==1){
                    for(;i<sum-1;i++){
                    book[i].booknum=book[i+1].booknum;
                    strcpy(book[i].bookname,book[i+1].bookname);
                    strcpy(book[i].auther,book[i+1].auther);
                    strcpy(book[i].publisher,book[i+1].publisher);
                    strcpy(book[i].publishtime,book[i+1].publishtime);
                    strcpy(book[i].price,book[i+1].price);
                    }
                    sum--;
                }
                WRITE();
                break;
            }else{
                i=-1;
            }
        }
        if(i==-1){
            printf("\n\t No such book!!\n");
        }

        printf("\n \t Would you continue delete infor?\n");        
        yesorno();
    }
    return;
}
void exitsystem(){
    clearscreen();
    printf("\n\t\t--DO YOU WANT QUIT?--\n");
    yesorno();
    if(input){
        printf("\n\t\t--THANKS FOR USING--\n");
        flag=0;
    }
    return;
}
void inputerror(){
    printf("\n\t\t--PLEASE TRY AGAIN---\n");
    return;
}
void yesorno(){
    printf("\t|--------------[1]YES----------------|\t\n");
    printf("\t|--------------[0]NO-----------------|\t\n");
    printf("\n\t\t--PLEASE CHOOSE--\n");
    input=0;
    scanf("%d",&input);
    return;
}
void firsttime(){
    clearscreen();
    printf("\tThe file is empty,would you input it?\t\n");
    yesorno();
    if(input){
        bookinput();
    }else{
        return;
    }
    return;
}
void RM(){
    system("rm library.txt");
    return;
}
