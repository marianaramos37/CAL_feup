#include "Restaurante.h"

template <class T>
Restaurante<T>::Restaurante(){
    this->morada = nullptr;
}
template<class T>
string Restaurante<T>::getNome() {
    return this->nome;
}
template<class T>
void Restaurante<T>::setNome(string n){
    this->nome=n;
}
template<class T>
string Restaurante<T>::getDescricao(){
    return descricao;
}
template<class T>
void Restaurante<T>::setDescricao(string d){
    this->descricao=d;
}
template<class T>
Vertex<T> Restaurante<T>::getMorada(){
    return morada;
}
template<class T>
void Restaurante<T>::setMorada(Vertex<T> v){
    this->morada=v;
}
