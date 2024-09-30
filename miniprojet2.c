#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact{
char nom[10];
char num_telephone[16];
char email[30];
};

int strtransform(char c,int t);
void ajouterContact(struct contact *contacts,int taille,int *n);
void modifierContact(struct contact *contacts,int taille,int *n);
void afficherContacts(struct contact *contacts,int taille,int *n);
void supprimerContact(struct contact *contacts,int taille,int *n);
void rechercherContact(struct contact *contacts,int taille,int *n);

int main(){

const int taille = 100;
int choice = 0;
char trans;
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
    scanf("%c",&trans);
    choice = strtransform(trans,choice);
    
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
 
 if (*n >= taille)
 {
    printf("le tableau et plein\n\n");
 }
 
 getchar();
 printf("entrer le nom : \n");
 fgets(contacts[*n].nom,sizeof(contacts[*n].nom),stdin);
 contacts[*n].nom[strcspn(contacts[*n].nom,"\n")] = '\0';

 printf("entrer le numero de telephone : \n");
 fgets(contacts[*n].num_telephone,sizeof(contacts[*n].num_telephone),stdin);
 contacts[*n].num_telephone[strcspn(contacts[*n].num_telephone,"\n")] = '\0';

 printf("entrer l'email : \n");
 fgets(contacts[*n].email,sizeof(contacts[*n].email),stdin);
 contacts[*n].email[strcspn(contacts[*n].email,"\n")] = '\0';

(*n)++;
printf("\n\n");

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
 
 char nom_saisi[50];  // Increase size to match the possible name length
    int found = 0;

    getchar();  // Clear any leftover newline character
    printf("Entrer le nom du contact à supprimer : \n");
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
            printf("Contact supprimé avec succès\n\n");
            break;  // Exit after deletion
        }
    }

    if (!found) {
        printf("Le contact n'existe pas\n\n");
    }
    /*char nom_saisi[10];
    char nom_temp[10];
    char num_temp[16];
    char email_temp[30];
    getchar();
    printf("entrer le nom du contact a supprimer : \n");
    fgets(nom_saisi,sizeof(nom_saisi),stdin);
    nom_saisi[strcspn(nom_saisi,"\n")] = '\0';

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(nom_saisi,contacts[i].nom) == 0)
        {
        for
            strcpy(nom_temp,contacts[i].nom);
            strcpy(contacts[i].nom,contacts[i+1].nom);

            strcpy(num_temp,contacts[i].num_telephone);
            strcpy(contacts[i].num_telephone,contacts[i+1].num_telephone);
            
            strcpy(email_temp,contacts[i].email);
            strcpy(contacts[i].email,contacts[i+1].email);
            (*n)--;
            break;
            printf("contact supprimer avec succes\n\n");
        }
        else printf("le contact n'existe pas");
        
    }
    printf("\n\n");
    */

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

int strtransform(char c,int t){
  t = (int)c - 48;
  return t;
}
