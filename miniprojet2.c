#include <stdio.h>
#include <string.h>

struct contact{
char nom[10];
char num_telephone[16];
char email[30];

};

void ajouterContact(struct contact *contacts,int taille,int *n);


int main(){

const int taille = 100;
int choice = 0;
struct contact *ct;
int nb = 0;
struct contact tabcontact[taille];

printf("Gestionaire de contact\n");
printf("-------------------------\n");

do
{
    printf("1.ajouter un contact\n");
    printf("2.modifier un contact\n");
    printf("3.suprimer un contact\n");
    printf("4.afficher tous les contacts\n");
    printf("5.rechercher un contact\n");
    printf("6.quiter\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        ajouterContact(tabcontact,taille,&nb);
        break;
    // case 2:
    //     modiferContact();
    //     break;
    // case 3:
    //     suprimerContact();
    //     break;
    // case 4:
    //     afficherContacts();
    //     break;
    // case 5:
    //     rechercherContacts();
    //     break;
    // case 6:
    //     printf("Aurevoir");
    //     break;
    
    default: printf("choi invalid");
        break;
    }
    
} while (choice != 6);


}

void ajouterContact(struct contact *contacts,int taille,int *n){
 
 if (*n >= taille);
 {
    printf("le tableau et plein\n");
 }
 
 getchar();
 printf("entrer le nom : \n");
 gets(contacts[*n].nom);
 contacts[*n].nom[strcspn(contacts[*n].nom,"\n")] = '0';

 printf("entrer le numero de telephone : \n");
 gets(contacts[*n].num_telephone);
 contacts[*n].num_telephone[strcspn(contacts[*n].num_telephone,"\n")] = '0';

 printf("entrer l'email : \n");
 gets(contacts[*n].email);
 contacts[*n].email[strcspn(contacts[*n].email,"\n")] = '0';

(*n)++;

}

void modifierContact(struct contact *contacts,int taille,int *n){
    
    int c;
    char ancien_nom[10];
    char nouveau_num[10];
    char nouveau_email[10];
    printf("entrer le nom de contact : \n");
    fgets(ancien_nom,10,stdin);
    ancien_nom[strcspn(ancien_nom,"\n")] = '0';

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(ancien_nom,contacts[i].nom) == 0)
        {
            do
            {

                printf("1.choisie une option\n\n");
                printf("1.changer numero\n");
                printf("2.changer email\n");
                printf("2.quiterl\n");
                scanf("%d",&c);
                switch (c)
                {
                case 1:
                    printf("entrer le nouveau numero");
                    fgets(nouveau_num,sizeof(nouveau_num),stdin);
                    nouveau_num[strcspn(nouveau_num,"\n")] = '0';
                    
                    break;
                case 2:
                    printf("entrer le nouveau email");
                    printf("entrer le nouveau numero");
                    fgets(nouveau_email,10,stdin);
                    nouveau_email[strcspn(nouveau_email,"\n")] = '0';
                    contacts[i].email = nouveau_email;
                    break;
                
                default: printf("choi invalid");
                    break;
                }
            } while (c != 3);
            
        }
        
    }
    
    
}