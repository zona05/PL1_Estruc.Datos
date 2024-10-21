
#ifndef NODOCOLA_H
#define NODOCOLA_H


class NodoCola {
    friend class Cola;
private:
    int valor;
    NodoCola* siguiente;
public:
    NodoCola();
    NodoCola(int v, NodoCola* sig = nullptr);
    ~NodoCola();

};







#endif //NODOCOLA_H
