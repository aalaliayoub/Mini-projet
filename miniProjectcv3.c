/*Les declarations des bibliothèques nécessaires*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*Crée une structure pour l'étudiant*/

typedef struct etudiant{
    int Numinscription;
    char nom [30];
    float note[2];
    int present;
}etudiant;

/*Crée une fonction qui permet de modifier le nom d'un(e) etudiant(e)*/
void modifiernom(char name1[],char name2[]){
    int Numinscription;
    char nom[30],module[20];
    float note;
    int t=0,j;
    int present;
    FILE *pfile,*qfile;
    pfile=fopen("dossier d'etudiants.txt","r");
    qfile=fopen("dossier d'etudiants.txt","a+");
    while(feof(pfile)==0){
        fscanf(pfile,"%d\t",&Numinscription);
        fscanf(pfile,"%s\t",nom);
        fprintf(qfile,"%d\t",Numinscription);
        if(strcmp(name1,nom)==0){
            t=1;
            fprintf(qfile,"%s\t",name2);
            printf("le nom  %s a ete modifie avec succes par %s \n",name1,name2);
        }
        else{
            fprintf(qfile,"%s\t",nom);
        }
        for(j=0;j<2;j++){
            fscanf(pfile,"%s\t",module);
            fprintf(qfile,"%s\t",module);
            fscanf(pfile,"%f\t",&note);
            fprintf(qfile,"%f\t",note);
        }
        fscanf(pfile,"%d\n",&present);
        fprintf(qfile,"%d\n",present);
    }
    if(t==0){
        printf("L'ancien nom n'existe pas dans la liste!!!");
    }
    fclose(qfile);
    fclose(pfile);
    exit(0);
}

/*Crée une fonction qui permet de modifier le numéro d'inscription d'un(e) etudiant(e)*/

void modifierNuminscription(int Numinscription0,int Numinscription1){
    int Numinscription;
    char nom[30],module[20];
    float note;
    int present,j;
    int t=0;
    FILE *pfile,*qfile;
    pfile=fopen("dossier d'etudiants.txt","r");
    qfile=fopen("dossier d'etudiants.txt","a+");
    while(feof(pfile)==0){
        fscanf(pfile,"%d\t",&Numinscription);
        if(Numinscription==Numinscription0){
            t=1;
            fprintf(qfile,"%d\t",Numinscription1);
            printf("Le numero d'inscription %d a ete modifie avec succes par %d \n",Numinscription0,Numinscription1);
        }
        else{
            fprintf(qfile,"%d\t",Numinscription);
            
        }
        fscanf(pfile,"%s\t",nom);
        fprintf(qfile,"%s\t",nom);
        for(j=0;j<2;j++){
                fscanf(pfile,"%s\t",module);
                fprintf(qfile,"%s\t",module);
                fscanf(pfile,"%f\t",&note);
                fprintf(qfile,"%f\t",note);
        }
        fscanf(pfile,"%d\t",&present);
        fprintf(qfile,"%d\n",present);
    }
    if(t==0){
        printf("L'ancien numero d'inscription n'existe pas dans la liste!!!\n");
    }
    fclose(qfile);
    fclose(pfile);
    exit(0);
}
/*Crée une fonction qui permet de modifier la note d'un(e) etudiant(e) dans un module*/

void modifiernote(int Numinscription0,char module0[],float note1){
    int Numinscription,j;
    char nom[30],module[20];
    float note;
    int present,t=0;
    FILE *pfile,*qfile;
    pfile=fopen("dossier d'etudiants.txt","r");
    qfile=fopen("dossier d'etudiants.txt","a+");
    while(feof(pfile)==0){
        fscanf(pfile,"%d\t",&Numinscription);
        fprintf(qfile,"%d\t",Numinscription);
        fscanf(pfile,"%s\t",nom);
        fprintf(qfile,"%s\t",nom);
        if(Numinscription0==Numinscription){
            t=1;
            for(j=0;j<2;j++){
                fscanf(pfile,"%s\t",module);
                fprintf(qfile,"%s\t",module);
                fscanf(pfile,"%f\t",&note);
                if(strcmp(module,module0)==0){
                    fprintf(qfile,"%f\t",note1);
                }
                else{
                    fprintf(qfile,"%f\t",note);
                }
            }
        }
        else{
            for(j=0;j<2;j++){
                fscanf(pfile,"%s\t",module);
                fprintf(qfile,"%s\t",module);
                fscanf(pfile,"%f\t",&note);
                fprintf(qfile,"%f\t",note);
            }
            
        }
        fscanf(pfile,"%d\n",&present);
        fprintf(qfile,"%d\n",present);
    }
    if(t==0){
        printf("Le numero d'inscription :%d n'existe pas dans la liste!!!",Numinscription0);
    }
    fclose(qfile);
    fclose(pfile);
    exit(0);
}

/*Crée une fonction qui permet de modifier le status de presence d'un(e) etudiant(e)*/

void modifierpresence(int Numinscription0,int pres1){
    int Numinscription,j;
    char nom[30],module[20];
    float note;
    int present,t=0;
    FILE *pfile,*qfile;
    pfile=fopen("dossier d'etudiants.txt","r");
    qfile=fopen("dossier d'etudiants.txt","a+");
    while(feof(pfile) == 0){
        fscanf(pfile,"%d\t",&Numinscription);
        fscanf(pfile,"%s\t",nom);
        fprintf(qfile,"%d\t",Numinscription);
        fprintf(qfile,"%s\t",nom);
        for(j=0;j<2;j++){
            fscanf(pfile,"%s\t",module);
            fprintf(qfile,"%s\t",module);
            fscanf(pfile,"%f\t",&note);
            fprintf(qfile,"%f\t",note);
        }
        if(Numinscription == Numinscription0){
            t=1;
            fprintf(qfile,"%d\t",pres1);
            printf("le status de presence a ete modifie avec succes par:\n");
        }
        else{
            fprintf(qfile,"%d\n",present);
        }
    }
    if (t==0){
        printf("le numero d'inscription %d n'existe pas dans la liste!!!\n",Numinscription0);
    }
    fclose(qfile);
    fclose(pfile);
    exit(0);
}

/*Crée une fonction qui permet de trier les etudiants selon le numéro d'inscription*/

void triparNuminscription(etudiant t[],int n){
    int i,j;
    etudiant tmp;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (t[i].Numinscription>t[j].Numinscription){
               tmp=t[i] ;
               t[i]=t[j];
               t[j]=tmp;
            }
        }
    }
}

/*Crée une fonction qui permet de trier les etudiants selon l'ordre alphabétique de nom*/

void triparnom(etudiant t[],int n){
    int i,j;
    etudiant tmp;
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (strcmp(t[i].nom,t[j].nom)>0){
               tmp=t[i];
               t[i]=t[j];
               t[j]=tmp;
            }
        }
    }
}

/*Crée une fonction qui permet de trier les etudiants selon l'ordre croissant de la note*/

void triparnotecroissante(etudiant t[],int n){
    int i,j,k;
    etudiant tmp;
    for (k=0;k<2;k++){
        for (i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(t[i].note[k]>t[j].note[k]){
                    tmp=t[i] ;
                    t[i]=t[j];
                    t[j]=tmp;  
                }
            }
        }
    }
}

/*Crée une fonction qui permet de trier les etudiants selon l'ordre décroissant de la note*/

void triparnotedecroissante(etudiant t[],int n){
    int i,j,k;
    etudiant tmp;
    for (k=0;k<2;k++){
        for (i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(t[i].note[k]<t[j].note[k]){
                    tmp=t[i] ;
                    t[i]=t[j];
                    t[j]=tmp;
                }
            }
        }
    }
}

/*Crée une fonction qui permet de chercher un(e) étudiant(e) selon son numéro d'inscription*/

void rechercher_un_etudiant_par_num(etudiant e[], int n){
      int num,i;
      printf("\nRechercher un etudiant par sa numero : \n");
      printf("--------------------------\n");
      printf(" Saisir un numero d'inscription d'etudiant: ");
      scanf("%d",&num);
       for(i=0;i<n;i++){

           if(e[i].Numinscription == num){
                  printf("Qullques informations sur l'etudiant que vous avez recherche : \n");
                  printf("----------------------------------\n");
                  printf("Numero d'inscription : %d\n",num);
                  printf("Nom : %s\n",e[i].nom);
                  printf("Status de presence : %d\n",e[i].present);
             }
            else 
            {
                printf("Le numero d'inscription saisi ne correspend pas a aucun(e) etudiant(e) dans la lsite des etudiants!!!\n");
                break;
            }
            
         }
}

/*Crée une fonction qui permet de chercher un(e) etudiant(e) selon son nom*/

void rechercher_un_etudiant_par_nom(etudiant e[], int n){
      int i;
      printf("\nRechercher un etudiant par son nom :\n");
      printf("--------------------------\n");
      char Nom[25];
      printf("Entrer le nom d'etudiant : ");
      scanf("%s",Nom);
       for(i=0;i<n;i++){
          if(strcmp(e[i].nom,Nom) == 0){
             printf("Qullques informations sur l'etudiant (%s) :\n",Nom);
             printf("----------------------------------\n");
             printf("Numero d'inscription : %d\n",e[i].Numinscription);
             printf("Nom : %s\n",e[i].nom);
             printf("Status de presence : %d\n",e[i].present);
          }
          else{
              printf("Le nom saisi ne correspend pas a aucun(e) etudiant(e) dans la lsite des etudiants!!!\n");
              break;
          }
  }
}

/*Crée une fonction qui permet de gérer les modifications*/

void modification(){
    int cas,num;
    float notee0,notee1;
    int pres0,pres1;
    int Numinscription0,Numinscription1;
    char name1[20],name2[20],nommodule[20];
    printf("ENTREZ :\n1 Pour modifier le numero d'inscription.\n2 Pour modifier nom.\n3 Pour modifier la note.\n4 Pour modifier le status de presence.\nENTREZ ICI : ");
    scanf("%d",&cas);
    if (cas==1){
        printf("Donnez l'ancien numero d'inscription :");
        scanf("%d",&Numinscription0);
        printf("Donnez le nouveau numero d'inscription :");
        scanf("%d",&Numinscription1);
        modifierNuminscription(Numinscription0,Numinscription1);
    }
    if (cas==2){
        printf("Donnez l'ancien nom :");
        scanf("%s",name1);
        printf("Donnez le nouveau nom :");
        scanf("%s",name2);
        modifiernom(name1,name2);
        
    }
    if(cas==3){
        printf("Donnez numero d'inscription d'etudiant :");
        scanf("%d",&num);
        printf("Donnez le nom de module :");
        scanf("%s",nommodule);
        printf("Entrez la nouvelle note : ");
        scanf("%f",&notee1);
        modifiernote(num,nommodule,notee1);
    }
    if(cas==4){
        printf("Entrez le numero d'inscription d'etudiant :");
        scanf("%d",&num);
        printf("Entrez le nouveau status de presence :");
        scanf("%d",&pres1);
        modifierpresence(num,pres1);
    }
}
/*Crée une fonction qui permet au nouveaux utilisateurs de créer un compte sur l'application*/

void signup(){
    char nom[30];
    char mot[10];
    char type[20];
    FILE *file1;
    file1=fopen("signup.txt","a");
    printf("\tEntrez le username: ");
    scanf("%s",nom);
    fprintf(file1,"%s\t",nom);
    printf("\tEntrez le mot de passe : ");
    scanf("%s",mot);
    fprintf(file1,"%s\t",mot);
    printf("\tVous ete etudiant ou administrateur? : ");
    scanf("%s",type);
    fprintf(file1,"%s\n",type);
    if(strcmp(type,"etudiant")==0){
        printf("Bienvenue dans notre application.\n");
        etudiants();
    }
    else if(strcmp(type,"administrateur")==0){
        printf("Bienvenue dans notre application.\n");
        administration();
    }
    else{
        printf("Erreur");
        exit(0);
    }
    fclose(file1);
}

/*Crée une fonction qui permet à l'utilisateur de se connecter à son compte déja existant*/

void signin(){
    char ptr[20];
    char ptrr[20];
    char q[20];
    char p[20];
    int c;
    char type[20];
    int j=0;
    FILE *file1;
    file1=fopen("signup.txt","r");
    printf("\tBienvunne dans notre application.\n\t\tLogin\n");
    printf("\tEntrez 1 si vous avez deja un compte.\n\tEntrez 0 pour creer un compte.\n\t\tENTRER: ");
    scanf("%d",&c);
    if(c==1){
        printf("\t\t Authentification :\n");
        printf("\t username : ");
        scanf(" %s",p);
        while(feof(file1)==0){
            fscanf(file1," %s\t",ptr);
            fscanf(file1," %s\t",ptrr);
            fscanf(file1,"%s\n",type);
            if(strcmp(p,ptr)==0){
                j=1;
                printf("\t password: ");
                scanf(" %s",q);
                while(strcmp(ptrr,q)!=0){
                    printf("\tle mot de passe est incorrect.\n");
                    printf("\tEntrez a nouveau votre mot de passe .\n\tou\n\tEntrez C pour recuperer le mot de passe.\n\tENTRER:");
                    scanf(" %s",q);
                    if (q[0]=='C'){
                        printf("\t\tVotre mot de passe est : %s\n",ptrr);
                        printf("\t password: ");
                        scanf(" %s",q);
                    }
                }
                fclose(file1);
                if(strcmp(type,"etudiant")==0){
                    printf("\tVous ete connecte!!!\n");
                    etudiants();
                }
                else if(strcmp(type,"administrateur")==0){
                    printf("\tVous ete connecte!!!\n");
                    administration();
                }
            }
        }
        if (j==0){
            printf("\tVous n'avez un compte essaiez-vous de creer un compte:\n");
            signup();
            
        }
    }
    else{
        signup();
        fclose(file1);
    }
}

/*Crée une fonction qui permet d'afficher les informations des etudiants inscris */
/*Cette fonction aussi permet à l'administrateur d'ajouter ou modifier un champ*/

void affichage(){
    char nom[30],module[20];
    int Numinscription;
    int present;
    float note;
    FILE *file1;
    int h,j;
    file1 = fopen("dossier d'etudiants.txt","r");
    printf("\tla liste des etudiants est:\n");
    while(feof(file1)==0){
        fscanf(file1,"%d\t",&Numinscription);
        printf("\tle numero d'inscription d'etudiant : %d\n",Numinscription);
        fscanf(file1,"%s\t",nom);
        printf("\tle nom d'etudiant:%s\n",nom);
        for(j=0;j<2;j++){
            fscanf(file1,"%s\t",module);
            fscanf(file1,"%f\t",&note);
            printf("\tle module %s sa note est %.2f\n",module,note);
        }
        fscanf(file1,"%d\n",&present);
        printf("\tLe status de presence est:%d\n",present);
        printf("-------------------\n");
    }
    fclose(file1);
    printf("\tPour modifier un champ Entrez 1. \n\tPour ajouter autre etudiants entrez 2\n\tPour quitter entrez 0.\n\t\tENTRER: ");
    scanf("%d",&h);
    if(h == 1){
        modification();
    }
    else if(h == 2){
        administration();
    }
    else{
        exit(0);
    }
}

/*Crée une fonction qui permet manipuler les données des étudiants (tri, recherche...)*/

void manipulation_etudiants(etudiant e[],int n,int a){
    int i,k;
    while (a!=0){
        if (a==1){
            triparnom(e,n);
            for (i=0;i<n;i++){
                printf("%s\n",e[i].nom);
            }
        }
        if (a==2){
            triparnotecroissante(e,n);
            for (k=0;k<2;k++){
                printf("\tPour le module %d :\n",k+1);
                for(i=0;i<n;i++){
                    printf("\t%.2f\n",e[i].note[k]);
                }
                printf("\t---------------\n");
            }
        }
        if (a==3){
            triparnotedecroissante(e,n);
            for (k=0;k<2;k++){
                printf("\tPour le module %d :\n",k+1);
                for(i=0;i<n;i++){
                    printf("\t%.2f\n",e[i].note[k]);
                }
                printf("\t---------------\n");
            }
        }
        if (a==4){
            triparNuminscription(e,n);
            for(i=0;i<n;i++){
                printf("%d\n",e[i].Numinscription);
            }
        }
        if (a == 5){
            rechercher_un_etudiant_par_num(e,n);
        }
        if (a == 6){
            rechercher_un_etudiant_par_nom(e,n);
        }
        
        printf("Entrez : ");
        scanf("%d",&a);
    }
    if (a==0){
        exit(0);
    }
}

/*Cette fonction permet à l'administrateur de voir la liste des étudiants inscris et d'ajouter d'autres étudiants à la liste*/

void administration(){
    FILE * pfile ;
    int n,i,j,a;
    char module[30];
    int v,k=0;
    pfile = fopen("dossier d'etudiants.txt","a");
    printf("\tPour afichier la liste des etudiants entrez 1.\n\tPour ajouter des etudiants entrez 2.\n\tENTRER: ");
    scanf("%d",&v);
    if (v==1){
        affichage();
    }
    if (v==2){
        printf("Entrez le nombre des etudiants : ");
        scanf("%d",&n);
        etudiant e[n];
        for (i=0;i<n;i++){
            printf("Entez le numero d'inscription d'etudiant %d:",i+1);
            scanf("%d",&e[i].Numinscription);
            fprintf(pfile,"%d\t",e[i].Numinscription);
            printf("Entez le nom d'etudiant %d: ",i+1);
            scanf("%s",e[i].nom);
            fprintf(pfile,"%s\t",e[i].nom);
            for (j=0;j<2;j++){
                printf("\tEntrez le nom de module %d :",j+1);
                scanf("%s",module);
                fprintf(pfile,"%s\t",module);
                printf("Entez la note d'etudiant %d dans le module %s: ",i+1,module);
                scanf("%f",&e[i].note[j]);
                while(e[i].note[j]<0 || e[i].note[j]>20){
                    printf("Erreur : la note est invalide!!!\nEntez la note  d'etudiant %d dans le module %s: ",i+1,module);
                    scanf("%f",&e[i].note);
                }
                fprintf(pfile,"%f\t",e[i].note[j]);
            }
            printf("Entrez le status de presence d'etudiant %d 0 si il est absent 1 si il est present : ",i+1);
            scanf("%d",&e[i].present);
            while(e[i].present!=0 && e[i].present!=1){
                printf("Erreur 404: le status de presence est invalid!!!\nEntrez le status de presence a nouveau : ");
                scanf("%d",&e[i].present);
            }
            fprintf(pfile,"%d\n",e[i].present);
        }
        fclose(pfile);
        printf("Pour faire manipuler ces donnees ENTREZ:\n1 Pour trier les etudiant selon le nom.\n2 Pour trier les etudiant selon la note croissnate.\n3 Pour trier les etudiant selon la note decroissante.\n4 Pour trier les etudiant selon numero d'inscription.\n5 Pour rechercher un etudiant par son numero d'inscription.\n6 Pour rechercher un etudiant par son nom.\n0 Pour arreter le programme.\nEntrez : ");
        scanf("%d",&a);
        manipulation_etudiants(e,n,a);
    }
}

/*Crée une fonction qui permet à l'étudiant(e) de voir sa note dans un module*/

void etudiants(){
    int Numinscription1,j;
    int d=0,k=0;
    etudiant e;
    char name[30];
    char module[20],module1[20];
    printf("Entrez votre numero d'inscription :");
    scanf("%d",&Numinscription1);
    FILE *pfile;
    pfile=fopen("dossier d'etudiants.txt","r");
    printf("Pour voir votre notes entrez 1.\nPour quiter entrez 0.\nENTREZ : ");
    scanf("%d",&d);
    if (d==1){
        while(feof(pfile)==0){
            fscanf(pfile,"%d\t",&e.Numinscription);
            fscanf(pfile,"%s\t",e.nom);
            if(Numinscription1==e.Numinscription){
                for(j=0;j<2;j++){
                    fscanf(pfile,"%s\t",module);
                    fscanf(pfile,"%f\t",&e.note[j]); 
                    printf("\t\tVotre note de module %s est : %.2f\n",module,e.note[j]);
                    if(e.note[j]>=10&& e.note[j]<=20){
                        printf("\tFelicitation vous avez valide ce module.\n");
                    }
                    else{
                        printf("\tMalheureusement vous n'avez pas reussir a valide ce module ):, redoubler votre efforts!!!\n");
                    }
                }
                exit(0);
            }
            for(j=0;j<2;j++){
                fscanf(pfile,"%s\t",module);
                fscanf(pfile,"%f\t",&e.note[j]);
            }
            fscanf(pfile,"%d\n",&e.present);
        }
        fclose(pfile);
    }
    exit(0);
}

/*La fonction principale*/
int main()
{
    signin();
    return 0;
}

