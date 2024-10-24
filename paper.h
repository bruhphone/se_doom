#ifndef _PAPER
#define _PAPER

struct N {
    long usr;
    long pwd;
    int (*fn)(void);
};

struct O {
    int (*oper)(void);
    long u1;
    long u2;
};

int myfunc1();
void register_real(long uid, long secret);
void register_fake(long uid, long secret);
void foo(long uid, long secret);
void bar(long user1, long user2);
void run_tests();

#endif
