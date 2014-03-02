#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//minor change
int main(int argc, char ** argv)
{
	FILE * in, * out;

	if(argc == 1)
	{
		in = stdin; 
		out = stdout;
	}
	else if( argc == 2)
	{
		in = fopen( argv[1], "r");
		out = stdout;
	}
	else
	{
		in = fopen( argv[1], "r");
		out = fopen ( argv[2], "w");
	}
	 
	char c;
	int indent = 0;
  
	while((c = fgetc(in)) != EOF)
	{	

	   if(c == '{') {
	   	fprintf(out, "%c", c);
		indent += 2;
	        fprintf(out, "\n");
		fprintf(out,"%*s", indent, " ");		
	    }
	   else if(c == '}') {
	   	indent -= 2;
                fprintf(out, "\n");
		fprintf(out,"%*s", indent, " ");	
	   	fprintf(out, "%c", c);
	   }	
	   else if(c == ',') {	
	   	fprintf(out, "%c", c);
		fprintf(out, "\n");
		fprintf(out,"%*s", indent, " ");
	    }
	    else if(c == '[') {
	   	fprintf(out, "%c", c);
		indent += 2;		
		fprintf(out, "\n");
		fprintf(out,"%*s", indent, " ");
	    }
	    else if(c == ']') {
	        indent -=2 ;
	   	fprintf(out, "%c", c);
		fprintf(out, "\n");
		fprintf(out,"%*s", indent, " ");
	    }
	    else
		fprintf(out, "%c", c);
	}
}


