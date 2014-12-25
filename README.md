RELUDP
======

Implementirati sistem za pouzdan prenos podataka posredstvom UDP transportnog protokola. pošto sam UDP ne garantuje pouzdanu isporuku datagrama, potrebno je implementirati mehanizme potvrde i retransmisije. Svaki paket koji se šalje treba, pored dela sa korisničkim podacima, da sadrži i zaglavlje koje se sastoji iz sledećih polja:

- tip paketa ( paket podataka ili paket potvrde )
- redni broj paketa
- veličina korisničkog dela u bajtima

Posle svakog poslatog paketa podataka, aplikacija pokreće tajmer i čeka da sa druge strane stigne paket potvrde. Ukoliko tajmer istekne, paket podataka se šalje ponovo. U protivnom, prelazi se na slanje sledećeg paketa. Sistem testirati slanjem binarne datoteke između 2 aplikacije.

MILESTONES
==========

1. Definisanje struktura i setup projekta
2. Dummy client i server
3. Slanje i prijem bez retransmisije
4. Slanje i prijem sa retransmisijom

CHECKLIST
=========

-
