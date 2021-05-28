typedef struct pilha Pilha;

Pilha* pilhaCria();

int pilhaVazia(Pilha* p);

void pilhaPush(Pilha* p, char v);

char pilhaPop(Pilha* p);

void pilhaLibera(Pilha* p);

char leTopo(Pilha* p);