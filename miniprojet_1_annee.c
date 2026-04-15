#include <stdio.h>
#include <string.h>
#define Max 100

struct voiture 
{
    int kilometrage, disponibilite;
    float Prix_du_kilometre;
    char Marque[20], Matricule[20];
};

struct Client 
{
    char Nom_du_client[20], CIN[20], Matricule[20];
    int Telephone;
    float Avance, Prix_à_payer;
};

struct voiture voitures[Max];
struct Client Clients[Max];

int Nombre_de_voiture = 0 , Nombre_de_client = 0;

void ajouter_voitures() 
{
    printf("Marque : ");
    scanf("%s", voitures[Nombre_de_voiture].Marque);

    printf("Matricule : ");
    scanf("%s", voitures[Nombre_de_voiture].Matricule);

    printf("Kilometrage : ");
    scanf("%d", &voitures[Nombre_de_voiture].kilometrage);

    printf("Disponibilite (0/1) : ");
    scanf("%d", &voitures[Nombre_de_voiture].disponibilite);

    printf("Prix du kilometre : ");
    scanf("%f", &voitures[Nombre_de_voiture].Prix_du_kilometre);

    Nombre_de_voiture ++ ;

    printf("\n");
}

void afficher_voitures() 
{
    char Matricule[20];

    printf("Entrer la matricule : ");
    scanf("%s", Matricule);

    for (int i = 0; i < Nombre_de_voiture; i++) 
    {
        if (strcmp(voitures[i].Matricule, Matricule) == 0) 
        {
            printf("--- Voiture trouve ! ---\n");

            printf("Marque : %s \n", voitures[i].Marque);
            printf("Kilometrage : %d \n", voitures[i].kilometrage);
            printf("Disponibilite ( 0 / 1 ) : %d \n", voitures[i].disponibilite);
            printf("Prix du kilometre : %.2f \n", voitures[i].Prix_du_kilometre);
        }
    }

    printf("\n");
}

void modifier_voitures () 
{
    char Matricule[20];
    int trouve = 0;

    printf("Matricule : ");
    scanf("%s", Matricule);

    for (int i = 0; i < Nombre_de_voiture; i++) 
    {
        if (strcmp(voitures[i].Matricule, Matricule) == 0) 
        {
            trouve = 1;
            
            printf("Nouvelle marque : ");
            scanf("%s", voitures[i].Marque);
            
            break;
        }
    }

    if ( trouve == 0 ) 
    {
        printf("Erreur ! Aucun voiture n'a ete trouve .\n");
    }

    printf("\n");
}

void supprimer_voitures() 
{
    char Matricule[20];

    printf("Matricule : ");
    scanf("%s", Matricule);

    for (int i = 0 ; i < Nombre_de_voiture ; i++) 
    {
        if (strcmp(voitures[i].Matricule, Matricule) == 0) 
        {
            voitures[i] = voitures[Nombre_de_voiture - 1];
            Nombre_de_voiture -- ;
            break;
        }
    }

    printf("\n");
}

void ajouter_client() 
{
    printf("Nom : ");
    scanf("%s", Clients[Nombre_de_client].Nom_du_client);

    printf("CIN : ");
    scanf("%s", Clients[Nombre_de_client].CIN);

    printf("Telephone : ");
    scanf("%d", &Clients[Nombre_de_client].Telephone);

    printf("Matricule de la voiture : ");
    scanf("%s", Clients[Nombre_de_client].Matricule);

    printf("Avance : ");
    scanf("%f", &Clients[Nombre_de_client].Avance);

    printf("Prix à payer : ");
    scanf("%f", &Clients[Nombre_de_client].Prix_à_payer);

    Nombre_de_client ++ ;

    printf("\n");
}

void modifier_client() 
{
    char CIN[20] ;
    int trouve = 0 ;

    printf("CIN : ");
    scanf("%s", CIN);

    for (int i = 0; i < Nombre_de_client; i++) 
    {
        if (strcmp(Clients[i].CIN, CIN) == 0) 
        {
            trouve = 1;

            printf("--- Client trouve ! ---\n");

            printf("Nouveau Nom : ");
            scanf("%s", Clients[i].Nom_du_client);

            printf("Nouveau Telephone : ");
            scanf("%d", &Clients[i].Telephone);

            printf("Nouvelle Avance : ");
            scanf("%f", &Clients[i].Avance);

            printf("Modification faite avec succes\n");
            break;
        }
    }
    if ( trouve == 0 ) {
        printf("Erreur ! Aucun client n'a ete trouve .\n");
    }

    printf("\n");
}

void supprimer_client() 
{
    char CIN[20];

    printf("CIN : ");
    scanf("%s", CIN);

    for (int i = 0; i < Nombre_de_client; i++) 
    {
        if (strcmp(Clients[i].CIN, CIN) == 0) 
        {
            Clients[i] = Clients[Nombre_de_client - 1];
            Nombre_de_client -- ;
            break;
        }
    }
}

void main() {
    int choix;
    do {
        printf("\n---- GESTION LOCATION ----\n");

        printf("1 - Ajouter voitures \n");
        printf("2 - Afficher voitures \n");
        printf("3 - Modifier voitures \n");
        printf("4 - Supprimer voitures \n");
        printf("5 - Ajouter Client \n");
        printf("6 - Modifier Client \n");
        printf("7 - Supprimer client \n");
        printf("0 - Quitter \n");

        printf("Votre choix : ");
        scanf("%d",&choix);
        printf("\n");

        switch (choix) 
        {
            case 1: ajouter_voitures(); 
                    break;

            case 2: afficher_voitures(); 
                    break;

            case 3: modifier_voitures(); 
                    break;

            case 4: supprimer_voitures(); 
                    break;

            case 5: ajouter_client(); 
                    break;

            case 6: modifier_client(); 
                    break;

            case 7: supprimer_client(); 
                    break;

            case 0: printf("Au revoir !\n"); 
                    break;

            default: printf("Choix invalide.\n"); 
                    break;
        }
        
    } while ( choix != 0 );
}
