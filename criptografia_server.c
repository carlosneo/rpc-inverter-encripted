/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "criptografia.h"

char **
enviar_1_svc(operands *argp, struct svc_req *rqstp){
	/* Declaracao das variaveis */
	static char *result;
	char *crip;
	int i,tam;
	
	/* Pegando tamanho da mensagem informada */
	tam = strlen(argp->palavra);
	/* Alocando espaco na memoria */
	crip = malloc((sizeof(char)*tam)+1);	

	//printf("Mensagem recebida do Cliente: %s\n", *argp,tam);
	printf("Mensagem recebida : %s\n", argp->palavra);
	
	/* Realizando criptografia com chave fixa */
	for(i=0;i<tam;i++)
	{	
		if (argp->palavra[i]>='a' && argp->palavra[i]<='z'){
			if ((argp->palavra[i])+argp->salto > 'z'){
				crip[i] = 'a'+((argp->palavra[i]+argp->salto)-('z')-1);

			}else{
				crip[i] = argp->palavra[i]+argp->salto;

			}
		} else if(argp->palavra[i]>='A' && argp->palavra[i]<='Z'){
			
			if(argp->palavra[i]+argp->salto>'Z'){
				crip[i] = 'A'+((argp->palavra[i]+argp->salto)-('Z')-1);

			}
			else{
				crip[i] = argp->palavra[i]+argp->salto;

			}
		}
		else{
			crip[i] = argp->palavra[i];
		}
	}
	crip[i]='\0';

	printf("Mensagem criptografada do Cliente: %s\n", crip);

	result = crip;
	
	return &result;
}
