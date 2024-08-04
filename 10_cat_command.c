//simulate CAT cmd (VIEW only)
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char *argv[])
{
FILE *fp;
char ch;
if(argc<2)
{
printf("File not entered");
exit(1);
}
fp=fopen(argv[1],"r");
if(fp==NULL)
{
printf("File does not exist\n");
exit(1);
}
while((ch=fgetc(fp))!=EOF)
printf("%c",ch);
fclose(fp);
printf("\n");
}