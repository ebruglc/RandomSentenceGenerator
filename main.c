#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const char *isimList[] = {"Cihat", "Ebru", "Burak", "Esra", "Seda", "Büşra"};
static const char *nesneList[] = {"okula", "eve", "geneleve", "diskoya", "bara", "partiye"};
static const char *edatList[] = {"ancak", "yalnız","da","gibi","diye"};
static const char *fiilList[] = {"geldi", "gitti", "baktı", "gitmedi", "gelmedi", "bakmadı"};

char *createSentence(int sentenceCount);


const char * getName();

const char * getNesne();

const char * getEdat();

const char * getFiil();

int getRandom(int i);

int main() {
    srand(time(NULL));   // Initialization, should only be called once.

    printf("%s", createSentence(20));
    return 0;
}

char *createSentence(int sentenceCount) {
    char *sentence = (char *) malloc(((sentenceCount * 10) + 1) * sizeof(char));

    int i = 0;
    for (i = 0; i < sentenceCount; i++) {
        strcat(sentence, getName());
        strcat(sentence, " ");
        strcat(sentence, getNesne());
        strcat(sentence, " ");
        strcat(sentence, getEdat());
        strcat(sentence, " ");
        strcat(sentence, getFiil());
        strcat(sentence, ".");
    }
    return sentence;
}

const char * getFiil() {
    int rand = getRandom(sizeof(fiilList) / sizeof(fiilList[0]));
    return fiilList[rand];
}

const char * getEdat() {
    int rand = getRandom(sizeof(edatList) / sizeof(edatList[0]));
    return edatList[rand];
}

const char * getNesne() {
    int rand = getRandom(sizeof(nesneList) / sizeof(nesneList[0]));
    return nesneList[rand];
}

const char * getName() {
    int rand = getRandom(sizeof(isimList)/ sizeof(isimList[0]));
    return isimList[rand];
}

int getRandom(int i) {
    return rand()%i;      // Returns a pseudo-random integer between 0 and RAND_MAX.
}

