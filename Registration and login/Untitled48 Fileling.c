#include<stdio.h>
#include<string.h>
// admin username admin.
// admin password 123.
void login(char* namee,char* passe);
void registeration(char* name,char* pass);
int main(){
	char n1[10],n2[10];
	char namee[50],passe[50],name[50],pass[50];
	printf(" Do you have an account \n");
	scanf("%s",&n1);
	getchar();//to discard newline it comes when we press enter. if we dont put getchar in registration both question will come together.
	if(strcmp(n1,"no")==0||strcmp(n1,"n")==0){
		registeration(name,pass);
	}
	else{
		login(namee,passe);
	}
	
	return 0;
}
void login(char* namee,char* passe){
char content[1000],name[50],pass[50];
int n;
char n1[50];
char n2[50];
FILE* fptr;
printf(" 1) Admin \n 2) Customer \n");
scanf("%d",&n);
getchar();
    if(n==2){
    printf(" Enter Username \n");
	fgets(namee,50,stdin);
	namee[strcspn(namee,"\n")]='\0';
	printf(" Enter Password \n");
	fgets(passe,50,stdin);
	passe[strcspn(passe,"\n")]='\0';
    fptr=fopen("customer.txt","r");
    int found=0;
if(fptr!=NULL){
	while(fgets(content,sizeof(content),fptr)){// we write stdin in fgets when we read input directly from keyboard but when write fptr means pointer of file to get input from file.
	    sscanf(content, "%s %s",name,pass);// seperates the content into name and pass
		if(strcmp(namee,name)==0 && strcmp(passe,pass)==0){
			printf(" welcome Customer \n");
			found=1;
			break;
		}
	}
	if(found!=1){
		printf(" Wrong credentials \n");
	}
	fclose(fptr);
}
else{
	printf(" File open unsuccessful \n");
}	
}

else if(n==1){
	printf(" Enter Username \n");
	scanf("%s",&n1);
	printf(" Enter Password \n");
	scanf("%s",&n2);
	if(strcmp(n1,"admin")==0 && strcmp(n2,"123")==0){
		printf(" Welcome Admin \n");
	}
	else{
		printf(" Admin failed to login \n");
	}
}

}
/* Here i created void fucntion because i dont need to return it to read data from file. actually i created a function here which handles the transfer 
of data in file so in main whenever i want to use this data i will call function and i will use it for example read it append more data etc. Also in function parameters
i used (char* name) actually this pointer also behave as array notation like this [] but you need to define size in fgets so that it completes in array form 
both will work.*/
void registeration(char* name,char* pass){
	FILE* fptr;
	printf(" Set Username \n");
	fgets(name,50,stdin);
	name[strcspn(name,"\n")]='\0';
	printf(" Set Password \n");
	fgets(pass,50,stdin);
	pass[strcspn(pass,"\n")]='\0';// count strlen before specified character here \n
	fptr=fopen("customer.txt","a");
	if(fptr!=NULL){
	fprintf(fptr, "%s %s\n",name,pass);
	printf(" Registeration successful \n");	
	}
	else{
		printf(" Registeration unsuccessful \n");
	}
	fclose(fptr);
}