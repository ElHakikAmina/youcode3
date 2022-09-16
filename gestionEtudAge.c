#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nbr_etud;
typedef struct
{
	int jour;
	int mois;
	int annee;
}Date;
typedef struct
{
	char nom[20];
	char prenom [20];
	Date date;
}Etudiant;
main()
{
	int i;
	printf("donner le nombre d\'etudiant: ");
	scanf("%d",&nbr_etud);
	Etudiant e[nbr_etud];
	for (i=0;i<nbr_etud;i++)
	{
		system("cls");
		printf("\n \n etudiant numero %d \n\n",i+1);
		printf("Le nom : ");
		fflush(stdin);
		gets(e[i].nom);
		printf("prenom : ");
		fflush(stdin);
		gets(e[i].prenom);
		printf("\n Date de naissance \n");
		do{
			printf("donner le jour : ");
			scanf("%d",&e[i].date.jour);	
		}while(e[i].date.jour<1 || e[i].date.jour>31);
		do{
			printf("donner le mois : ");
			scanf("%d",&e[i].date.mois);
		}while(e[i].date.mois<1 || e[i].date.mois>12);
		do
		{
			printf("donner l\'annee : ");
			scanf("%d",&e[i].date.annee);
		}while(e[i].date.annee>2022 || e[i].date.annee<1980);	
}
system("cls");
//affichage
printf("\t Nom \t Prenom \t date de naisance\n");
for(i=0;i<nbr_etud;i++)
{
	printf("\t %s \t\t %s \t\t %d/%d/%d\n",e[i].nom,e[i].prenom,e[i].date.jour,e[i].date.mois,e[i].date.annee);
}
//tri

int j,max,aide;
for (i=0;i<nbr_etud-1;i++)
{
	max=i;
	for(j=i+1;j<nbr_etud;j++)
	{
		if(e[i].date.annee<e[j].date.annee)
		{
			max=j;
		}
		else if(e[i].date.annee==e[j].date.annee)
		{
			if(e[i].date.mois<e[j].date.mois) max=j;
			else if(e[i].date.mois==e[j].date.mois) 
				if(e[i].date.jour<e[j].date.jour) max=j;	
		} 
	}
	if(i!=max)
	{
		Etudiant tmp;
		tmp=e[i];
		e[i]=e[max];
		e[max]=tmp;
	}
}
//affichage
printf("\nLe tableau du plus grand au plus petit \n \n \t Nom \t Prenom \t date de naisance\n");
	for(i=0;i<nbr_etud;i++)
	{
		printf("\t %s \t\t %s \t\t %d/%d/%d\n",e[i].nom,e[i].prenom,e[i].date.jour,e[i].date.mois,e[i].date.annee);
	}
	printf("\n\n \tLe plus petit est :");
	printf("\t %s \t\t %s \t\t %d/%d/%d\n",e[0].nom,e[0].prenom,e[0].date.jour,e[0].date.mois,e[0].date.annee);
	printf("\n\n \tLe plus grand  est :");
	printf("\t %s \t\t %s \t\t %d/%d/%d\n",e[nbr_etud-1].nom,e[nbr_etud-1].prenom,e[nbr_etud-1].date.jour,e[nbr_etud-1].date.mois,e[nbr_etud-1].date.annee);
	int age[nbr_etud],somme=0;
	printf("\n les ages des etudiants: ");
	for(i=0;i<nbr_etud;i++)
	{
		age[i]=2022-e[i].date.annee;
		somme+=age[i];
		printf(" %d ",age[i]);
	}
	printf("\n Le moyenne de l\'age est %d",somme/nbr_etud);
}
