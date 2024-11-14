#include <stdio.h>
#include <string.h>

/*
filename : 복사해서 붙여넣을 파일의 이름.
pathname : 복사할 파일의 이름.
*/
void copy_file(char* filename,char* pathname){
    /*
    input answer
    */
    FILE* fp = fopen(pathname, "r");
    FILE* fp2 = fopen(filename, "w");
    int cnt1 = 0 ,cnt2 = 0 ;
    char buf[4096];

    while(fgets(buf,4095,fp) != NULL){
        fprintf(fp2,"%s",buf);
        cnt1++;
        cnt2+=strlen(buf);
    }

    fclose(fp);
    fclose(fp2);   

    printf("Read Lines : %d\nRead letters : %d\n", cnt1, cnt2);
}

int main(){
    char filename[4096];
    char pathname[4096];
    printf("Please input pathname : ");
    scanf("%s", pathname);
    printf("Please input filename : ");
    scanf("%s", filename);

    copy_file(filename, pathname);

    return 0;
}