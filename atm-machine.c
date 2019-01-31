#include <stdio.h>
#include <stdlib.h>

int lueKokonaisluku(void);
void lueRoskat(void);
int valikko(void);
void tulostaSaldo(double saldo);
void tulostaTapahtumat(double saldo);
int kysyNosto(void);
double nostaRahaa(int nostettava, double saldo);

int main(void){

  int pin = 1234;
  double saldo = 2938.58;
  int virhelaskuri = 0;
  int nro;
  int valinta;
  int nostettava;

  printf("\nTervetuloa! Syötä pin-koodi: ");

  do{
    nro = lueKokonaisluku();
    if(nro != pin){
      printf("Väärin. Yritä uudestaan: ");
      virhelaskuri++;
    }
    if(nro == pin)
      printf("\nOikein!");
  } while(nro != pin && virhelaskuri < 3);

  if(virhelaskuri == 3){
    printf("\nLiian monesti väärin. Heippa!\n\n");
    exit(0);
  }

  do{
    valinta = valikko();

    switch(valinta){

      case 1:
      nostettava = kysyNosto();

      if(nostettava > saldo){
        printf("\n\nTilin kate ei riitä. Saldo on %.2lf. Kiitos ja näkemiin.\n\n", saldo);
        exit(0);
      }

      nostaRahaa(nostettava, saldo);

      printf("\nKiitos käynnistä!\n\n");
      exit(0);
      break;

      case 2:
      tulostaSaldo(saldo);
      break;

      case 3:
      tulostaTapahtumat(saldo);
      break;
    }

  } while(valinta != 0);

  printf("\nKiitos käynnistä!\n\n");

  return 0;
}



/* Tulostaa valikon, lukee käyttäjän valinnan, ja palauttaa valinnan. */
int valikko(void){

  int valinta;

  printf("\n1: Otto\n"
    "2: Saldo\n"
    "3: Tapahtumat\n"
    "0: Lopeta\n\nValintasi: ");

  valinta = lueKokonaisluku();

  while(valinta < 0 || valinta > 3){
    printf("Valinta virheellinen. Yritä uudestaan: ");
    valinta = lueKokonaisluku();
  }

  return valinta;
}





/* Lukee kokonaisluvun, ja palauttaa sen pääfunktiolle. */
int lueKokonaisluku(void){

  int luku;
  char mki;
  int status;

  while((status = scanf("%d%c", &luku, &mki))==0  || (2 == status && mki != '\n') ){
    lueRoskat();
    printf("Et syottanyt kokonaislukua: ");
  }

  return luku;
}





/* Tyhjentää lukupuskurin. */
void lueRoskat(void){

  while( fgetc(stdin) != '\n');

}





/* Saa parametrinä tilin saldon, ja tulostaa sen ruudulle */
void tulostaSaldo(double saldo){

  printf("\nTilin saldo on %.2lf\nPaina enter palataksesi alkuun", saldo);
  getchar();
}





void tulostaTapahtumat(double saldo){

  /* Käyttäjän tilitiedot tehtävä tallennetaan tiedostoon. Aina kun tehdään nosto, tallennetaan uusi saldo ja lisätään
  tapahtuma tiedostoon. Tulostetaan tapahtumatiedoston sisältö tässä. */

  printf("\n\nOMINAISUUS EI VIELÄ TOIMINNASSA!\n\n");

}





/* Kysyy käyttäjältä nostettavan summan, ja palauttaa sen kokonaislukuna. */
int kysyNosto(void){

  int valinta;
  int nostettava;

  printf("\nPaljonko nostetaan?\n"
    "1: 20e\n"
    "2: 40e\n"
    "3: 60e\n"
    "4: 90e\n"
    "5: 140e\n"
    "6: 240e\n"
    "7: Muu summa\n"
    "0: Peruuta\n\nValintasi: ");

  valinta = lueKokonaisluku();

  while(valinta < 0 || valinta > 7){
    printf("Virheellinen valinta. Yritä uudestaan: ");
    valinta = lueKokonaisluku();
  }
  
  switch(valinta){
    case 1:
    nostettava = 20;
    break;

    case 2:
    nostettava = 40;
    break;

    case 3:
    nostettava = 60;
    break;

    case 4:
    nostettava = 90;
    break;

    case 5:
    nostettava = 140;
    break;

    case 6:
    nostettava = 240;
    break;

    case 7:
    printf("Syötä summa: ");
    nostettava = lueKokonaisluku();
    while(nostettava == 30 || nostettava > 1000 || nostettava < 20 || nostettava % 10 != 0 ){
      printf("Virheellinen summa. Syötä uusi summa: ");
      nostettava = lueKokonaisluku();
    }
    break;

    case 0:
    printf("\nKiitos käynnistä!\n\n");
    exit(0);
    break;
  }

  return nostettava;
}





/* Saa parametrina nostettavan summan ja tilin saldon. Tulostaa, montako mitäkin seteliä nostetaan, ja tulostaa ja
palauttaa uuden saldon. */
double nostaRahaa(int nostettava, double saldo){

  int seteli50 = 0;
  int seteli20 = 0;

  saldo = saldo - (double)nostettava;

  while(nostettava % 50 != 0){
    nostettava = nostettava - 20;
    seteli20++;
  }
  seteli50 = nostettava / 50;

  printf("\n50 euron setelit: %d\n20 euron setelit: %d\nTilin saldo on %.2lf\n\nPaina enter lopettaaksesi.", seteli50, seteli20, saldo);
  getchar();

  return saldo;
}