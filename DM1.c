#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
float a[22];
const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
/*long convertType(char* value)
{
   int i = 0;
   char ch;
   double ret = 0;
   while((ch = value[i] )!= '\0')
   {
      ret = ret*10 +(ch - '0');
      ++i;
   }
   return ret;
   
}*/

int main()
{
    FILE* fp = fopen("data.csv", "r");
    int i,flag=1,count=0;
    char line[1024];
    float x;
    while (fgets(line, 1024, fp))
    {
	if(flag==1)
	{
		continue;
	}
        char* tmp = strdup(line);
	char* te=strtok(tmp,"\"");
	for(i=0;i<4;i++)
		te=strtok(NULL,"\"");
	printf("%s",te);
	x=strtof(te,NULL);
        printf("%f\n", x);
        free(tmp);
	count++;
    }
    for(i=0;i<22;i++)
    {
	printf("%f",a[i]);
	printf(",");
	}

}
