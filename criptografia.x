/* inverter.x : definição da interface */
 
#define PROGRAM_NUMBER 12345678
#define VERSION_NUMBER 1
 
/* tipo de dado que será passado aos procedimentos remotos */
 
struct operands
{
        char palavra[20];
	int salto;
};
 
/* Definição da interface que será oferecida aos clientes */
 
program CRIPT_PROG
{
   version CRIPT_VERSION
   {
     string ENVIAR (operands) = 1;
     
   }
   = VERSION_NUMBER;
}
= PROGRAM_NUMBER;
