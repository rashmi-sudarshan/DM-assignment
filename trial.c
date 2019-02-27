#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long trade[24];
float tover[24];
int i=0;
void getData(char *buff);
int main()
{
	FILE *fp = fopen("data.csv","r");
        int count=0,i;
	do
	{
	 char buff[1024];
	 fgets(buff, 1024, (FILE*)fp);
	 if(fp)
	 {
      if(count==0)
      {
          count=1;
          continue;
      }
	  getData(buff);
	 }
	}while((getc(fp))!=EOF);
    
    fclose(fp);
    
    for (i=0;i<23;i++)
    {
        printf("Trade:%ld\nTurn:%f\n\n",trade[i],tover[i]);
    }
	return 1;
}
void getData(char buff[])
{
   char *token = strtok(buff,",");
   int counter=1;
 
   while( token != NULL ) 
   {
    counter++; 
    if(counter>=7)
    {
        if(counter==7) 
            trade[i]=atol(token);
        else 
            tover[i]=atof(token);
    }
      token = strtok(NULL,",");
   }	  
   i++;
}
