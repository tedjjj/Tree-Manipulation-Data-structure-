Sécurité des messages : chiffrement standard Aucun élément sélectionné 

Aller au contenu
Utiliser Messagerie Ecole nationale supérieure d'informatique avec un lecteur d'écran
in:sent 

Conversations
 
Règlement du programme
Fourni par Google
Dernière activité sur le compte : il y a 4 minutes
Détails
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
 #include <stdbool.h>
//colors for menu
#define RESET       "\033[0m"
#define RED         "\033[91m"
#define GREEN       "\033[92m"
#define MAGENTA     "\033[95m"
#define BLUE        "\033[94m"
#define BOLD        "\033[1m"
void show_menu() {
    printf("\n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"RED"          BST OPTIMIZATION - TP KHAWARIZM          "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf (BLUE"|" MAGENTA"  1.  Generate Random Words File                   "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"MAGENTA"  2.  Construct BST1, BST2, BST3 from File         "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|" MAGENTA"  3.  Run Full BST Test Suite                      "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"MAGENTA"  4.  Search for a Single Word                     "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"MAGENTA"  5.  Range Search [Word1 - Word2]                 "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"MAGENTA"  6.  Inorder / Preorder Traversal                 "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"MAGENTA"  8. module 01                           "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"MAGENTA"  9. module 02                           "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"MAGENTA"  7.  Exit Program                                 "BLUE"| \n");
    printf(BLUE "=====================================================\n");
   
    printf(BLUE"|"GREEN"  Select an option [1-9]:                          "BLUE"| \n");
    printf(BLUE "=====================================================\n");
}
void show_menu_test() {
    printf("\n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"RED"          BST                                      "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf (BLUE"|" MAGENTA"  1.  Bst -- 1                                     "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|"MAGENTA"  2.  Bst -- 2                                     "BLUE"| \n");
    printf(BLUE "=====================================================\n");
    printf(BLUE"|" MAGENTA"  3.  Bst -- 3                                     "BLUE"| \n");
    printf(BLUE "=====================================================\n");
     printf(BLUE"|" MAGENTA"  4.  back                                         "BLUE"| \n");
    printf(BLUE "=====================================================\n");
   
}
/**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Realisee par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

   
  /*--------ACTION HEAD---------------------------*/

  /* BST CREATION  --- */


  typedef char * string255 ;
  typedef char * string2 ;


  /** Implementation **\: FILE DE CHAINES DE CARACTERES**/
  /** Files d'attente **/

  typedef string255 Typeelem_Fs ;
  typedef  struct Filedattente_Fs * Pointeur_Fs ;
  typedef  struct Maillon_Fs * Ptliste_Fs ;

  struct Maillon_Fs
    {
      Typeelem_Fs Val ;
      Ptliste_Fs Suiv  ;
    };

  struct Filedattente_Fs
    {
      Ptliste_Fs Tete, Queue ;
    };

  void Creerfile_Fs ( Pointeur_Fs *Fil   )
    {
      *Fil = (struct Filedattente_Fs *) malloc( sizeof( struct Filedattente_Fs)) ;
      (*Fil)->Tete = NULL ;
      (*Fil)->Queue = NULL ;
    }

  bool Filevide_Fs (Pointeur_Fs Fil  )
    { return  Fil->Tete == NULL ;}

  void Enfiler_Fs ( Pointeur_Fs Fil , Typeelem_Fs Val   )
    {
      Ptliste_Fs Q;

      Q = (struct Maillon_Fs *) malloc( sizeof( struct Maillon_Fs))   ;
      Q->Val = (char *) malloc(256 * sizeof(char));
      strcpy( Q->Val , Val );
      Q->Suiv = NULL;
      if ( ! Filevide_Fs(Fil) )
        Fil->Queue->Suiv = Q ;
      else Fil->Tete = Q;
        Fil->Queue = Q;
    }

  void Defiler_Fs (Pointeur_Fs Fil, Typeelem_Fs *Val )
    {
      if (! Filevide_Fs(Fil) )
        {
          strcpy( *Val , Fil->Tete->Val );
          Fil->Tete =  Fil->Tete->Suiv;
        }
      else printf ("%s \n", "File d'attente vide");
    }


  /** Implementation **\: ARBRE BINAIRE DE CHAINES DE CARACTERES**/

  /** Arbres de recherche binaire **/

  typedef string255 Typeelem_As   ;
  typedef struct Noeud_As * Pointeur_As ;

  struct Noeud_As
    {
      Typeelem_As  Val ;
      Pointeur_As Fg ;
      Pointeur_As Fd ;
      Pointeur_As Pere ;
     } ;

  Typeelem_As Info_As( Pointeur_As P )
    { return P->Val;   }

  Pointeur_As Fg_As( Pointeur_As P)
    { return P->Fg ; }

  Pointeur_As Fd_As( Pointeur_As P)
    { return P->Fd ; }

  Pointeur_As Pere_As( Pointeur_As P)
    { return P->Pere ; }

  void Aff_info_As ( Pointeur_As P, Typeelem_As Val)
    {
       strcpy( P->Val , Val );
    }

  void Aff_fg_As( Pointeur_As P, Pointeur_As Q)
    { P->Fg =  Q;  }

  void Aff_fd_As( Pointeur_As P, Pointeur_As Q)
    { P->Fd =  Q ; }

  void Aff_pere_As( Pointeur_As P, Pointeur_As Q)
    { P->Pere =  Q ; }

  void Creernoeud_As( Pointeur_As *P)
    {
      *P = (struct Noeud_As *) malloc( sizeof( struct Noeud_As))   ;
      (*P)->Val =(string255 ) malloc(255 * sizeof(string255));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_As( Pointeur_As P)
    { free( P ) ; }


  /** Implementation **\: FICHIER **/

  /* Traitement des fichiers ouverts */

  struct _Noeud
    {
      FILE * Var_fich ;
      char * Nom_fich ;
      int Sauv_pos;
      struct _Noeud *Suiv ;
    } ;

  typedef struct _Noeud * _Ptr_Noeud;

  _Ptr_Noeud  _Pile_ouverts  = NULL;

  /* Teste si un fichier est ouvert */
  _Ptr_Noeud _Ouvert ( char * Fp)
    {
      _Ptr_Noeud P;
      bool Trouv ;
      P = _Pile_ouverts; Trouv = false ;
      while ((P != NULL) && ! Trouv )
        if ( strcmp(P->Nom_fich, Fp) == 0)
        Trouv = true;
        else P = P->Suiv;
      return P;
    }

  /* Ajouter un fichier ouvert */
  void _Empiler_ouvert ( char *Fp, FILE *Fl)
    {
      _Ptr_Noeud  P ;
      P = (_Ptr_Noeud) malloc( sizeof( struct _Noeud)) ;
      P->Nom_fich = Fp;
      P->Var_fich = Fl;
      P->Suiv = _Pile_ouverts;
      _Pile_ouverts = P;
    }

  /* Supprimer un fichier ouvert et rendre son nom*/
  char * _Depiler_ouvert ( FILE *Fl)
    {
      char *Fp = (char *) malloc(100);
      _Ptr_Noeud P,  Prec  ;
      P= _Pile_ouverts;
      Prec = NULL;
      while (P->Var_fich != Fl )
        { Prec = P ; P = P->Suiv ;}
      strcpy(Fp, P->Nom_fich);
      if (Prec != NULL)
        Prec->Suiv = P->Suiv;
      else _Pile_ouverts = P->Suiv;
      free (P);
      return Fp ;
    }


  /** Fichiers **/

  typedef char _Tx[255];
  /** Types des champs du bloc **/
  typedef string255 Typechamp1_s;
  typedef _Tx Typechamp1_s_Buf ;

  /** Type du bloc de donnees du fichier **/
  typedef struct
    {
      Typechamp1_s_Buf Champ1 ;
    }  Typestruct1_s_Buf;

  /** Type de la structure du bloc de donnees du fichier **/
  typedef struct
    {
      Typechamp1_s Champ1 ;
    }  Typestruct1_s_;

  typedef Typestruct1_s_  * Typestruct1_s ;

  typedef Typestruct1_s Typestr_Ts;
  typedef Typestruct1_s_ Type_Ts;


  Typechamp1_s Struct1_Ts ( Typestruct1_s Buf )
    {
      return Buf->Champ1;
    }

  /** Manipulation de la structure **/
  void Aff_struct1_Ts ( Typestruct1_s Buf, Typechamp1_s Val )
    {
     strcpy( Buf->Champ1 , Val );
    }

  /** Machine abstaite sur les fichiers **/

  void Ouvrir_s ( FILE **s , char *Fp , char * Mode )
    {
      _Ptr_Noeud P = _Ouvert(Fp);
      if ( P != NULL )
      /* Le fichier est deja ouvert */
        {
         P->Sauv_pos = ftell (P->Var_fich);
         fclose(P->Var_fich);
        }
      /* Le fichier est non ouvert */
      if ( strcmp(Mode,"A") == 0)
        *s = fopen(Fp, "r+b");
      else
        *s = fopen(Fp, "w+b");
      _Empiler_ouvert( Fp, *s);
    }

  void Fermer_s ( FILE * s )
    {
      char *Fp = (char *) malloc(100);
      _Ptr_Noeud P;
      strcpy(Fp, _Depiler_ouvert(s));
      fclose(s) ;
      /* Ya-til un fichier ouvert avec le m?me nom ?  */
      /* Si Oui, le Reouvrir a la position sauvegardee */
      P =  _Ouvert (Fp);
      if ( P != NULL)
      {
        s = fopen(P->Nom_fich, "r+b");
        fseek(s, P->Sauv_pos, 0);
      }
    }

  void Ecrireseq_s ( FILE * s, Typestruct1_s Buf  )
    {
      Typestruct1_s_Buf Buffer ;
      int I, J;
      for(J=0; J<= strlen(Buf->Champ1); ++J)
        Buffer.Champ1[J] = Buf->Champ1[J];
      fwrite(&Buffer, sizeof( Typestruct1_s_Buf), 1, s)  ;
    }

  void Ecriredir_s ( FILE * s, Typestruct1_s Buf, int N )
    {
      Typestruct1_s_Buf Buffer ;
      int I, J;
      for(J=0; J<= strlen(Buf->Champ1); ++J)
        Buffer.Champ1[J] = Buf->Champ1[J];
      fseek(s, (long) (N-1)* sizeof(  Typestruct1_s_Buf), 0);
      fwrite(&Buffer, sizeof( Typestruct1_s_Buf), 1, s)  ;
    }

  void Lireseq_s ( FILE * s, Typestruct1_s Buf )
    {
      Typestruct1_s_Buf Buffer ;
      int I, J;
      if (fread(&Buffer, sizeof( Typestruct1_s_Buf), 1, s) != 0) {
      for(J=0; J<= strlen(Buffer.Champ1); ++J)
        Buf->Champ1[J] = Buffer.Champ1[J];
      }
    }

  void Liredir_s ( FILE * s, Typestruct1_s Buf, int N)
    {
      Typestruct1_s_Buf Buffer ;
      int I, J;
      fseek(s, (long) (N-1)* sizeof( Typestruct1_s_Buf), 0 );
      fread(&Buffer, sizeof( Typestruct1_s_Buf), 1, s);
      for(J=0; J<= strlen(Buffer.Champ1); ++J)
        Buf->Champ1[J] = Buffer.Champ1[J];
    }

  void Rajouter_s ( FILE * s, Typestruct1_s Buf )
    {
      Typestruct1_s_Buf Buffer ;
      int I, J;
      for(J=0; J<= strlen(Buf->Champ1); ++J)
        Buffer.Champ1[J] = Buf->Champ1[J];
      fseek(s, 0, 2); /* Fin du fichier */
      fwrite(&Buffer, sizeof( Typestruct1_s_Buf), 1, s)  ;
    }

  bool Finfich_s (FILE * s)
    {
      long K = ftell(s);
      fseek(s, 0, 2); /* Fin du fichier */
      long K2 = ftell(s);   /* position a partir du debut */
      if  (K==K2)
        { fseek(s, K, 0); return 1;}
      else
        { fseek(s, K, 0); return 0;}
    }

  int Alloc_bloc_s (FILE * s)
    {
      long K;
      fseek(s, 0, 2); /* Fin du fichier */
      K = ftell(s);   /* position a partir du debut */
      K = K / sizeof (Typestruct1_s_Buf);
      K ++;
      return(K);
    }


  /** Implementation **\: PILE DE CHAINES DE CARACTERES**/
  /** Piles **/

  typedef string255 Typeelem_Ps ;
  typedef struct Maillon_Ps * Pointeur_Ps ;
  typedef   Pointeur_Ps  Typepile_Ps  ;

  struct Maillon_Ps
    {
      Typeelem_Ps  Val ;
      Pointeur_Ps Suiv ;
    } ;

  void Creerpile_Ps( Pointeur_Ps *P )
    { *P = NULL ; }

  bool Pilevide_Ps ( Pointeur_Ps P )
    { return  (P == NULL ); }

  void Empiler_Ps ( Pointeur_Ps *P,  Typeelem_Ps Val )
    {
      Pointeur_Ps Q;

      Q = (struct Maillon_Ps *) malloc( sizeof( struct Maillon_Ps))   ;
      Q->Val =(string255 ) malloc(255 * sizeof(string255));
      strcpy( Q->Val , Val );
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_Ps ( Pointeur_Ps *P,  Typeelem_Ps *Val )
    {
      Pointeur_Ps Sauv;

      if (! Pilevide_Ps (*P) )
        {
          strcpy( *Val , (*P)->Val );
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implementation **\: TABLEAU DE CHAINES DE CARACTERES**/

  /** Tableaux **/

  typedef string255 Typeelem_V120s ;
  typedef Typeelem_V120s * Typevect_V120s ;

  Typeelem_V120s Element_V120s ( Typevect_V120s V , int I1  )
    {
      return  *(V +  (I1-1)  ) ;
    }

  void Aff_element_V120s ( Typevect_V120s V  , int I1 ,  Typeelem_V120s Val )
    {
     strcpy( *(V +  (I1-1)  ) , Val );
    }

  /** Variables du programme principal **/
  string2 T1;
  string2 T2;
  string2 T3;
  Pointeur_Fs Que=NULL;
  Pointeur_As Bst0=NULL;
  Pointeur_As Bst1=NULL;
  Pointeur_As Bst2=NULL;
  Pointeur_As Bst3=NULL;
  Pointeur_As New=NULL;
  string255 X;
  string255 Y;
  string255 Z;
  string255 Swsearch;
  string255 Rgs1;
  string255 Rgs2;
  string2 X1;
  string2 Y1;
  string2 Z1;
  FILE *F1,*F2,*F;
  Typestruct1_s S ;
  int J;
  int I;
  int Cmp;
  int Choix;

  /** Fonctions standards **/

  char *Caract ( string255 Ch , int I )
    {
     char *s = (char *) malloc(2);
      s[0] = Ch[I-1];
      s[1] = '\0';
      return  s;
    }

  int Aleanombre( int N )
    { return ( rand() % N ); }

  char  *Aleachaine ( int N )
    {
      int k;
     char *Chaine = (char *) malloc(N + 1);

      char  * Chr1 = "abcdefghijklmnopqrstuvwxyz";
      char  * Chr2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      for (k=0;k<N; k++)
        switch ( rand() % 2 ){
        case 0 :  *(Chaine+k) = Chr1[rand() % 26] ; break ;
        case 1 :  *(Chaine+k) = Chr2[rand() % 26] ; break ;
        }
      Chaine[k] =  '\0' ;

      return (Chaine);
    }

  int Max (int a, int b)
    {
      if (a > b) return(a);
      else return(b);
    }


  /** Initialisation d'une structure **/
  void Init_struct_Ts ( Typestr_Ts S, Type_Ts S_ )
    {
      S->Champ1 = S_.Champ1 ;
    }


  /** Prototypes des fonctions **/

  void Display_tests (Pointeur_As *Bst , string2 *X1 , string2 *Y1 , string2 *Z1 , int *Cmp);
  void Count_number_of_words (Pointeur_As *Root , string2 *X , string2 *Y , string2 *Z , int *Count);
  void End_programme (Pointeur_As *Bst);
  void Create_bst1 (Pointeur_As *Bst1 , FILE *Fichierr , int *Fille_len , string255 *X , string255 *Y , string255 *Z);
  void Recherche_to_insert (Pointeur_As *R , Pointeur_As *Per , Pointeur_As *P , string255 *Val);
  void Recherche_by_path (Pointeur_As *R , Pointeur_As *Per , Pointeur_As *P , string255 *Val , int *Path);
  void Insert_bst1 (Pointeur_As *R , string255 *Val , string2 *X , string2 *Y , string2 *Z);
  void N_node_xyz_level (Pointeur_As *Bst_tete , string2 *X1 , string2 *Y1 , string2 *Z1);
  void Values_of_level (Pointeur_As *Bst_tete , int *Level , Pointeur_Ps *Stack);
  void Create_bst2 (Pointeur_As *Bst1 , FILE *Fichierr , int *Fille_len , string255 *X , string255 *Y , string255 *Z);
  void Insert_bst2 (Pointeur_As *R , string255 *Val , string2 *X , string2 *Y , string2 *Z);
  void Swap_xy (string2 *X , string2 *Y);
  void Order_xyz (string2 *X , string2 *Y , string2 *Z);
  void Insert_bst3 (Pointeur_As *R , string255 *Val , string2 *X , string2 *Y , string2 *Z);
  void Range_display (string255 *Word1 , string255 *Word2 , Pointeur_As *Bst_tete);
  void Range_words_order (Pointeur_Fs *Quues);
  void Create_bst3 (Pointeur_As *Bst1 , FILE *Fichierr , int *Fille_len , string255 *X , string255 *Y , string255 *Z);
  void Generate_file (FILE *F , int *J , string255 *X , string255 *Y , string255 *Z);
  void Inorder (Pointeur_As *Root);
  void Preorder (Pointeur_As *Root);
  void Tri_vecteur (Typevect_V120s *Vect , int *N);
  void Range_search (Pointeur_As *Bst_tete , string255 *Word1 , string255 *Word2 , Pointeur_Fs *Quues);
  void Range_apply (Pointeur_As *Bst1 , Pointeur_As *Bst2 , Pointeur_As *Bst3 , string255 *Word1 , string255 *Word2 , string2 *X , string2 *Y , string2 *Z);
  bool  Cas_triv (Pointeur_As *Bst_tete , string255 *Curr_node , string255 *Word , string2 *X , string2 *Y , string2 *Z) ;
  bool  Search_in_bst (Pointeur_As *Bst , string255 *Lkelma , string2 *X , string2 *Y , string2 *Z) ;
  bool  Search_word (Pointeur_As *Bst1 , Pointeur_As *Bst2 , Pointeur_As *Bst3 , string255 *Lkelma , string2 *X , string2 *Y , string2 *Z) ;
  int  Depth_tree (Pointeur_As *Bst_tete) ;
  Pointeur_As Rotation_bst13 (Pointeur_As *Bst_x) ;
  Pointeur_As Rot_left (Pointeur_As *Bst_node) ;
  Pointeur_As Rot_right (Pointeur_As *Bst_node) ;
  Pointeur_As Rotation_bst2 (Pointeur_As *Bst_x , int *Lengh_path) ;
  bool  In_xyz (string255 *Kelma , string2 *X , string2 *Y , string2 *Z) ;
  int  Quues_lengh (Pointeur_Fs *Filee) ;

  /* MODULES BODIES ----------------------------------------------------------------------*/
  /*ACTIONS  ---------------------------------------------- ------------------------------*/
  void Display_tests (Pointeur_As *Bst , string2 *X1 , string2 *Y1 , string2 *Z1 , int *Cmp)
    {

      /** Corps du module **/
     printf (  RED"------------------------------------------BST1-TEST----------------------------------\n" ) ;
     printf ( BLUE "1) Count the number of words starting with X, Y, and Z.   \n " ) ;
     printf ( RED "--------------------------------------------------------------------------------------- \n"GREEN ) ;
     *Cmp  =  0 ;
     Count_number_of_words ( & *Bst , & *X1 , & *Y1 , & *Z1 , & *Cmp ) ;
    /*MTNSASH CMP T3ARFO*/
     printf (GREEN "the number : %d\n", *Cmp ) ;
     printf ( RED "--------------------------------------------------------------------------------------- \n" ) ;
     printf ( BLUE" 2) Compute the depth of the tree.    \n" ) ;
     printf ( RED "--------------------------------------------------------------------------------------- \n"GREEN ) ;
     printf ( GREEN"the depth : %d\n", Depth_tree(&*Bst) ) ;
     printf ( RED"---------------------------------------------------------------------------------------\n " ) ;
     printf ( BLUE" 4) For each level, compute and display the number of nodes starting with X, Y, and Z \n " ) ;
     printf (RED "---------------------------------------------------------------------------------------\n "GREEN ) ;
     N_node_xyz_level ( & *Bst , & *X1 , & *Y1 , & *Z1 ) ;
     printf ( RED"\n-------------------------------------------------------------------------------------\n " ) ;
     printf ( BLUE "3) Perform an inorder traversal  \n  " ) ;
     printf ( RED "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n "GREEN ) ;
     Inorder ( & *Bst ) ;
     printf ( RED" %s", "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n " ) ;
   
    }
  /* MODULES BODIES ----------------------------------------------------------------------*/
  /*ACTIONS  ---------------------------------------------- ------------------------------*/
  /* COUNT NUM OF WORD THAT STARTRT WITH X Y Z */

  void Count_number_of_words (Pointeur_As *Root , string2 *X , string2 *Y , string2 *Z , int *Count)
    {
      /** Variables locales **/
      Pointeur_As _Px1=NULL;
      string255 _Px2;
      Pointeur_As _Px3=NULL;

      /** Corps du module **/
     _Px2 =( char* ) malloc(255 * sizeof(char));
     if( ( *Root != NULL )) {
       _Px1 =  Fg_As ( *Root ) ;
       Count_number_of_words ( &_Px1, & *X , & *Y , & *Z , & *Count ) ;
       strcpy(_Px2,  Info_As ( *Root ) );
       if( In_xyz ( &_Px2, & *X , & *Y , & *Z )) {
         *Count  =  *Count + 1 ;
         ;
       
       } ;
       _Px3 =  Fd_As ( *Root ) ;
       Count_number_of_words ( &_Px3, & *X , & *Y , & *Z , & *Count ) ;
     
     }
    }
  /*------------------------------------------------------------------------*/
  void End_programme (Pointeur_As *Bst)
    {
      /** Variables locales **/
      Pointeur_As _Px1=NULL;
      Pointeur_As _Px2=NULL;

      /** Corps du module **/
     if( ( *Bst != NULL )) {
       _Px1 =  Fg_As ( *Bst ) ;
       End_programme ( &_Px1) ;
       _Px2 =  Fd_As ( *Bst ) ;
       End_programme ( &_Px2) ;
       Liberernoeud_As ( *Bst ) ;
     
     }
    }
  /*------------------------------------------------------------------------*/
  void Create_bst1 (Pointeur_As *Bst1 , FILE *Fichierr , int *Fille_len , string255 *X , string255 *Y , string255 *Z)
    {
      /** Variables locales **/
      Typestruct1_s S ;
      int J;
      string255 Tempchaine;
      string2 T1;
      string2 T2;
      string2 T3;

      /** Corps du module **/
     S = (Typestruct1_s)malloc(sizeof(Typestruct1_s));
     S->Champ1 =(char*) malloc(255 * sizeof(char));
     Tempchaine =(char*) malloc(255 * sizeof(char));
     T1 =(char*) malloc(2 * sizeof(char));
     T2 =(char*) malloc(2 * sizeof(char));
     T3 = (char*)malloc(2 * sizeof(char));
     J  =  1 ;
     Ouvrir_s (&Fichierr , "D:/FILEWORD/WORDS.txt" , "A" ) ;
     while( ( J <= *Fille_len )) {
       Liredir_s ( Fichierr , S , J ) ;
       J  =  J + 1 ;
       strcpy (T1,   Caract ( *X , 1 )) ;
       strcpy (T2,   Caract ( *Y , 1 )) ;
       strcpy (T3,   Caract ( *Z , 1 )) ;
       strcpy (Tempchaine,   Struct1_Ts ( S  )) ;
       Insert_bst1 ( & *Bst1 , & Tempchaine , & T1 , & T2 , & T3 ) ;
     
 } ;
     Fermer_s ( Fichierr ) ;
   
    }
    /*-----------------------------------------------------------------------*/
    void Insert_bst0 (Pointeur_As *R , string255 *Val , string2 *X , string2 *Y , string2 *Z)
    {
      /** Variables locales **/
      Pointeur_As Q=NULL;
      Pointeur_As Per=NULL;
      Pointeur_As P=NULL;

      /** Corps du module **/
     Recherche_to_insert ( & *R , & Per , & P , & *Val ) ;
     if( P == NULL) {
       Creernoeud_As (& Q ) ;
       Aff_info_As ( Q , *Val ) ;
       if( Per == NULL) {
         *R  =  Q ;
         Aff_pere_As ( *R , NULL ) ;
         }
       else
         {
         if(strcmp( Info_As ( Per ), *Val) > 0 ) {
           Aff_fg_As ( Per , Q ) ;
           }
         else
           {
           Aff_fd_As ( Per , Q ) ;
         
         } ;
         Aff_pere_As ( Q , Per ) ;
       
       } ;
     } ;
   
    }
  /*------------------------------------------------------------------*/
    void Create_bst0 (Pointeur_As *Bst0, FILE *Fichierr , int *Fille_len , string255 *X , string255 *Y , string255 *Z)
    {
      /** Variables locales **/
      Typestruct1_s S ;
      int J;
      string255 Tempchaine;
      string2 T1;
      string2 T2;
      string2 T3;

      /** Corps du module **/
     S = (Typestruct1_s)malloc(sizeof(Typestruct1_s));
     S->Champ1 =(char*) malloc(255 * sizeof(char));
     Tempchaine =(char*) malloc(255 * sizeof(char));
     T1 =(char*) malloc(2 * sizeof(char));
     T2 =(char*) malloc(2 * sizeof(char));
     T3 = (char*)malloc(2 * sizeof(char));
     J  =  1 ;
     Ouvrir_s (&Fichierr , "D:/FILEWORD/WORDS.txt" , "A" ) ;
     while( ( J <= *Fille_len )) {
       Liredir_s ( Fichierr , S , J ) ;
       J  =  J + 1 ;
       strcpy (T1,   Caract ( *X , 1 )) ;
       strcpy (T2,   Caract ( *Y , 1 )) ;
       strcpy (T3,   Caract ( *Z , 1 )) ;
       strcpy (Tempchaine,   Struct1_Ts ( S  )) ;
       Insert_bst0 ( & *Bst0 , & Tempchaine , & T1 , & T2 , & T3 ) ;
     
 } ;
     Fermer_s ( Fichierr ) ;
   
    }
  /*------------------------------------------------------------------------*/
  void Recherche_to_insert (Pointeur_As *R , Pointeur_As *Per , Pointeur_As *P , string255 *Val)
    {
      /** Variables locales **/
      bool Trouv;

      /** Corps du module **/
     Trouv  =  false ;
     *P  =  *R ;
     *Per  =  NULL ;
     if( *P == NULL) {
       *Per  =  NULL ;
       }
     else
       {
       while( ( *P != NULL ) && ( ! Trouv )) {
         if(strcmp( *Val, Info_As ( *P )) == 0 ) {
           Trouv  =  true ;
           }
         else
           {
           *Per  =  *P ;
           if(strcmp( *Val, Info_As ( *P )) > 0 ) {
             *P  =  Fd_As ( *P ) ;
             }
           else
             {
             *P  =  Fg_As ( *P ) ;
           
           } ;
         
         } ;
       
 } ;
     
     }
    }
  /*--------------------------------------------------------------------------*/
  void Recherche_by_path (Pointeur_As *R , Pointeur_As *Per , Pointeur_As *P , string255 *Val , int *Path)
    {
      /** Variables locales **/
      bool Trouv;

      /** Corps du module **/
     *Path  =  0 ;
     Trouv  =  false ;
     *P  =  *R ;
     *Per  =  NULL ;
     if( *P == NULL) {
       *Per  =  NULL ;
       }
     else
       {
       while( ( *P != NULL ) && ( ! Trouv )) {
         if(strcmp( *Val, Info_As ( *P )) == 0 ) {
           Trouv  =  true ;
           }
         else
           {
           *Per  =  *P ;
           *Path  =  *Path + 1 ;
           if(strcmp( *Val, Info_As ( *P )) > 0 ) {
             *P  =  Fd_As ( *P ) ;
             }
           else
             {
             *P  =  Fg_As ( *P ) ;
           
           } ;
         
         } ;
       
 } ;
     
     }
    }
  /*--------------------------------------------------------------*/
  void Insert_bst1 (Pointeur_As *R , string255 *Val , string2 *X , string2 *Y , string2 *Z)
    {
      /** Variables locales **/
      Pointeur_As Q=NULL;
      Pointeur_As Per=NULL;
      Pointeur_As P=NULL;

      /** Corps du module **/
     Recherche_to_insert ( & *R , & Per , & P , & *Val ) ;
     if( P == NULL) {
       Creernoeud_As (& Q ) ;
       Aff_info_As ( Q , *Val ) ;
       if( Per == NULL) {
         *R  =  Q ;
         Aff_pere_As ( *R , NULL ) ;
         }
       else
         {
         if(strcmp( Info_As ( Per ), *Val) > 0 ) {
           Aff_fg_As ( Per , Q ) ;
           }
         else
           {
           Aff_fd_As ( Per , Q ) ;
         
         } ;
         Aff_pere_As ( Q , Per ) ;
       
       } ;
       if( In_xyz ( & *Val , & *X , & *Y , & *Z )) {
         Per  =  Rotation_bst13 ( & Q ) ;
         if( Pere_As ( Per ) == NULL) {
           *R  =  Per ;
         
         }
       }
     } ;
   
    }
    /*----------------------------------------------------------------*/
     
  void N_node_xyz_level (Pointeur_As *Bst_tete , string2 *X1 , string2 *Y1 , string2 *Z1)
    {
      /** Variables locales **/
      int Count;
      int Level;
      int I;
      Pointeur_Ps Stack=NULL;
      string255 Strng;

      /** Corps du module **/
     Strng =(char*) malloc(255 * sizeof(char));
     Level  =  Depth_tree ( & *Bst_tete ) ;
     printf ( " %d", Level ) ;
     Creerpile_Ps (& Stack ) ;
     for( I  =  0 ;I <=  Level ; ++I){
       Values_of_level ( & *Bst_tete , & I , & Stack ) ;
       Count  =  0 ;
       while( ! Pilevide_Ps ( Stack )) {
         Depiler_Ps (& Stack , &Strng ) ;
         if( In_xyz ( & Strng , & *X1 , & *Y1 , & *Z1 )) {
           Count  =  Count + 1 ;
         
         }
 } ;
       printf ( " %s", "\n THE NUMBER OF NODE XYZ IN THE LEVEL :" );
       printf ( " %d", I );
       printf ( "--  IS : " );
       printf ( " %d", Count ) ;
     
     }
    }
  /*-------------------------------------------------------------------*/
  void Values_of_level (Pointeur_As *Bst_tete , int *Level , Pointeur_Ps *Stack)
    {
      /** Variables locales **/
      Pointeur_As _Px1=NULL;
      int _Px2;
      Pointeur_As _Px3=NULL;
      int _Px4;

      /** Corps du module **/
     if( *Bst_tete != NULL) {
       if( *Level == 0) {
         Empiler_Ps (& *Stack , Info_As ( *Bst_tete ) ) ;
         }
       else
         {
         _Px1 =  Fg_As ( *Bst_tete ) ;
         _Px2 =  *Level - 1 ;
         Values_of_level ( &_Px1, &_Px2, & *Stack ) ;
         _Px3 =  Fd_As ( *Bst_tete ) ;
         _Px4 =  *Level - 1 ;
         Values_of_level ( &_Px3, &_Px4, & *Stack ) ;
       
       }
     }
    }
  /*--------------------------------------------------------------------*/
  void Create_bst2 (Pointeur_As *Bst1 , FILE *Fichierr , int *Fille_len , string255 *X , string255 *Y , string255 *Z)
    {
      /** Variables locales **/
      Typestruct1_s S ;
      int J;
      string255 Tempchaine;
      string2 T1;
      string2 T2;
      string2 T3;

      /** Corps du module **/
     S =(Typestruct1_s) malloc(sizeof(Typestruct1_s));
     S->Champ1 =(char*) malloc(255 * sizeof(char));
     Tempchaine =(char*) malloc(255 * sizeof(char));
     T1 =(char*) malloc(2 * sizeof(char));
     T2 =(char*) malloc(2 * sizeof(char));
     T3 = (char*)malloc(2 * sizeof(char));
     J  =  1 ;
     Ouvrir_s (&Fichierr , "D:/FILEWORD/WORDS.txt" , "A" ) ;
     while( ( J <= *Fille_len )) {
       Liredir_s ( Fichierr , S , J ) ;
       J  =  J + 1 ;
       strcpy (T1,   Caract ( *X , 1 )) ;
       strcpy (T2,   Caract ( *Y , 1 )) ;
       strcpy (T3,   Caract ( *Z , 1 )) ;
       strcpy (Tempchaine,   Struct1_Ts ( S  )) ;
       Insert_bst2 ( & *Bst1 , & Tempchaine , & T1 , & T2 , & T3 ) ;
     
 } ;
     Fermer_s ( Fichierr ) ;
   
    }
  /*-----------------------------------------------------------------------*/
  /* INSERT A NODE TO BST 2 */

  void Insert_bst2 (Pointeur_As *R , string255 *Val , string2 *X , string2 *Y , string2 *Z)
    {
      /** Variables locales **/
      Pointeur_As Q=NULL;
      Pointeur_As Per=NULL;
      Pointeur_As P=NULL;
      int Path;

      /** Corps du module **/
     Recherche_by_path ( & *R , & Per , & P , & *Val , & Path ) ;
     if( P == NULL) {
       Creernoeud_As (& Q ) ;
       Aff_info_As ( Q , *Val ) ;
       if( Per == NULL) {
         *R  =  Q ;
         Aff_pere_As ( *R , NULL ) ;
         }
       else
         {
         if(strcmp( Info_As ( Per ), *Val) > 0 ) {
           Aff_fg_As ( Per , Q ) ;
           }
         else
           {
           Aff_fd_As ( Per , Q ) ;
         
         } ;
         Aff_pere_As ( Q , Per ) ;
       
       } ;
       if( In_xyz ( & *Val , & *X , & *Y , & *Z )) {
         Per  =  Rotation_bst2 ( & Q , & Path ) ;
         if( Pere_As ( Per ) == NULL) {
           *R  =  Per ;
         
         }
       }
     } ;
   
    }
  /*-----------------------------------------------------------------------*/
  void Swap_xy (string2 *X , string2 *Y)
    {
      /** Variables locales **/
      string2 Tmp;

      /** Corps du module **/
     Tmp =(string2) malloc(2 * sizeof(string2));
     strcpy (Tmp,   *X) ;
     strcpy (*X,   *Y) ;
     strcpy (*Y,   Tmp) ;
   
    }
  /*----------------------------------------------------------------------*/
  void Order_xyz (string2 *X , string2 *Y , string2 *Z)
    {

      /** Corps du module **/
     if(strcmp( *X, *Y) > 0 ) {
       Swap_xy ( X , Y ) ;
     
     } ;
     if(strcmp( *X, *Z) > 0 ) {
       Swap_xy( X , Z ) ;
     
     } ;
     if(strcmp( *Y, *Z) > 0 ) {
       Swap_xy ( & *Y , & *Z ) ;
     
     }
    }
  /*------------------------------------------------------------------------*/
  /* Insert toBST 3 */

  void Insert_bst3 (Pointeur_As *R , string255 *Val , string2 *X , string2 *Y , string2 *Z)
    {
      /** Variables locales **/
      Pointeur_As Q=NULL;
      Pointeur_As Per=NULL;
      Pointeur_As P=NULL;

      /** Corps du module **/
     Recherche_to_insert ( & *R , & Per , & P , & *Val ) ;
     if( P == NULL) {
       Creernoeud_As (& Q ) ;
       Aff_info_As ( Q , *Val ) ;
       if( Per == NULL) {
         *R  =  Q ;
         Aff_pere_As ( *R , NULL ) ;
         }
       else
         {
         if(strcmp( Info_As ( Per ), *Val) > 0 ) {
           Aff_fg_As ( Per , Q ) ;
           }
         else
           {
           Aff_fd_As ( Per , Q ) ;
         
         } ;
         Aff_pere_As ( Q , Per ) ;
       
       } ;
       if( In_xyz ( & *Val , & *X , & *Y , & *Z ) == false) {
         *R  =  Rotation_bst13 ( & Q ) ;
       
       }
     } ;
   
    }
  /*---------------------------------------------------------------------------------------*/
  void Range_display (string255 *Word1 , string255 *Word2 , Pointeur_As *Bst_tete)
    {
      /** Variables locales **/
      string255 H;
      Pointeur_Fs Que=NULL;

      /** Corps du module **/
     H = (string255)malloc(255 * sizeof(string255));
     Creerfile_Fs (& Que ) ;
     Range_search ( & *Bst_tete , & *Word1 , & *Word2 , & Que ) ;
     Range_words_order ( & Que ) ;
     printf ( " %s", " LE RANGE ENTRE " );
     printf ( " %s", *Word1 );
     printf ( " %s", " ET " );
     printf ( " %s", *Word2 ) ;
     printf ( " %s", "\n-----" ) ;
     printf (RED " %s", *Word2 ) ;
     printf ( " %s", "\n-----" ) ;
     while( ! Filevide_Fs ( Que )) {
       Defiler_Fs ( Que , &*Word2 ) ;
       printf ( MAGENTA"\n --(%s)--", *Word2 ) ;
     
 } ;
     printf ( " %s", "\n-----" ) ;
     printf (RED "\n %s", *Word1 ) ;
   
    }
    /*-------------------------------------------------*/
   
  /*-------------------------------------------------------------------------*/
  void Range_words_order (Pointeur_Fs *Quues)
    {
      /** Variables locales **/
      int N;
      int I;
      Typevect_V120s T;
      string255 Strg;

      /** Corps du module **/
     T = (Typevect_V120s ) malloc( 120 *255  * sizeof(Typevect_V120s));
     int _Izw2;for (_Izw2=0; _Izw2<120; ++_Izw2)
       T[_Izw2]= (char*)malloc(255 * sizeof(char));
     Strg = (char*)malloc(255 * sizeof(char));
     N  =  Quues_lengh ( & *Quues ) ;
     for( I  =  1 ;I <=  N ; ++I){
       Defiler_Fs ( *Quues , &Strg ) ;
       Aff_element_V120s ( T , I   , Strg ) ;
     
     } ;
     Tri_vecteur ( & T , & N ) ;
     for( I  =  1 ;I <=  N ; ++I){
       strcpy (Strg,   Element_V120s ( T , I   )) ;
       Enfiler_Fs ( *Quues , Strg ) ;
     
     } ;
   
    }
  /*-------------------------------------------------------------------*/
  void Create_bst3 (Pointeur_As *Bst1 , FILE *Fichierr , int *Fille_len , string255 *X , string255 *Y , string255 *Z)
    {
      /** Variables locales **/
      Typestruct1_s S ;
      int J;
      string255 Tempchaine;
      string2 T1;
      string2 T2;
      string2 T3;

      /** Corps du module **/
     S =( Typestruct1_s ) malloc(sizeof(Typestruct1_s));
     S->Champ1 =( char * ) malloc(255 * sizeof(char));
     Tempchaine = ( char * )malloc(255 * sizeof(char));
     T1 =( char * ) malloc(2 * sizeof(char));
     T2 = ( char * )malloc(2 * sizeof(char));
     T3 = ( char * )malloc(2 * sizeof(char));
     J  =  1 ;
     Ouvrir_s (&Fichierr , "D:/FILEWORD/WORDS.txt" , "A" ) ;
     while( ( J <= *Fille_len )) {
       Liredir_s ( Fichierr , S , J ) ;
       J  =  J + 1 ;
       strcpy (T1,   Caract ( *X , 1 )) ;
       strcpy (T2,   Caract ( *Y , 1 )) ;
       strcpy (T3,   Caract ( *Z , 1 )) ;
       strcpy (Tempchaine,   Struct1_Ts ( S  )) ;
       Insert_bst3 ( & *Bst1 , & Tempchaine , & T1 , & T2 , & T3 ) ;
     
 } ;
     Fermer_s ( Fichierr ) ;
   
    }
  /*--------------------------------------------------------------------*/
  void Generate_file_2 (FILE *F   )
    {
      /** Variables locales **/
      string255 Word;
      Typestruct1_s S ;
      int I,J;
      int C;
      string255 _Sx;
      Type_Ts S_S;

      /** Corps du module **/
     Word =(char*) malloc(255 * sizeof(char));
     S = (Typestruct1_s)malloc(sizeof(Typestruct1_s));
     S->Champ1 = (char*)malloc(255 * sizeof(char));
     _Sx =(char*) malloc(255 * sizeof(char));
     J  = 10000 ;
     Ouvrir_s (&F , "D:/FILEWORD/WORDS.txt" , "N" ) ;
     for( C  =  1 ;C <=  J ; ++C){
     
      strcpy (Word,   Aleachaine(Aleanombre(5 ) + 3 )) ;
      
       S_S.Champ1= ( char * )malloc(255 * sizeof(char));
       strcpy(S_S.Champ1 , Word) ;
       Init_struct_Ts ( S , S_S )  ;
       Ecriredir_s ( F , S , C ) ;
     

     } ;
     Fermer_s ( F ) ;
   
    }
  /*-------------------------------------------------------------------*/
  void Generate_file (FILE *F , int *J , string255 *X , string255 *Y , string255 *Z)
    {
      /** Variables locales **/
      string255 Word;
      Typestruct1_s S ;
      int I;
      int C;
      string255 _Sx;
      Type_Ts S_S;

      /** Corps du module **/
     Word =(char*) malloc(255 * sizeof(char));
     S = (Typestruct1_s)malloc(sizeof(Typestruct1_s));
     S->Champ1 = (char*)malloc(255 * sizeof(char));
     _Sx =(char*) malloc(255 * sizeof(char));
     *J  = Aleanombre(40 ) +100 ;
     Ouvrir_s (&F , "D:/FILEWORD/WORDS.txt" , "N" ) ;
     for( C  =  1 ;C <=  *J ; ++C){
       I  =  Aleanombre(10 ) ;
       if( ( I == 0 ))   {
         strcpy (_Sx, *X);
         strcpy (Word,  strcat(_Sx, Aleachaine(Aleanombre(5 ) + 3 ))) ;
         }
       else
         {
         if( ( I == 1 ))   {
           strcpy (_Sx, *Y);
           strcpy (Word,  strcat(_Sx, Aleachaine(Aleanombre(5 ) + 3 ))) ;
           }
         else
           {
           if( ( I == 2 ))   {
             strcpy (_Sx, *Z);
             strcpy (Word,  strcat(_Sx, Aleachaine(Aleanombre(5 ) + 3 ))) ;
             }
           else
             {
             strcpy (Word,   Aleachaine(Aleanombre(5 ) + 3 )) ;
           
           } ;
         
         } ;
       
       } ;
       S_S.Champ1= ( char * )malloc(255 * sizeof(char));
       strcpy(S_S.Champ1 , Word) ;
       Init_struct_Ts ( S , S_S )  ;
       Ecriredir_s ( F , S , C ) ;
     
     } ;
     Fermer_s ( F ) ;
   
    }
    /*--------------------------------------------------------------------*/
  void Inorder (Pointeur_As *Root)
    {
      /** Variables locales **/
      Pointeur_As _Px1=NULL;
      Pointeur_As _Px2=NULL;

      /** Corps du module **/
     if( ( *Root != NULL )) {
       _Px1 =  Fg_As ( *Root ) ;
       Inorder ( &_Px1) ;
       printf ( " ( %s ) --", Info_As(*Root) ) ;
       _Px2 =  Fd_As ( *Root ) ;
       Inorder ( &_Px2) ;
     
     }
    }
  /*------------------------------------------------------------------*/
  void Preorder (Pointeur_As *Root)
    {
      /** Variables locales **/
      Pointeur_As _Px1=NULL;
      Pointeur_As _Px2=NULL;

      /** Corps du module **/
     if( ( *Root != NULL )) {
       printf ( " %s", Info_As(*Root) ) ;
       _Px1 =  Fg_As ( *Root ) ;
       Preorder ( &_Px1) ;
       _Px2 =  Fd_As ( *Root ) ;
       Preorder ( &_Px2) ;
     
     }
    }
  /*------------------------------------------------------------------*/
  void Tri_vecteur (Typevect_V120s *Vect , int *N)
    {
      /** Variables locales **/
      int Minindx;
      int I;
      int J;
      string255 Min_strn;

      /** Corps du module **/
     Min_strn =( char * ) malloc(255 * sizeof(char));
     for( I  =  1 ;I <=  *N ; ++I){
       Minindx  =  I ;
       for( J  =  I + 1 ;J <=  *N ; ++J){
         if(strcmp( Element_V120s ( *Vect , Minindx   ), Element_V120s ( *Vect , J   )) < 0 ) {
           Minindx  =  J ;
         
         }
       } ;
       strcpy (Min_strn,   Element_V120s ( *Vect , I   )) ;
       Aff_element_V120s ( *Vect , I   , Element_V120s ( *Vect , Minindx   ) ) ;
       Aff_element_V120s ( *Vect , Minindx   , Min_strn ) ;
     
     }
    }
/*-------------------------------------------------------------------------------------------*/
 void Range_search2 (Pointeur_As *Bst_tete , string255 *Word1 , string255 *Word2 , Pointeur_Fs *Quues,int * count )
    {
      /** Variables locales **/
      bool Stop;
      Pointeur_As _Px1=NULL;
      Pointeur_As _Px2=NULL;

      /** Corps du module **/
     Stop  =  false ;
     if( ( *Bst_tete != NULL ) && ( Stop == false )) {
       _Px1 =  Fg_As ( *Bst_tete ) ;
       *count = *count++ ;
       Range_search2 ( &_Px1, & *Word1 , & *Word2 , & *Quues, count ) ;
       if( (strcmp( Info_As ( *Bst_tete ), *Word1) > 0  ) && (strcmp( Info_As ( *Bst_tete ), *Word2) < 0  )) {
         Enfiler_Fs ( *Quues , Info_As ( *Bst_tete ) ) ;
         }
       else
         {
         if( (strcmp( Info_As ( *Bst_tete ), *Word2) > 0  )) {
           Stop  =  true ;
         
         }
       } ;
       _Px2 =  Fd_As ( *Bst_tete ) ;
        *count = *count++ ;
       Range_search2 ( &_Px2, & *Word1 , & *Word2 , & *Quues, count ) ;
     
     }
    }


  /*----------------------------------------------------------*/
  void Range_search (Pointeur_As *Bst_tete , string255 *Word1 , string255 *Word2 , Pointeur_Fs *Quues)
    {
      /** Variables locales **/
      bool Stop;
      Pointeur_As _Px1=NULL;
      Pointeur_As _Px2=NULL;

      /** Corps du module **/
     Stop  =  false ;
     if( ( *Bst_tete != NULL ) && ( Stop == false )) {
       _Px1 =  Fg_As ( *Bst_tete ) ;
       Range_search ( &_Px1, & *Word1 , & *Word2 , & *Quues ) ;
       if( (strcmp( Info_As ( *Bst_tete ), *Word1) > 0  ) && (strcmp( Info_As ( *Bst_tete ), *Word2) < 0  )) {
         Enfiler_Fs ( *Quues , Info_As ( *Bst_tete ) ) ;
         }
       else
         {
         if( (strcmp( Info_As ( *Bst_tete ), *Word2) > 0  )) {
           Stop  =  true ;
         
         }
       } ;
       _Px2 =  Fd_As ( *Bst_tete ) ;
       Range_search ( &_Px2, & *Word1 , & *Word2 , & *Quues ) ;
     
     }
    }
  /*--------------------------------------------------------------*/
  void Range_apply (Pointeur_As *Bst1 , Pointeur_As *Bst2 , Pointeur_As *Bst3 , string255 *Word1 , string255 *Word2 , string2 *X , string2 *Y , string2 *Z)
    {
      /** Variables locales **/
      string255 Tmp;

      /** Corps du module **/
     Tmp   =( char * ) malloc(255 * sizeof(char));
     if(strcmp( *Word2, *Word1) < 0 )
   {    strcpy (Tmp,   *Word2) ;
       strcpy (*Word2,   *Word1) ;
       strcpy (*Word1,   Tmp) ;
     
     } ;
     if( In_xyz ( & *Word1 , & *X , & *Y , & *Z ) == true) {
       Range_display ( & *Word1 , & *Word2 , & *Bst1 ) ;
       }
     else
       {
       if( (strcmp( Caract ( *Word1 , 1 ), *X) > 0  ) || (strcmp( Caract ( *Word1 , 1 ), *Y) > 0  ) || (strcmp( Caract ( *Word1 , 1 ), *Z) > 0  )) {
         Range_display ( & *Word1 , & *Word2 , & *Bst2 ) ;
       
         }
       else
         {
         Range_display ( & *Word1 , & *Word2 , & *Bst3 ) ;
       
       }
     }
    }
  /*---------------------------------------------------------*/
  void Range_02 (Pointeur_As *Bst1 , Pointeur_As *Bst2 , Pointeur_As *Bst3 , string255 *Word1 , string255 *Word2 , string2 *X , string2 *Y , string2 *Z,int *count)
    {
      /** Variables locales **/
      string255 Tmp;
     
      Pointeur_Fs Qu=NULL;

      /** Corps du module **/
     Tmp   =( char * ) malloc(255 * sizeof(char));
     if(strcmp( *Word2, *Word1) < 0 )
   {    strcpy (Tmp,   *Word2) ;
       strcpy (*Word2,   *Word1) ;
       strcpy (*Word1,   Tmp) ;
     
     } ;
     if( In_xyz ( & *Word1 , & *X , & *Y , & *Z ) == true) {

       Range_search2(& *Bst1,&*Word1,&*Word2,&Qu,count);
       }
     else
       {
       if( (strcmp( Caract ( *Word1 , 1 ), *X) > 0  ) || (strcmp( Caract ( *Word1 , 1 ), *Y) > 0  ) || (strcmp( Caract ( *Word1 , 1 ), *Z) > 0  )) {
         Range_search2(& *Bst2,&*Word1,&*Word2,&Qu,count);
       
         }
       else
         {
        Range_search2(& *Bst3,&*Word1,&*Word2,&Qu,count);
       
       }
     }
    }
    void module_03(Pointeur_As *Bst0 ,Pointeur_As *Bst1 , Pointeur_As *Bst2 , Pointeur_As *Bst3){
Pointeur_Fs qu;
int J,count,count0;
string255 w1 ;
printf("i  |  c | c0");
      for (int i=1;i<=10;i++){

Generate_file_2(F2);
 Ouvrir_s (&F2 , "D:/FILEWORD/WORDS.txt" , "A" ) ;
 count=0;
     while( ( J <= 10000)) {
       Liredir_s ( F2 , S , J ) ;
        string255 Tempchaine;
       strcpy (Tempchaine,   Struct1_Ts ( S  )) ;
     strcpy(w1,Tempchaine);

       J  =  J + 1 ;
        Liredir_s ( F2 , S , J ) ;
 J  =  J + 1 ;
       strcpy (Tempchaine,   Struct1_Ts ( S  )) ;
       char* X,*Y,*a;
       X[1]='X';
           Y[1]='Y';
               a[1]='a';
 Range_02(&*Bst1,&*Bst2,&*Bst3,&w1,&Tempchaine,&X,&Y,&a,&count);





      }
      count0=0;
       while( ( J <= 10000)) {
       Liredir_s ( F2 , S , J ) ;
     
 string255 Tempchaine;
 strcpy(w1,Tempchaine);
       strcpy (Tempchaine,   Struct1_Ts ( S  )) ;
       J  =  J + 1 ;
        Liredir_s ( F2 , S , J ) ;
 J  =  J + 1 ;
 
       strcpy (Tempchaine,   Struct1_Ts ( S  )) ;
 Range_search2(&*Bst0,&w1,&Tempchaine,&qu,&count0);





      }
      printf("-------------------------------------------------------------");
      printf("|%d|%d|%d|",i,count,count0);
     
    }
    Fermer_s(F2);
  }
  /*FUNCTION ------------------------------------------------*/
  bool  Cas_triv (Pointeur_As *Bst_tete , string255 *Curr_node , string255 *Word , string2 *X , string2 *Y , string2 *Z)
    {
      /** Variables locales **/
      bool  Cas_triv2 ;

      /** Corps du module **/
     Cas_triv2  =  true ;
     if( ( In_xyz ( & *Word , & *X , & *Y , & *Z ) == true )) {
       if( ( In_xyz ( & *Curr_node , & *X , & *Y , & *Z ) == false )) {
         Cas_triv2  =  false ;
       
       } }
     else
       {
       if( (strcmp( Caract ( *Word , 1 ), *X) > 0  ) || (strcmp( Caract ( *Word , 1 ), *Y) > 0  ) || (strcmp( Caract ( *Word , 1 ), *Z) > 0  )) {
         if( ( (strcmp( *Curr_node, *X) < 0  ) && (strcmp( *Curr_node, *Y) < 0  ) && (strcmp( *Curr_node, *Z) < 0  ) )) {
           Cas_triv2  =  false ;
         
         } }
       else
         {
         if( ( In_xyz ( & *Curr_node , & *X , & *Y , & *Z ) == true )) {
           Cas_triv2  =  false ;
         
         }
       }
     }
     return Cas_triv2 ;
    }
  /*--------------------------------------------------------*/
  bool  Search_in_bst (Pointeur_As *Bst , string255 *Lkelma , string2 *X , string2 *Y , string2 *Z)
    {
      /** Variables locales **/
      bool  Search_in_bst2 ;
      int I;
      string255 _Px1;
      Pointeur_As _Px2=NULL;
      Pointeur_As _Px3=NULL;

      /** Corps du module **/
     _Px1 =( char * ) malloc(255 * sizeof(char));
     if( *Bst == NULL)
     {
       Search_in_bst2  =  false ;
      }
     else
       {
       if( (strcmp( *Lkelma, Info_As ( *Bst )) == 0  )) {
         Search_in_bst2  =  true ;
         }
       else
         {
         strcpy(_Px1,  Info_As ( *Bst ) );
         if( Cas_triv ( & *Bst , &_Px1, & *Lkelma , & *X , & *Y , & *Z ) == false) {
           Search_in_bst2  =  false ;
           }
         else
           {
           if(strcmp( *Lkelma, Info_As ( *Bst )) > 0 ) {
             _Px2 =  Fd_As ( *Bst ) ;
             Search_in_bst2  =  Search_in_bst ( &_Px2, & *Lkelma , & *X , & *Y , & *Z ) ;
             }
           else
             {
             _Px3 =  Fg_As ( *Bst ) ;
             Search_in_bst2  =  Search_in_bst ( &_Px3, & *Lkelma , & *X , & *Y , & *Z ) ;
           
           }
         }
       }
     }
     return Search_in_bst2 ;
    }
  /*--------------------------------------------------------------*/


  /*----------------------------------------------------------------*/
  int  Depth_tree (Pointeur_As *Bst_tete)
    {
      /** Variables locales **/
      int  Depth_tree2 ;
      Pointeur_As _Px1=NULL;
      Pointeur_As _Px2=NULL;

      /** Corps du module **/
     if( *Bst_tete == NULL) {
       Depth_tree2  =  - 1 ;
       }
     else
       {
       _Px1 =  Fg_As ( *Bst_tete ) ;
       _Px2 =  Fd_As ( *Bst_tete ) ;
       Depth_tree2  =  Max ( Depth_tree ( &_Px1) , Depth_tree ( &_Px2) ) + 1 ;
     
     }
     return Depth_tree2 ;
    }
  /*------------------------------------------------------------------*/
  Pointeur_As Rotation_bst13 (Pointeur_As *Bst_x)
    {
      /** Variables locales **/
      Pointeur_As Rotation_bst132 =NULL;

      /** Corps du module **/
     while( Pere_As ( *Bst_x ) != NULL) {
       if( *Bst_x == Fg_As ( Pere_As ( *Bst_x ) )) {
         *Bst_x  =  Rot_right ( & *Bst_x ) ;
         }
       else
         {
         *Bst_x  =  Rot_left ( & *Bst_x ) ;
       
       } ;
     
 } ;
     Rotation_bst132  =  *Bst_x ;
   
     return Rotation_bst132 ;
    }
  /*-----------------------------------------------------------------*/
  Pointeur_As Rot_left (Pointeur_As *Bst_node)
    {
      /** Variables locales **/
      Pointeur_As Rot_left2 =NULL;
      Pointeur_As G_par=NULL;
      Pointeur_As Parent=NULL;

      /** Corps du module **/
     Parent  =  Pere_As ( *Bst_node ) ;
     G_par  =  Pere_As ( Parent ) ;
     Aff_fd_As ( Parent , Fg_As ( *Bst_node ) ) ;
     if( Fg_As ( *Bst_node ) != NULL) {
       Aff_pere_As ( Fg_As ( *Bst_node ) , Parent ) ;
     
     } ;
     Aff_fg_As ( *Bst_node , Parent ) ;
     Aff_pere_As ( Parent , *Bst_node ) ;
     Aff_pere_As ( *Bst_node , G_par ) ;
     if( G_par != NULL) {
       if( Fg_As ( G_par ) == Parent) {
         Aff_fg_As ( G_par , *Bst_node ) ;
         }
       else
         {
         Aff_fd_As ( G_par , *Bst_node ) ;
       
       } ;
     
     } ;
     Rot_left2  =  *Bst_node ;
   
     return Rot_left2 ;
    }
  /*-------------------------------------------------------------------*/
  Pointeur_As Rot_right (Pointeur_As *Bst_node)
    {
      /** Variables locales **/
      Pointeur_As Rot_right2 =NULL;
      Pointeur_As G_par=NULL;
      Pointeur_As Parent=NULL;

      /** Corps du module **/
     Parent  =  Pere_As ( *Bst_node ) ;
     G_par  =  Pere_As ( Parent ) ;
     Aff_fg_As ( Parent , Fd_As ( *Bst_node ) ) ;
     if( Fd_As ( *Bst_node ) != NULL) {
       Aff_pere_As ( Fd_As ( *Bst_node ) , Parent ) ;
     
     } ;
     Aff_fd_As ( *Bst_node , Parent ) ;
     Aff_pere_As ( Parent , *Bst_node ) ;
     Aff_pere_As ( *Bst_node , G_par ) ;
     if( G_par != NULL) {
       if( Fg_As ( G_par ) == Parent) {
         Aff_fg_As ( G_par , *Bst_node ) ;
         }
       else
         {
         Aff_fd_As ( G_par , *Bst_node ) ;
       
       } ;
     
     } ;
     Rot_right2  =  *Bst_node ;
   
     return Rot_right2 ;
    }
  /*--------------------------------------------------------------------*/
  Pointeur_As Rotation_bst2 (Pointeur_As *Bst_x , int *Lengh_path)
    {
      /** Variables locales **/
      Pointeur_As Rotation_bst22 =NULL;
      int Middle_lengh;

      /** Corps du module **/
     Middle_lengh  =  ( *Lengh_path / 2 ) ;
     while( ( Pere_As ( *Bst_x ) != NULL ) && ( ( *Lengh_path > Middle_lengh ) )) {
       if( *Bst_x == Fg_As ( Pere_As ( *Bst_x ) )) {
         *Bst_x  =  Rot_right ( & *Bst_x ) ;
         }
       else
         {
         *Bst_x  =  Rot_left ( & *Bst_x ) ;
       
       } ;
       Middle_lengh  =  Middle_lengh + 1 ;
     
 } ;
     Rotation_bst22  =  *Bst_x ;
   
     return Rotation_bst22 ;
    }
  /*-----------------------------------------------------------------*/
  bool  In_xyz (string255 *Kelma , string2 *X , string2 *Y , string2 *Z)
    {
      /** Variables locales **/
      bool  In_xyz2 ;

      /** Corps du module **/
     if( (strcmp( Caract ( *Kelma , 1 ), *X) == 0  ) || (strcmp( Caract ( *Kelma , 1 ), *Y) == 0  ) || (strcmp( Caract ( *Kelma , 1 ), *Z) == 0  )) {
       In_xyz2  =  true ;
       }
     else
       {
       In_xyz2  =  false ;
     
     }
     return In_xyz2 ;
    }
  /*--------------------------------------------------------------------*/
  int  Quues_lengh (Pointeur_Fs *Filee)
    {
      /** Variables locales **/
      int  Quues_lengh2 ;
      int I;
      string255 H;
      Pointeur_Fs Newfile=NULL;

      /** Corps du module **/
     H = ( char * )malloc(255 * sizeof(char));
     I  =  0 ;
     Creerfile_Fs (& Newfile ) ;
     while( ! Filevide_Fs ( *Filee )) {
       Defiler_Fs ( *Filee , &H ) ;
       I  =  I + 1 ;
       Enfiler_Fs ( Newfile , H ) ;
     
 } ;
     *Filee  =  Newfile ;
     Quues_lengh2  =  I ;
   
     return Quues_lengh2 ;
    }

    /*------------------------------------------------------------------------------*/
    void total_lengh_path(bool result, int searchpath, int *total_found, int *total_unfound) {
    if (result) {
        *total_found += searchpath;
    } else {
        *total_unfound += searchpath;
    }
}

void Search_in_bst_02(Pointeur_As *Bst, string255 *Lkelma, string2 *X, string2 *Y, string2 *Z, bool *result, int *searchpath) {
    string255 _Px1 = (char *)malloc(255 * sizeof(char));
    Pointeur_As _Px2 = NULL;
    Pointeur_As _Px3 = NULL;

    if (*Bst == NULL) {
        *result = false;
    } else {
        if (strcmp(*Lkelma, Info_As(*Bst)) == 0) {
            *result = true;
        } else {
            strcpy(_Px1, Info_As(*Bst));
            if (!Cas_triv(Bst, &_Px1, Lkelma, X, Y, Z)  ) {
                *result = false;
            } else {
                (*searchpath)++;
                if (strcmp(*Lkelma, Info_As(*Bst)) > 0) {
                    _Px2 = Fd_As(*Bst);
                    Search_in_bst_02(&_Px2, Lkelma, X, Y, Z, result, searchpath);
                } else {
                    _Px3 = Fg_As(*Bst);
                    Search_in_bst_02(&_Px3, Lkelma, X, Y, Z, result, searchpath);
                }
            }
        }
    }
    free(_Px1);
}
/*------------------------------------------------*/
void Search_in_bst_020(Pointeur_As *Bst, string255 *Lkelma, string2 *X, string2 *Y, string2 *Z, bool *result, int *searchpath) {
    string255 _Px1 = (char *)malloc(255 * sizeof(char));
    Pointeur_As _Px2 = NULL;
    Pointeur_As _Px3 = NULL;

    if (*Bst == NULL) {
        *result = false;
    } else {
        if (strcmp(*Lkelma, Info_As(*Bst)) == 0) {
            *result = true;
        } else {
            
             
                (*searchpath)++;
                if (strcmp(*Lkelma, Info_As(*Bst)) > 0) {
                    _Px2 = Fd_As(*Bst);
                    Search_in_bst_02(&_Px2, Lkelma, X, Y, Z, result, searchpath);
                } else {
                    _Px3 = Fg_As(*Bst);
                    Search_in_bst_02(&_Px3, Lkelma, X, Y, Z, result, searchpath);
                }
            
        }
    }
    free(_Px1);
}

void Search_word_02(Pointeur_As *Bst1, Pointeur_As *Bst2, Pointeur_As *Bst3, string255 *Lkelma, string2 *X, string2 *Y, string2 *Z, bool *result, int *searchpath) {
    if (In_xyz(Lkelma, X, Y, Z)) {
        Search_in_bst_02(Bst1, Lkelma, X, Y, Z, result, searchpath);
    } else if (strcmp(Caract(*Lkelma, 1), *X) > 0 || strcmp(Caract(*Lkelma, 1), *Y) > 0 || strcmp(Caract(*Lkelma, 1), *Z) > 0) {
        Search_in_bst_02(Bst2, Lkelma, X, Y, Z, result, searchpath);
    } else {
        Search_in_bst_02(Bst3, Lkelma, X, Y, Z, result, searchpath);
    }
}

/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
void module_2(Pointeur_As *Bst0, Pointeur_As *Bst1, Pointeur_As *Bst2, Pointeur_As *Bst3) {
    // Initialize X, Y, Z
    char* X = (char*)malloc(2 * sizeof(char));
    char* Y = (char*)malloc(2 * sizeof(char));
    char* Z = (char*)malloc(2 * sizeof(char));
    X[0] = 'X'; X[1] = '\0';
    Y[0] = 'Y'; Y[1] = '\0';
    Z[0] = 'Z'; Z[1] = '\0';

    printf("\nSimulation | BST0 Found | BST0 Not Found | BST0 Total | BST Triplet Found | BST Triplet Not Found | BST Triplet Total\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    // Allocate memory
    Typestruct1_s S = (Typestruct1_s)malloc(sizeof(Typestruct1_s_));
    S->Champ1 = (char*)malloc(255 * sizeof(char));
    string255 Tempchaine = (char*)malloc(255 * sizeof(char));

    for (int i = 1; i <= 10; i++) {
        int total_found = 0, total_unfound = 0;
        int total_found0 = 0, total_unfound0 = 0;
        
        // Generate new test file with more words (100)
        Generate_file_2(F2);
        
        // Create new BSTs with proper file handling
        int file_len = 100; // Increased number of words
        Pointeur_As newBst0 = NULL, newBst1 = NULL, newBst2 = NULL, newBst3 = NULL;
        
        // Properly open and close files for each BST
        FILE *F = fopen("C:/FILEWORD/WORDS.txt", "r+b");
        Create_bst0(&newBst0, F, &file_len, &X,& Y, &Z);
        fclose(F);
        
        F = fopen("C:/FILEWORD/WORDS.txt", "r+b");
        Create_bst1(&newBst1, F, &file_len, &X,& Y,& Z);
        fclose(F);
        
        F = fopen("C:/FILEWORD/WORDS.txt", "r+b");
        Create_bst2(&newBst2, F, &file_len,& X,& Y, &Z);
        fclose(F);
        
        F = fopen("C:/FILEWORD/WORDS.txt", "r+b");
        Create_bst3(&newBst3, F, &file_len, &X, &Y,& Z);
        fclose(F);

        // Generate search words (50% from file, 50% random)
        FILE *F_search = fopen("C:/FILEWORD/WORDS.txt", "r+b");
        for (int j = 1; j <= 10000; j++) {
            // Alternate between words from file and random words
            if (j % 2 == 0 && j/2 <= file_len) {
                Liredir_s(F_search, S, j/2);
                strcpy(Tempchaine, Struct1_Ts(S));
            } else {
                strcpy(Tempchaine, Aleachaine(Aleanombre(5) + 3));
            }

            // Search in BST Triplet
            bool result;
            int searchpath = 0;
            Search_word_02(&newBst1, &newBst2, &newBst3, &Tempchaine, &X, &Y, &Z, &result, &searchpath);
            total_lengh_path(result, searchpath, &total_found, &total_unfound);

            // Search in BST0
            searchpath = 0;
            Search_in_bst_020(&newBst0, &Tempchaine, &X, &Y, &Z, &result, &searchpath);
            total_lengh_path(result, searchpath, &total_found0, &total_unfound0);
        }
        fclose(F_search);

        // Free memory
        End_programme(&newBst0);
        End_programme(&newBst1);
        End_programme(&newBst2);
        End_programme(&newBst3);
        
        // Print results
        printf("| %2d | %9d | %13d | %10d | %16d | %19d | %15d |\n", 
               i, 
               total_found0, total_unfound0, total_found0 + total_unfound0,
               total_found, total_unfound, total_found + total_unfound);
    }

    // Free allocated memory
    free(X);
    free(Y);
    free(Z);
    free(S->Champ1);
    free(S);
    free(Tempchaine);
}

void module_3(Pointeur_As *Bst0, Pointeur_As *Bst1, Pointeur_As *Bst2, Pointeur_As *Bst3) {
    // Initialize variables
   char* X = (string2)malloc(sizeof(string2));
      char* Y = (string2)malloc(sizeof(string2));
        char* Z = (string2)malloc(sizeof(string2));
    X[0] = 'X'; X[1] = '\0';
    Y[0] = 'Y'; Y[1] = '\0';
    Z[0] = 'Z'; Z[1] = '\0';

    printf("\nSimulation | BST0 Nodes Visited | BST Triplet Nodes Visited\n");
    printf("---------------------------------------------------------\n");
    
    // Allocate memory for file operations
    Typestruct1_s S = (Typestruct1_s)malloc(sizeof(Typestruct1_s_));
    S->Champ1 = (char*)malloc(255 * sizeof(char));
    string255 w1 = (char*)malloc(255 * sizeof(char));
    string255 w2 = (char*)malloc(255 * sizeof(char));

    for (int i = 1; i <= 10; i++) {
        int count0 = 0, count = 0;
        
        // Generate new test file
        Generate_file_2(F2);
        
        // Create new BSTs from the generated file
        Pointeur_As newBst0 = NULL, newBst1 = NULL, newBst2 = NULL, newBst3 = NULL;
        int file_len = 10; // Number of words in F2
        
        // Build the BSTs
          Create_bst0(&newBst0, F2, &file_len, &X, &Y,& Z);
        Create_bst1(&newBst1, F2, &file_len, &X, &Y,& Z);
        Create_bst2(&newBst2, F2, &file_len, &X, &Y, &Z);
        Create_bst3(&newBst3, F2, &file_len, &X, &Y, &Z);

        // Perform range searches
        int J = 1;
        Ouvrir_s(&F2, "C:/FILEWORD/WORDS.txt", "A");
        while (J <= file_len) {
            // Get first word
            Liredir_s(F2, S, J);
            strcpy(w1, Struct1_Ts(S));
            J++;
            
            // Get second word
            if (J <= file_len) {
                Liredir_s(F2, S, J);
                strcpy(w2, Struct1_Ts(S));
                J++;
            } else {
                strcpy(w2, w1); // If odd number of words, compare with itself
            }
            
            // Test with optimized BSTs
            int temp_count = 0;
            Pointeur_Fs qu = NULL;
            Creerfile_Fs(&qu);
            Range_search2(&newBst1, &w1, &w2, &qu, &temp_count);
            count += temp_count;
            
            // Test with standard BST
            temp_count = 0;
            qu = NULL;
            Creerfile_Fs(&qu);
            Range_search2(&newBst0, &w1, &w2, &qu, &temp_count);
            count0 += temp_count;
        }

        Fermer_s(F2);
        
        // Free the BSTs for this iteration
        End_programme(&newBst0);
        End_programme(&newBst1);
        End_programme(&newBst2);
        End_programme(&newBst3);
        
        // Print results for this simulation
        printf("| %2d | %19d | %25d |\n", i, count0, count);
    }

    // Free allocated memory
    free(X);
    free(Y);
    free(Z);
    free(S->Champ1);
    free(S);
    free(w1);
    free(w2);
}

int main(){

printf("\n");
    printf("\x1b[33m""               +----------------------------------------+           \n");
    printf("               |                                        |           \n");
    printf("               |       Ecole Nationale Superieure       |           \n");
    printf("               |            d' Informatique             |           \n");
    printf("               +----------------------------------------+           \n");
    printf("\n");
    printf("                      CPI - 1ere Annee                       \n");
    printf("              Annee Universitaire 2024/2025                   \n");
    printf("\n");

   
    printf("+------------------------------------------------------------------+\n");
    printf("|                                                                  |\n");
    printf("| REALISE PAR :                                                    |\n");
    printf("|                                                                  |\n");
    printf("|      FIRST STUDENT=> HALKOM RABEH                                |\n");
    printf("|             &                                                    |\n");
    printf("|        SECOND STUDENT=>  ZERROUG TADJ EL ISLEM                   |\n");
    printf("|                                                                  |\n");
    printf("|                                                                  |\n");
    printf("|        SECTION: A                     GROUPE: 03                 |\n");
    printf("|                                                                  |\n");
    printf("|        TP2 :           bst_search                                |\n");
    printf("|                                                                  |\n");
    printf("+------------------------------------------------------------------+\n");
    printf("\n");
    printf ( " %s", "---------------------------------------------------------------------------------------\n" ) ;
     printf ( " %s", "  YOU MUST CREATE A FILE.TXT NAME IT WORDS IN THIS PATH D:\\FILEWORD\\WORDS.txt      \n " ) ;
     printf ( " %s", "---------------------------------------------------------------------------------------\n " ) ;
    printf("                    Please Press any key to continue...            \n");
    getchar();


int choix,CHOIX2,CHOIX3;
bool bstConstructed=false;
bool fileGenerated=false;
   srand(time(NULL));
     T1 =( char * ) malloc(2 * sizeof(char));
     T2 = ( char * )malloc(2 * sizeof(char));
     T3 = ( char * )malloc(2 * sizeof(char));
     X = ( char * )malloc(255 * sizeof(char));
     Y = ( char * )malloc(255 * sizeof(char));
     Z = ( char * )malloc(255 * sizeof(char));
     Swsearch =( char * ) malloc(255 * sizeof(char));
     Rgs1 =( char * ) malloc(255 * sizeof(char));
     Rgs2 =( char * ) malloc(255 * sizeof(char));
     X1 =( char * ) malloc(2 * sizeof(char));
     Y1 = ( char * )malloc(2 * sizeof(char));
     Z1 = ( char * )malloc(2 * sizeof(char));
     S =( Typestruct1_s  ) malloc(sizeof(Typestruct1_s));
     S->Champ1 = ( char * )malloc(255 * sizeof(char));
do{
  show_menu();  
scanf("%d",&choix);
 switch (choix) {
            case 1:
                printf(" Generating file with random words...\n");
              printf ( " %s", "GIVE ME XYZ" ) ;
     scanf ( " %s", X );
     scanf ( " %s", Y );
     scanf ( " %s", Z ) ;
     strcpy (X1,   Caract ( X , 1 )) ;
     strcpy (Y1,   Caract ( Y , 1 )) ;
     strcpy (Z1,   Caract ( Z , 1 )) ;
     Generate_file ( F1 , & J , & X , & Y , & Z ) ;
                fileGenerated = true;
                break;
               

            case 2:
                if (!fileGenerated) {
                    printf(" You must generate the file first (Option 1).\n");
                    break;
                }
                printf(" Constructing BST1, BST2, BST3...\n");
                 Create_bst1 ( & Bst1 ,  F1 , & J , & X , & Y , & Z ) ;
     printf ( " %s", "CREATE_BST0-- SUCCESSFULLY" ) ;
                 Create_bst0 ( & Bst0 ,  F1 , & J , & X , & Y , & Z ) ;
     printf ( " %s", "CREATE_BST1-- SUCCESSFULLY" ) ;
     Create_bst2 ( & Bst2 ,  F1 , & J , & X , & Y , & Z ) ;
     printf ( " %s", "CREATE_BST2-- SUCCESSFULLY" ) ;
     Create_bst3 ( & Bst3 ,  F1 , & J , & X , & Y , & Z ) ;
     printf ( " %s", "CREATE_BST3-- SUCCESSFULLY" ) ;
                bstConstructed = true;
                break;

            case 3:
                if (!bstConstructed) {
                    printf(" Construct the BSTs first (Option 2).\n");
                    break;
                }

                printf("Running all BST tests...\n");
                do{
                 show_menu_test();
                  scanf("%d",&CHOIX2);
                  switch (CHOIX2)
                  {
                  case 1:
                   Display_tests ( & Bst1 , & X1 , & Y1 , & Z1 , & Cmp ) ;
                    break;
                     case 2:
                   Display_tests ( & Bst2 , & X1 , & Y1 , & Z1 , & Cmp ) ;
                    break;
                     case 3:
                   Display_tests ( & Bst3 , & X1 , & Y1 , & Z1 , & Cmp ) ;
                    break;
                   case 4:
                printf("back to menu.++\n");
                break;
                  default:
                    break;
                  }
                }while (CHOIX2!=4);
               
               
                break;

            case 4:
                if (!bstConstructed) {
                    printf(" Construct the BSTs first (Option 2).\n");
                    break;
                }
                printf(" Enter word to search: ");
                scanf ( " %s", Swsearch ) ;
                printf(" %s",Swsearch);
                if( Search_word ( & Bst1 , & Bst2 , & Bst3 , & Swsearch , & X1 , & Y1 , & Z1 )) {
                                                                                                printf ( GREEN" %s", "WORD FOUND " ) ;
                                             
                                                                                              } else {
                                                                                                printf (RED " %s", "DOESNT EXISTE" ) ;} ;

                                                                         
break;
            case 5:
                if (!bstConstructed) {
                    printf(" Construct the BSTs first (Option 2).\n");
                    break;
                }
                printf(" Enter range [Word1 Word2]: ");
             scanf ( " %s", Rgs1 );
     scanf ( " %s", Rgs2 ) ;
     Range_apply ( & Bst1 , & Bst2 , & Bst3 , & Rgs1 , & Rgs2 , & X1 , & Y1 , & Z1 ) ;
                break;
            case 6:
             if (!bstConstructed) {
                    printf(" Construct the BSTs first (Option 2).\n");
                    break;
                }  
            printf("  inorder traversal\n");
   do{
                 show_menu_test();
                  scanf("%d",&CHOIX3);
                  switch (CHOIX3)
                  {
                  case 1:
                   Inorder(& Bst1 );
                    break;
                     case 2:
                   Inorder(& Bst2 );
                    break;
                     case 3:
                 Inorder(& Bst3 );;
                    break;
                   case 4:
                printf("back to menu.++\n");
                break;
                  default:
                    break;
                  }
                }while (CHOIX3!=4);
             
             break;
            case 7:
                printf(" Exiting program.++\n");
                break;
  case 8:
    printf("Running Module 2 - Single Word Search Efficiency Comparison\n");
    module_2(&Bst0, &Bst1, &Bst2, &Bst3);
    break;
case 9:
    printf("Running Module 3 - Range Search Efficiency Comparison\n");
    module_3(&Bst0, &Bst1, &Bst2, &Bst3);
    break;
            default:
                printf("Invalid choice. Please select between 1 and 6.\n");
        }}while (choix != 7);

    } ;

    /*------------------------------------------------------*/
  
