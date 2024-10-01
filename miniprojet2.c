#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact{
char nom[10];
char num_telephone[16];
char email[30];
};

int strtransform(char c);
void ajouterContact(struct contact *contacts,int taille,int *n);
void modifierContact(struct contact *contacts,int taille,int *n);
void afficherContacts(struct contact *contacts,int taille,int *n);
void supprimerContact(struct contact *contacts,int taille,int *n);
void rechercherContact(struct contact *contacts,int taille,int *n);

int main(){

const int taille = 100;
char choice = 0;
struct contact contact_tab[taille];
int nb = 0;
//struct contact tabcontact[taille];

printf("Gestionaire de contact\n");
printf("-------------------------\n");

do
{
    printf("choisir une option : \n\n");
    printf("1.ajouter un contact\n");
    printf("2.modifier un contact\n");
    printf("3.suprimer un contact\n");
    printf("4.afficher tous les contacts\n");
    printf("5.rechercher un contact\n");
    printf("6.quiter\n");
    scanf(" %c",&choice);
    choice = strtransform(choice);
    
    switch (choice)
    {
    case 1:
        ajouterContact(contact_tab,taille,&nb);
        break;
    case 2:
        modifierContact(contact_tab,taille,&nb);
        break;
    case 3:
        supprimerContact(contact_tab,taille,&nb);
        break;
    case 4:
        afficherContacts(contact_tab,taille,&nb);
        break;
    case 5:
        rechercherContact(contact_tab,taille,&nb);
        break;
    case 6:
        printf("Aurevoir\n");
        break;
    
    default: printf("choi invalid\n");
        break;
    }
    printf("\n");
} while (choice != 6);
printf("\n");


}

void ajouterContact(struct contact *contacts,int taille,int *n){
 
 int n_contacts;

 if (*n >= taille)
 {
    printf("le tableau et plein\n\n");
 }
 
 printf("entrer le nombre de contacts a ajouetr : \n");
 scanf("%d",&n_contacts);

 for (int i = 0; i < n_contacts ; i++)
 {
 
 printf("contact %d\n",i+1);
 
 printf("entrer le nom : \n");
 getchar();
 fgets(contacts[i].nom,sizeof(contacts[i].nom),stdin);
 contacts[i].nom[strcspn(contacts[i].nom,"\n")] = '\0';

 printf("entrer le numero de telephone : \n");
 fgets(contacts[i].num_telephone,sizeof(contacts[i].num_telephone),stdin);
 contacts[i].num_telephone[strcspn(contacts[i].num_telephone,"\n")] = '\0';

 printf("entrer l'email : \n");
 fgets(contacts[i].email,sizeof(contacts[i].email),stdin);
 contacts[i].email[strcspn(contacts[i].email,"\n")] = '\0';

 (*n)++;

 }


}

void modifierContact(struct contact *contacts,int taille,int *n){
    
    int c;
    char ancien_nom[10];
    char nouveau_num[16];
    char nouveau_email[50];
    getchar();
    printf("entrer le nom de contact : \n");
    fgets(ancien_nom,sizeof(ancien_nom),stdin);
    ancien_nom[strcspn(ancien_nom,"\n")] = '\0';

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(ancien_nom,contacts[i].nom) == 0)
        {
            do
            {

                printf("1.choisie une option\n\n");
                printf("1.changer numero\n");
                printf("2.changer email\n");
                printf("3.quiter\n");
                scanf("%d",&c);

                switch (c)
                {
                case 1:
                    getchar();
                    printf("entrer le nouveau numero\n");
                    fgets(nouveau_num,sizeof(nouveau_num),stdin);
                    nouveau_num[strcspn(nouveau_num,"\n")] = '\0';
                    strcpy(contacts[i].num_telephone,nouveau_num);
                    break;
                case 2:
                    getchar();
                    printf("entrer le nouveau email\n");
                    fgets(nouveau_email,sizeof(nouveau_email),stdin);
                    nouveau_email[strcspn(nouveau_email,"\n")] = '\0';
                    strcpy(contacts[i].email,nouveau_email);
                    break;
                case 3:
                    printf("bye!\n");
                    break;
                
                default: printf("choi invalid\n");
                    break;
                }
            } while (c != 3);
            
        }
        
    }
    printf("\n\n");
    
    
}

void afficherContacts(struct contact *contacts,int taille,int *n){

if (*n == 0)
{
   printf("auncun contact disponible\n\n");
}

for (int i = 0; i < *n; i++)
{
    printf("contact %d :\n",i+1);
    printf("nom : %s \t",contacts[i].nom);
    printf("numero de telephone : %s \t",contacts[i].num_telephone);
    printf("adress email : %s \t",contacts[i].email);
    printf("\n\n");
}

}

void supprimerContact(struct contact *contacts,int taille,int *n){
 
 /*char nom_saisi[50];  // Increase size to match the possible name length
    int found = 0;

    getchar();  // Clear any leftover newline character
    printf("Entrer le nom du contact a supprimer : \n");
    fgets(nom_saisi, sizeof(nom_saisi), stdin);
    nom_saisi[strcspn(nom_saisi, "\n")] = '\0';  // Remove the newline character

    for (int i = 0; i < *n; i++) {
        if (strcmp(nom_saisi, contacts[i].nom) == 0) {
            found = 1;  // Mark that the contact has been found

            // Shift all the subsequent contacts forward
            for (int j = i; j < *n - 1; j++) {
                strcpy(contacts[j].nom, contacts[j + 1].nom);
                strcpy(contacts[j].num_telephone, contacts[j + 1].num_telephone);
                strcpy(contacts[j].email, contacts[j + 1].email);
            }

            (*n)--;  // Reduce the contact count
            printf("Contact supprime avec succes\n\n");
            break;  // Exit after deletion
        }
    }

    if (!found) {
        printf("Le contact n'existe pas\n\n");
    }
    */
   char nom_saisi[10];
    getchar();
    printf("entrer le nom du contact a supprimer : \n");
    fgets(nom_saisi,sizeof(nom_saisi),stdin);
    nom_saisi[strcspn(nom_saisi,"\n")] = '\0';

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(nom_saisi,contacts[i].nom) == 0)
        {
            strcpy(contacts[i].nom,contacts[i+1].nom);
            strcpy(contacts[i].num_telephone,contacts[i+1].num_telephone);
            strcpy(contacts[i].email,contacts[i+1].email);

            (*n)--;
            printf("contact supprimer avec succes\n");
            break;
            
        }
        else printf("le contact n'existe pas\n");
        
    }
    printf("\n");
    
}

void rechercherContact(struct contact *contacts,int taille,int *n){
    
    char nom_rechercher [10];
    getchar();
    printf("entrer le nom du contact a rechercher : \n");
    fgets(nom_rechercher,sizeof(nom_rechercher),stdin);
    nom_rechercher[strcspn(nom_rechercher,"\n")] = '\0';
    
    for (int i = 0; i < *n; i++)
    {
        if (strcmp(nom_rechercher,contacts[i].nom) == 0)
        {
            printf("contact %d :\n",i+1);
            printf("nom : %s \t",contacts[i].nom);
            printf("numero telephone : %s \t",contacts[i].num_telephone);
            printf("email : %s \t",contacts[i].email);
            printf("\n\n");
        }
        
    }
    
}

int strtransform(char c){
    if (c >= '0' && c <='9')
    {
        return (int)c - 48;
    }
    return 0;
}
