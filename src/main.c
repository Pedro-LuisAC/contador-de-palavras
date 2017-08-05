/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int compare(char dado){
  if ((dado>='a' && dado<='z') || (dado>='A' && dado <= 'Z')||(dado >= '0' && dado <= '9')){
    return 1;
  }
  else{
    return 0;
  }
}

int compnum(char dado){
  if (dado>='0' && dado <='9'){
    return 1;
  }
  else{
    return 0;
  }
}

int main() {

  char c=' ';
  char cant = ' ';
  char cpas = ' ';
  int flagword=0;
  int count = 0;
  int flagnum = 0;
  int flagdot=0;

  c = 1;

  while (c != '\n') {
    cpas = cant;
    cant = c;
    scanf("%c", &c);
    if (compare(c) == 1){
      flagword = 1;
    }
    if(c=='.'){
      flagdot++;
    }
    if(flagdot == 2 && compnum(cpas) == 1 && cant == '.' && compare(c) == 1 ){ 
      flagdot = 0;
      count++;
    }
       
    if( (compare(c) == 0 && flagword == 1)){
      if(compnum(c)==0 && compnum(cant)==1 &&(c=='.'||c==',')){
	count = count;
      }
      else{
	count++;
	flagword = 0;
	flagdot = 0;
      }
    }
  }

  printf("%d\n",count);
  return 0;
}
