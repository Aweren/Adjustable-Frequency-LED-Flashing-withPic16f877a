////////////////////////////////////////////////////////////////////////////////
/*
TeslimTarihi = 12.05.2021
AdSoyad =      Emirhan S�zer
��renciNo =    170519019
DersAdi =      Mikrodenetleyiciler ve Uygulamalar�
DersKodu =     ELM2006.1
*/
////////////////////////////////////////////////////////////////////////////////



void my_delay_ms(int n) {   // microC de delay i�ine i yazam�yoruz o y�zden bu fonksiyonu yazd�m.
 while(n--) {
  Delay_ms(1);
 }
}

 // ��enmezsen intterup ile yap

int i;
unsigned seg_display[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

// do while d�ng�s�nde i�imizi kolayla�t�rmak i�in
// seg_display[] dizisinin i�ine 7segmetdisplayin hex format�nda yaz�yoruz


void main()
{
TRISC.F0 = 0;// c portundaki 0 pinini output olarak se�iyoruz
TRISB = 0; //   B portundaki t�m pinleri output olarak se�iyoruz
i=5;       //   seg_display[] i�inde kullan�lmak i�in i'ye bir de�er veriyoruz.
           //   e�er i belli bir de�erde ba�latmazsak kodumuz hata verir

do
{


if(PORTD.F0 == 0) {   // 0 pine ba�l� pine d��meye bas�ld�ktan sonra i art�ran kod

i++;
if(i==10){ // 9 dan daha y�ksek bir say�y� almas�n� engelleyen kod
i = 9;
}
PORTB = 0x00;
portb= seg_display[i]; // seg_displaydeki hex kodunu portb g�deriyoruz bunda onun 7segmet disylade istedi�imiz say�lar� g�stermesini sa�l�yor

}


if(PORTD.F1 == 0){    //1 pine ba�l� pine d��meye bas�ld�ktan sonra i azaltan kod
i--;
if(i==0){   // 0 dan daha k���k bir say�y� almas�n� engelleyen kod
i = 1;
}
PORTB = 0x00;
portb= seg_display[i]; // seg_displaydeki hex kodunu portb g�deriyoruz bunda onun 7segmet disylade istedi�imiz say�lar� g�stermesini sa�l�yor

}

PORTC.F0 = 1; // Ledi a�an
my_delay_ms(900/i);// istenen frekansta kodun �al��mas�n� sa�layan delay fonksiyonu. �ste neden kendi yazd���m fonksiyonu yazd���m� yazd�m
PORTC.F0 = 0; // Ledi kapayan
my_delay_ms(900/i);// istenen frekansta kodun �al��mas�n� sa�layan delay fonksiyonu.

}while(1);
}