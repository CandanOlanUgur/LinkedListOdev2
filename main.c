#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

typedef struct log {  // STRUCT YAPISI

    int *event_no;
    char *event_type[32];
    char *event_message[128];
    time_t *event_time;

    struct log *next;

}log;

struct log* logOlustur(int event_no, char event_type[], char event_message[], time_t event_time) {




    struct log* new_log = (struct log*)malloc(sizeof(struct log));   // NEW LOG ADINDA VE LOG* TİPİNDE BİR KÜME OLUSTURDUK VE MALLOC FONK. İLE BELLEĞİMİZDE YER TAHSİS ETTİK ||(SİZEOF(LOG)) --> LOG YAPISININ KAPLADIĞI YER KADAR||
    new_log -> event_no = event_no;
    strcpy(new_log -> event_type, event_type);
    strcpy(new_log -> event_message, event_message);
    new_log -> event_time = event_time;
    new_log -> next = NULL;  // EKLENEN KÜMENİN BİR SONRAKİ KÜMEYİ GÖSTEREN İŞARETCİSİNİN, NULL OLDUĞUNU SÖYLÜYORUZ

    return new_log;
}

struct log* logEkle(struct log* head, int event_no, char event_type[], char event_message[], time_t event_time) {
    struct log* new_log = logOlustur(event_no, event_type, event_message, event_time);
    new_log -> next = head; // HEAD İŞARETCİMİZİ,
    head = new_log;
    return head;
}

void gunluguGoruntule(struct log* head) {
    struct log* current = head;

    while (current != NULL) {

        printf("| %d | %s | %s | %s", current -> event_no, current -> event_type, current -> event_message, current-> event_time);
        current = current -> next;
    }
    printf("\n");
}

int main() {
    struct log* head = NULL;


    printf("Add Log --> 1\n"
                 "View Log --> 2\n"
                 "Exit --> 3\n");

    int secim= 0;
    int evntNo = 1000;

    while (secim != 3) {


        scanf("%d", &secim);
        while (getchar() != '\n');



        //struct log* head = NULL;
        if (secim == 1) {

            time_t time_now;
            time_now = time(NULL);

            head = logEkle(head, evntNo, "mymachine.example.com", "'su root' failed for lonvick on /dev/pts/8",ctime(&time_now));
            evntNo++;
        }

        else if (secim == 2) {
            gunluguGoruntule(head);
        }


    }

    return 0;


}
