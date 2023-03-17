#include <bits/stdc++.h>

using namespace std;


struct  Biblioteca{
    int id;
    string autor;
    string nume_carte;
    int an_publicatie;
    string Persoana;
};
void Info(Biblioteca b){

    cout<<"Urmatoarele comenzi sunt permise: "<<endl;
    cout<<"A-Adaugarea unei carti in biblioteca"<<endl;
    cout<<"L-Listarea tuturor cartilor din biblioteca"<<endl;
    cout<<"E-Eliminarea unei carti din biblioteca"<<endl;
    cout<<"C-Listarea informatiilor despre o carte"<<endl;
    cout<<"I-Imprumutul unei carti catre o persoana"<<endl;
    cout<<"P-Listarea informatiilor despre o persoana"<<endl;
    cout<<"D-Afiseaza numarul total de carti din biblioteca"<<endl;
    cout<<"X-Iesire din program"<<endl<<endl;
}
vector<Biblioteca>biblioteca;

void AdaugaCarteInBiblioteca(Biblioteca b){

    cout<<"Introdu ID-ul cartii (integer): "<<endl;
    cin>>b.id;

    cout<<"Introdu numele autorului(fara spatii) pentru cartea cu ID-ul "<<b.id<<": "<<endl;
    cin>>b.autor;

    cout<<"Introdu numele cartii(fara spatii) pentru cartea cu ID-ul "<<b.id<<": "<<endl;
    cin>>b.nume_carte;

    cout<<"Introdu anul publicatiei(integer) pentru cartea cu ID-ul "<<b.id<<": "<<endl;
    cin>>b.an_publicatie;
    biblioteca.emplace_back(b);

    cout<<endl;
    cout<<"Ce altceva doresti sa faci? "<<endl;
    Info(b);
    cout<<endl;

}
void ListareDateBiblioteca(Biblioteca b){

    for(auto it:biblioteca){

        cout<<"Cartea cu ID-ul "<<it.id<<" are numele "<<it.nume_carte<<" si este scrisa de "<<it.autor<<" in anul "<<it.an_publicatie<<endl;

    }
    cout<<endl;
    cout<<"Ce altceva doresti sa faci? "<<endl;
    Info(b);
    cout<<endl;
}
void EliminareCarteDinBiblioteca(Biblioteca b) {

    int id_eliminat;

    int ok = 0,w=0;

    cout << "Introdu ID-ul cartii(integer) pe care doresti sa o stergi: "<<endl;
    cin >> id_eliminat;
    for (int i = 0; i < biblioteca.size(); i++) {
        if (biblioteca[i].id == id_eliminat) {
            w++;
        }
        if (w == 0) {
            cout << "Cartea cu ID-ul " << id_eliminat << " nu exista in biblioteca! " << endl;
        } else {
            if (biblioteca[i].id == id_eliminat && ok == 0) {
                biblioteca.erase(biblioteca.begin() + i);
                cout << "Cartea cu ID-ul " << id_eliminat << " a fost eliminata din biblioteca! " << endl;
                ok++;
            }
        }
    }
    cout<<endl;
    cout<<"Ce altceva doresti sa faci? "<<endl;
    Info(b);
    cout<<endl;

}

void ImprumutCarteDinBiblioteca(Biblioteca b) {
    int id_imprumut;
    string persoana_imprumut;

    cout << "Introdu ID-ul cartii pe care vrei sa o imprumuti: " << endl;
    cin >> id_imprumut;
    cout << "Introdu nume persoanei(fara spatii) ce imprumuta/restituie cartea: " << endl;
    cin>>persoana_imprumut;
    int k=0;
    for (int i = 0; i < biblioteca.size(); i++) {

        if (biblioteca[i].id == id_imprumut) {
            k++;
            if (biblioteca[i].Persoana.size() == 0) {
                biblioteca[i].Persoana.append(persoana_imprumut);
                cout << "Cartea cu ID-ul " << id_imprumut << " a fost imprumutata de " << persoana_imprumut << endl;
            }
            else {
                cout << "Cartea a fost deja imprumutata! "<<endl;
            }
        }}
    if(k==0){
        cout << "Cartea cu ID-ul " << id_imprumut << " nu se gaseste in biblioteca! Cartea nu se poate imprumuta. " << endl;

    }
    cout<<endl;
    cout<<"Ce altceva doresti sa faci? "<<endl;
    Info(b);
    cout<<endl;

}
void InfoCarteDinBiblioteca(Biblioteca b) {
    int id_carte;
    cout << "Introdu ID-ul cartii(integer) despre care vrei sa aflii informatii: " << endl;
    cin >> id_carte;
    int q=0;

    for (auto it: biblioteca) {

        if (id_carte == it.id ) {
            cout << "Cartea cu ID-ul " << it.id << " are numele " << it.nume_carte << " si este scrisa de " << it.autor<< " in anul " << it.an_publicatie << endl;
            q++;
            if(it.Persoana.size()!=0)
                cout<<" Cartea este imprumutata de "<<it.Persoana<<endl;
            else
                cout<<" Cartea nu a fost imprumutata."<<endl;
        }

    }
    if(q==0){
        cout<<"Cartea cu ID-ul "<<id_carte<<" nu a fost gasita in biblioteca. "<<endl;
    }
    cout<<endl;
    cout<<"Ce altceva doresti sa faci? "<<endl;
    Info(b);
    cout<<endl;
}

void InfoPersoana(Biblioteca b) {
    int p = 0, l = 0;
    string persoana_dorita;
    vector<string> carti_persoana;
    for (auto it: biblioteca) {

        if (it.Persoana.size() == 0) {
            cout << " In biblioteca nu exista conturi de persoane create. " << endl;
        } else {
            p++;
        }
    }
    if (p != 0) {
        cout << " In biblioteca au cont urmatoarele persoane: " << endl;
        set<string>pers;
        for (int j = 0; j < biblioteca.size(); j++)
            pers.insert(biblioteca[j].Persoana);
        for(auto it:pers)
            cout<<it<<endl;
    }
    if (p != 0) {
        cout << " Despre ce persoana vrei sa obtii informatii? " << endl;
        cin >> persoana_dorita;

        for (auto it: biblioteca) {
            if (it.Persoana == persoana_dorita) {
                l++;
            }
        }
        if (l == 0) {
            cout << "Ai tastat numele gresit. Reia procesul de informatii referitoare la persoane si tasteaza corect! "
                 << endl;
        } else {
            cout << "Persoana " << persoana_dorita << " a imprumutat cartea: " << endl;
            for (auto it: biblioteca) {
                if (it.Persoana == persoana_dorita) {
                    cout << it.nume_carte << endl;

                }
            }
        }
    }
    cout<<endl;
    cout<<"Ce altceva doresti sa faci? "<<endl;
    Info(b);
    cout<<endl;
}
void NrTotalCartiInBiblioteca(Biblioteca b){
    cout<<"Nr total de carti din biblioteca este: "<<endl;
    cout<<biblioteca.size()<<endl;
    cout<<"Ce altceva doresti sa faci? "<<endl;
}


int main() {

    int nr_maxim=0;
    char op;
    int nr_curent=0;
    Biblioteca b;

    cout<<"Bine ai venit. Aceasta aplicatie gestioneaza o biblioteca de carti."<<endl;
    Info(b);

    cout<<"Introdu nr_max de carti din biblioteca: "<<endl;
    cin>>nr_maxim;


    while (op != 'X'){
        cout << "Introdu op: " << endl;
        cin >> op;

        switch (op)
        {

            case 'A':
                nr_curent++;
                if (nr_curent > nr_maxim)
                {
                    cout << "Cap max a fost atinsa! " << endl;
                    //op = 'q';
                }
                else
                {

                    AdaugaCarteInBiblioteca(b);
                }
                break;

            case 'L':

                if(biblioteca.size()==0){
                    cout<<"Nu avem carti in biblioteca! Poti adauga una cu ajutorul comenzii A. "<<endl<<endl;
                }
                else{
                    ListareDateBiblioteca(b);}
                break;


            case 'E':
                cout << "In biblioteca se afla urmatoarele carti: " << endl;
                for(auto it:biblioteca) {
                    cout << "Cartea cu ID-ul " << it.id << " are numele " << it.nume_carte << " si este scrisa de "
                         << it.autor << " in anul " << it.an_publicatie << endl;
                }
                if(biblioteca.size()!=0){
                    EliminareCarteDinBiblioteca(b);

                }
                else{
                    cout<<"Nu avem carti in biblioteca! Poti adauga una cu comanda A."<<endl;}
                break;

            case 'I':

                cout << "In biblioteca se afla urmatoarele carti: " << endl;
                for(auto it:biblioteca) {
                    cout << "Cartea cu ID-ul " << it.id << " are numele " << it.nume_carte << " si este scrisa de "
                         << it.autor << " in anul " << it.an_publicatie << endl;
                }

                if(biblioteca.size()!=0) {

                    ImprumutCarteDinBiblioteca(b);
                }
                else {
                    cout<<"Nu avem carti in biblioteca! Nu se poate imprumuta o carte! Poti adauga una cu comanda A si sa incerci din nou."<<endl;
                }
                break;

            case 'C':
                cout << "In biblioteca se afla urmatoarele carti: " << endl;
                for(auto it:biblioteca) {
                    cout << "Cartea cu ID-ul " << it.id << " are numele " << it.nume_carte << " si este scrisa de "
                         << it.autor << " in anul " << it.an_publicatie << endl;
                }
                if(biblioteca.size()!=0) {

                    InfoCarteDinBiblioteca(b);
                }
                else {
                    cout<<"Nu avem carti in biblioteca! Nu se poate imprumuta o carte! Poti adauga una cu comanda A si sa incerci din nou."<<endl;
                }

                break;


            case 'P':
                InfoPersoana(b);
                break;


            case 'D':
                NrTotalCartiInBiblioteca(b);
                break;

            case 'X':
                cout<<"Aplicatia s-a inchis! "<<endl;
                return 0;

            default:
                cout << "Comada este gresita! " << endl;
                break;
        }

    }
}