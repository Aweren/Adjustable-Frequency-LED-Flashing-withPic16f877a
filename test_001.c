////////////////////////////////////////////////////////////////////////////////
/*
TeslimTarihi = 12.05.2021
AdSoyad =      Emirhan Süzer
ÖðrenciNo =    170519019
DersAdi =      Mikrodenetleyiciler ve Uygulamalarý
DersKodu =     ELM2006.1
*/
////////////////////////////////////////////////////////////////////////////////



void my_delay_ms(int n) {   // microC de delay içine i yazamýyoruz o yüzden bu fonksiyonu yazdým.
 while(n--) {
  Delay_ms(1);
 }
}

 // üþenmezsen intterup ile yap

int i;
unsigned seg_display[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

// do while döngüsünde iþimizi kolaylaþtýrmak için
// seg_display[] dizisinin içine 7segmetdisplayin hex formatýnda yazýyoruz


void main()
{
TRISC.F0 = 0;// c portundaki 0 pinini output olarak seçiyoruz
TRISB = 0; //   B portundaki tüm pinleri output olarak seçiyoruz
i=5;       //   seg_display[] içinde kullanýlmak için i'ye bir deðer veriyoruz.
           //   eðer i belli bir deðerde baþlatmazsak kodumuz hata verir

do
{


if(PORTD.F0 == 0) {   // 0 pine baðlý pine düðmeye basýldýktan sonra i artýran kod

i++;
if(i==10){ // 9 dan daha yüksek bir sayýyý almasýný engelleyen kod
i = 9;
}
PORTB = 0x00;
portb= seg_display[i]; // seg_displaydeki hex kodunu portb göderiyoruz bunda onun 7segmet disylade istediðimiz sayýlarý göstermesini saðlýyor

}


if(PORTD.F1 == 0){    //1 pine baðlý pine düðmeye basýldýktan sonra i azaltan kod
i--;
if(i==0){   // 0 dan daha küçük bir sayýyý almasýný engelleyen kod
i = 1;
}
PORTB = 0x00;
portb= seg_display[i]; // seg_displaydeki hex kodunu portb göderiyoruz bunda onun 7segmet disylade istediðimiz sayýlarý göstermesini saðlýyor

}

PORTC.F0 = 1; // Ledi açan
my_delay_ms(900/i);// istenen frekansta kodun çalýþmasýný saðlayan delay fonksiyonu. üste neden kendi yazdýðým fonksiyonu yazdýðýmý yazdým
PORTC.F0 = 0; // Ledi kapayan
my_delay_ms(900/i);// istenen frekansta kodun çalýþmasýný saðlayan delay fonksiyonu.

}while(1);
}