#include <assert.h>
#include <string.h>
#include "tests.h"

//Teste Domeniu

void test_creazaTrans(){
    Trans t = create_transaction("descriere", 210, "intrare", 21);
    assert(strcmp(t.descriere, "descriere") == 0);
    assert(strcmp(t.tip, "intrare") == 0);
    assert(t.suma == 210);
    assert(t.zi == 21);

    Trans t2 = create_transaction("alta descriere", 210, "iesire", 16);
    assert(strcmp(t2.descriere, "alta descriere") == 0);
    assert(strcmp(t2.tip, "iesire") == 0);
    assert(t2.suma == 210);
    assert(t2.zi == 16);

}

void test_destroyTrans(){
    Trans t = create_transaction("descriere", 210, "intrare", 21);
    delete_transaction(&t);
    assert(strcmp(t.descriere, "") == 0);
    assert(strcmp(t.tip, "") == 0);
    assert(t.suma == 0);
    assert(t.zi == 0);
}

void test_valid(){
    Trans t = create_transaction("descriere", 210, "intrare", 21);
    int valid1 = validate(t);
    assert(valid1 == 1);

    Trans t2 = create_transaction("", 0, "intrare", 16);
    int valid2 = validate(t2);
    assert(valid2 == 0);

    Trans t3 = create_transaction("descriere", 200, "", 16);
    int valid3 = validate(t3);
    assert(valid3 == 0);

    Trans t4 = create_transaction("o descriere", 10, "intrare", -1);
    int valid4 = validate(t4);
    assert(valid4 == 0);

}

//Teste Repository

void test_create_empty(){
    List l = createEmpty();
    assert(l.len == 0);
}

void test_AddGet() {
    List v = createEmpty();
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);
    Trans el2 = create_transaction("descriere", 240, "iesire", 16);
    add(&v, el1);
    add(&v, el2);
    assert(size(&v) == 2);
    assert(strcmp(get(&v, 0).tip, el1.tip) == 0);
    assert(strcmp(get(&v, 0).descriere, el1.descriere) == 0);
    assert(get(&v, 0).zi == el1.zi);
    assert(get(&v, 0).suma == el1.suma);

    assert(strcmp(get(&v, 1).tip, el2.tip) == 0);
    assert(strcmp(get(&v, 1).descriere, el2.descriere) == 0);
    assert(get(&v, 1).zi == el2.zi);
    assert(get(&v, 1).suma == el2.suma);
}

void test_destroy(){
    List l = createEmpty();
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);
    add(&l, el1);
    destroy(&l);
    assert(l.len == 0);
}

void test_add(){
    List l = createEmpty();
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);
    add(&l, el1);
    assert(l.len == 1);
}

void test_delete(){
    List v = createEmpty();
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);
    Trans el2 = create_transaction("descriere", 240, "iesire", 16);
    add(&v, el1);
    add(&v, el2);

    assert(size(&v) == 2);

    delete(&v, 0);
    assert(size(&v) == 1);

    assert(strcmp(get(&v, 0).tip, el2.tip) == 0);
    assert(strcmp(get(&v, 0).descriere, el2.descriere) == 0);
    assert(get(&v, 0).zi == el2.zi);
    assert(get(&v, 0).suma == el2.suma);
}

void test_addTrans(){
    List v = createEmpty();
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);

    addTrans(&v, el1, 2);
    assert(v.elem[2].zi == 21);
    assert(strcmp(v.elem[2].descriere, "descriere") == 0);
    assert(strcmp(v.elem[2].tip, "intrare") == 0);
    assert(v.elem[2].suma == 210);
}

void test_size(){
    List v = createEmpty();
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);
    Trans el2 = create_transaction("descriere", 240, "iesire", 16);
    add(&v, el1);
    add(&v, el2);

    assert(size(&v) == 2);
}

void test_addTransService(){
    List v = createEmpty();
    int valid1 = adaugaTrans(&v, "descriere", 210, "intrare", 16);
    int valid2 = adaugaTrans(&v, "", 0, "", 0);
    assert(valid1 == 1);
    assert(valid2 == 0);
}

void test_deleteTransService(){
    List v = createEmpty();
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);
    add(&v, el1);

    int valid2 = stergeTrans(&v, "", 190, "iesire", 16);
    assert(valid2 == 0);

    int valid1 = stergeTrans(&v, "descriere", 210, "intrare", 21);
    assert(valid1 == 1);
}

void test_modifyDomain(){
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);
    Trans el2 = create_transaction("descriere", 240, "iesire", 16);

    modify_transaction(&el1, &el2);

    assert(strcmp(el1.descriere, "descriere") == 0);
    assert(strcmp(el1.tip, "iesire") == 0);
    assert(el1.suma == 240);
    assert(el1.zi == 16);
}

void test_modifyRepo(){
    List v = createEmpty();
    Trans el1 = create_transaction("descriere", 210, "intrare", 21);

    modifyTrans(&v, el1, 2);
    assert(v.elem[2].zi == 21);
    assert(strcmp(v.elem[2].descriere, "descriere") == 0);
    assert(strcmp(v.elem[2].tip, "intrare") == 0);
    assert(v.elem[2].suma == 210);
}

void test_modifyServ(){
    List v = createEmpty();
    Trans t = create_transaction("descriere", 210, "intrare", 21);
    add(&v, t);
    int valid1 = modifyTransServ(&v, "descriere", 210, "intrare", 21,
                                 "descriere", 240, "iesire", 16);
    assert(valid1 == 1);

    int valid2 = modifyTransServ(&v, "descriere", 200, "intrare", 21,
                                 "descriere", 240, "iesire", 16);
    assert(valid2 == 0);

    int valid3 = modifyTransServ(&v, "descriere", 210, "intrare", 21,
                                 "descriere", 0, "bla bla", 0);
    assert(valid3 == 0);

}

void test_critTip(){
    List l = createEmpty();
    Trans t1 = create_transaction("descriere", 210, "intrare", 21);
    Trans t2 = create_transaction("descriere", 210, "intrare", 21);
    Trans t3 = create_transaction("descriere", 210, "iesire", 21);

    add(&l, t1);
    add(&l, t2);
    add(&l, t3);

    List valid = transCritTip(&l, "intrare");
    assert(size(&valid) == 2);

    List valid2 = transCritTip(&l, "iesire");
    assert(size(&valid2) == 1);
}

void test_critSuma(){
    List l = createEmpty();
    Trans t1 = create_transaction("descriere", 100, "intrare", 21);
    Trans t2 = create_transaction("descriere", 200, "intrare", 21);
    Trans t3 = create_transaction("descriere", 50, "iesire", 21);

    add(&l, t1);
    add(&l, t2);
    add(&l, t3);

    List valid1 = transCritSuma(&l, 100, 1);
    assert(size(&valid1) == 1);

    List valid2 = transCritSuma(&l, 100, 2);
    assert(size(&valid2) == 1);
}

void test_Sort(){
    List l = createEmpty();
    Trans t1 = create_transaction("descriere", 2, "intrare", 3);
    Trans t2 = create_transaction("descriere", 1, "intrare", 2);
    Trans t3 = create_transaction("descriere", 3, "iesire", 1);

    add(&l, t1);
    add(&l, t2);
    add(&l, t3);

    sort_zi_suma(&l, 1, -1, 1);

    assert(l.elem[0].suma == 1);

    sort_zi_suma(&l, 1, -1, 2);

    assert(l.elem[0].suma == 3);

    List v = createEmpty();
    Trans s1 = create_transaction("descriere", 1, "intrare", 2);
    Trans s2 = create_transaction("descriere", 2, "intrare", 1);
    Trans s3 = create_transaction("descriere", 3, "iesire", 3);

    add(&v, s1);
    add(&v, s2);
    add(&v, s3);

    sort_zi_suma(&v, -1, 1, 1);

    assert(v.elem[0].zi == 1);

    sort_zi_suma(&v, -1, 1, 2);

    assert(v.elem[0].zi == 3);
}