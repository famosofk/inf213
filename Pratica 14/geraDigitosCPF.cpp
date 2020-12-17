#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]){
    int number;
    cin >> number;


    for(int i = 0; i < number; i++){
        string cpf;
        cin >> cpf;
        string::iterator it = cpf.begin();
        int values[2] = {0,0};
        for(int i = 0;it != cpf.end();it++, i++){
            values[0] += ((int)*it - 48) * (11 - i);
            values[1] += ((int)*it - 48) * (10 - i);
        }
        int firstDigit = (10 * values[1]) % 11;
        firstDigit == 10 ? cout << 0 : cout << firstDigit;

        values[0] += firstDigit == 10 ? 0 : firstDigit*2;
        (values[0] * 10) % 11 == 10 ? cout << 0 : cout << (values[0] * 10) % 11;
        cout << endl;
    }
    return 0;
}
