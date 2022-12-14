#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main();


struct varaaja {

    string nimi;
    string kotiosoite;
    string postinumero;
    string kaupunki;



};


void tarkastelevarauksia(int varausnumero, int huone_numero, varaaja s)
{

    int uusivarausnumero;
    int x{};
    void huoneenvaraus(varaaja & s, int& varausnumero, int& huone_numero);

    cout << "Syöttäkää varausnumeronne! " << '\n';
    cin >> uusivarausnumero;

    if (uusivarausnumero == varausnumero) {
        cout << "Varauksenne löytyi varausnumerolla " << varausnumero << '\n';
        cout << s.nimi << '\n';
        cout << s.kotiosoite << '\n';
        cout << s.postinumero << '\n';
        cout << s.kaupunki << '\n';
        cout << "Huoneenne numero on " << huone_numero << "." << '\n';
        cout << "1. Varaa uusi huone." << '\n';
        cout << "2. Tarkastele varauksia." << '\n';
        cout << "3. Poistu hotellista." << '\n';
        cin >> x;
        system("cls");

        switch (x)
        {
        case 2:
            tarkastelevarauksia(varausnumero, huone_numero, s);

        case 3:
            exit(0);

        case 1:
            huoneenvaraus(s, varausnumero, huone_numero);



        }



    }
    else {
        cout << "Tällä varausnumerolla ei löytynyt varausta. " << '\n';
        cout << "1. Varaa uusi huone." << '\n';
        cout << "2. Tarkastele varauksia." << '\n';
        cout << "3. Poistu hotellista." << '\n';
        cin >> x;
        system("cls");

        switch (x)
        {
        case 2:
            tarkastelevarauksia(varausnumero, huone_numero, s);

        case 3:
            exit(0);

        case 1:
            huoneenvaraus(s, varausnumero, huone_numero);



        }
    }

}




void huoneenvaraus(varaaja& s, int& varausnumero, int& huone_numero) {
    std::random_device rd;
    std::uniform_int_distribution<int> dist(30, 70);
    string varaajannimi;
    double öidenmäärä;
    srand(time(0));
    int huoneet = 30 + rand() % 41;
    int hinnat = 80 + rand() % 21;
    int number;
    int lower = 80, upper = 100;
    int pienempi = 10000, isompi = 99999;
    int x;

    varausnumero = (rand() % (isompi - pienempi + 1)) + pienempi;
    huone_numero = 1 + rand() % huoneet;
    srand(time(NULL));

    number = (rand() % (upper - lower + 1)) + lower;


    cout << "Syötä varaajan nimi." << '\n';
    cin >> ws;
    getline(cin, s.nimi);
    cout << "Syötä kotiosoitteesi." << '\n';
    cin >> ws;
    getline(cin, s.kotiosoite);
    cout << "Syötä postinumerosi." << '\n';
    cin >> ws;
    getline(cin, s.postinumero);
    cout << "Syötä kotikaupunkisi." << '\n';
    cin >> ws;
    getline(cin, s.kaupunki);
    cout << "Hotellissamme on " << huoneet << " huonetta vapaana." << '\n'; // Kertoo kuinka monta huonetta on vapaana
    cout << "Varaan sinulle huoneen numero " << huone_numero << "." << endl; // Kertoo missä huoneessa yövyt

    cout << "Hei " << s.nimi << "! Teidän varausnumeronne on " << varausnumero << " ja yövytte huoneessa numero " << huone_numero << "." << '\n';
    cout << "Kuinka monta yötä yövytte hotellissa? Hinta on yhdeltä yöltä " << hinnat << " euroa." << '\n';
    cin >> öidenmäärä;
    cout << "Laskunne " << öidenmäärä << " yöltä on " << öidenmäärä * hinnat << " euroa." << '\n';
    cout << "1. Varaa uusi huone." << '\n';
    cout << "2. Tarkastele varauksiasi." << '\n';
    cout << "3. Poistu hotellista." << '\n';
    cin >> x;


    switch (x)
    {
    case 1:
        huoneenvaraus(s, varausnumero, huone_numero);
    case 2:
        tarkastelevarauksia(varausnumero, huone_numero, s);
    case 3:
        exit(0);

    }




}

int main()

{
    setlocale(LC_ALL, "fi_FI");
    int varausnumero{};
    varaaja s;
    double öidenmäärä;
    double hinta;
    int number;
    int lower = 80, upper = 100;
    int x;
    int huone_numero{};


    srand(time(NULL));

    number = (rand() % (upper - lower + 1)) + lower;


    cout << "Tervetuloa Miikan hotelliin!" << '\n'; // Tervetuloviesti
    cout << "1. Varaa huone." << '\n';
    cout << "2. Tarkastele varauksiasi." << '\n';
    cout << "3. Poistu hotellista." << '\n';
    cin >> x;

    switch (x)
    {
    case 1:
        huoneenvaraus(s, varausnumero, huone_numero);
    case 2:
        tarkastelevarauksia(varausnumero, huone_numero, s);
    case 3:
        exit(0);

    }













    return 0;
}