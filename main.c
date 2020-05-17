#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const char *isimList[] = {"Cihat", "Ebru", "Burak", "Esra", "Seda", "Büşra"};//burada isimler kullanılmıs, değiştirilebilir ve yenileri eklenebilir
static const char *nesneList[] = {"okula", "eve", "kütüphaneye", "yürüyüşe", "sahile", "koroya"};
static const char *edatList[] = {"ancak", "yalnız", "da", "gibi", "diye"};
static const char *fiilList[] = {"geldi", "gitti", "baktı", "gitmedi", "gelmedi", "bakmadı"};


//fonksiyonların taslakları burada tanımlanıyor. main methodunun altında da fonksiyonların içi dolduruluyor...
char *createSentence(int sentenceCount);

const char *getName();

const char *getNesne();

const char *getEdat();

const char *getFiil();

int getRandom(int i);

int main() {
    srand(time(NULL));   // Initialization, should only be called once.
    // random sayı için bunu yazmamız gerekiyor

    printf("%s", createSentence(20));//createSentence methodunun dünüşünü ekrana bastırıyoruz.
    return 0;
}

char *createSentence(int sentenceCount) {
    char *sentence = (char *) malloc(((sentenceCount * 10 * 4) + 1) * sizeof(char));// burada sentence için
    //memoryden alan alıyoruz, 20 tane cümle için, her cumlede 4 kelime ve her kelime maksimum 10 harf olarak hesaplanmıstır.

    int i = 0;
    for (i = 0; i < sentenceCount; i++) {// for döngüsünde 20 tane cümle olusturuyoruz,
        //strcat fonksiyonu ile sentence ın sonuna bunu ekliyoruz.
        strcat(sentence, getName());// burada isim alıyoruz
        strcat(sentence, " ");//her kelimeden sonra boşluk koyuyoruz.
        strcat(sentence, getNesne());//burada random nesne alıyoruz
        strcat(sentence, " ");
        strcat(sentence, getEdat());//burada random edat
        strcat(sentence, " ");
        strcat(sentence, getFiil());// burada random fiil alıyoruz.
        strcat(sentence, ".");//cümlenin sonuna nokta koyuyoruz.
    }
    return sentence;//cümle değerini fonksiyon dönüşünde gödneriyoruz.
}

const char *getFiil() {
    int rand = getRandom(sizeof(fiilList) / sizeof(fiilList[0]));
    //burada fiil listesinin eleman sayısını random methoduna gönderiyoruz.
    return fiilList[rand];
}

const char *getEdat() {
    int rand = getRandom(sizeof(edatList) / sizeof(edatList[0]));
    //burada edat listesinin eleman sayısını random methoduna gönderiyoruz.
    return edatList[rand];
}

const char *getNesne() {
    int rand = getRandom(sizeof(nesneList) / sizeof(nesneList[0]));
    //burada nesne listesinin eleman sayısını random methoduna gönderiyoruz.
    return nesneList[rand];
}

const char *getName() {
    int rand = getRandom(sizeof(isimList) / sizeof(isimList[0]));
    //burada isim listesinin eleman sayısını random methoduna gönderiyoruz.
    return isimList[rand];
}

int getRandom(int i) {
    //Dısarıdan gelen i degeri maksimum oalcak sekilde random sayı türetilir.
    return rand() % i;
}

