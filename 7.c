#include<stdio.h>
int main()
{
  FILE *fp;
  char data[100];
  fp=popen("date","r");
  if(fp==NULL)
  {
    printf("Error opening pipe\n");
    return 1;
  }
while(fgets(data,sizeof(data),fp)!=NULL)
{
  printf("Output : %s\n",data);
}
pclose(fp);
return 0;
}
