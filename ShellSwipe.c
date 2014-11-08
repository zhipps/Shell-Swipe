#include <stdio.h>

#define IDLENGTH 25
#define AUTHORIZED_USER_COUNT 5

char AuthorizedID[IDLENGTH]; //[AUTHORIZED_USER_COUNT]
char TestID[IDLENGTH];
int authorized=0;

int main ()
{
	//fill in TestID[] and AuthorizedID[] with '0's
	int i=0;
	for(i=0; i<IDLENGTH;i++)
	{
		TestID[i]='0';
		AuthorizedID[i]='0';
	}
	
	//Create FILE variable for reading in the authorized user IDs
	FILE *AuthorizedIDFile;
	AuthorizedIDFile = fopen("AuthorizedIDFile.txt", "r");
	
	//Read in the authorized user IDs and store them in AuthorizedID[][]
	fscanf(AuthorizedIDFile,"%s",AuthorizedID);
	fclose(AuthorizedIDFile);
	printf("Here's a list of authorized IDs:\n");
	for(i=0; i<IDLENGTH;i++)
		printf("%c",AuthorizedID[i]);
	printf("\n");
	
	
	while(1)
	{
		
		//Read from stdio (magnetic card reader) the test user ID
		printf("Please swipe your student ID card\n");	
		scanf("%s",TestID);	
	
		//Check TestID[] against the list of AuthorizedID[]		
		for(i=0; i<IDLENGTH;i++)
		{			
			if(TestID[i] != AuthorizedID[i])
			{	
				printf("AuthID[%d]=%c\n",i,AuthorizedID[i]);
				printf("TestID[%d]=%c\n",i,TestID[i]);
				authorized=0;
				break; 
			}
			else
				authorized=1; 
		}
	
		//print whether or not the user is authorized
		if(authorized)
			printf("Authorized User\n");
		else
			printf("Unauthorized User!\n");
	}
		
	printf("\n");

return 0; 
}


