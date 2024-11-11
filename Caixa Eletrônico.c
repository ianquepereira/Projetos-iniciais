#include<stdio.h>
#include<string.h>
#include<windows.h>

int n = 3, i;

struct cliente {
       char nome[20];
       char conta[6];      
       float saldo;
       }usuario[20];
 
mensagem(){
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tSEJA BEM-VINDO CLIENTE!\n\t\t\t\t\tSEJA BEM-VINDO CLIENTE!\n\t\t\t\t\t\tSEJA BEM-VINDO CLIENTE!\n\t\t\t\t\t\tSEJA BEM-VINDO CLIENTE!");
	sleep(2);
}
consultarsaldo(){
     for (i=1; i<=3; i++){
      printf("\nNome do Cliente: %s \nSaldo: %2.f reais\n\n",usuario[i].nome, usuario[i].saldo);
	  }
    sleep(5);
}

saque(){ 
    int b,c;
    float saq;
    char conta[6];
    
    printf ("\n\t\tSAQUE\n"); 
    
    printf ("\nNumero da conta:");
    scanf ("%s", &conta);
    
    for (i=1;i<=n;i++){
        b = strcmp(conta,usuario[i].conta);
        if  ( b == 0 ){
          printf ("\n Cliente: %s", usuario[i].nome) ;
          printf ("\n\nValor a ser sacado: ");
          scanf ("%f", &saq) ;
          if ((saq > 0) && (saq <= usuario[i].saldo) )
          {
            c=1;
            usuario[i].saldo = usuario[i].saldo - saq;
          }
          printf("Saque efetuado com sucesso!");
        }
     } 
     if (c != 1){
           printf ("\n\a\aSaque negada!\nSeu saldo é insuficiente!!");
           }
      printf ("\n\nAguarde...");
      sleep (5);  
}

deposito(){
    int b,x;
    float dep;
    char conta[6];
    
    printf ("\n\t\tDEPOSITO\n"); 
    
    printf ("\nNumero da conta: ");
    scanf ("%s", &conta);
    
    for (i=1;i<=n;i++){
    	
        b = strcmp(conta,usuario[i].conta);
        if  (b == 0){
        	
          x=1;
          printf ("\nCliente: %s", usuario[i].nome) ;
          printf ("\n\nQuantia do deposito: ");
          scanf ("%f", &dep) ;
          if (dep >= 0)
          {
            usuario[i].saldo = usuario[i].saldo + dep;
          }
          else
          {
          printf ("\nO deposito precisa ser positivo!");
          break;
          }
          printf("O valor atual na sua conta : %2.f reais", usuario[i].saldo);
        }
     
     } 
     if(x!=1)
     printf ("\n\a\aDados incorretos!");
     printf ("\n\nAguarde...");
     sleep(5) ;
                 
}          

transfe(){
   char nome[20], conta[6], nome2[6],conta2[6];
    int a,b,c,d,e,j,x,l; 
    float val;
    printf ("\n\t\t ===== TRANSFERENCIA ===== \n"); 
    
    printf ("\nDigite seu nome: ");
    scanf ("%s", &nome); 
    printf ("\nNumero da sua conta: ");
    scanf ("%s", &conta);
    
    for (i=1;i<=n;i++)
    {
        
        a = strcmp(nome,usuario[i].nome);
        b = strcmp(conta,usuario[i].conta);
        
        if  (   (a == 0) && (b == 0)  )
        {
         l=1;
          printf ("\nCliente: %s", usuario[i].nome) ; 
          printf ("\nConta: %s", usuario[i].conta) ;
        } 
      if (l != 1){
      printf ("\a\aOps... Algo deu errado!");
      printf ("\n\nRetornando ao Menu...");
      sleep (5);
      system ("cls");
      menu();
      }
    }  //for   1
    printf ("\nNome do cliente que vai receber o deposito: ");
    scanf ("%s", &nome2);  
    printf ("\nNumero da conta que recebera o deposito: ");
    scanf ("%s", &conta2);
    
            d = strcmp(nome2,usuario[j].nome);
            e = strcmp(conta2,usuario[j].conta);
               if  ((d == 0) && (e == 0))
               {
                x=1;
               printf ("\nClinte que vai receber o deposito: %s", usuario[j].nome) ; 
                
               printf ("\nValor da transferencia:");
               scanf ("%f", &val);
               
                        
                            if (val <= usuario[i].saldo)
                            {
                            	x=1;
                            usuario[j].saldo = usuario[j].saldo + val;
                            usuario[i].saldo = usuario[i].saldo - val; 
							                 
                            }
                            else 
                            {
                            	x!=1;
                            printf("Ops... Dados invalidos!\nAguarde...");
                            }
                              
               }                      
          
  printf ("\n\nVoltando ao Menu...");  
 sleep (5) ;        
} 

menu(){
	int op;
	
	printf ("OPCOES:\n");
	
	printf ("1 - Consultar Saldo\n") ;
	printf ("2 - Saque\n") ;
	printf ("3 - Deposito\n") ;
	printf ("4 - Trasferencia\n") ;
	printf ("5 - Sair\n");
	printf("\nDigite sua opcao... ");
	
	scanf("%d", &op);
	switch (op)
 {
    case 1:
    system ("cls") ;
    consultarsaldo();
    system ("cls") ;
    menu();
   
    case 2:
    system ("cls") ;
    saque(); 
    system ("cls") ;
    menu();
    
    case 3:
    system ("cls");
    deposito();
    system ("cls") ;
    menu();
    
    case 4:
    system ("cls") ;
    transfe();
    system ("cls") ;
    menu();
    
    case 5:  
    exit(5);
	}
	getch();
	}
     
int main(){
	
	int i=1, n=3, op;
	mensagem();
	system("cls");
	
	printf("Para fins de cadastro digite seus dados:\n");
    for (i=1;i<=n;i++)
	{
    printf ("\nNome:");
    scanf ("%s", &usuario[i].nome);
    printf ("\nNumero da conta:");
    scanf ("%s", &usuario[i].conta);
	printf("\nQual saldo da sua conta corrente:");
    scanf("%f",&usuario[i].saldo);
    }
    printf ("\n\nDados cadastrados!\nVoce sera redirecionado ao menu...");
    sleep(5);
    system("cls");
    
	menu();

}	



