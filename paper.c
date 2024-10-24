#include <stdio.h>
#include <stdlib.h>

#include "paper.h"

int myfunc1() {
    return 2;
}

void register_real(long uid, long secret) {
    struct N *p = (struct N*) malloc(sizeof(struct N));
    p->fn = myfunc1;
    p->usr = uid;
    p->pwd = secret;
    p->fn();
}

void register_fake(long uid, long secret) {
    struct N *x = (struct N*) malloc(sizeof(struct N));
    x->fn = myfunc1;
    struct N *q = x;
    free(x);
    q->fn();
    q->usr = uid;
    q->pwd = secret;
    printf("usr: %ld, pwd: %ld\n", q->usr, q->pwd);
    free(q);
}

void foo(long uid, long secret) {
    struct N *p = (struct N*) malloc(sizeof(struct N));
    p->fn = myfunc1;
    p->usr = uid; p->pwd = secret;
    p->fn();
}

void bar(long user1, long user2) {
    struct O *x = (struct O*) malloc(sizeof(struct O));
    x->oper = myfunc1;
    struct O *q = x;
    free(x);
    q->oper();
    q->u1 = user1; q->u2 = user2;
    printf("Users: %ld | %ld\n", q->u1, q->u2);
    free(q);
}

void run_tests() {
    register_fake(123, 1234);
    return;
}
