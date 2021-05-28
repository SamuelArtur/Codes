typedef struct pilha Pilha;

Pilha* pilhaCria();

void pilhaPush(Pilha* p, char v);

char pilhaPop(Pilha* p);

int pilhaVazia(Pilha* p);

void liberaPilha(Pilha* p);

int pilhaCheia(Pilha* p);