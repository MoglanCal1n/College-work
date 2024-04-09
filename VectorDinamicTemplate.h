#pragma once
#include "Locatar.h"
typedef Locatar Element;
#define INITIAL_CAPACITY 5
template <typename ElementT>
class IteratorVectorT;

template <typename ElementT>
class Vector
{
public:
    /*
    Constructor default
    Alocam loc pentru 5 elemente
    */
    Vector();

    /*
    Constructor de copiere
    */
    Vector(const Vector& ot); //rule of 3

    /*
    Eliberam memoria
    */
    ~Vector();//rule of 3

    /*
    Operator assgnment
    elibereaza ce era in obiectul curent (this)
    aloca spatiu pentru elemente
    copieaza elementele din ot in this
    */
    Vector& operator=(const Vector& ot);//rule of 3


    /*
    Move constructor
    Apelat daca construim un nou vector dintr-un r-value (ex temporary, expresie de la return)
    Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
    */
    Vector(Vector&& ot); //rule of 5

    /*
    Move assignment
    Similar cu move constructor
    Folosit la assignment
    */
    Vector& operator=(Vector&& ot); //rule of 5


    void add(const ElementT& el);

    ElementT& get(int poz) const;

    void set(int poz, const ElementT& el);

    int size() const noexcept;

    friend class IteratorVectorT<ElementT>;
    //functii care creaza iteratori
    IteratorVectorT<ElementT> begin();
    IteratorVectorT<ElementT> end();


private:
    int lg;//numar elemente
    int cap;//capacitate
    ElementT* elems;//elemente

    void ensureCapacity();
};

/*
Constructor default
Alocam loc pentru 5 elemente
*/
template<typename ElementT>
Vector<ElementT>::Vector() :elems{new Element[INITIAL_CAPACITY] }, cap{INITIAL_CAPACITY }, lg{0 } {}

/*
Constructor de copiere
Obiectul current (this) acum se creaza
aloca spatiu pentru elemente
copieaza elementele din ot in this
*/
template<typename ElementT>
Vector<ElementT>::Vector(const Vector<ElementT>& ot) {
    elems = new ElementT[ot.cap];
    //copiez elementele
    for (int i = 0; i < ot.lg; i++) {
        elems[i] = ot.elems[i];  //assignment din Pet
    }
    lg = ot.lg;
    cap = ot.cap;
}

/*
Operator assgnment
elibereaza ce era in obiectul curent (this)
aloca spatiu pentru elemente
copieaza elementele din ot in this
*/
template<typename ElementT>
Vector<ElementT>& Vector<ElementT>::operator=(const Vector<ElementT>& ot) {
    if (this == &ot) {
        return *this;//s-a facut l=l;
    }
    delete[] elems;
    elems = new ElementT[ot.cap];
    //copiez elementele
    for (int i = 0; i < ot.lg; i++) {
        elems[i] = ot.elems[i];  //assignment din Pet
    }
    lg = ot.lg;
    cap = ot.cap;
    return *this;
}

/*
Eliberam memoria
*/
template<typename ElementT>
Vector<ElementT>::~Vector() {
    delete[] elems;
}


/*
Move constructor
Apelat daca construim un nou vector dintr-un r-value (ex temporary)
Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
*/
template<typename ElementT>
Vector<ElementT>::Vector(Vector&& ot) {
    // Copy the data pointer from other
    elems = ot.elems;
    lg = ot.lg;
    cap = ot.cap;

    // Release the data pointer from the source object so that
    // the destructor does not free the memory multiple times.
    ot.elems = nullptr;
    ot.lg = 0;
    ot.cap = 0;
}

/*
Move assignment
Similar cu move constructor
Folosit la assignment
Elibereaza ce continea obiectul curent (this)
"fura" interiorul lui ot
pregateste ot pentru distrugere
*/
template<typename ElementT>
Vector<ElementT>& Vector<ElementT>::operator=(Vector<ElementT>&& ot) {
    if (this == &ot) {
        return *this;
    }
    delete[] elems;
    // Copy the data pointer from other
    elems = ot.elems;
    lg = ot.lg;
    cap = ot.cap;

    // Release the data pointer from the source object so that
    // the destructor does not free the memory multiple times.
    ot.elems = nullptr;
    ot.lg = 0;
    ot.cap = 0;
    return *this;
}

template<typename ElementT>
void Vector<ElementT>::add(const ElementT& el) {
    ensureCapacity();//daca e nevoie mai alocam memorie
    elems[lg++] = el;
}

template<typename ElementT>
ElementT& Vector<ElementT>::get(int poz) const {
    return elems[poz];
}

template<typename ElementT>
void Vector<ElementT>::set(int poz, const ElementT& el) {
    elems[poz] = el;
}

template<typename ElementT>
int Vector<ElementT>::size() const noexcept {
    return lg;
}

template<typename ElementT>
void Vector<ElementT>::ensureCapacity() {
    if (lg < cap) {
        return; //mai avem loc
    }
    cap *= 2;
    ElementT* aux = new ElementT[cap];
    for (int i = 0; i < lg; i++) {
        aux[i] = elems[i];
    }
    delete[] elems;
    elems = aux;
}

template<typename ElementT>
IteratorVectorT<ElementT> Vector<ElementT>::begin()
{
    return IteratorVectorT<ElementT>(*this);
}

template<typename ElementT>
IteratorVectorT<ElementT> Vector<ElementT>::end()
{
    return IteratorVectorT<ElementT>(*this, lg);
}

template<typename ElementT>
class IteratorVectorT {
private:
    const Vector<ElementT>& v;
    int poz = 0;
public:
    IteratorVectorT(const Vector<ElementT>& v) noexcept;
    IteratorVectorT(const Vector<ElementT>& v, int poz)noexcept;
    bool valid()const;
    ElementT& element() const;
    void next();
    ElementT& operator*();
    IteratorVectorT& operator++();
    bool operator==(const IteratorVectorT& ot)noexcept;
    bool operator!=(const IteratorVectorT& ot)noexcept;
};

template<typename ElementT>
IteratorVectorT<ElementT>::IteratorVectorT(const Vector<ElementT>& v) noexcept:v{v } {}

template<typename ElementT>
IteratorVectorT<ElementT>::IteratorVectorT(const Vector<ElementT>& v, int poz)noexcept : v{v }, poz{poz } {}

template<typename ElementT>
bool IteratorVectorT<ElementT>::valid()const {
    return poz < v.lg;
}

template<typename ElementT>
ElementT& IteratorVectorT<ElementT>::element() const {
    return v.elems[poz];
}

template<typename ElementT>
void IteratorVectorT<ElementT>::next() {
    poz++;
}

template<typename ElementT>
ElementT& IteratorVectorT<ElementT>::operator*() {
    return element();
}

template<typename ElementT>
IteratorVectorT<ElementT>& IteratorVectorT<ElementT>::operator++() {
    next();
    return *this;
}

template<typename ElementT>
bool IteratorVectorT<ElementT>::operator==(const IteratorVectorT<ElementT>& ot) noexcept {
    return poz == ot.poz;
}

template<typename ElementT>
bool IteratorVectorT<ElementT>::operator!=(const IteratorVectorT<ElementT>& ot)noexcept {
    return !(*this == ot);
}

