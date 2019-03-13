#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>

#pragma region FUNCTION PROTOTYPES
void search(FILE *Ptr);
void registernoileara(FILE* Ptr,struct pbook kisi );
void isimleara(FILE *Ptr);
void soyadlaara(FILE *Ptr);
void mobileileara(FILE *Ptr);
void evnoileara(FILE *Ptr);
void isnoileara(FILE *Ptr);
void dogumtarihiileara(FILE *Ptr);
void adresileara(FILE *Ptr);

void deleteperson(FILE *Ptr);
void isimlearasil(FILE* Ptr,struct pbook silici,char *isim,char *soyad );
void registernoilearasil(FILE* Ptr,struct pbook silici,char *kayitno );
void komplesil(FILE *Ptr);

void menufunction(FILE* Ptr);
void addperson(FILE *Ptr);
void update(FILE *Ptr);
void viewpbook(FILE *Ptr);

bool is_int(char const* p);
bool regnocontrol(char *regno,FILE *Ptr);
bool areyousure(char* str);
#pragma endregion


struct pbook
	{		
		char kayitno[20];
		char ceptel[20];
		char ad[20];
		char soyad[20];
		char evtel[20];
		char istel[20];
		char dogum[20];
		char adres[30];

	};

void main()
{	
	FILE *Ptr;
	errno_t err;
	char mode[4] = "rb+";
	err = fopen_s(&Ptr,"PBOOK.DB", mode);	 // ZERO IF SUCCESSFUL, NON-ZERO IF UNSUCCESSFUL
	if(NULL != err)
	printf("ERROR IN OPENING FILE"); 
	else
	{			
			if(strcmp(mode,"rb+") != NULL)
			{
				struct pbook starter = {"*","","","","","","",""};
				for (int i = 1; i < 10000; i++)
				fwrite(&starter,sizeof(struct pbook),1,Ptr);	
			}

		    menufunction(Ptr);			
			fclose(Ptr);

	}
	getch();

}

bool is_int(char const* p)
{
	char x[20] = {0};
	itoa(atoi(p),x,10);
    return strcmp(x, p) == 0;
}
void menufunction(FILE* Ptr)
{
	system("CLS");
	char menusecimi;
	printf("_______________________________________________\n");	
	printf("***************PHONE BOOK**********************\n"
		   "************** BY TAYFUN ADAKOGLU**************");
		printf("\n_______________________________________________");
	printf("\n|||||1 - ADD NEW CONTACT"
			"\n|||||2 - DELETE CONTACT "
			"\n|||||3 - UPDATE A CONTACT"
			"\n|||||4 - SEARCH "
			"\n|||||5 - VIEW PHONEBOOK"
			"\n|||||6 - QUIT"
			"\n|||||? : ");

	fflush(stdin);
	scanf_s("%c", &menusecimi);		
	switch(menusecimi)
			{
				case '1': addperson(Ptr); break; 
				case '2': deleteperson(Ptr); break;
				case '3': update(Ptr); break;  
				case '4': search(Ptr);  break;  
				case '5': viewpbook(Ptr); break;
				case '6': fclose(Ptr);
						  exit(0); break;
				default:
								printf("\n_______________________________________________");
								printf("\n		    	           ");
								printf("W");
								_sleep(80);
								printf("R");
								_sleep(80);
								printf("O");
								_sleep(80);
								printf("N");
								_sleep(80);
								printf("G");
								_sleep(80);
								printf(" ");
								_sleep(80);
								printf("C");
								_sleep(80);
								printf("H");
								_sleep(80);
								printf("O");
								_sleep(80);
								printf("I");
								_sleep(80);
								printf("C");
								_sleep(80);
								printf("E");							
								_sleep(1200);	
								menufunction(Ptr);
								break;	
					
			} 	

} 
bool areyousure(char* str)
{
						
						char choice;
						printf("\n_______________________________________________\n");
						printf("%s",str);
						printf("\nYes(Y) or No(N):");
						fflush(stdin);
						scanf_s("%c", &choice);
						choice = toupper(choice);

						if(choice == 'Y')
						{
							return true;
						}
						else
						{
							return false;
						}
}

bool regnocontrol(char *regno,FILE *Ptr)
{
	rewind(Ptr);
	struct pbook kisi;
	while (!feof(Ptr)) 
			{
				fread(&kisi,sizeof(struct pbook), 1, Ptr);
				if(strcmp(regno,"*") != NULL)
					{
						if(atoi(kisi.kayitno) == atoi(regno))
						return true;
					}

			}
	return false;
}
void addperson(FILE *Ptr)
{	
		system("cls");
		struct pbook kisi;
		struct pbook test;
		printf("_______________________________________________\n");		
		printf("***************ADD PERSON**********************");
		printf("\n_______________________________________________");	
	
			printf("\n\tRegister NO #");
			fflush(stdin);  gets(kisi.kayitno);
			fseek( Ptr, (atoi(kisi.kayitno)) * sizeof( struct pbook ), SEEK_SET );
			fread(&test,sizeof(struct pbook),1,Ptr);

			while (true ) // strcmp(test.kayitno,"*") != NULL
			{		
						
					    if(atoi(kisi.kayitno) > 10000 || atoi(kisi.kayitno) < 0)
						{
							printf("\tYou must enter a no between 0-10000");
							printf("\n\tRegister NO #");
					
							gets(kisi.kayitno);
							fseek( Ptr, (atoi(kisi.kayitno)) * sizeof( struct pbook ), SEEK_SET );
							fread(&test,sizeof(struct pbook),1,Ptr);
						}
						else if(strcmp(test.kayitno, "*") != NULL)
						{							
							printf("\tThis was found in database,try again");
							printf("\n\tRegister NO #");
							 gets(kisi.kayitno);
							fseek( Ptr, (atoi(kisi.kayitno)) * sizeof( struct pbook ), SEEK_SET );
							fread(&test,sizeof(struct pbook),1,Ptr);	  	
						}
						else if(strlen(kisi.kayitno) == 0)
						{
							printf("\tYou didn't enter an register!");
							printf("\n\tRegister NO #");
							gets(kisi.kayitno);
							fseek( Ptr, (atoi(kisi.kayitno)) * sizeof( struct pbook ), SEEK_SET );
							fread(&test,sizeof(struct pbook),1,Ptr);
						}
						else if(!is_int(kisi.kayitno))
						{
							printf("\tRegister no must be a number, not string!");
							printf("\n\tRegister NO #");
							gets(kisi.kayitno);
							fseek( Ptr, (atoi(kisi.kayitno)) * sizeof( struct pbook ), SEEK_SET );
							fread(&test,sizeof(struct pbook),1,Ptr);
						}
					    else if(atoi(kisi.kayitno) < 10000 && atoi(kisi.kayitno) > 0 && strcmp(test.kayitno, "*") == NULL && is_int(kisi.kayitno) == TRUE)
						break;
						
			}		   
		

		fflush(stdin);
		printf("\tMobile Phone Number #");		
		gets(kisi.ceptel);
	    while(strlen(kisi.ceptel) == 0)
		{
			printf("\tYou didn't enter a mobile no!\n");
			printf("\tMobile Phone Number #");		
			gets(kisi.ceptel);
		}
		printf("\tPerson Name :");
		gets(kisi.ad);
		while(strlen(kisi.ad) == 0)
		{
			printf("\tYou didn't enter a name!\n");
			printf("\tPerson Name  #");		
			gets(kisi.ad);
		}
		printf("\tPerson Surname :");
		gets(kisi.soyad);
		printf("\tHome Number #");
		gets(kisi.evtel);
		printf("\tBusiness Number #");
		gets(kisi.istel);
		printf("\tBirth Date with '.' #");
		gets(kisi.dogum);
		printf("\tPerson Address :");
		gets(kisi.adres);
			fseek( Ptr, ( atoi(kisi.kayitno) ) * sizeof( struct pbook ), SEEK_SET );
			fwrite( &kisi, sizeof( struct pbook ), 1, Ptr );
			printf("\n_______________________________________________");
			printf("\n		    	     ");
			printf("S");
			_sleep(100);
			printf("u");
			_sleep(100);
			printf("c");
			_sleep(100);
			printf("c");
			_sleep(100);
			printf("e");
			_sleep(100);
			printf("s");
			_sleep(100);
			printf("s");
			_sleep(100);
			printf("f");
			_sleep(100);
			printf("u");
			_sleep(100);
			printf("l");
			_sleep(100);
			printf("l");
			_sleep(100);
			printf("y");
			_sleep(100);
			printf(" ");
			_sleep(100);
			printf("A");
			_sleep(100);
			printf("d");
			_sleep(100);
			printf("d");
			_sleep(100);
			printf("e");
			_sleep(100);
			printf("d");
			printf("");
			_sleep(99);		

		if(areyousure("Do you want to add another one?"))
		addperson(Ptr);	
		else
		menufunction(Ptr);
		
		

					
}

//////////////////////////////////
void deleteperson(FILE *Ptr)
{
	system("cls");
	struct pbook silici = {"*","","","","","","",""};
	printf("_______________________________________________\n");	
	printf("****************DELETE CONTACT*****************");
	printf("\n_______________________________________________"
	   "\n|||||1 - With register no"
	   "\n|||||2 - With name and surname altogether"
	   "\n|||||3 - Clear all phone book,with confirmation"
	   "\n|||||4 - Return menu"
	   "\n|||||? : ");
	fflush(stdin);
	int choice = getchar();	
	switch (choice)
	{
		case '1':	system("cls");
					printf("_______________________________________________\n");	
					printf("****************DELETE CONTACT*****************");
					printf("\n_______________________________________________");
					char kayitno[20];
					printf("\nRegister no of person you wanted to delete ?:");
					fflush(stdin); gets(kayitno);
					
					
					while (true)
					{
						if(strlen(kayitno) == 0)
						{
							printf("You didn't enter a register no!");
							printf("\nEnter the register no, #");		
							gets(kayitno);
						}
						if(!is_int(kayitno))
						{
							printf("Register no must be number,not string!");
							printf("\nEnter the register no, #");	
							gets(kayitno);
						}
						if(is_int(kayitno) == TRUE && strlen(kayitno) > 0)
						break;
					}
					registernoilearasil(Ptr,silici,kayitno);
					menufunction(Ptr);		   					
					break;

		case '2':	system("cls");
					char isim[20],soyad[20];
					printf("_______________________________________________\n");	
					printf("****************DELETE CONTACT*****************");
					printf("\n_______________________________________________");
					printf("\nPlease enter the name : "); 					
					fflush(stdin);  gets(isim);
					printf("Please enter the lastname : "); 
					fflush(stdin);  gets(soyad);	
					isimlearasil(Ptr,silici,isim,soyad);	
					menufunction(Ptr);
					break;
		case '3': komplesil(Ptr); 
			   	  menufunction(Ptr);
				  break;
		case '4' : menufunction(Ptr);			
				   break;

		default:			    printf("\n_______________________________________________");
								printf("\n		    	           ");
								printf("W");
								_sleep(80);
								printf("R");
								_sleep(80);
								printf("O");
								_sleep(80);
								printf("N");
								_sleep(80);
								printf("G");
								_sleep(80);
								printf(" ");
								_sleep(80);
								printf("C");
								_sleep(80);
								printf("H");
								_sleep(80);
								printf("O");
								_sleep(80);
								printf("I");
								_sleep(80);
								printf("C");
								_sleep(80);
								printf("E");							
								_sleep(1200);	
								deleteperson(Ptr);
								break;	
		
	}
}
void isimlearasil(FILE* Ptr,struct pbook silici,char *isim,char *soyad )
{
				
				rewind(Ptr);
				struct pbook kisi;
				bool success = false;
				while(!feof(Ptr)) 
				{
						fread(&kisi, sizeof(struct pbook), 1, Ptr);
						if ((NULL == strcmp(isim, kisi.ad)) && (NULL == strcmp(soyad, kisi.soyad)) )
						{
							success = true;
							/*kisi = silici;*/
							if(regnocontrol(kisi.kayitno,Ptr))
							{
									fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION \n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							}
							if(areyousure("Are you sure to delete?"))
							{
								fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
								fwrite(&silici, sizeof(struct pbook), 1, Ptr);	
								printf("\n_______________________________________________");
								printf("\n		    	   ");
								printf("S");
								_sleep(100);
								printf("u");
								_sleep(100);
								printf("c");
								_sleep(100);
								printf("c");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("s");
								_sleep(100);
								printf("s");
								_sleep(100);
								printf("f");
								_sleep(100);
								printf("u");
								_sleep(100);
								printf("l");
								_sleep(100);
								printf("l");
								_sleep(100);
								printf("y");
								_sleep(100);
								printf(" ");
								_sleep(100);
								printf("D");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("l");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("t");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("d");
								_sleep(99);		
								break;
							}
							else
							{
								deleteperson(Ptr);
							}
						}						
				} 

				if(success == false)
				{
						
						printf("\n_______________________________________________\nRegister couldn't found!");	
						if(areyousure("Do you want to try again?"))
						{
							system("cls");
							printf("_______________________________________________\n");	
							printf("****************DELETE CONTACT*****************");
							printf("\n_______________________________________________");				
							printf("\nPlease enter the name : "); 					
							fflush(stdin);  
							gets(isim);
							printf("Please enter the lastname : "); 
							fflush(stdin);  
							gets(soyad);	
							isimlearasil(Ptr,silici,isim,soyad);		
						}
						else
						deleteperson(Ptr);
				}
}
void registernoilearasil(FILE* Ptr,struct pbook silici,char *kayitno )
{	
					struct pbook kisi = {0};
					if(regnocontrol(kayitno,Ptr))
					{
							
									fseek(Ptr, (atoi(kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION\n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							
							if(areyousure("Are you sure to delete?"))
							{
									fseek(Ptr, (atoi(kayitno))*sizeof(struct pbook), SEEK_SET);
									fwrite(&silici, sizeof(struct pbook), 1, Ptr);	

									printf("\n_______________________________________________");
									printf("\n		          ");
									printf("S");
									_sleep(100);
									printf("u");
									_sleep(100);
									printf("c");
									_sleep(100);
									printf("c");
									_sleep(100);
									printf("e");
									_sleep(100);
									printf("s");
									_sleep(100);
									printf("s");
									_sleep(100);
									printf("f");
									_sleep(100);
									printf("u");
									_sleep(100);
									printf("l");
									_sleep(100);
									printf("l");
									_sleep(100);
									printf("y");
									_sleep(100);
									printf(" ");
									_sleep(100);
									printf("D");
									_sleep(100);
									printf("e");
									_sleep(100);
									printf("l");
									_sleep(100);
									printf("e");
									_sleep(100);
									printf("t");
									_sleep(100);
									printf("e");
									_sleep(100);
									printf("d");
									_sleep(99);		
							}
							else
							{
								deleteperson(Ptr);
							}
					}
					else
					{
						
						if(areyousure("Register is not found\n_______________________________________________\nDo you want to try again?"))
						{
							system("cls");
							printf("_______________________________________________\n");	
							printf("****************DELETE CONTACT*****************");
							printf("\n_______________________________________________");
							printf("\nRegister no of person you wanted to delete ?:");
							fflush(stdin); 
							gets(kayitno);
							while (true)
							{
								if(strlen(kayitno) == 0)
								{
									printf("You didn't enter a register no!");
									printf("\nEnter the register no, #");		
									gets(kayitno);
								}
								if(!is_int(kayitno))
								{
									printf("Register no must be number,not string!");
									printf("\nEnter the register no, #");	
									gets(kayitno);
								}
								if(is_int(kayitno) == TRUE && strlen(kayitno) > 0)
								break;
							}

							registernoilearasil(Ptr,silici,kayitno);			
						}
						else
						deleteperson(Ptr);
					}
}
void komplesil(FILE *Ptr)
{					
					system("cls");
					char isim[20],soyad[20];
					printf("_______________________________________________\n");	
					printf("****************DELETE CONTACT*****************");
					printf("\n_______________________________________________");
					if(areyousure("ARE YOU SURE TO CLEAR ALL PHONE BOOK?"))
					{
						rewind(Ptr);
						struct pbook silici = {"*","","","","","","",""};
						for (int i = 1; i < 10000; i++)
						fwrite(&silici,sizeof(struct pbook),1,Ptr);
						printf("\n_______________________________________________");
								printf("\n		    	   ");
								printf("S");
								_sleep(100);
								printf("u");
								_sleep(100);
								printf("c");
								_sleep(100);
								printf("c");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("s");
								_sleep(100);
								printf("s");
								_sleep(100);
								printf("f");
								_sleep(100);
								printf("u");
								_sleep(100);
								printf("l");
								_sleep(100);
								printf("l");
								_sleep(100);
								printf("y");
								_sleep(100);
								printf(" ");
								_sleep(100);
								printf("D");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("l");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("t");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("d");
								_sleep(99);		
					}
					else					
					deleteperson(Ptr);		
						
					
}
/////////////////////////////////

void viewpbook(FILE *Ptr)
{
	rewind(Ptr);	
	system("cls");
	struct pbook kisi; 	
	bool var = false;	
	printf("_______________________________________________\n");	
	printf("******************PHONE BOOK*******************");
	printf("\n_______________________________________________\n");
			
			while (!feof(Ptr)) 
			{
			    fread(&kisi,sizeof(struct pbook), 1, Ptr);	
				if(strcmp(kisi.kayitno,"*") != NULL && is_int(kisi.kayitno) == TRUE)
					{	var = true;						
						printf("#%s",kisi.kayitno);
						printf("\tName    : %s\n", kisi.ad);    
						printf("\tSurname  : %s\n", kisi.soyad);
						printf("\tMobile: %s\n", kisi.ceptel);
						printf("\tHome Phone#: %s\n",  kisi.evtel);
						printf("\tBusiness Phone#: %s\n", kisi.istel);
						printf("\tBirthdate: %s\n", kisi.dogum);
						printf("\tAddress: %s\n", kisi.adres);
						printf("_______________________________________________\n");
					}

			}
			if(!var)
			printf("PHONE BOOK IS EMPTY");
			if(areyousure("Do you wanna return?"))
			menufunction(Ptr);
			else
			viewpbook(Ptr);
	
}
//////////////////////////////////
void updatewithno(FILE *Ptr)
{
				struct pbook kisi;
				struct pbook silici = {"*","","","","","","",""};
				system("cls");
				printf("_______________________________________________\n");	
				printf("****************UPDATE CONTACT*****************");
				printf("\n_______________________________________________");
				char kayitno[20];
				fflush(stdin);
				printf("\nEnter the register no, #");
				gets(kayitno);
				while (true)
					{
						if(strlen(kayitno) == 0)
						{
							printf("You didn't enter a register no!");
							printf("\nEnter the register no, #");		
							gets(kayitno);
						}
						if(!is_int(kayitno))
						{
							printf("Register no must be number,not string!");
							printf("\nEnter the register no, #");	
							gets(kayitno);
						}
						if(is_int(kayitno) == TRUE && strlen(kayitno) > 0)
						break;
					}
				
				if(regnocontrol(kayitno,Ptr))
				{
						fseek(Ptr, (atoi(kayitno))*sizeof(struct pbook), SEEK_SET);
						fread(&kisi, sizeof(struct pbook),1,Ptr);
						printf("_______________________________________________");
						printf("\nPERSON INFORMATION\n");		
						printf("_______________________________________________\n");
						printf("\t#%s",kayitno);
						printf("\n\tName    : %s\n", kisi.ad);    
						printf("\tSurname  : %s\n", kisi.soyad);
						printf("\tMobile: %s\n", kisi.ceptel);
						printf("\tHome Phone #: %s\n",  kisi.evtel);
						printf("\tBusiness Phone #: %s\n", kisi.istel);
						printf("\tBirthdate: %s\n", kisi.dogum);
						printf("\tAddress: %s\n", kisi.adres);

						printf("_______________________________________________\n");
						printf("NEW - PERSON INFORMATION\n");
						printf("_______________________________________________\n");
						printf("\tNEW #"); 
						gets(kisi.kayitno);


					if(strcmp(kayitno,kisi.kayitno) != NULL) // AYNI NO KALABÝLÝR
					{
						while(regnocontrol(kisi.kayitno,Ptr))
						{
							if(strcmp(kayitno,kisi.kayitno) == NULL)
							break;

							printf("\tThis register NO is used please try again...\n"); 
							printf("\tNEW # :"); 
							gets(kisi.kayitno);
							while (true)
							{
									if(strlen(kisi.kayitno) == 0)
									{
										printf("You didn't enter a register no!");
										printf("\nEnter the register no, #");		
										gets(kisi.kayitno);
									}
									if(!is_int(kisi.kayitno))
									{
										printf("Register no must be number,not string!");
										printf("\nEnter the register no, #");	
										gets(kisi.kayitno);
									}
									if(is_int(kisi.kayitno) == TRUE && strlen(kisi.kayitno) > 0)
									break;
							}
						}
					}
					
					printf("\tNEW Name    :"); 
					gets(kisi.ad);
					printf("\tNEW Surname  :");
					gets(kisi.soyad);
					printf("\tNEW Mobile :");
					gets(kisi.ceptel);
					printf("\tNEW Home Phone #:");
					gets(kisi.evtel);
					printf("\tNEW Business Phone #:");
					gets(kisi.istel);
					printf("\tNEW Birthdate:");
					gets(kisi.dogum);
					printf("\tNEW Address :");
					gets(kisi.adres);
					fseek(Ptr, (atoi(kayitno))*sizeof(struct pbook), SEEK_SET);
					fwrite(&silici, sizeof(struct pbook), 1, Ptr);

					fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
					fwrite(&kisi, sizeof(struct pbook), 1, Ptr);

					printf("\n_______________________________________________");
								printf("\n		    	   ");
								printf("S");
								_sleep(100);
								printf("u");
								_sleep(100);
								printf("c");
								_sleep(100);
								printf("c");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("s");
								_sleep(100);
								printf("s");
								_sleep(100);
								printf("f");
								_sleep(100);
								printf("u");
								_sleep(100);
								printf("l");
								_sleep(100);
								printf("l");
								_sleep(100);
								printf("y");
								_sleep(100);
								printf(" ");
								_sleep(100);
								printf("U");
								_sleep(100);
								printf("p");
								_sleep(100);
								printf("d");
								_sleep(100);
								printf("a");
								_sleep(100);
								printf("t");
								_sleep(100);
								printf("e");
								_sleep(100);
								printf("d");
								_sleep(700);		
				}
				else
				{
						printf("Register couldn't found!");	
						if(areyousure("Do you want to try again?"))
					    updatewithno(Ptr);
						else
						update(Ptr);
				}
}
void update(FILE *Ptr)
{
	system("cls");
	fflush(stdin); 
	printf("_______________________________________________\n");	
	printf("****************UPDATE CONTACT*****************");
	printf("\n_______________________________________________\n");
	printf("|||||1 - Update by register no"
		"\n|||||2 - Return main menu "
		"\n|||||? : ");
	int choice = getchar();
	struct pbook kisi;
	switch(choice)
	{
		case '1':		
				updatewithno(Ptr);
				update(Ptr);
		break;
		case '2':
			menufunction(Ptr);
			break;
		default: printf("\n_______________________________________________");
								printf("\n		    	           ");
								printf("W");
								_sleep(80);
								printf("R");
								_sleep(80);
								printf("O");
								_sleep(80);
								printf("N");
								_sleep(80);
								printf("G");
								_sleep(80);
								printf(" ");
								_sleep(80);
								printf("C");
								_sleep(80);
								printf("H");
								_sleep(80);
								printf("O");
								_sleep(80);
								printf("I");
								_sleep(80);
								printf("C");
								_sleep(80);
								printf("E");							
								_sleep(1200);	
							    update(Ptr);
								break;	
	}
}
///////////////////////////////////////////////////////////
void registernoileara(FILE* Ptr,struct pbook kisi )
{
		system("cls");
		printf("_______________________________________________\n");	
		printf("********************SEARCH*********************");
		printf("\n_______________________________________________\n");
		char kayitno[20];
		printf("Enter register NO #"); 
		fflush(stdin);
		gets(kayitno);	
		while (true)
					{
						if(strlen(kayitno) == 0)
						{
							printf("You didn't enter a register no!");
							printf("\nEnter the register no, #");		
							gets(kayitno);
						}
						if(!is_int(kayitno))
						{
							printf("Register no must be number,not string!");
							printf("\nEnter the register no, #");	
							gets(kayitno);
						}
						if(is_int(kayitno) == TRUE && strlen(kayitno) > 0)
						break;
					}
		if(regnocontrol(kayitno,Ptr))
		{
						fseek(Ptr,atoi(kayitno)*sizeof(struct pbook),SEEK_SET);
						fread(&kisi,sizeof(struct pbook),1,Ptr);
						printf("_______________________________________________");
						printf("\nPERSON INFORMATION\n");
				    	printf("_______________________________________________\n");
						printf("#%s",kisi.kayitno);
						printf("\tName    : %s\n", kisi.ad);    
						printf("\tSurname  : %s\n", kisi.soyad);
						printf("\tMobile: %s\n", kisi.ceptel);
						printf("\tHome Phone#: %s\n",  kisi.evtel);
						printf("\tBusiness Phone#: %s\n", kisi.istel);
						printf("\tBirthdate: %s\n", kisi.dogum);
						printf("\tAddress: %s\n", kisi.adres);
						printf("_______________________________________________\n");
		}
		else
		{

			printf("The register you apply couldn't be founded");
			if(areyousure("Do you want to try again?"))
			registernoileara(Ptr,kisi);
			else
			search(Ptr);
		}	
}
void isimleara(FILE *Ptr)
{				
			system("cls");
			printf("_______________________________________________\n");	
			printf("********************SEARCH*********************");
			printf("\n_______________________________________________\n");
				struct pbook kisi;
				bool success = false;
				char isim[20]; 
				fflush(stdin);  
				printf("Enter name :"); 			
				gets(isim);
				rewind(Ptr);
				while(!feof(Ptr)) 
				{
						fread(&kisi, sizeof(struct pbook), 1, Ptr);
						if (NULL == strcmp(isim, kisi.ad)  )
						{
									success = true;				
							
									fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION\n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							
							
						}						
				} 

				if(success == false)
				{
						printf("Register couldn't found!");	
						if(areyousure("Do you want to try again?"))
						isimleara(Ptr);
						else
						search(Ptr);
				}
}
void soyadlaara(FILE *Ptr)
{				
	system("cls");
		printf("_______________________________________________\n");	
		printf("********************SEARCH*********************");
		printf("\n_______________________________________________\n");
				struct pbook kisi;
				bool success = false;
				char soyad[20]; 
				fflush(stdin);  
				printf("Enter surname :"); 			
				gets(soyad);
				rewind(Ptr);
				while(!feof(Ptr)) 
				{
						fread(&kisi, sizeof(struct pbook), 1, Ptr);
						if (NULL == strcmp(soyad, kisi.soyad)  )
						{
									success = true;				
							
									fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION\n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							
							
						}						
				} 

				if(success == false)
				{
						printf("Register couldn't found!");	
						if(areyousure("Do you want to try again?"))
						soyadlaara(Ptr);
						else
						search(Ptr);
				}
}
void mobileileara(FILE *Ptr)
{				
	system("cls");
		printf("_______________________________________________\n");	
		printf("********************SEARCH*********************");
		printf("\n_______________________________________________\n");
				struct pbook kisi;
				bool success = false;
				char mobilno[20]; 
				fflush(stdin);  
				printf("Enter mobile no :"); 			
				gets(mobilno);
				rewind(Ptr);
				while(!feof(Ptr)) 
				{
						fread(&kisi, sizeof(struct pbook), 1, Ptr);
						if (NULL == strcmp(mobilno, kisi.ceptel)  )
						{
									success = true;				
							
									fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION\n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							
							
						}						
				} 

				if(success == false)
				{
						printf("Register couldn't found!");	
						if(areyousure("Do you want to try again?"))
						mobileileara(Ptr);
						else
						search(Ptr);
				}
}
void evnoileara(FILE *Ptr)
{
	system("cls");
		printf("_______________________________________________\n");	
		printf("********************SEARCH*********************");
		printf("\n_______________________________________________\n");
				struct pbook kisi;
				bool success = false;
				char homeno[20]; 
				fflush(stdin);  
				printf("Enter home no :"); 			
				gets(homeno);
				rewind(Ptr);
				while(!feof(Ptr)) 
				{
						fread(&kisi, sizeof(struct pbook), 1, Ptr);
						if (NULL == strcmp(homeno, kisi.evtel)  )
						{
									success = true;				
							
									fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION\n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							
							
						}						
				} 

				if(success == false)
				{
						printf("Register couldn't found!");	
						if(areyousure("Do you want to try again?"))
						evnoileara(Ptr);
						else
						search(Ptr);
				}
}
void isnoileara(FILE *Ptr)
{
	system("cls");
		printf("_______________________________________________\n");	
		printf("********************SEARCH*********************");
		printf("\n_______________________________________________\n");
				struct pbook kisi;
				bool success = false;
				char istel[20]; 
				fflush(stdin);  
				printf("Enter business no :"); 			
				gets(istel);
				rewind(Ptr);
				while(!feof(Ptr)) 
				{
						fread(&kisi, sizeof(struct pbook), 1, Ptr);
						if (NULL == strcmp(istel, kisi.istel)  )
						{
									success = true;				
							
									fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION\n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							
							
						}						
				} 

				if(success == false)
				{
						printf("Register couldn't found!");	
						if(areyousure("Do you want to try again?"))
						isnoileara(Ptr);
						else
						search(Ptr);
				}
}
void dogumtarihiileara(FILE *Ptr)
{
	system("cls");
		printf("_______________________________________________\n");	
		printf("********************SEARCH*********************");
		printf("\n_______________________________________________\n");
				struct pbook kisi;
				bool success = false;
				char dogum[20]; 
				fflush(stdin);  
				printf("Enter birthdate no like (27/07/1993):"); 			
				gets(dogum);
				rewind(Ptr);
				while(!feof(Ptr)) 
				{
						fread(&kisi, sizeof(struct pbook), 1, Ptr);
						if (NULL == strcmp(dogum, kisi.dogum)  )
						{
									success = true;				
							
									fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION\n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							
							
						}						
				} 

				if(success == false)
				{
						printf("Register couldn't found!");	
						if(areyousure("Do you want to try again?"))
						dogumtarihiileara(Ptr);
						else
						search(Ptr);
				}
}
void adresileara(FILE *Ptr)
{
	system("cls");
		printf("_______________________________________________\n");	
		printf("********************SEARCH*********************");
		printf("\n_______________________________________________\n");
				struct pbook kisi;
				bool success = false;
				char adres[20]; 
				fflush(stdin);  
				printf("Enter adress:"); 			
				gets(adres);
				rewind(Ptr);
				while(!feof(Ptr)) 
				{
						fread(&kisi, sizeof(struct pbook), 1, Ptr);
						if (NULL == strcmp(adres, kisi.adres)  )
						{
									success = true;				
							
									fseek(Ptr, (atoi(kisi.kayitno))*sizeof(struct pbook), SEEK_SET);
									fread(&kisi, sizeof(struct pbook),1,Ptr);
									printf("_______________________________________________");
									printf("\nPERSON INFORMATION\n");
									printf("_______________________________________________\n");
									printf("#%s",kisi.kayitno);
									printf("\tName    : %s\n", kisi.ad);    
									printf("\tSurname  : %s\n", kisi.soyad);
									printf("\tMobile: %s\n", kisi.ceptel);
									printf("\tHome Phone#: %s\n",  kisi.evtel);
									printf("\tBusiness Phone#: %s\n", kisi.istel);
									printf("\tBirthdate: %s\n", kisi.dogum);
									printf("\tAddress: %s\n", kisi.adres);
									printf("_______________________________________________\n");
							
							
						}						
				} 

				if(success == false)
				{
						printf("Register couldn't found!");	
						if(areyousure("Do you want to try again?"))
						adresileara(Ptr);
						else
						search(Ptr);
				}
}
void search(FILE *Ptr)
{
	system("cls");
	printf("_______________________________________________\n");	
	printf("********************SEARCH*********************");
	printf("\n_______________________________________________");
	struct pbook kisi = {0};
	printf("\n|||||1 - With register no"
	   "\n|||||2 - With name"
	   "\n|||||3 - With surname"
	   "\n|||||4 - With mobile number(#)"
	   "\n|||||5 - With home number(#)"
	   "\n|||||6 - With business number(#)"
	   "\n|||||7 - With birth date(#)"
	   "\n|||||8 - With address of person"
	   "\n|||||9 - Return menu"
	   "\n|||||? : ");
	fflush(stdin);
	int choice;
	choice = getchar();	
	//////////////////////////////////
	switch(choice)
	{
	case '1': 		
		registernoileara(Ptr,kisi);
		if(areyousure("Do you wanna return?"))
		search(Ptr);
		else
		menufunction(Ptr);
		break;
	case '2': 
		isimleara(Ptr);
		if(areyousure("Do you wanna return?"))
		search(Ptr);
		else
		menufunction(Ptr); 			
		break;

	case '3': 
		soyadlaara(Ptr);
		if(areyousure("Do you wanna return?"))
		search(Ptr);
		else
			menufunction(Ptr);			
		break;

	case '4': 
		mobileileara(Ptr);
		if(areyousure("Do you wanna return?"))
		search(Ptr);
		else
			menufunction(Ptr);	
		break;
	case '5': 
		evnoileara(Ptr);
		if(areyousure("Do you wanna return?"))
		search(Ptr);
		else
		menufunction(Ptr);
		break;
	case '6': 
		isnoileara(Ptr);
		if(areyousure("Do you wanna return?"))
		search(Ptr);
		else
		menufunction(Ptr);
		break;
	case '7': 
		dogumtarihiileara(Ptr);
		if(areyousure("Do you wanna return?"))
		search(Ptr);
		else
		menufunction(Ptr);
		break;
	case '8': 
		adresileara(Ptr);
		if(areyousure("Do you wanna return?"))
		search(Ptr);
		else
		menufunction(Ptr);
		break;
	case '9': 
		menufunction(Ptr);
		break;
	default: 
		printf("\n_______________________________________________");
								printf("\n		    	           ");
								printf("W");
								_sleep(80);
								printf("R");
								_sleep(80);
								printf("O");
								_sleep(80);
								printf("N");
								_sleep(80);
								printf("G");
								_sleep(80);
								printf(" ");
								_sleep(80);
								printf("C");
								_sleep(80);
								printf("H");
								_sleep(80);
								printf("O");
								_sleep(80);
								printf("I");
								_sleep(80);
								printf("C");
								_sleep(80);
								printf("E");							
								_sleep(1200);	
								search(Ptr);
								break;	

	}

}
