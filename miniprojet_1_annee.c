#include<stdio.h>
#include<string.h>
#define Max 100

    struct voiture
    {
        int kilometrage , disponibilite ;
        float Prix_du_kilometre ;
        char Marque[20] , Matricule[20] ;

    };
    
    struct Client
    {
        char Nom_du_client[20] , CIN[20] , Matricule[20] ;
        int Telephone[10] ; 
        float Avance , Prix_à_payer 
    } Client;


    struct voiture voitures[Max];
    struct Client Clients[Max];
    
    int Nombre_de_voiture , Nombre_de_client ;

    Nombre_de_voiture = 0 ;
    Nombre_de_client = 0 ;


void ajouter_voitures ()

{
    printf("Marque : ");
    scanf("%s",&voitures[Nombre_de_voiture].marque);

    printf("Matricule : ");
    scanf("%s",&voitures[Nombre_de_voiture].matricule);

    printf("kilometrage : ");
    scanf("%d",&voitures[Nombre_de_voiture].kilometrage);

    printf("Disponibilte (0/1) : ");
    scanf("%d",&voitures[Nombre_de_voiture].disponibilite);

    printf("Prix du kilometre : ");
    scanf("%f",&voitures[Nombre_de_voiture].Prix_du_kilometre);

    Nombre_de_voiture ++ ;
}

void afficher_voitures ()
{
    char Matricule[20] ;

    printf("entrer la matricule : ");
    scanf("%s",&Matricule);

    for ( int i = 0 ; i < Nombre_de_voiture ; i++)
    {
        if ( strcmp( voitures[i].Matricule , Matricule ) == 0 )
        {
            prnitf("--- Voiture trouve ! --- \n");

            printf("Marque : %s \n",voitures[i].Marque);
            printf("kilometrage : %d \n",voitures[i].kilometrage);
            printf("Disponibilte (0/1) : %d \n",voitures[i].disponibilite);
            printf("Prix du kilometre : %.2f \n",voitures[i].Prix_du_kilometre);
        }
    }
}

void mofifier_voitures ()
{
    char Matricule[20] ;
    int trouve = 0 ;

    printf("Matricule : ");
    scanf("%s",&Matricule);

    for ( int i = 0 ; i < Nombre_de_voiture ; i++)
    {
        if ( strcmp( voitures[i].Matricule , Matricule) == 0 )
        {
            trouve = 1 ;

            printf("Nouvelle marque : ");
            scanf(" %s",voitures[i].Marque);
    
            break ;
        }
    }

    if ( trouve == 0)
    {
        printf("Erreur ! Aucun client n'as ete trouve \n");
    }
}

void supprimer_voitures ()
{
    char Matricule ;

    printf("Matricule : ");
    scanf("%s",&Matricule);

    for ( int i = 0 ; i < Nombre_de_voiture ; i++)
    {
        if ( strcmp( voitures[i].Matricule , Matricule ) == 0 )
        {
            voitures[i] = voitures[Nombre_de_voiture - 1 ];
            Nombre_de_voiture -- ;
        }
        
    }
    
}

void ajouter_client ()
{
    printf("Nom : ");
    scanf(" %s",&Clients[Nombre_de_client].Nom_du_client);

    printf("CIN : ");
    scanf(" %s",&Clients[Nombre_de_client].CIN);

    printf("le telephone : ");
    scanf("%d",&Clients[Nombre_de_client].telephone);

    printf("La matricule de la voiture : ");
    scanf("%s",&Clients[Nombre_de_client].Matricule);

    printf("L'avance : ");
    scanf("%f",&Clients[Nombre_de_client].Avance);

    printf("Le prix à payer : ");
    scanf("%.2f",&Clients[Nombre_de_client].Prix_à_payer);

    Nombre_de_client ++ ;
}

void modifier_client ()
{
    char CIN ;
    int trouve = 0 ;

    printf("CIN : ");
    scanf("%s",&CIN);

    for ( int i = 0 ; i < Nombre_de_client ; i++ )
    {
        if ( strcmp(Clients[Nombre_de_client].CIN , CIN ) == 0 )
        {
            trouve = 1 ;

            printf("--- Client trouve ! --- \n");

            printf("Nouveau Nom : ");
            scanf("%s",&Clients[i].Nom_du_client);

            printf("Nouveau telephone : ");
            scanf("%d",&Clients[Nombre_de_client].telephone);

            printf("Nouvelle avance : ");
            scanf("%f",&Clients[i].Avance);

            printf("Modification faite avec succes \n");
            break ;
        }        
    }

    if ( trouve == 0)
    {
        printf("Erreur ! Aucun client n'as ete trouve \n");
    }
}

void supprimer_client ()
{
    char CIN ;

    printf("CIN : ");
    scanf("%s",&CIN);

    for ( int i = 0 ; i < Nombre_de_client ; i++)
    {
        if ( strcmp( Clients[i].CIN , CIN ) == 0 )
        {
            Clients[i] = Clients[Nombre_de_client - 1 ];
            Nombre_de_client -- ;
        }

    }
}

void main ()
{
    int choix ;

    do
    {
        printf("\n ---- GESTION LOCATION ---- \n");

        printf("1 _ Ajouter voitures  \n");
        printf("2 _ Afficher voitures  \n");
        printf("3 _ Supprimer voitures  \n");
        printf("4 _ Ajouter Client \n");
        printf("5 _ Modifier Client \n");
        printf("6 _ Supprimer client \n");
        prinf("0 _ Quitter \n");

        switch ( choix )
        {
        case 1 :
            ajouter_voitures () ;
            break;

        case 2 :
            afficher_voitures () ;
            break ;

        case 3 :
            supprimer_voitures () ;
            break ;

        case 4 :
            ajouter_client () ;
            break ;

        case 5 :
            modifier_client () ;
            break ;

        case 6 : 
            supprimer_client () ;
            break;

        case 0 :
            printf("Au revoir ! \n");
            break;

        default:
            printf("Choix invalide . \n");
            break;
            
        }
    } while ( choix != 0 );
    
}
