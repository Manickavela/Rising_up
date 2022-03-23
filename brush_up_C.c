#include <stdio.h>
#include <string.h>



int* get_array();


int main()
{
	printf("Basic Strings\n");
	printf("=============\n");

	char str[] = "string trails";
	char str2[] = "";

	strcpy(str2,str);
	printf("%s\n",str);
	printf("%s\n",str2);

	puts(str);

	printf("\n\nPointers\n");
	printf("========\n");

	double num = 2.71;
	double *pnum = &num;

	printf("num                : %f\n",num);
	printf("num address        : %p\n",&num);
	printf("num pointer valuie : %p\n",pnum);
	printf("num pointer        : %f\n",*pnum);

	double num2 = 5;
	double *pnum2 =  &num2;

	printf("\n\nAt num2            : %f\n",num2);
	printf("*pnum + *pnum2     : %f\n",*pnum+*pnum2);

	/*
	int numint = 4;
	int *pnumint = &numint;
	//pnum = (int*)pnum;
 	pnum = pnumint;
	printf("pnumint            : %p\n",pnumint);
	printf("type casted pointer: %f\n",*pnum);
	*/
	
	

	
	//Calling a function to demonstrate scope of the pointer variables  
	int *num_ar = get_array();
	//printf("%d",*num_ar);  //Segmentation fault

	printf("\n\n\n");
	printf("Size : %ld\n",sizeof(str));
	printf("Size : %ld\n",sizeof(str2));
	printf("Size : %ld\n",sizeof(num));
	printf("Size : %ld\n",sizeof(*pnum2));
	printf("Size : %ld\n",sizeof(num_ar));

	printf("\n\n\n");
	printf("Array and Pointers\n");
	printf("==================\n");
	int ar[5] = {1,2,3,4,5};
	int *p = ar;
	printf("ar         : %p\n",ar);
	printf("p          : %p\n",p);
	printf("*p         : %d\n",*p);
	printf("*(p+1)     : %d\n",*(p+1));
	printf("*(P+3)     : %d\n",*(p+3));
	printf("*(P+3)     : %d\n",*(p+3));
	
	
	printf("\n\n\n");
	printf("String Utility functions\n");
	printf("==================\n");

	char str_1[] = "How is it working";
	char str_2[] = "12345678998765432";
	char str_3[] = "";

	printf("strcpy(str_3,str_1)      : \n");//*
	strcpy(str_3,str_1);
	printf("str1      : %s\n",str_1);
	printf("str2      : %s\n",str_2);
	printf("str3      : %s\n",str_3);
	strcat(str_1,str_2);
	printf("strcat(str_1,str_2)      : \n");
	printf("str1      : %s\n",str_1);
	printf("str2      : %s\n",str_2);
	printf("str3      : %s\n",str_3);


	printf("\n\n\n");
	printf("Pointer of Pointers\n");
	printf("==================\n");
	num = 3;
	pnum = &num ;
	double **ppnum = &pnum ;
	printf("num                : %f\n",num);
	printf("num address        : %p\n",&num);
	printf("num pointer valuie : %p\n",pnum);
	printf("num pointer        : %f\n",*pnum);
	printf("pointer to  pointer: %f\n",**ppnum);

	printf("\n\n\n");
	printf("Void Pointers\n");
	printf("==================\n");

	int val = 5;
	float fval = 6.71;
	void* vp = &val;
	int* intp;
	float* floatp;
	printf("val                : %d\n",val);
	printf("fval               : %f\n"	,fval);
	//printf("val in vp          : %d",*vp);   ERROR
	intp = (int*)vp;
	printf("val int intvp      : %d\n",*intp);
	vp = &fval;
	floatp = (float*)vp;
	printf("val int intvp      : %f\n",*floatp);

	return 0;
}

int* get_array() 
{
	int ar[] = {1,2,3};
	return ar;
}
