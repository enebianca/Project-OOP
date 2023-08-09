#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;


//Gestionare Librarie; - Ene Bianca Elena

class Carte {
protected:
    const int codCarte;
    static int numarator;
    char numeCarte[50];
    string numeAutor;
    int anAparitie;
    float pret;
    int nrPagini;
    int* cuvintePerPagina;
    bool esteInStoc;

public:
    Carte() :codCarte(numarator++) {
        strcpy(this->numeCarte, "Anonim");
        this->numeAutor = "Necunoscut";
        this->anAparitie = 0;
        this->pret = 0;
        this->nrPagini = 0;
        this->cuvintePerPagina = NULL;
        this->esteInStoc = 0;
    }

    Carte(const char numeCarte[50], string numeAutor, int anAparitie, float pret, int nrPagini, int* cuvintePerPagina, bool esteInStoc) :codCarte(numarator++) {
        strcpy(this->numeCarte, numeCarte);
        this->numeAutor = numeAutor;
        this->anAparitie = anAparitie;
        this->pret = pret;
        this->nrPagini = nrPagini;
        this->cuvintePerPagina = new int[this->nrPagini];
        for (int i = 0;i < this->nrPagini;i++) {
            this->cuvintePerPagina[i] = cuvintePerPagina[i];
        }
        this->esteInStoc = esteInStoc;
    }

    Carte(int nrPagini, int* cuvintePerPagina) :codCarte(numarator++) {
        strcpy(this->numeCarte, "Anonim");
        this->numeAutor = "Necunoscut";
        this->anAparitie = 0;
        this->pret = 0;
        this->nrPagini = nrPagini;
        this->cuvintePerPagina = new int[this->nrPagini];
        for (int i = 0;i < this->nrPagini;i++) {
            this->cuvintePerPagina[i] = cuvintePerPagina[i];
        }
        this->esteInStoc = 0;
    }

    char* getNumeCarte() {
        return this->numeCarte;
    }

    void setNumeCarte(const char numeCarte[50]) {
        strcpy(this->numeCarte, numeCarte);
    }

    string getNumeAutor() {
        return this->numeAutor;
    }

    void setNumeAutor(string numeAutor) {
        this->numeAutor = numeAutor;
    }

    int getAnAparitie() {
        return this->anAparitie;
    }

    void setAnAparitie(int anAparitie) {
        if (anAparitie > 0) {
            this->anAparitie = anAparitie;
        }
        else {
            this->anAparitie = 0;
        }
    }

    float getPret() {
        return this->pret;
    }

    void setPret(float pret) {
        if (pret > 0) {
            this->pret = pret;
        }
        else {
            this->pret = 0;
        }
    }

    int getNrPagini() {
        return this->nrPagini;
    }

    int* getCuvintePerPagina() {
        return this->cuvintePerPagina;
    }

    void setCuvintePerPagina(int nrPagini, int* cuvintePerPagina) {
        if (nrPagini > 0 && cuvintePerPagina != NULL) {
            if (this->cuvintePerPagina != NULL) {
                delete[]this->cuvintePerPagina;
            }
            this->nrPagini = nrPagini;
            this->cuvintePerPagina = new int[this->nrPagini];
            for (int i = 0;i < this->nrPagini;i++) {
                this->cuvintePerPagina[i] = cuvintePerPagina[i];
            }
        }
        else {
            this->nrPagini = 0;
            this->cuvintePerPagina = NULL;
        }
    }


    bool getEsteInStoc() {
        return this->esteInStoc;
    }

    void setEsteInStoc(bool esteInStoc) {
        this->esteInStoc = esteInStoc;
    }

    ~Carte() {
        if (this->cuvintePerPagina != NULL) {
            delete[]this->cuvintePerPagina;
        }
    }

    Carte(const Carte& c) :codCarte(c.codCarte) {
        strcpy(this->numeCarte, c.numeCarte);
        this->numeAutor = c.numeAutor;
        this->anAparitie = c.anAparitie;
        this->pret = c.pret;
        this->nrPagini = c.nrPagini;
        this->cuvintePerPagina = new int[this->nrPagini];
        for (int i = 0;i < this->nrPagini;i++) {
            this->cuvintePerPagina[i] = c.cuvintePerPagina[i];
        }
        this->esteInStoc = c.esteInStoc;
    }

    Carte& operator=(const Carte& c) {
        if (this != &c) {
            if (this->cuvintePerPagina != NULL) {
                delete[]this->cuvintePerPagina;
            }
            strcpy(this->numeCarte, c.numeCarte);
            this->numeAutor = c.numeAutor;
            this->anAparitie = c.anAparitie;
            this->pret = c.pret;
            this->nrPagini = c.nrPagini;
            this->cuvintePerPagina = new int[this->nrPagini];
            for (int i = 0;i < this->nrPagini;i++) {
                this->cuvintePerPagina[i] = c.cuvintePerPagina[i];
            }
            this->esteInStoc = c.esteInStoc;
        }
        return*this;
    }

    friend ostream& operator<<(ostream& out, const Carte& c) {
        out << "Nume carte: " << c.numeCarte << endl;
        out << "Nume autor: " << c.numeAutor << endl;
        out << "An aparitie: " << c.anAparitie << endl;
        out << "Pret carte: " << c.pret << endl;
        out << "Numar pargini :" << c.nrPagini << endl;
        out << "Cuvinte per pagina: ";
        for (int i = 0;i < c.nrPagini;i++) {
            out << c.cuvintePerPagina[i] << ", ";
        }
        out << endl;
        out << "Este in stoc?(1-DA,0-Nu): " << c.esteInStoc << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Carte& c) {
        cout << "Nume Carte: ";
        char buffer[50];
        in.getline(buffer, 99);
        strcpy(c.numeCarte, buffer);

        cout << "Nume autor: ";
        getline(in, c.numeAutor);

        cout << "An aparitie: ";
        in >> c.anAparitie;

        cout << "Pret Carte: ";
        in >> c.pret;

        cout << "Numar pagini: ";
        in >> c.nrPagini;

        cout << "Cuvinte per pagina: ";
        if (c.cuvintePerPagina != NULL) {
            delete[]c.cuvintePerPagina;
        }
        c.cuvintePerPagina = new int[c.nrPagini];
        for (int i = 0;i < c.nrPagini;i++) {
            in >> c.cuvintePerPagina[i];
        }

        cout << "Este in stoc?(1-DA,0-NU): ";
        in >> c.esteInStoc;
        return in;

    }

    //metoda calculNrCuvinteMediu() care calculeaza media cuvintelor per pagina din carte.
    float calculNrCuvinteMediu() {
        float suma = 0;
        for (int i = 0;i < this->nrPagini;i++) {
            suma = suma + this->cuvintePerPagina[i];
        }
        return suma / this->nrPagini;
    }

    //metoda minimCuvinte() care calculeaza cel mai mic numar de cuvinte de pe o pagina din carte.
    float minimCuvinte() {
        float minim = this->cuvintePerPagina[0];
        for (int i = 0;i < this->nrPagini;i++) {
            if (this->cuvintePerPagina[i] < minim) {
                minim = this->cuvintePerPagina[i];
            }
        }
        return minim;
    }



    //operatorul pentru indexare[]
    char operator[](int pozitie) {
        if (pozitie >= 0 && pozitie < 50) {
            return this->numeCarte[pozitie];
        }
        else {
            int eroare = -1;
            return eroare;
        }
    }

    //operatorul +
    Carte operator+(float valoare) {
        Carte copie = *this;
        copie.pret += valoare;
        return copie;
    }

    //operator++(post-incrementat)
    Carte operator++(int) {
        Carte copie = *this;
        if (this->cuvintePerPagina != NULL) {
            delete[]this->cuvintePerPagina;
        }
        this->nrPagini++;
        this->cuvintePerPagina = new int[this->nrPagini];
        for (int i = 0;i < copie.nrPagini;i++) {
            this->cuvintePerPagina[i] = copie.cuvintePerPagina[i];
        }
        this->cuvintePerPagina[this->nrPagini - 1] = 222;
        return copie;
    }

    //operator++(pre-incrementat)
    Carte operator++() {
        Carte copie = *this;
        if (this->cuvintePerPagina != NULL) {
            delete[]this->cuvintePerPagina;
        }
        this->nrPagini++;
        this->cuvintePerPagina = new int[this->nrPagini];
        for (int i = 0;i < copie.nrPagini;i++) {
            this->cuvintePerPagina[i] = copie.cuvintePerPagina[i];
        }
        this->cuvintePerPagina[this->nrPagini - 1] = 111;
        return *this;
    }

    //operator cast explicit
    explicit operator string() {
        return this->numeAutor;
    }

    //operator de negatie!
    bool operator!() {
        return this->esteInStoc;
    }

    //operator <
    bool operator<(Carte c) {
        float minim = this->cuvintePerPagina[0];
        float minim1 = this->cuvintePerPagina[0];
        for (int i = 0;i < this->nrPagini;i++) {
            if (minim > this->cuvintePerPagina[i]) {
                minim = this->cuvintePerPagina[i];
            }
        }
        for (int i = 0;i < c.nrPagini;i++) {
            if (minim1 > c.cuvintePerPagina[i]) {
                minim1 = c.cuvintePerPagina[i];
            }
        }
        return minim < minim1;

    }

    //operator ==

    bool operator==(Carte c) {
        bool suntIdentice = 1;
        if (strcmp(this->numeCarte, c.numeCarte) == 1) {
            suntIdentice = 0;
        }
        if (this->numeAutor != c.numeAutor) {
            suntIdentice = 0;
        }
        if (this->anAparitie != c.anAparitie) {
            suntIdentice = 0;
        }
        if (this->pret != c.pret) {
            suntIdentice = 0;
        }
        if (this->nrPagini != c.nrPagini) {
            suntIdentice = 0;
        }
        for (int i = 0;i < this->nrPagini;i++) {
            if (this->cuvintePerPagina[i] != c.cuvintePerPagina[i]) {
                suntIdentice = 0;
            }
        }
        if (this->esteInStoc != c.esteInStoc) {
            suntIdentice = 0;
        }
        return suntIdentice;
    }

    friend ofstream& operator<<(ofstream& out, const Carte& c) {
        out << c.numeCarte << endl;
        out << c.numeAutor << endl;
        out << c.anAparitie << endl;
        out << c.pret << endl;
        out << c.nrPagini << endl;
        for (int i = 0;i < c.nrPagini;i++) {
            out << c.cuvintePerPagina[i] << endl;
        }
        out << c.esteInStoc << endl;
        return out;
    }

    friend ifstream& operator>>(ifstream& in, Carte& c) {
        char buffer[50];
        in.getline(buffer, 99);
        strcpy(c.numeCarte, buffer);

        getline(in, c.numeAutor);

        in >> c.anAparitie;
        in >> c.pret;
        in >> c.nrPagini;

        if (c.cuvintePerPagina != NULL) {
            delete[]c.cuvintePerPagina;
        }
        c.cuvintePerPagina = new int[c.nrPagini];
        for (int i = 0;i < c.nrPagini;i++) {
            in >> c.cuvintePerPagina[i];
        }
        in >> c.esteInStoc;
        return in;

    }

    //Serializarea(scriere in fisiere binare)
    void serializare(string numeFisier) {
        ofstream f(numeFisier, ios::out | ios::binary);
        
        //char[]
        f.write((char*)&this->numeCarte[10], sizeof(this->numeCarte[10]));


   /*     for (int i = 0;i < 10;i++) {
            f.write((char*)&this->numeCarte[i], sizeof(this->numeCarte[i]));
        }*/

        //string
        int dimNumeAutor = this->numeAutor.size();
        f.write((char*)&dimNumeAutor, sizeof(dimNumeAutor));
        f.write(this->numeAutor.c_str(), dimNumeAutor + 1);

        //int
        f.write((char*)&this->anAparitie, sizeof(this->anAparitie));

        //float
        f.write((char*)&this->pret, sizeof(this->pret));
        //int
        f.write((char*)&this->nrPagini, sizeof(this->nrPagini));
        //int*
        for (int i = 0;i < this->nrPagini;i++) {
            f.write((char*)&this->cuvintePerPagina[i], sizeof(this->cuvintePerPagina[i]));
        }
        //bool
        f.write((char*)&this->esteInStoc, sizeof(this->esteInStoc));
    }

    //deserializare
    void deserializare(string numeFisier) {
        ifstream f(numeFisier, ios::in | ios::binary);
        if (f.is_open()) {
            //char[]
            for (int i = 0;i < 10;i++) {
                f.read((char*)&this->numeCarte[i], sizeof(this->numeCarte[i]));
            }

            //string
            int dimNumeAutor = 0;
            f.read((char*)&dimNumeAutor, sizeof(dimNumeAutor));
            char* aux = new char[dimNumeAutor + 1];
            f.read(aux, dimNumeAutor + 1);
            this->numeAutor = aux;
            delete[]aux;

            //int
            f.read((char*)&this->anAparitie, sizeof(this->anAparitie));

            //float
            f.read((char*)&this->pret, sizeof(this->pret));
            //int
            f.read((char*)&this->nrPagini, sizeof(this->nrPagini));
            //int*
            if (this->cuvintePerPagina != NULL) {
                delete[]this->cuvintePerPagina;
            }
            this->cuvintePerPagina = new int[this->nrPagini];
            for (int i = 0;i < this->nrPagini;i++) {
                f.read((char*)&this->cuvintePerPagina[i], sizeof(this->cuvintePerPagina[i]));
            }
            //bool
            f.read((char*)&this->esteInStoc, sizeof(this->esteInStoc));

        }
        else { cout << "Fisierul cautat nu exista."; }
    }

    //FISIERE CSV
    void exportCSV(string numeFisier) {
        ofstream f(numeFisier, ios::out);
        f << this->numeCarte << ",";
        f << this->numeAutor << ",";
        f << this->anAparitie << ",";
        f << this->pret << ",";
        f << this->nrPagini << ",";
        for (int i = 0;i < this->nrPagini;i++) {
            f << this->cuvintePerPagina[i] << ",";
        }
        f << this->esteInStoc << endl;
        f.close();
    }




};
int Carte::numarator = 1;


class Roman :public Carte {
    string gen;
    int nrExemplareVandute;
public:
    Roman():Carte() {
        this->gen = "Anonim";
        this->nrExemplareVandute = 0;
    }

    Roman(const char numeCarte[50], string numeAutor, int anAparitie, float pret, int nrPagini, int* cuvintePerPagina, bool esteInStoc,
        string gen, int nrExemplareVandute) :Carte(numeCarte, numeAutor, anAparitie, pret, nrPagini, cuvintePerPagina, esteInStoc) {
        this->gen = gen;
        this->nrExemplareVandute = nrExemplareVandute;
    }

    Roman(const Roman& r):Carte(r) {
        this->gen = r.gen;
        this->nrExemplareVandute = r.nrExemplareVandute;
    }

    ~Roman() {

    }

    Roman& operator=(const Roman& r) {
        if (this != &r) {
            Carte::operator=(r);
            this->gen = r.gen;
            this->nrExemplareVandute = r.nrExemplareVandute;
        }
        return*this;
    }
    friend ostream& operator<<(ostream& out, const Roman& r) {
        out << (Carte&)r << endl;
        out << "Genul romanului: " <<r.gen<< endl;
        out << "Numarul exemplarelor vandute: " <<r.nrExemplareVandute<< endl;
        return out;
    }

    friend istream& operator>>(istream& in, Roman& r) {
        cout << "Genul romanului: ";
        getline(in, r.gen);
        cout << "Numarul exemplarelor vandute: " ;
        in >> r.nrExemplareVandute;
        return in;
    }

    //down-casting
    Roman(const Carte& c) :Carte(c) {
        this->gen = "Scolar";
        this->nrExemplareVandute = 31;
    }
};







class Angajat {
protected:
    char nume[50];
    string prenume;
    int varsta;
    float salariu;
    int nrLuniAngajat;
    float* venitLunar;
    bool estePensionar;

public:

    Angajat() {
        strcpy(this->nume, "Anonim");
        this->prenume = "Anonim";
        this->varsta = 0;
        this->salariu = 0;
        this->nrLuniAngajat = 0;
        this->venitLunar = NULL;
        this->estePensionar = 0;
    }

    Angajat(const char nume[50], string prenume, int varsta, float salariu, int nrLuniAngajat, float* venitLunar, bool estePensionar) {
        strcpy(this->nume, nume);
        this->prenume = prenume;
        this->varsta = varsta;
        this->salariu = salariu;
        this->nrLuniAngajat = nrLuniAngajat;
        this->venitLunar = new float[this->nrLuniAngajat];
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            this->venitLunar[i] = venitLunar[i];
        }
        this->estePensionar = estePensionar;

    }

    char* getNume() {
        return this->nume;
    }

    void setNume(const char nume[50]) {
        strcpy(this->nume, nume);
    }

    string getPrenume() {
        return this->prenume;
    }

    void setPrenume(string prenume) {
        this->prenume = prenume;
    }

    int getVarsta() {
        return this->varsta;
    }

    void setVarsta(int varsta) {
        if (varsta > 0) {
            this->varsta = varsta;
        }
        else {
            this->varsta = 0;
        }
    }

    float getSalariu() {
        return this->salariu;
    }

    void setSalariu(float salariu) {
        if (salariu > 0) {
            this->salariu = salariu;
        }
        else {
            this->salariu = 0;
        }
    }

    int getNrLuniAngajat() {
        return this->nrLuniAngajat;
    }

    float* getVenitLunar() {
        return this->venitLunar;
    }

    void setVenitLunar(int nrLuniAngajat, float* venitLunar) {
        if (nrLuniAngajat > 0 && venitLunar != NULL) {
            if (this->venitLunar != NULL) {
                delete[]this->venitLunar;
            }
            this->nrLuniAngajat = nrLuniAngajat;
            this->venitLunar = new float[this->nrLuniAngajat];
            for (int i = 0;i < this->nrLuniAngajat;i++) {
                this->venitLunar[i] = venitLunar[i];
            }
        }
        else {
            this->nrLuniAngajat = 0;
            this->venitLunar = NULL;
        }
    }


    bool getEstePensionar() {
        return this->estePensionar;
    }

    void setEstePensionar(bool estePensionar) {
        this->estePensionar = estePensionar;
    }

    ~Angajat() {
        if (this->venitLunar != NULL) {
            delete[]this->venitLunar;
        }
    }

    Angajat(const Angajat& a) {
        strcpy(this->nume, a.nume);
        this->prenume = a.prenume;
        this->varsta = a.varsta;
        this->salariu = a.salariu;
        this->nrLuniAngajat = a.nrLuniAngajat;
        this->venitLunar = new float[this->nrLuniAngajat];
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            this->venitLunar[i] = a.venitLunar[i];
        }
        this->estePensionar = a.estePensionar;
    }

    Angajat& operator=(const Angajat& a) {
        if (this != &a) {
            if (this->venitLunar != NULL) {
                delete[]this->venitLunar;
            }
            strcpy(this->nume, a.nume);
            this->prenume = a.prenume;
            this->varsta = a.varsta;
            this->salariu = a.salariu;
            this->nrLuniAngajat = a.nrLuniAngajat;
            this->venitLunar = new float[this->nrLuniAngajat];
            for (int i = 0;i < this->nrLuniAngajat;i++) {
                this->venitLunar[i] = a.venitLunar[i];
            }
            this->estePensionar = a.estePensionar;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Angajat& a) {
        out << "Nume Angajat: " << a.nume << endl;
        out << "Prenume Angajat: " << a.prenume << endl;
        out << "Varsta Angajat: " << a.varsta << " ani" << endl;
        out << "Salariu angajat: " << a.salariu << " lei" << endl;
        out << "Numar luni de cand este angajat: " << a.nrLuniAngajat << " luni" << endl;
        out << "Venit lunar(salariu+bonusuri): ";
        for (int i = 0;i < a.nrLuniAngajat;i++) {
            out << a.venitLunar[i] << " lei, ";
        }
        out << endl;
        out << "Este pensionar(1-DA,O-NU): " << a.estePensionar << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Angajat& a) {
        cout << "Nume angajat: ";
        in >> ws;
        char buffer[50];
        in.getline(buffer, 99);
        strcpy(a.nume, buffer);

        cout << "Prenume angajat: ";
        getline(in, a.prenume);

        cout << "Varsta angajat: ";
        in >> a.varsta;

        cout << "Salariu angajat: ";
        in >> a.salariu;

        cout << "Numar luni de cand este angajat : ";
        in >> a.nrLuniAngajat;

        cout << "Venit lunar(salariu+bonusuri): ";
        if (a.venitLunar != NULL) {
            delete[]a.venitLunar;
        }
        a.venitLunar = new float[a.nrLuniAngajat];
        for (int i = 0;i < a.nrLuniAngajat;i++) {
            in >> a.venitLunar[i];
        }
        cout << "Este pensionar(1-DA,O-NU): ";
        in >> a.estePensionar;
        return in;

    }

    //Metoda calculTotalVenitLunar() care calculeaza suma totala a veniturilor.

    float calculTotalVenitLunar() {
        float suma = 0;
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            suma = suma + this->venitLunar[i];
        }
        return suma;
    }

    //Metoda maxVenitLunar() care calculeaza cel mai mare venit lunar al angajatului.

    float  maxVenitLunar() {
        float maxim = this->venitLunar[0];
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            if (this->venitLunar[i] > maxim) {
                maxim = this->venitLunar[i];
            }
        }
        return maxim;
    }

    //operatorul pentru indexare[]
    float operator[](int pozitie) {
        if (pozitie >= 0 && pozitie < 10) {
            return this->venitLunar[pozitie];
        }
        else {
            int eroare = -1;
            return eroare;
        }
    }

    //operator +
    Angajat operator+(string prenume2) {
        Angajat copie = *this;
        copie.prenume = copie.prenume + prenume2;
        return copie;
    }

    //operator ++(post-incrementat)
    Angajat operator++(int) {
        Angajat copie = *this;
        if (this->venitLunar != NULL) {
            delete[]this->venitLunar;
        }
        this->nrLuniAngajat++;
        this->venitLunar = new float[this->nrLuniAngajat];
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            this->venitLunar[i] = copie.venitLunar[i];
        }
        this->venitLunar[this->nrLuniAngajat - 1] = 3000;
        return copie;
    }

    //operator++(pre-incrementat)
    Angajat operator++() {
        Angajat copie = *this;
        if (this->venitLunar != NULL) {
            delete[]this->venitLunar;
        }
        this->nrLuniAngajat++;
        this->venitLunar = new float[this->nrLuniAngajat];
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            this->venitLunar[i] = copie.venitLunar[i];
        }
        this->venitLunar[this->nrLuniAngajat - 1] = 3100;
        return *this;
    }

    //operator cast explicit
    explicit operator int() {
        return this->varsta;
    }

    //operator de negatie!
    bool operator!() {
        return this->estePensionar;
    }

    //operator <
    bool operator<(Angajat a) {
        float minim = this->venitLunar[0];
        float minim1 = this->venitLunar[0];
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            if (minim > this->venitLunar[i]) {
                minim = this->venitLunar[i];
            }
        }
        for (int i = 0;i < a.nrLuniAngajat;i++) {
            if (minim1 > a.venitLunar[i]) {
                minim1 = a.venitLunar[i];
            }
        }
        return minim < minim1;

    }

    bool operator<(Angajat a)const {
        return(this->varsta < a.varsta);
    }

    //operator ==

    bool operator==(Angajat a) {
        bool suntIdentice = 1;
        if (strcmp(this->nume, a.nume) == 1) {
            suntIdentice = 0;
        }
        if (this->prenume != a.prenume) {
            suntIdentice = 0;
        }
        if (this->varsta != a.varsta) {
            suntIdentice = 0;
        }
        if (this->salariu != a.salariu) {
            suntIdentice = 0;
        }
        if (this->nrLuniAngajat != a.nrLuniAngajat) {
            suntIdentice = 0;
        }
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            if (this->venitLunar[i] != a.venitLunar[i]) {
                suntIdentice = 0;
            }
        }
        if (this->estePensionar != a.estePensionar) {
            suntIdentice = 0;
        }
        return suntIdentice;
    }



    friend ofstream& operator<<(ofstream& out, const Angajat& a) {
        out << a.nume << endl;
        out << a.prenume << endl;
        out << a.varsta << endl;
        out << a.salariu << endl;
        out << a.nrLuniAngajat << endl;
        for (int i = 0;i < a.nrLuniAngajat;i++) {
            out << a.venitLunar[i] << " ";
        }
        out << endl;
        out << a.estePensionar << endl;
        return out;
    }

    friend ifstream& operator>>(ifstream& in, Angajat& a) {
        in >> ws;
        char buffer[50];
        in.getline(buffer, 99);
        strcpy(a.nume, buffer);
        getline(in, a.prenume);
        in >> a.varsta;
        in >> a.salariu;
        in >> a.nrLuniAngajat;
        if (a.venitLunar != NULL) {
            delete[]a.venitLunar;
        }
        a.venitLunar = new float[a.nrLuniAngajat];
        for (int i = 0;i < a.nrLuniAngajat;i++) {
            in >> a.venitLunar[i];
        }
        in >> a.estePensionar;
        return in;

    }

    void serializare(string numeFisier2) {
        ofstream f(numeFisier2, ios::out | ios::binary);

        for (int i = 0;i < 10;i++) {
            f.write((char*)&this->nume[i], sizeof(this->nume[i]));
        }

        //string
        int dimPrenume = this->prenume.size();
        f.write((char*)&dimPrenume, sizeof(dimPrenume));
        f.write(this->prenume.c_str(), dimPrenume + 1);

        //int
        f.write((char*)&this->varsta, sizeof(this->varsta));

        //float
        f.write((char*)&this->salariu, sizeof(this->salariu));
        //int
        f.write((char*)&this->nrLuniAngajat, sizeof(this->nrLuniAngajat));
        //int*
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            f.write((char*)&this->venitLunar[i], sizeof(this->venitLunar[i]));
        }
        //bool
        f.write((char*)&this->estePensionar, sizeof(this->estePensionar));
    }


    void deserializare(string numeFisier2) {
        ifstream f(numeFisier2, ios::in | ios::binary);
        if (f.is_open()) {
            //char[]
            for (int i = 0;i < 10;i++) {
                f.read((char*)&this->nume[i], sizeof(this->nume[i]));
            }

            //string
            int dimPrenume = 0;
            f.read((char*)&dimPrenume, sizeof(dimPrenume));
            char* aux = new char[dimPrenume + 1];
            f.read(aux, dimPrenume + 1);
            this->prenume = aux;
            delete[]aux;

            //int
            f.read((char*)&this->varsta, sizeof(this->varsta));

            //float
            f.read((char*)&this->salariu, sizeof(this->salariu));
            //int
            f.read((char*)&this->nrLuniAngajat, sizeof(this->nrLuniAngajat));
            //int*
            if (this->venitLunar != NULL) {
                delete[]this->venitLunar;
            }
            this->venitLunar = new float[this->nrLuniAngajat];
            for (int i = 0;i < this->nrLuniAngajat;i++) {
                f.read((char*)&this->venitLunar[i], sizeof(this->venitLunar[i]));
            }
            //bool
            f.read((char*)&this->estePensionar, sizeof(this->estePensionar));

        }
        else { cout << "Fisierul cautat nu exista."; }

    }

    //FISIERE CSV
    void exportCSV(string numeFisier) {
        ofstream f(numeFisier, ios::out);
        f << this->nume << ",";
        f << this->prenume << ",";
        f << this->varsta << ",";
        f << this->salariu << ",";
        f << this->nrLuniAngajat << ",";
        for (int i = 0;i < this->nrLuniAngajat;i++) {
            f << this->venitLunar[i] << ",";
        }
        f << this->estePensionar << endl;
        f.close();
    }


};


class Vanzator :public Angajat {
    int nrOreSuplimentare;
    bool areFacultate;

public:
    Vanzator() :Angajat() {
        this->nrOreSuplimentare = 0;
        this->areFacultate = 0;
    }

    Vanzator(const char nume[50], string prenume, int varsta, float salariu, int nrLuniAngajat, float* venitLunar, bool estePensionar,
        int nrOreSuplimentare, bool areFacultate) :Angajat(nume, prenume, varsta, salariu, nrLuniAngajat, venitLunar, estePensionar) {
        this->nrOreSuplimentare = nrOreSuplimentare;
        this->areFacultate = areFacultate;
    }

    Vanzator(const Vanzator& v) :Angajat(v) {
        this->nrOreSuplimentare = v.nrOreSuplimentare;
        this->areFacultate = v.areFacultate;
    }

    ~Vanzator() {

    }

    Vanzator& operator=(const Vanzator& v) {
        if (this != &v) {
            Angajat::operator =(v);
            this->nrOreSuplimentare = v.nrOreSuplimentare;
            this->areFacultate = v.areFacultate;
        }
        return*this;
    }

    friend ostream& operator<<(ostream& out, const Vanzator& v) {
        out << (Angajat &) v << endl;
        out << "Numar ore suplimentare: " << v.nrOreSuplimentare << endl;
        out << "Are facultate(1-DA,0-NU)?: " << v.areFacultate << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Vanzator& v) {
        cout << "Numar ore suplimentare: ";
        in >> v.nrOreSuplimentare;
        cout << "Are facultate(1-DA,0-NU)?: ";
        in >> v.areFacultate;

    }
    //down-casting
    Vanzator(const Angajat& a) :Angajat(a) {
        this->nrOreSuplimentare = 2;
        this->areFacultate = 1;
    }

};


class Comanda {
    const int idComanda;
    int data[3];
    int nrCarti;
    Carte* carti;
    int nrRechizite;
    float* valoareRechizite;
    static int TVA;
    bool estePersoanaFizica;

public:

    Comanda() :idComanda(99999) {
        for (int i = 0;i < 3;i++) {
            this->data[i] = 0;
        }
        this->nrCarti = 0;
        this->carti = NULL;
        this->nrRechizite = 0;
        this->valoareRechizite = 0;
        this->estePersoanaFizica = 0;
    }

    Comanda(int idComanda, int data[3], int nrCarti, Carte* carti, int nrRechizite, float* valoareRechizite, bool estePersoanaFizica) :idComanda(idComanda) {
        for (int i = 0;i < 3;i++) {
            this->data[i] = data[i];
        }
        this->nrCarti = nrCarti;
        this->carti = new Carte[this->nrCarti];
        for (int i = 0;i < this->nrCarti;i++) {
            this->carti[i] = carti[i];
        }
        this->nrRechizite = nrRechizite;
        this->valoareRechizite = new float[this->nrRechizite];
        for (int i = 0;i < this->nrRechizite;i++) {
            this->valoareRechizite[i] = valoareRechizite[i];
        }
        this->estePersoanaFizica = estePersoanaFizica;
    }

    int getIdComanda() {
        return this->idComanda;
    }

    int* getData() {
        return this->data;
    }

    void setData(int data[3]) {
        for (int i = 0;i < 3;i++) {
            this->data[i] = data[i];
        }
    }

    int getNrCarti() {
        return this->nrCarti;
    }

    Carte* getCarti() {
        return this->carti;
    }

    void setCarti(int nrCarti, Carte* carti) {
        if (this->carti != NULL) {
            delete[]this->carti;
        }
        this->nrCarti = nrCarti;
        this->carti = new Carte[this->nrCarti];
        for (int i = 0;i < this->nrCarti;i++) {
            this->carti[i] = carti[i];
        }
    }

    int getNrRechizite() {
        return this->nrRechizite;
    }

    float* getValoareRechizite() {
        return this->valoareRechizite;
    }

    void setValoareRechizite(int nrRechizite, float* valoareRechizite) {
        if (this->valoareRechizite != NULL) {
            delete[]this->valoareRechizite;
        }
        this->nrRechizite = nrRechizite;
        this->valoareRechizite = new float[this->nrRechizite];
        for (int i = 0;i < this->nrRechizite;i++) {
            this->valoareRechizite[i] = valoareRechizite[i];
        }
    }

    bool getEstePersoanaFizica() {
        return this->estePersoanaFizica;
    }

    void setEstePersoanaFizica(bool estePersoanaFizica) {
        this->estePersoanaFizica = estePersoanaFizica;
    }


    ~Comanda() {
        if (this->carti != NULL) {
            delete[]this->carti;
        }
        if (this->valoareRechizite != NULL) {
            delete[]this->valoareRechizite;
        }
    }

    Comanda(const Comanda& com) :idComanda(com.idComanda) {
        for (int i = 0;i < 3;i++) {
            this->data[i] = com.data[i];
        }
        this->nrCarti = com.nrCarti;
        this->carti = new Carte[this->nrCarti];
        for (int i = 0;i < this->nrCarti;i++) {
            this->carti[i] = com.carti[i];
        }
        this->nrRechizite = com.nrRechizite;
        this->valoareRechizite = new float[this->nrRechizite];
        for (int i = 0;i < this->nrRechizite;i++) {
            this->valoareRechizite[i] = com.valoareRechizite[i];
        }
        this->estePersoanaFizica = com.estePersoanaFizica;
    }

    Comanda& operator=(const Comanda& com) {
        if (this != &com) {
            if (this->carti != NULL) {
                delete[]this->carti;
            }
            if (this->valoareRechizite != NULL) {
                delete[]this->valoareRechizite;
            }
            for (int i = 0;i < 3;i++) {
                this->data[i] = com.data[i];
            }
            this->nrCarti = com.nrCarti;
            this->carti = new Carte[this->nrCarti];
            for (int i = 0;i < this->nrCarti;i++) {
                this->carti[i] = com.carti[i];
            }
            this->nrRechizite = com.nrRechizite;
            this->valoareRechizite = new float[this->nrRechizite];
            for (int i = 0;i < this->nrRechizite;i++) {
                this->valoareRechizite[i] = com.valoareRechizite[i];
            }
            this->estePersoanaFizica = com.estePersoanaFizica;
        }
        return *this;
    }


    friend ostream& operator<<(ostream& out, const Comanda& com) {
        out << "Id comanda: " << com.idComanda << endl;
        out << "Data comanda: ";
        for (int i = 0;i < 3;i++) {
            out << com.data[i] << ". ";
        }
        out << endl;
        out << "Numar carti: " << com.nrCarti << endl;
        out << "Carti: " << endl << endl;
        for (int i = 0;i < com.nrCarti;i++) {
            out << com.carti[i] << endl << "*************" << endl;
        }
        out << "Numar rechizite: " << com.nrRechizite << endl;
        out << "Valoare Rechizite:";
        for (int i = 0;i < com.nrRechizite;i++) {
            out << com.valoareRechizite[i] << " lei" << endl;
        }
        out << "Este persoana fizica(1-DA,0-NU): " << com.estePersoanaFizica << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Comanda& com) {
        cout << "Data comanda: ";
        for (int i = 0;i < 3;i++) {
            in >> com.data[i];
        }

        cout << "Numar carti:";
        in >> com.nrCarti;

        cout << "Carti:" << endl;
        if (com.carti != NULL) {
            delete[]com.carti;
        }
        com.carti = new Carte[com.nrCarti];
        for (int i = 0;i < com.nrCarti;i++) {
            in >> com.carti[i];
        }
        cout << "Numar rechizite: ";
        in >> com.nrRechizite;

        cout << "Valoare rechizite: ";
        if (com.valoareRechizite != NULL) {
            delete[]com.valoareRechizite;
        }
        com.valoareRechizite = new float[com.nrRechizite];
        for (int i = 0;i < com.nrRechizite;i++) {
            in >> com.valoareRechizite[i];
        }
        cout << "Este persoana fizica?(1-DA,0-NU): ";
        in >> com.estePersoanaFizica;

        return in;

    }

    //metoda care adaunga o noua carte la comanda
    void adaugaComanda(Carte c) {
        Comanda copie = *this;
        if (this->carti != NULL) {
            delete[]this->carti;
        }
        this->nrCarti++;
        this->carti = new Carte[this->nrCarti];
        for (int i = 0;i < copie.nrCarti;i++) {
            this->carti[i] = copie.carti[i];
        }
        this->carti[this->nrCarti - 1] = c;

    }

    //metoda care calculeaza pretul tuturor cartilor din comanda
    float totalPretCarti() {
        float suma = 0;
        for (int i = 0;i < this->nrCarti;i++) {
            suma = suma + this->carti[i].getPret();
        }
        return suma;
    }

    //operatorul pentru indexare[]
    float operator[](int pozitie) {
        if (pozitie >= 0 && pozitie < nrRechizite) {
            return this->valoareRechizite[pozitie];
        }
        else {
            int eroare = -1;
            return eroare;
        }
    }

    //operator +
    Comanda operator+(int nr) {
        Comanda copie = *this;
        copie.data[0] = copie.data[0] + nr;
        return copie;
    }

    //operator ==

    bool operator==(Comanda com) {
        bool suntIdentice = 1;
        for (int i = 0;i < 3;i++) {
            if (this->data[i] != com.data[i]) {
                suntIdentice = 0;
            }
        }
        if (this->nrCarti != com.nrCarti) {
            suntIdentice = 0;
        }
        //comparare carti[i]??
        if (this->nrRechizite != com.nrRechizite) {
            suntIdentice = 0;
        }
        for (int i = 0;i < this->nrRechizite;i++) {
            if (this->valoareRechizite[i] != com.valoareRechizite[i]) {
                suntIdentice = 0;
            }
        }
        if (this->estePersoanaFizica != com.estePersoanaFizica) {
            suntIdentice = 0;
        }

        return suntIdentice;
    }

    //operator cast explicit
    explicit operator int() {
        return this->nrCarti;
    }

    //operator de negatie!
    bool operator!() {
        return this->estePersoanaFizica;
    }

    //operator++
    Comanda operator++() {
        Comanda copie = *this;
        if (this->valoareRechizite != NULL) {
            delete[]this->valoareRechizite;
        }
        this->nrRechizite++;
        this->valoareRechizite = new float[this->nrRechizite];
        for (int i = 0;i < this->nrRechizite;i++) {
            this->valoareRechizite[i] = copie.valoareRechizite[i];
        }
        this->valoareRechizite[this->nrRechizite - 1] = 45;
        return*this;
    }


    friend ofstream& operator<<(ofstream& out, const Comanda& com) {
        out << com.idComanda << endl;
        for (int i = 0;i < 3;i++) {
            out << com.data[i] << " ";
        }
        out << endl;
        out << com.nrCarti << endl;
        for (int i = 0;i < com.nrCarti;i++) {
            out << com.carti[i] << endl << " " << endl;
        }
        out << com.nrRechizite << endl;
        for (int i = 0;i < com.nrRechizite;i++) {
            out << com.valoareRechizite[i] << "  " << endl;
        }
        out << com.estePersoanaFizica << endl;
        return out;
    }

    friend ifstream& operator>>(ifstream& in, Comanda& com) {
        for (int i = 0;i < 3;i++) {
            in >> com.data[i];
        }
        in >> com.nrCarti;

        if (com.carti != NULL) {
            delete[]com.carti;
        }
        com.carti = new Carte[com.nrCarti];
        for (int i = 0;i < com.nrCarti;i++) {
            in >> com.carti[i];
        }

        in >> com.nrRechizite;
        if (com.valoareRechizite != NULL) {
            delete[]com.valoareRechizite;
        }
        com.valoareRechizite = new float[com.nrRechizite];
        for (int i = 0;i < com.nrRechizite;i++) {
            in >> com.valoareRechizite[i];
        }
        in >> com.estePersoanaFizica;
        return in;
    }


    void serializare(string numeFisier3) {
        ofstream f(numeFisier3, ios::out | ios::binary);

        for (int i = 0;i < 3;i++) {
            f.write((char*)&this->data[i], sizeof(this->data[i]));
        }
        //int
        f.write((char*)&this->nrCarti, sizeof(this->nrCarti));
        //int*
        for (int i = 0;i < this->nrCarti;i++) {
            f.write((char*)&this->carti[i], sizeof(this->carti[i]));
        }

        //int
        f.write((char*)&this->nrRechizite, sizeof(this->nrRechizite));
        //float*
        for (int i = 0;i < this->nrRechizite;i++) {
            f.write((char*)&this->valoareRechizite[i], sizeof(this->valoareRechizite[i]));
        }
        //bool
        f.write((char*)&this->estePersoanaFizica, sizeof(this->estePersoanaFizica));
    }


    void deserializare(string numeFisier3) {
        ifstream f(numeFisier3, ios::in | ios::binary);
        if (f.is_open()) {
            for (int i = 0;i < 3;i++) {
                f.read((char*)&this->data[i], sizeof(this->data[i]));
            }
            //int
            f.read((char*)&this->nrCarti, sizeof(this->nrCarti));
            //int*
            if (this->carti != NULL) {
                delete[]this->carti;
            }
            this->carti = new Carte[this->nrCarti];
            for (int i = 0;i < this->nrCarti;i++) {
                f.read((char*)&this->carti[i], sizeof(this->carti[i]));
            }

            //int
            f.read((char*)&this->nrRechizite, sizeof(this->nrRechizite));
            //float*
            if (this->valoareRechizite != NULL) {
                delete[]this->valoareRechizite;
            }
            this->valoareRechizite = new float[this->nrRechizite];
            for (int i = 0;i < this->nrRechizite;i++) {
                f.read((char*)&this->valoareRechizite[i], sizeof(this->valoareRechizite[i]));
            }
            //bool
            f.read((char*)&this->estePersoanaFizica, sizeof(this->estePersoanaFizica));
        }
        else { cout << "Fisierul cautat nu exista."; }

    }

    //FISIERE CSV
    void exportCSV(string numeFisier) {
        ofstream f(numeFisier, ios::out);
        f << this->data << ",";
        f << this->nrCarti << ",";
        for (int i = 0;i < this->nrCarti;i++) {
            f << this->carti[i] << ",";
        }
        f << this->nrRechizite << ",";
        for (int i = 0;i < this->nrRechizite;i++) {
            f << this->valoareRechizite[i] << ",";
        }
        f << this->estePersoanaFizica << endl;
        f.close();
    }



};
int Comanda::TVA = 3;



class Furnizor {
    char denumire[50];
    string adresaFurnizor;
    int nrProduse;
    float* valoareProduse;
    bool oferaReducere;
    static int valoareTransport;

public:

    Furnizor() {
        strcpy(this->denumire, "Anonim");
        this->adresaFurnizor = "Necunoscut";
        this->nrProduse = 0;
        this->valoareProduse = NULL;
        this->oferaReducere = 0;

    }

    Furnizor(const char denumire[50], string adresaFurnizor, int nrProduse, float* valoareProduse, bool oferaReducere) {
        strcpy(this->denumire, denumire);
        this->adresaFurnizor = adresaFurnizor;
        this->nrProduse = nrProduse;
        this->valoareProduse = new float[this->nrProduse];
        for (int i = 0;i < this->nrProduse;i++) {
            this->valoareProduse[i] = valoareProduse[i];
        }
        this->oferaReducere = oferaReducere;
    }

    ~Furnizor() {
        if (this->valoareProduse != NULL) {
            delete[]this->valoareProduse;
        }
    }

    char* getDenumire() {
        return this->denumire;
    }

    void setDenumire(const char denumire[50]) {
        strcpy(this->denumire, denumire);
    }

    string getAdresaFurnizor() {
        return this->adresaFurnizor;
    }

    void setAdresaFurnizor(string adresaFurnizor) {
        this->adresaFurnizor = adresaFurnizor;
    }

    int getNrProduse() {
        return this->nrProduse;
    }

    float* getValoareProduse() {
        return this->valoareProduse;
    }

    void setValoareProduse(int nrProduse, float* valoareProduse) {
        if (nrProduse > 0 && valoareProduse != NULL) {
            if (this->valoareProduse != NULL) {
                delete[]this->valoareProduse;
            }
            this->nrProduse = nrProduse;
            this->valoareProduse = new float[this->nrProduse];
            for (int i = 0;i < this->nrProduse;i++) {
                this->valoareProduse[i] = valoareProduse[i];
            }
        }
        else {
            this->nrProduse = 0;
            this->valoareProduse = NULL;
        }
    }


    bool getOferaReducere() {
        return this->oferaReducere;
    }

    void setOferaReducere(bool oferaReducere) {
        this->oferaReducere = oferaReducere;
    }

    Furnizor(const Furnizor& f) {
        strcpy(this->denumire, f.denumire);
        this->adresaFurnizor = f.adresaFurnizor;
        this->nrProduse = f.nrProduse;
        this->valoareProduse = new float[this->nrProduse];
        for (int i = 0;i < this->nrProduse;i++) {
            this->valoareProduse[i] = f.valoareProduse[i];
        }
        this->oferaReducere = f.oferaReducere;
    }

    Furnizor& operator=(const Furnizor& f) {
        if (this != &f) {
            if (this->valoareProduse != NULL) {
                delete[]this->valoareProduse;
            }
            strcpy(this->denumire, f.denumire);
            this->adresaFurnizor = f.adresaFurnizor;
            this->nrProduse = f.nrProduse;
            this->valoareProduse = new float[this->nrProduse];
            for (int i = 0;i < this->nrProduse;i++) {
                this->valoareProduse[i] = f.valoareProduse[i];
            }
            this->oferaReducere = f.oferaReducere;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Furnizor& f) {
        out << "Nume furnizor: " << f.denumire << endl;
        out << "Adresa Furnizor: " << f.adresaFurnizor << endl;
        out << "Numar produse: " << f.nrProduse << endl;
        out << "Valoare produse: ";
        for (int i = 0;i < f.nrProduse;i++) {
            out << f.valoareProduse[i] << " lei, ";
        }
        out << endl;
        out << "Ofera reducere(1-DA,0-NU): " << f.oferaReducere << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Furnizor& f) {
        cout << "Nume furnizor: ";
        char buffer[50];
        in.getline(buffer, 99);
        strcpy(f.denumire, buffer);

        cout << "Adresa furnizor: ";
        getline(in, f.adresaFurnizor);

        cout << "Numar produse: ";
        in >> f.nrProduse;

        cout << "Valoare produse: ";
        for (int i = 0;i < f.nrProduse;i++) {
            in >> f.valoareProduse[i];
        }

        cout << "Ofera reducere(1-DA,0-NU): ";
        in >> f.oferaReducere;
        return in;
    }

    //metoda care calculeaza suma totala a produselor luate de la furnizor;

    float calculSumaFurnizor() {
        float suma = 0;
        for (int i = 0;i < this->nrProduse;i++) {
            suma = suma + this->valoareProduse[i];
        }
        return suma;
    }

    //metoda care adauga un produs nou si o valoare in vector;
    void adaugaProdus(float pretProdus) {
        Furnizor copie = *this;
        if (this->valoareProduse != NULL) {
            delete[]this->valoareProduse;
        }
        this->nrProduse++;
        this->valoareProduse = new float[this->nrProduse];
        for (int i = 0;i < copie.nrProduse;i++) {
            this->valoareProduse[i] = copie.valoareProduse[i];
        }
        this->valoareProduse[this->nrProduse - 1] = pretProdus;
    }


    //operatorul pentru indexare[]
    int operator[](int pozitie) {
        if (pozitie >= 0 && pozitie < nrProduse) {
            return this->valoareProduse[pozitie];
        }
        else {
            int eroare = -1;
            return eroare;
        }
    }

    //operator +
    Furnizor operator+(string adress) {
        Furnizor copie = *this;
        copie.adresaFurnizor = copie.adresaFurnizor + adress;
        return copie;
    }


    //operator cast explicit
    explicit operator int() {
        return this->nrProduse;
    }


    //operator de negatie!
    bool operator!() {
        return this->oferaReducere;
    }

    //operator++
    Furnizor operator++() {
        Furnizor copie = *this;
        if (this->valoareProduse != NULL) {
            delete[]this->valoareProduse;
        }
        this->nrProduse++;
        this->valoareProduse = new float[this->nrProduse];
        for (int i = 0;i < this->nrProduse;i++) {
            this->valoareProduse[i] = copie.valoareProduse[i];
        }
        this->valoareProduse[this->nrProduse - 1] = 150;
        return*this;
    }

    //operator <

    bool operator<(Furnizor f) {
        float minim = this->valoareProduse[0];
        float minim1 = this->valoareProduse[0];
        for (int i = 0;i < this->nrProduse;i++) {
            if (minim > this->valoareProduse[i]) {
                minim = this->valoareProduse[i];
            }
        }
        for (int i = 0;i < f.nrProduse;i++) {
            if (minim > f.valoareProduse[i]) {
                minim = f.valoareProduse[i];
            }
        }
        return minim < minim1;
    }


    //operator==

    bool operator==(Furnizor f) {
        bool suntIdentice = 1;
        if (strcmp(this->denumire, f.denumire) == 1) {
            suntIdentice = 0;
        }
        if (this->adresaFurnizor != f.adresaFurnizor) {
            suntIdentice = 0;
        }
        if (this->nrProduse != f.nrProduse) {
            suntIdentice = 0;
        }
        for (int i = 0;i < this->nrProduse;i++) {
            if (this->valoareProduse[i] != f.valoareProduse[i]) {
                suntIdentice = 0;
            }
        }
        if (this->oferaReducere != f.oferaReducere) {
            suntIdentice = 0;
        }
        return suntIdentice;
    }


    friend ofstream& operator<<(ofstream& out, const Furnizor& f) {
        out << f.denumire << endl;
        out << f.adresaFurnizor << endl;
        out << f.nrProduse << endl;
        for (int i = 0;i < f.nrProduse;i++) {
            out << f.valoareProduse[i] << "  ";
        }
        out << endl;
        out << f.oferaReducere << endl;
        return out;
    }

    friend ifstream& operator>>(ifstream& in, Furnizor& f) {
        char buffer[50];
        in.getline(buffer, 99);
        strcpy(f.denumire, buffer);

        getline(in, f.adresaFurnizor);

        in >> f.nrProduse;

        for (int i = 0;i < f.nrProduse;i++) {
            in >> f.valoareProduse[i];
        }
        in >> f.oferaReducere;
        return in;
    }

    void serializare(string numeFisier4) {
        ofstream f(numeFisier4, ios::out | ios::binary);

        for (int i = 0;i < 10;i++) {
            f.write((char*)&this->denumire[i], sizeof(this->denumire[i]));
        }

        //string
        int dimAdresaFurnizor = this->adresaFurnizor.size();
        f.write((char*)&dimAdresaFurnizor, sizeof(dimAdresaFurnizor));
        f.write(this->adresaFurnizor.c_str(), dimAdresaFurnizor + 1);

        //int
        f.write((char*)&this->nrProduse, sizeof(this->nrProduse));
        //float*
        for (int i = 0;i < this->nrProduse;i++) {
            f.write((char*)&this->valoareProduse[i], sizeof(this->valoareProduse[i]));
        }
        //bool
        f.write((char*)&this->oferaReducere, sizeof(this->oferaReducere));
    }


    void deserializare(string numeFisier4) {
        ifstream f(numeFisier4, ios::in | ios::binary);
        if (f.is_open()) {
            //char[]
            for (int i = 0;i < 20;i++) {
                f.read((char*)&this->denumire[i], sizeof(this->denumire[i]));
            }
            //string
            int dimAdresaFurnizor = 0;
            f.read((char*)&dimAdresaFurnizor, sizeof(dimAdresaFurnizor));
            char* aux = new char[dimAdresaFurnizor + 1];
            f.read(aux, dimAdresaFurnizor + 1);
            this->adresaFurnizor = aux;
            delete[]aux;
            //int
            f.read((char*)&this->nrProduse, sizeof(this->nrProduse));

            //float*
            if (this->valoareProduse != NULL) {
                delete[]this->valoareProduse;
            }
            this->valoareProduse = new float[this->nrProduse];
            for (int i = 0;i < this->nrProduse;i++) {
                f.read((char*)&this->valoareProduse[i], sizeof(this->valoareProduse[i]));
            }
            //bool
            f.read((char*)&this->oferaReducere, sizeof(this->oferaReducere));

        }
        else { cout << "Fisierul cautat nu exista."; }

    }

    //FISIERE CSV
    void exportCSV(string numeFisier) {
        ofstream f(numeFisier, ios::out);
        f << this->denumire << ",";
        f << this->adresaFurnizor << ",";
        f << this->nrProduse << ",";
        for (int i = 0;i < this->nrProduse;i++) {
            f << this->valoareProduse[i] << ",";
        }
        f << this->oferaReducere << endl;
        f.close();
    }


};
int Furnizor::valoareTransport = 25;


class Librarie {
    char numeLibrarie[50];
    string adresaLibrarie;
    int nrAngajati;
    Angajat* angajati;
    int nrRaioane;
    int* obiectePeRaion;
    float suprafata;
    bool acceptaPlataCard;

public:

    Librarie() {
        strcpy(this->numeLibrarie, "Necunoscut");
        this->adresaLibrarie = "Necunoscut";
        this->nrAngajati = 0;
        this->angajati = NULL;
        this->nrRaioane = 0;
        this->obiectePeRaion = NULL;
        this->suprafata = 0;
        this->acceptaPlataCard = 0;
    }

    Librarie(const char numeLibrarie[50], string adresaLibrarie, int nrAngajati, Angajat* angajati, int nrRaioane, int* obiectePeRaion, float suprafata, bool acceptaPlataCard) {
        strcpy(this->numeLibrarie, numeLibrarie);
        this->adresaLibrarie = adresaLibrarie;
        this->nrAngajati = nrAngajati;
        this->angajati = new Angajat[this->nrAngajati];
        for (int i = 0;i < this->nrAngajati;i++) {
            this->angajati[i] = angajati[i];
        }
        this->nrRaioane = nrRaioane;
        this->obiectePeRaion = new int[this->nrRaioane];
        for (int i = 0;i < this->nrRaioane;i++) {
            this->obiectePeRaion[i] = obiectePeRaion[i];
        }
        this->suprafata = suprafata;
        this->acceptaPlataCard = acceptaPlataCard;
    }

    char* getNumeLibrarie() {
        return this->numeLibrarie;
    }

    void setNumeLibrarie(const char numeLibrarie[50]) {
        strcpy(this->numeLibrarie, numeLibrarie);
    }

    string getAdresaLibrarie() {
        return this->adresaLibrarie;
    }

    void setAdresaLibrarie(string adresa) {
        this->adresaLibrarie = adresaLibrarie;
    }

    int getNrRaioane() {
        return this->nrRaioane;
    }

    int* getObiectePeRaion() {
        return this->obiectePeRaion;
    }

    void setObiectePeRaion(int nrRaioane, int* obiectePeRaion) {
        if (nrRaioane > 0 && obiectePeRaion != NULL) {
            if (this->obiectePeRaion != NULL) {
                delete[]this->obiectePeRaion;
            }
            this->nrRaioane = nrRaioane;
            this->obiectePeRaion = new int[this->nrRaioane];
            for (int i = 0;i < this->nrRaioane;i++) {
                this->obiectePeRaion[i] = obiectePeRaion[i];
            }
        }
        else {
            this->nrRaioane = 0;
            this->obiectePeRaion = NULL;
        }
    }

    int getNrAngajati() {
        return this->nrAngajati;
    }

    Angajat* getAngajati() {
        return this->angajati;
    }

    void setAngajati(int nrAngajati, Angajat* angajati) {
        if (nrAngajati > 0 && angajati != NULL) {
            if (this->angajati != NULL) {
                delete[]this->angajati;
            }
            this->nrAngajati = nrAngajati;
            this->angajati = new Angajat[this->nrAngajati];
            for (int i = 0;i < this->nrAngajati;i++) {
                this->angajati[i] = angajati[i];
            }
        }
        else {
            this->nrAngajati = 0;
            this->angajati = NULL;
        }
    }

    float getSuprafata() {
        return this->suprafata;
    }

    void setSuprafata(float suprafata) {
        if (suprafata > 0) {
            this->suprafata = suprafata;
        }
        else {
            this->suprafata = 0;
        }
    }

    bool getAcceptaPlataCard() {
        return this->acceptaPlataCard;
    }

    void setAcceptaPlataCard(bool acceptaPlataCard) {
        this->acceptaPlataCard = acceptaPlataCard;
    }

    ~Librarie() {
        if (this->angajati != NULL) {
            delete[]this->angajati;
        }
        if (this->obiectePeRaion != NULL) {
            delete[]this->obiectePeRaion;
        }
    }

    Librarie(const Librarie& l) {
        strcpy(this->numeLibrarie, l.numeLibrarie);
        this->adresaLibrarie = l.adresaLibrarie;
        this->nrAngajati = l.nrAngajati;
        this->angajati = new Angajat[this->nrAngajati];
        for (int i = 0;i < this->nrAngajati;i++) {
            this->angajati[i] = l.angajati[i];
        }
        this->nrRaioane = l.nrRaioane;
        this->obiectePeRaion = new int[this->nrRaioane];
        for (int i = 0;i < this->nrRaioane;i++) {
            this->obiectePeRaion[i] = l.obiectePeRaion[i];
        }
        this->suprafata = l.suprafata;
        this->acceptaPlataCard = l.acceptaPlataCard;
    }

    Librarie& operator=(const Librarie& l) {
        if (this != &l) {
            if (this->angajati != NULL) {
                delete[]this->angajati;
            }
            if (this->obiectePeRaion != NULL) {
                delete[]this->obiectePeRaion;
            }
            strcpy(this->numeLibrarie, l.numeLibrarie);
            this->adresaLibrarie = l.adresaLibrarie;
            this->nrAngajati = l.nrAngajati;
            this->angajati = new Angajat[this->nrAngajati];
            for (int i = 0;i < this->nrAngajati;i++) {
                this->angajati[i] = l.angajati[i];
            }
            this->nrRaioane = l.nrRaioane;
            this->obiectePeRaion = new int[this->nrRaioane];
            for (int i = 0;i < this->nrRaioane;i++) {
                this->obiectePeRaion[i] = l.obiectePeRaion[i];
            }
            this->suprafata = l.suprafata;
            this->acceptaPlataCard = l.acceptaPlataCard;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Librarie& l) {
        cout << "Nume librarie: " << l.numeLibrarie << endl;
        cout << "Adresa librarie: " << l.adresaLibrarie << endl;
        cout << "Numar angajati: " << l.nrAngajati << endl;
        cout << "Angajati: " << endl << endl;
        cout << "*********" << endl;
        for (int i = 0;i < l.nrAngajati;i++) {
            cout << l.angajati[i] << endl << "********" << endl;
        }
        cout << endl;
        cout << "Numar raioane librarie: " << l.nrRaioane << endl;
        cout << "Obiecte pe raion: ";
        for (int i = 0;i < l.nrRaioane;i++) {
            cout << l.obiectePeRaion[i] << ", ";
        }
        cout << endl;
        cout << "Suprafata librarie: " << l.suprafata << " metri patrati" << endl;
        cout << "Accepta plata cu cardul(1-DA,0-NU): " << l.acceptaPlataCard << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Librarie& l) {
        cout << "Nume librarie: ";
        char buffer[50];
        in.getline(buffer, 99);
        strcpy(l.numeLibrarie, buffer);

        cout << "Adresa librarie: ";
        getline(in, l.adresaLibrarie);

        cout << "Numar angajati: ";
        in >> l.nrAngajati;

        cout << "Angajati: ";
        if (l.angajati != NULL) {
            delete[]l.angajati;
        }
        l.angajati = new Angajat[l.nrAngajati];
        for (int i = 0;i < l.nrAngajati;i++) {
            in >> l.angajati[i];
        }

        cout << "Numar raioane librarie: ";
        in >> l.nrRaioane;

        cout << "Obiecte pe raion: ";
        if (l.obiectePeRaion != NULL) {
            delete[]l.obiectePeRaion;
        }
        l.obiectePeRaion = new int[l.nrRaioane];
        for (int i = 0;i < l.nrRaioane;i++) {
            in >> l.obiectePeRaion[i];
        }

        cout << "Suprafata librarie: ";
        in >> l.suprafata;

        cout << "Accepta plata cu cardul(1-DA,0-NU): ";
        in >> l.acceptaPlataCard;
        return in;
    }

    //metoda care sa adauge un nou angajat in librarie.

    void adaugaAngajat(Angajat a) {
        Librarie copie = *this;
        if (this->angajati != NULL) {
            delete[]this->angajati;
        }
        this->nrAngajati++;
        this->angajati = new Angajat[this->nrAngajati];
        for (int i = 0;i < copie.nrAngajati;i++) {
            this->angajati[i] = copie.angajati[i];
        }
        this->angajati[this->nrAngajati - 1] = a;
    }

    //metoda care calculeaza salariul total al angajatilor din librarie.
    float totalSumaSalariu() {
        float suma = 0;
        for (int i = 0;i < this->nrAngajati;i++) {
            suma = suma + this->angajati[i].getSalariu();
        }
        return suma;
    }

    //operatorul pentru indexare[]
    int operator[](int pozitie) {
        if (pozitie >= 0 && pozitie < nrRaioane) {
            return this->obiectePeRaion[pozitie];
        }
        else {
            int eroare = -1;
            return eroare;
        }
    }

    //operator +
    Librarie operator+(string adress) {
        Librarie copie = *this;
        copie.adresaLibrarie = copie.adresaLibrarie + adress;
        return copie;
    }



    //operator cast explicit
    explicit operator int() {
        return this->nrAngajati;
    }

    //operator de negatie!
    bool operator!() {
        return this->acceptaPlataCard;
    }

    //operator++
    Librarie operator++() {
        Librarie copie = *this;
        if (this->obiectePeRaion != NULL) {
            delete[]this->obiectePeRaion;
        }
        this->nrRaioane++;
        this->obiectePeRaion = new int[this->nrRaioane];
        for (int i = 0;i < this->nrRaioane;i++) {
            this->obiectePeRaion[i] = copie.obiectePeRaion[i];
        }
        this->obiectePeRaion[this->nrRaioane - 1] = 88;
        return*this;
    }

    //operator <

    bool operator<(Librarie l) {
        float minim = this->obiectePeRaion[0];
        float minim1 = this->obiectePeRaion[0];
        for (int i = 0;i < this->nrRaioane;i++) {
            if (minim > this->obiectePeRaion[i]) {
                minim = this->obiectePeRaion[i];
            }
        }
        for (int i = 0;i < l.nrRaioane;i++) {
            if (minim > l.obiectePeRaion[i]) {
                minim = l.obiectePeRaion[i];
            }
        }
        return minim < minim1;
    }

    //operator==

    bool operator==(Librarie l) {
        bool suntIdentice = 1;
        if (strcmp(this->numeLibrarie, l.numeLibrarie) == 1) {
            suntIdentice = 0;
        }
        if (this->adresaLibrarie != l.adresaLibrarie) {
            suntIdentice = 0;
        }
        if (this->nrAngajati != l.nrAngajati) {
            suntIdentice = 0;
        }
        if (this->nrRaioane != l.nrRaioane) {
            suntIdentice = 0;
        }
        for (int i = 0;i < this->nrRaioane;i++) {
            if (this->obiectePeRaion[i] != l.obiectePeRaion[i]) {
                suntIdentice = 0;
            }
        }
        if (this->suprafata != l.suprafata) {
            suntIdentice = 0;
        }
        if (this->acceptaPlataCard != l.acceptaPlataCard) {
            suntIdentice = 0;
        }
        return suntIdentice;
    }


    friend ofstream& operator<<(ofstream& out, const Librarie& l) {
        out << l.numeLibrarie << endl;
        out << l.adresaLibrarie << endl;
        out << l.nrAngajati << endl;
        for (int i = 0;i < l.nrAngajati;i++) {
            out << l.angajati[i] << endl << " " << endl;
        }
        out << endl;
        out << l.nrRaioane << endl;
        for (int i = 0;i < l.nrRaioane;i++) {
            out << l.obiectePeRaion[i] << " ";
        }
        out << endl;
        out << l.suprafata << endl;
        out << l.acceptaPlataCard << endl;
        return out;
    }

    friend ifstream& operator>>(ifstream& in, Librarie& l) {
        char buffer[50];
        in.getline(buffer, 99);
        strcpy(l.numeLibrarie, buffer);

        getline(in, l.adresaLibrarie);

        in >> l.nrAngajati;

        if (l.angajati != NULL) {
            delete[]l.angajati;
        }
        l.angajati = new Angajat[l.nrAngajati];
        for (int i = 0;i < l.nrAngajati;i++) {
            in >> l.angajati[i];
        }

        in >> l.nrRaioane;

        if (l.obiectePeRaion != NULL) {
            delete[]l.obiectePeRaion;
        }
        l.obiectePeRaion = new int[l.nrRaioane];
        for (int i = 0;i < l.nrRaioane;i++) {
            in >> l.obiectePeRaion[i];
        }

        in >> l.suprafata;

        in >> l.acceptaPlataCard;
        return in;
    }


    void serializare(string numeFisier5) {
        ofstream f(numeFisier5, ios::out | ios::binary);

        for (int i = 0;i < 10;i++) {
            f.write((char*)&this->numeLibrarie[i], sizeof(this->numeLibrarie[i]));
        }

        //string
        int dimAdresaLibrarie = this->adresaLibrarie.size();
        f.write((char*)&dimAdresaLibrarie, sizeof(dimAdresaLibrarie));
        f.write(this->adresaLibrarie.c_str(), dimAdresaLibrarie + 1);

        //int
        f.write((char*)&this->nrAngajati, sizeof(this->nrAngajati));

        for (int i = 0;i < this->nrAngajati;i++) {
            f.write((char*)&this->angajati[i], sizeof(this->angajati[i]));
        }
        //int
        f.write((char*)&this->nrRaioane, sizeof(this->nrRaioane));

        for (int i = 0;i < this->nrRaioane;i++) {
            f.write((char*)&this->obiectePeRaion[i], sizeof(this->obiectePeRaion[i]));
        }
        //float
        f.write((char*)&this->suprafata, sizeof(this->suprafata));
        //bool
        f.write((char*)&this->acceptaPlataCard, sizeof(this->acceptaPlataCard));
    }


    void deserializare(string numeFisier5) {
        ifstream f(numeFisier5, ios::in | ios::binary);
        if (f.is_open()) {
            //char[]
            for (int i = 0;i < 20;i++) {
                f.read((char*)&this->numeLibrarie[i], sizeof(this->numeLibrarie[i]));
            }
            //string
            int dimAdresaLibrarie = 0;
            f.read((char*)&dimAdresaLibrarie, sizeof(dimAdresaLibrarie));
            char* aux = new char[dimAdresaLibrarie + 1];
            f.read(aux, dimAdresaLibrarie + 1);
            this->adresaLibrarie = aux;
            delete[]aux;
            //int
            f.read((char*)&this->nrAngajati, sizeof(this->nrAngajati));

            if (this->angajati != NULL) {
                delete[]this->angajati;
            }
            this->angajati = new Angajat[this->nrAngajati];
            for (int i = 0;i < this->nrAngajati;i++) {
                f.read((char*)&this->angajati[i], sizeof(this->angajati[i]));
            }
            //int
            f.read((char*)&this->nrRaioane, sizeof(this->nrRaioane));

            if (this->obiectePeRaion != NULL) {
                delete[]this->obiectePeRaion;
            }
            this->obiectePeRaion = new int[this->nrRaioane];
            for (int i = 0;i < this->nrRaioane;i++) {
                f.read((char*)&this->obiectePeRaion[i], sizeof(this->obiectePeRaion[i]));
            }
            //bool
            f.read((char*)&this->acceptaPlataCard, sizeof(this->acceptaPlataCard));

        }
        else { cout << "Fisierul cautat nu exista."; }

    }

    //FISIERE CSV
    void exportCSV(string numeFisier) {
        ofstream f(numeFisier, ios::out);
        f << this->numeLibrarie << ",";
        f << this->adresaLibrarie << ",";
        f << this->nrAngajati << ",";
        for (int i = 0;i < this->nrAngajati;i++) {
            f << this->angajati[i] << ",";
        }
        f << this->nrRaioane << ",";
        for (int i = 0;i < this->nrRaioane;i++) {
            f << this->obiectePeRaion[i] << ",";
        }
        f << this->acceptaPlataCard << endl;
        f.close();
    }

};



class Abstracta {
public:
    virtual void totalSumaSalariu() = 0;
    virtual void totalPretCarti() = 0;
};




int main() {
    Carte c;
    cout << "Constructor fara parametrii:" << endl;
    cout << c << endl << endl;

    cout << "Apel getteri si setteri:" << endl << endl;
    c.setNumeCarte("Dictionar ");
    c.setNumeAutor("Meta");
    c.setPret(59.99);
    c.setAnAparitie(2000);
    int cuv[4] = { 542,567,447,898 };
    c.setCuvintePerPagina(4, cuv);
    c.setEsteInStoc(1);
    cout << "Nume carte: " << c.getNumeCarte() << endl;
    cout << "Nume autor: " << c.getNumeAutor() << endl;
    cout << "An aparitie: " << c.getAnAparitie() << endl;
    cout << "Pret: " << c.getPret() << endl;
    cout << "Numar pagini: " << c.getNrPagini() << endl;
    cout << "Cuvinte per pagina: ";
    for (int i = 0;i < c.getNrPagini();i++) {
        cout << c.getCuvintePerPagina()[i] << ", ";
    }
    cout << endl;
    cout << "Este in stoc: " << c.getEsteInStoc() << endl;

    cout << endl << endl;

    cout << "Constructor cu toti parametrii:" << endl;
    int cuvinte[] = { 759,242,598 };
    Carte c1("Morometii", "Marin Preda", 1955, 29.99, 3, cuvinte, 1);
    cout << c1 << endl << endl;

    cout << "Media cuvintelor per pagina: " << c1.calculNrCuvinteMediu() << " cuvinte" << endl << endl;
    cout << "Nr minim de cuvinte de pe pagina: " << c1.minimCuvinte() << " cuvinte" << endl << endl;

    //cin>>c1;
   // cout<<c1<<endl;

    cout << "Operatorul de indexare: ";
    cout << c1[0] << endl << endl;

    cout << "Operatorul +: " << endl;
    Carte c2 = c1 + 10;
    cout << c2 << endl << endl;

    cout << "Operatorul ++ post-incrementat: " << endl;
    Carte c3 = c2++;
    cout << c3 << endl;
    cout << c2 << endl << endl;

    cout << "Operatorul ++ pre-incrementat: " << endl;
    Carte c4 = ++c2;
    cout << c4 << endl << endl;

    cout << "Operatorul cast: ";
    string numeAutor = (string)c2;
    cout << numeAutor << endl;

    cout << "Operatorul de negatie: ";
    cout << !c2 << endl;
    if (!c2) {
        cout << "Cartea este in stoc." << endl;
    }
    else {
        cout << "Cartea nu este in stoc." << endl;
    }
    cout << endl;

    cout << "Operatorul cu 2 parametrii: " << endl;
    int cuvinte3[2] = { 9,12 };
    Carte c5(2, cuvinte3);

    cout << c5 << endl << endl;

    cout << "Operatorul < " << endl;
    cout << (c5 < c2) << endl;
    if (c5 < c2) {
        cout << "Cartea 1 are mai putine cuvinte per pagina." << endl;
    }
    else {
        cout << "Cartea 2 are mai putine cuvinte per pagina." << endl;
    }

    cout << endl << endl;

    cout << "Operatorul == " << endl;
    if (c1 == c2) {
        cout << "Sunt identice." << endl;
    }
    else {
        cout << "Nu sunt identice." << endl;

    }
    cout << endl << endl;
    cout << "Fisiere text-- Scrierea in fisiere text (Afisare in fisier text)" << endl << endl;
    ofstream file("carte.txt", ios::out);
    file << c1;
    file.close();



    cout << "Fisiere text--Citirea in fisiere text(Importarea din fisiere text)" << endl;
    ifstream g("carte.txt", ios::in);
    if (g.is_open()) {
        g >> c2;
    }
    else {
        cout << "Fisierul cautat nu exista." << endl;
    }
    cout << c2 << endl << endl;


    cout << "Fisiere Binare--Scrierea in fisiere binare(Serializarea)" << endl;
    c1.serializare("fisBin.bin");
    cout << endl << endl;

    cout << "Fisiere Binare--Citirea din fisiere binare(deserializarea)" << endl;
    Carte cBin;
    cout << cBin << endl << endl;
    cBin.deserializare("fisBin.bin");
    cout << cBin << endl << endl;

    cout << "Fisiere CSV-Scriere in fisier CSV" << endl;
    c.exportCSV("exportCSVcarte.csv");
    cout << endl << endl;

    cout << "Derivare(IS-A): " << endl << endl;

    Roman r;
    cout << r << endl;
    Roman r1("Ion", "Liviu Rebreanu", 1920, 19.99, 3, cuvinte, 1, "realism", 12);
    cout << r1 << endl;

    Roman r2 = r1;
    cout << r2 << endl;
    r2 = r1;
    cout << r2 << endl;

    Carte cUpCasting = r1;
    cout << cUpCasting << endl;

    Roman rDownCasting = c1;
    cout << rDownCasting << endl << endl;


    cout << "---------------------------------------" << endl << endl << endl;


    Angajat a;
    cout << a << endl << endl;

    Angajat a1("Ene", "Bianca Elena", 20, 2200, 4, new float[4]{ 2500,2222,2566,2432 }, 0);
    cout << a1 << endl << endl;

    //cin>>a1;
    //cout<<a1<<endl<<endl;

    cout << "Suma veniturilor lunare ale angajatului: " << a1.calculTotalVenitLunar() << " lei" << endl;
    cout << "Venitul lunar maxim al angajatului: " << a1.maxVenitLunar() << " lei" << endl;

    cout << endl << endl;
    cout << a1[0] << endl;

    cout << endl << endl;
    Angajat a2 = a1 + " Ioana";
    cout << a2 << endl << endl;

    Angajat a3 = a2++;
    cout << a3 << endl << endl;
    cout << a2 << endl;

    Angajat a4 = ++a2;
    cout << a4 << endl << endl;
    cout << a2 << endl << endl;

    int varsta = (int)a1;
    cout << varsta << endl;

    cout << !a2 << endl;
    if (!a2) {
        cout << "Angajatul este pensionar." << endl;
    }
    else {
        cout << "Angajatul nu este pensionar." << endl;
    }

    cout << (a4 < a1) << endl;
    if (a4 < a1) {
        cout << "Angajatul 1" << endl;
    }
    else {
        cout << "Angajatul 2." << endl;
    }

    cout << endl << endl;

    if (a1 == a1) {
        cout << "Sunt identice." << endl;
    }
    else {
        cout << "Nu sunt identice." << endl;
    }

    cout << endl << endl;

    Angajat a5("Badea", "Mihai", 22, 2000, 2, new float[2]{ 3000,2999 }, 0);
    cout << a5 << endl << endl;

    a5.setNume("Ionescu");
    a5.setPrenume("Rares");
    a5.setVarsta(35);
    a5.setSalariu(4000);
    a5.setVenitLunar(4, new float[4]{ 4100,5000,4900,4500 });
    a5.setEstePensionar(0);

    cout << "Nume Angajat: " << a5.getNume() << endl;
    cout << "Prenume Angajat: " << a5.getPrenume() << endl;
    cout << "Varsta angajat: " << a5.getVarsta() << endl;
    cout << "Salariu angajat: " << a5.getSalariu() << endl;
    cout << "Numar luni angajare: " << a5.getNrLuniAngajat() << endl;
    cout << "Venit lunar: ";
    for (int i = 0;i < a5.getNrLuniAngajat();i++) {
        cout << a5.getVenitLunar()[i] << " lei,";
    }
    cout << endl;
    cout << "Este pensionar(1-DA,0-NU): " << a5.getEstePensionar() << endl;

    cout << endl << endl;
    cout << "Fisiere text-- Scrierea in fisiere text (Afisare in fisier text)" << endl << endl;
    ofstream file2("angajat.txt", ios::out);
    file2 << a5;
    file2.close();

    Angajat a6;

    cout << "Fisiere text--Citirea in fisiere text(Importarea din fisiere text)" << endl;
    ifstream g2("angajat.txt", ios::in);
    if (g2.is_open()) {
        g2 >> a6;
    }
    else {
        cout << "Fisierul cautat nu exista." << endl;
    }
    cout << a6 << endl;

    cout << "\nFisiere Binare--Scrierea in fisiere binare(Serializarea)" << endl;
    a6.serializare("fisBin2.bin");
    cout << endl << endl;

    cout << "Fisiere Binare--Citirea din fisiere binare(deserializarea)" << endl;
    Angajat aBin;
    cout << aBin << endl << endl;
    aBin.deserializare("fisBin2.bin");
    cout << aBin << endl << endl;

    cout << "Fisiere CSV-Scriere in fisier CSV" << endl;
    a5.exportCSV("exportCSVangajat.csv");

    cout << endl;

    cout << "Derivare(IS-A):" << endl << endl;
    Vanzator v;
    cout << v << endl << endl;

    Vanzator v1("Costache", "Viorel", 29, 2500, 2, new float[2]{ 1999,3000 }, 0, 3, 1);
    cout << v1 << endl << endl;

    Vanzator v2 = v1;
    cout << v2 << endl << endl;

    v2 = v1;
    cout << v2 << endl << endl;

    Angajat aUpCasting = v1;
    cout << aUpCasting << endl << endl;
    
    Vanzator vDownCasting = a1;
    cout << vDownCasting << endl << endl;


    cout << "---------------------------------------" << endl << endl << endl;
    Comanda com;
    cout << com << endl;

    int date[3] = { 12,12,2020 };
    Carte carti[2] = { c,c2 };
    float rechizite[3] = { 99,100,101 };
    Comanda com1(83894, date, 2, carti, 3, rechizite, 1);
    cout << com1 << endl;

    cout << endl << endl << endl;
    //cin>>com1;
   // cout<<com1<<endl<<endl;

    cout << endl << endl << endl;

    com1.adaugaComanda(c3);
    cout << com1 << endl;
    cout << endl << endl << endl;

    cout << "Pretul total al cartilor din comanda: " << com1.totalPretCarti() << " lei" << endl;

    cout << endl << endl << endl;

    cout << endl << endl;
    cout << com1[0] << endl;

    cout << endl << endl;
    Comanda com2 = com1 + 2;
    cout << com2 << endl << endl;

    cout << endl << endl << endl;

    if (com1 == com2) {
        cout << "Sunt identice." << endl;
    }
    else {
        cout << "Nu sunt identice." << endl;
    }

    cout << endl << endl << endl;

    int nrCarti = (int)com2;
    cout << "Numar de carti din comanda:" << nrCarti << endl;

    cout << !com2 << endl;
    if (!com2) {
        cout << "Este persoana fizica." << endl;
    }
    else {
        cout << "Nu este persoana fizica." << endl;
    }
    cout << endl << endl << endl;
    Comanda com3 = ++com1;
    cout << com3 << endl;

    cout << endl << endl << endl;


    Carte carti2[2] = { c1,c2 };
    com2.setCarti(2, carti2);
    com2.setValoareRechizite(5, new float[5]{ 30,60,80,10,20 });
    cout << com2 << endl;

    cout << "Numar carti: " << com2.getNrCarti() << endl;
    cout << endl;
    cout << "Carti: ";
    for (int i = 0;i < com2.getNrCarti();i++) {
        cout << com2.getCarti()[i] << endl << endl;
    }

    cout << "Nr rechizite: " << com2.getNrRechizite() << endl;
    cout << "Valoare rechizite: " << endl;
    for (int i = 0;i < com2.getNrRechizite();i++) {
        cout << com2.getValoareRechizite()[i] << endl;
    }
    cout << endl << endl;


    cout << endl << endl;
    cout << "Fisiere text-- Scrierea in fisiere text (Afisare in fisier text)" << endl << endl;
    ofstream file3("comanda.txt", ios::out);
    file3 << com1;
    file3.close();


    /*cout << "Fisiere text--Citirea in fisiere text(Importarea din fisiere text)" << endl;
    ifstream g3("comanda.txt", ios::in);
    if (g3.is_open()) {
        g3 >> com3;
    }
    else {
    cout << "Fisierul cautat nu exista." << endl;
     }
    cout << com3 << endl;*/

    cout << "Fisiere Binare--Scrierea in fisiere binare(Serializarea)" << endl;
    com1.serializare("fisBin3.bin");
    cout << endl << endl;

    /*   cout << "Fisiere Binare--Citirea din fisiere binare(deserializarea)" << endl;
       Comanda comBin;
       cout << comBin << endl << endl;
       comBin.deserializare("fisBin3.bin");
       cout << comBin << endl << endl;*/

    cout << "Fisiere CSV-Scriere in fisier CSV" << endl;
    com1.exportCSV("exportCSVcomanda.csv");

    cout << "---------------------------------------" << endl << endl << endl;

    Furnizor f;
    cout << f << endl << endl;

    f.setDenumire("Books");
    f.setAdresaFurnizor("Craiova,str.Dunarii,nr.3");
    f.setValoareProduse(6, new float[6]{ 200,324,654,550,304,390 });
    f.setOferaReducere(0);

    cout << "Nume furnizor: " << f.getDenumire() << endl;
    cout << "Adresa furnizor: " << f.getAdresaFurnizor() << endl;
    cout << "Numar produse: " << f.getNrProduse() << endl;
    cout << "Valoare produse: ";
    for (int i = 0;i < f.getNrProduse();i++) {
        cout << f.getValoareProduse()[i] << " lei,";
    }
    cout << endl;
    cout << "Ofera reducere(1-DA,0-NU): " << f.getOferaReducere();

    cout << endl << endl;


    Furnizor f1("Delta", "Bucuresti,str.Apusului,nr.11", 5, new float[5]{ 10,20,30,40,50 }, 1);
    cout << f1 << endl << endl;


    //cin>>f1;
    //cout<<endl<<endl;

    cout << "Suma totala a produselor de la furnizor: " << f1.calculSumaFurnizor() << " lei" << endl;
    cout << endl;
    f1.adaugaProdus(60.44);
    cout << f1 << endl;

    cout << endl << endl;
    cout << f1[0] << endl;

    cout << endl << endl;
    Furnizor f2 = f1 + " ,sector 3";
    cout << f2 << endl << endl;

    int nrProduse = (int)f2;
    cout << "Numar produse luate de la furnizor: " << nrProduse << endl;

    cout << !f2 << endl;
    if (!f2) {
        cout << "Ofera reducere." << endl;
    }
    else {
        cout << "Nu ofera reducere." << endl;
    }
    cout << endl << endl << endl;
    Furnizor f3 = ++f2;
    cout << f3 << endl;
    cout << endl << endl;

    Furnizor f4("Omega", "Iasi,str.soarelui,nr.9", 8, new float[8]{ 100,200,300,400,500,600,700,800 }, 1);

    cout << (f1 < f4) << endl;
    if (f1 < f4) {
        cout << "Furnizorul 4 are valoarea produselor mai mica." << endl;
    }
    else {
        cout << "Furnizor 1 are valoarea produselor mai mica." << endl;
    }

    cout << endl << endl;

    if (f1 == f4) {
        cout << "Sunt identice." << endl;
    }
    else {
        cout << "Nu sunt identice." << endl;
    }

    cout << endl << endl;
    cout << "Fisiere text-- Scrierea in fisiere text (Afisare in fisier text)" << endl << endl;
    ofstream file4("furnizor.txt", ios::out);
    file4 << f1;
    file4.close();


    cout << "Fisiere text--Citirea in fisiere text(Importarea din fisiere text)" << endl;
    ifstream g4("furnizor.txt", ios::in);
    if (g4.is_open()) {
        g4 >> f2;
    }
    else {
        cout << "Fisierul cautat nu exista." << endl;
    }
    cout << f2 << endl;

    cout << "Fisiere Binare--Scrierea in fisiere binare(Serializarea)" << endl;
    f1.serializare("fisBin4.bin");
    cout << endl << endl;

    cout << "Fisiere Binare--Citirea din fisiere binare(deserializarea)" << endl;
    Furnizor fBin;
    cout << fBin << endl << endl;
    fBin.deserializare("fisBin4.bin");
    cout << fBin << endl << endl;

    cout << "Fisiere CSV-Scriere in fisier CSV" << endl;
    f4.exportCSV("exportCSVfurnizor.csv");



    cout << "---------------------------------------" << endl << endl << endl;

    Librarie l;
    cout << l << endl;

    l.setNumeLibrarie("Libraris");
    l.setAdresaLibrarie("Bucuresti,bulevardul Unirii,nr.8");
    Angajat angajati[2] = { a1,a5 };
    l.setAngajati(2, angajati);
    int raioane[5] = { 90,50,30,10,20 };
    l.setObiectePeRaion(5, raioane);
    l.setAcceptaPlataCard(1);

    cout << "Nume Librarie: " << l.getNumeLibrarie() << endl;
    cout << "Adresa Librarie: " << l.getAdresaLibrarie() << endl;
    cout << "Numar angajati: " << l.getNrAngajati() << endl;
    cout << "Angajati:" << endl;
    cout << "********" << endl;
    for (int i = 0;i < l.getNrAngajati();i++) {
        cout << l.getAngajati()[i] << endl;
    }
    cout << endl;
    cout << "Numar raioane: " << l.getNrRaioane() << endl;
    cout << "Obiecte pe raion: ";
    for (int i = 0;i < l.getNrRaioane();i++) {
        cout << l.getObiectePeRaion()[i] << " ,";
    }
    cout << endl;
    cout << "Accepta plata card(1-DA,0-NU): " << l.getAcceptaPlataCard() << endl;

    cout << endl << endl;



    Angajat angajati2[2] = { a1,a5 };
    int raioane2[4] = { 60,100,90,44 };
    Librarie l1("Carturesti", "Timisoara,str.Bicaz,nr.5", 2, angajati2, 4, raioane2, 70.5, 1);
    cout << l1 << endl;

    cout << endl << endl;
    l1.adaugaAngajat(a2);
    cout << l1 << endl << endl;

    cout << "Suma salariilor tuturor angajatilor din librarie : " << l1.totalSumaSalariu() << " lei" << endl;

    cout << endl << endl;
    cout << l1[0] << endl;

    cout << endl << endl;
    Librarie l2 = l1 + " ,in interior mall";
    cout << l2 << endl << endl;

    int nrAngajati = (int)l2;
    cout << "Numar angajati din librarie:" << nrAngajati << endl;

    cout << !l2 << endl;
    if (!l2) {
        cout << "Accepta plata cu cardul." << endl;
    }
    else {
        cout << "Nu accepta plata cu cardul." << endl;
    }
    cout << endl << endl << endl;
    Librarie l3 = ++l2;
    cout << l3 << endl;
    cout << endl << endl;

    Angajat angajati3[1] = { a1 };
    int raioane3[3] = { 99,100,80 };
    Librarie l4("Libraris", "Brasov,str.scolii,nr.10", 1, angajati3, 3, raioane3, 59, 0);

    cout << (l1 < l4) << endl;
    if (l1 < l4) {
        cout << "Libraria 1 are mai putine obiecte pe raion." << endl;
    }
    else {
        cout << "Libraria 4 are mai putine obiecte pe raion." << endl;
    }

    cout << endl << endl;

    if (l1 == l4) {
        cout << "Sunt identice." << endl;
    }
    else {
        cout << "Nu sunt identice." << endl;
    }
    cout << endl << endl;


    // cin >> l2;
  //   cout << endl << endl;
   //  cout << l2 << endl << endl;

    cout << endl << endl;
    cout << "Fisiere text-- Scrierea in fisiere text (Afisare in fisier text)" << endl << endl;
    ofstream file5("librarie.txt", ios::out);
    file5 << l1;
    file5.close();


    cout << "Fisiere text--Citirea in fisiere text(Importarea din fisiere text)" << endl;
    ifstream g5("librarie.txt", ios::in);
    if (g5.is_open()) {
        g5 >> l4;
    }
    else {
        cout << "Fisierul cautat nu exista." << endl;
    }
    cout << l4 << endl;



    cout << "Fisiere Binare--Scrierea in fisiere binare(Serializarea)" << endl;
    l1.serializare("fisBin5.bin");
    cout << endl << endl;

    cout << "Fisiere Binare--Citirea din fisiere binare(deserializarea)" << endl;
    Librarie lBin;
    cout << lBin << endl << endl;
    lBin.deserializare("fisBin5.bin");
    cout << lBin << endl << endl;

    cout << "Fisiere CSV" << endl;

    cout << "Fisiere CSV-Scriere in fisier CSV" << endl;
    l1.exportCSV("exportCSVlibrarie.csv");

    cout << endl << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

    cout << "VECTOR(container secvential) STL" << endl << endl;

    Angajat a7("Popescu", "Elena", 29, 3000, 3, new float[3]{ 3000,2999,2500 }, 0);
    Angajat a8("Cristea", "Alina", 39, 3420, 2, new float[3]{ 3120,3100 }, 0);
    Angajat a9("Gheorghe", "Liviu", 51, 4000, 4, new float[4]{ 3700,2999,3400,3800 }, 1);

    vector<Angajat>vectorAngajat;

  
    vectorAngajat.push_back(a4);
    vectorAngajat.push_back(a5);
    vectorAngajat.push_back(a6);
    vectorAngajat.push_back(a7);
    vectorAngajat.push_back(a8);
    vectorAngajat.push_back(a9);

    cout << "Numarul angajatilor este: "<< vectorAngajat.size() << endl;
    cout << endl;
    
    cout << "Angajatii sunt: " << endl << endl;
    for (int i = 0;i < vectorAngajat.size();i++) {
        cout << vectorAngajat[i] << endl;
    }
    
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

    cout << "SET(container asociativ) - ordonare dupa varsta: " << endl << endl;

    set<Angajat>setAngajat;

    setAngajat.insert(a4);
    setAngajat.insert(a5);
    setAngajat.insert(a6);
    setAngajat.insert(a7);
    setAngajat.insert(a8);
    setAngajat.insert(a9);

    set<Angajat>::iterator sIt;
    for (sIt = setAngajat.begin();sIt != setAngajat.end();sIt++) {
        cout << *sIt << endl;
    }

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl << endl;

    cout << "MAP(container asociativ)--sortare dupa cheie" << endl << endl;

    map<int, Angajat>mapAngajat;

    mapAngajat.insert(pair<int, Angajat>(2, a4));
    mapAngajat.insert(pair<int, Angajat>(7, a5));
    mapAngajat.insert(pair<int, Angajat>(3, a6));
    mapAngajat.insert(pair<int, Angajat>(1, a7));
    mapAngajat.insert(pair<int, Angajat>(4, a8));
    mapAngajat.insert(pair<int, Angajat>(8, a9));

    map<int, Angajat>::iterator mIt;
    for (mIt = mapAngajat.begin();mIt != mapAngajat.end();mIt++) {
        cout << mIt->first << endl;
        cout << mIt->second << endl;
        cout << endl << endl;
    }


    return 0;

}


