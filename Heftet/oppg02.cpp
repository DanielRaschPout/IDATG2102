/**
 * @file oppg02.cpp
 * @author Daniel Fernando Petter Rasch-Pout (dfraschp@gmail.com)
 * @brief Selvlaget implementasjon av container-klassen map.
 * @date 05-09-2023
 * 
 * 
 */

#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Map{

    private:
        T1* keyer;
        T2* data;
        int kapasitet, antall;
    
    public:
    // Initierer medlemmer vha. default parameter:
    Map(const int lengde = 200) {
        keyer = new T1[lengde];
        data = new T2[lengde];
        kapasitet = lengde;
        antall =0;
    }

    // Frigir allokert minne (vha. new)
    ~Map()   { delete[] keyer; delete[] data; }

    // Antallet i map'en
    int size() const {return antall;}

    // Skriver HELE map'ens innhold
    void display() {
        for (int i = 0; i < antall; i++) 
            cout << keyer[i] << " : "<< data[i] << endl;
        
        cout << "Antall keyer med data i map: " << antall << endl;
    }

    // Setter inn et nytt par med key og data
    void insert(const T1 key, const T2 da) {
        int nyIndeks = 0;
        if (!find(key)) {
            if (antall < kapasitet) {

                // Leter etter hvor den skal putte inn ny key & data
                while (nyIndeks < antall  &&  keyer[nyIndeks] < key)
                    nyIndeks++;
                antall++;

                // Flytter alle ETTER OPP ett hakk
                for (int i = antall-1; i > nyIndeks; i--) {
                    keyer[i] = keyer[i-1];
                    data[i] = data[i-1];
                }

                // Legger inn det nye paret av key og dets data
                keyer[nyIndeks] = key;
                data[nyIndeks] = da;
            }

            else 
                cout << "Map is already full" << endl;
        }
        else 
            cout << "Keyen already exists" << endl;
        
    }

    // Sjekker om keyen finnes i map'en
    bool find(const T1 key) {

        // Går gjennom HELE map'en
        for (int i = 0; i < antall; i++) 
            if (keyer[i] == key) return true;
        return false;
        
    }

    // Hvis keymatch funnet, returnerer data til key
    T2 get(const T1 key) const {
        
        for (int i = 0; i < antall; i++)
            if (keyer[i] == key) return data[i];

        return T2();
    }

    void change(const T1 key, const T2 da) {
        
        int i;

        // Hvis key'en eksisterer
        if(find(key)) {
            for (i = 0; i < antall; i++) 
                if (keyer[i] == key) break; // breaker ut når key'en er funnet
                data[i] = da;   // Endrer dataen tilknyttet key'en
            
            cout << "Key's data has been changed" << endl;
        }
        else
            // Feilmelding hvis keyen ikke finnes
            cout << "Key not found" << endl;
        
    }

    void erase(const T1 key) {
        int i;
        if(find(key)) {
            
            // Finner key'ens index
            for (i = 0; i < antall; i++) 
                if (keyer[i] == key) break;
            
            // Fjerner 1 fra antall
            antall--;

            // Flytter alle over det fjernede key data pairet et hakk ned
            for (int j = i; j < antall; j++) {
                keyer[j] = keyer[j+1];
                data[j] = data[j+1];
            }
            cout << "Key deleted" << endl;
            
        }
        else
            // Feilmelding hvis key'en ikke ble funnet
            cout << "Key not found" << endl;
    }

};

int main() {

    return 0;
}