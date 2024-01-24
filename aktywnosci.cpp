#include <iostream>
#include <vector>

using namespace std;

// Klasa reprezentująca użytkownika
class Uzytkownik {
public:
    string nazwaUzytkownika;
    // inne dane użytkownika

    // metody związane z użytkownikiem
};

// Klasa reprezentująca wizytę
class Wizyta {
public:
    string data;
    string godzina;
    // inne dane wizyty

    // metody związane z wizytą
};

// Klasa reprezentująca lekarza
class Lekarz {
public:
    string imieINazwisko;
    vector<Wizyta> wizyty;
    // inne dane lekarza

    // metody związane z lekarzem
};

// Funkcja sprawdzająca dostępność lekarza
bool czyLekarzDostepny(Lekarz& lekarz, string data, string godzina) {
    // Implementacja sprawdzania dostępności lekarza
    // Może wymagać dostępu do bazy danych lub innego źródła danych
    // W tym przykładzie założono, że lekarz może mieć tylko jedną wizytę w danym czasie
    for (const auto& wizyta : lekarz.wizyty) {
        if (wizyta.data == data && wizyta.godzina == godzina) {
            return false; // Lekarz jest zajęty w tym czasie
        }
    }
    return true; // Lekarz jest dostępny w tym czasie
}

// Funkcja do edycji wizyty
void edytujWizyte(Uzytkownik& uzytkownik, Wizyta& wizyta, Lekarz& lekarz, string nowaData, string nowaGodzina) {
    // Sprawdzamy dostępność lekarza dla nowej daty i godziny
    if (czyLekarzDostepny(lekarz, nowaData, nowaGodzina)) {
        // Nadpisujemy dane wizyty
        wizyta.data = nowaData;
        wizyta.godzina = nowaGodzina;
        // Informujemy lekarza
        cout << "Zmiany zostały nadpisane. Lekarz został powiadomiony.\n";
    }
    else {
        cout << "Lekarz jest zajęty w tym terminie. Proszę wybrać inny termin.\n";
    }
}

int main() {
    // Przykładowe użycie

    // Tworzymy przykładowego użytkownika, lekarza i wizytę
    Uzytkownik uzytkownik;
    uzytkownik.nazwaUzytkownika = "przykladowy_uzytkownik";

    Lekarz lekarz;
    lekarz.imieINazwisko = "Dr. Kowalski";

    Wizyta wizyta;
    wizyta.data = "2023-12-01";
    wizyta.godzina = "10:00";

    // Użytkownik zalogowany, przeniesiony do panelu wizyt
    // Otrzymuje opcję edycji wizyty
    string nowaData = "2023-12-02";
    string nowaGodzina = "14:30";

    // Edycja wizyty
    edytujWizyte(uzytkownik, wizyta, lekarz, nowaData, nowaGodzina);

    return 0;
}
