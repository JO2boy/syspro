#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,char *argv[])
{
      FILE *fp1, *fp2;
      char ch;

	  fp1 = fopen(argv[1], "r");
      if (fp1 == NULL)
      {
            puts("File does not exist..");
            exit(1);
      }
      fp2 = fopen(argv[2], "w");
      if (fp2 == NULL)
      {
            puts("File does not exist..");
            fclose(fp1);
            exit(1);
      }
      while((ch=fgetc(fp1))!=EOF)
      {
            ch = toupper(ch);
            fputc(ch,fp2);
	  }

	  fclose(fp1);
	  fclose(fp2);

      return 0;
}
