#include <iostream>
#include <string.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

int panjangInputan, status;
int i = 0;
int j = 0;
int pilih;
char a[100];
char b[100];

// numb = 1 | opr = 2 | kurb = 3 | kurt = 4
void lexical(char* a){
    panjangInputan = strlen(a);
    while(i < panjangInputan){
        if(a[i] == '+' || a[i] == '-'){
            if(a[i+1] == ' '  || a[i+1] == '\0'){
                cout << a[i] << " : operator"  << endl;
                b[j] = '2';
                j++;
            }else if(isdigit(a[i+1])){
                cout << a[i];
                i++;
                while(true){
                    if (isdigit(a[i]) || a[i] == 'E' || a[i] == ',' || a[i] == '+' || a[i] == '-'){
                        cout << a[i];
                    }else{
                        cout << a[i];
                        status = 0;
                        break;
                    }
                    if(a[i+1] == ' '  || a[i+1] == '\0'){
                        if(a[i] == 'E' || a[i] == ',' || a[i] == '+' || a[i] == '-'){
                            status = 0;
                        }
                        if (isdigit(a[i])){
                            status = 1;
                        }

                        break;
                    }
                    i++;
                }

                if(status == 1){
                    cout << " : number" << endl;
                    b[j] = '1';
                    j++;
                }else{
                    b[j] = '5';
                    j++;
                    cout << " : error" << endl;
                }
            }else{
                b[j] = '5';
                j++;
                cout << a[i] << a[i+1] << " : error" << endl;
                break;
            }
        }else if (isdigit(a[i])){
            if(a[i+1] == ' '  || a[i+1] == '\0'){
                cout << a[i] << " : Number"  << endl;
                b[j] = '1';
                j++;
            }else{
                cout << a[i];
                i++;
                while(true){
                    if (isdigit(a[i]) || a[i] == 'E' || a[i] == ',' || a[i] == '+' || a[i] == '-'){
                        cout << a[i];
                    }else{
                        cout << a[i];
                        status = 0;
                        break;
                    }
                    if(a[i+1] == ' '  || a[i+1] == '\0'){
                        if(a[i] == 'E' || a[i] == ',' || a[i] == '+' || a[i] == '-'){
                            status = 0;
                        }
                        if (isdigit(a[i])){
                            status = 1;
                        }

                        break;
                    }
                    i++;
                }

                if(status == 1){
                    cout << " : number" << endl;
                    b[j] = '1';
                    j++;
                }else{
                    b[j] = '5';
                    j++;
                    cout << " : error" << endl;
                }
            }
        }else if(a[i] == '*' || a[i] == '/'){
            if(a[i+1] = ' ' || a[i+1] == '\0'){
                cout << a[i] << " : Operator" << endl;
                b[j] = '2';
                j++;
                i++;
            }else{
                cout << a[i] << " : error" << endl;
                b[j] = '5';
                j++;
                break;
            }
        }else if(a[i] == '('){
            if(a[i+1] == ' '  || a[i+1] == '\0'){
                cout << a[i] << " : Kurung Buka" << endl;
                b[j] = '3';
                j++;
            }else{
                cout << a[i] << " : error" << endl;
                b[j] = '5';
                j++;
                break;
            }
        }else if(a[i] == ')'){
            if(a[i+1] == ' '  || a[i+1] == '\0'){
                cout << a[i] << " : Kurung Tutup" << endl;
                b[j] = '4';
                j++;
            }else{
                cout << a[i] << " : error" << endl;
                b[j] = '5';
                j++;
                break;
            }
        }else if(isalpha(a[i])){
            cout << a[i] << " : error" << endl;
            b[j] = '5';
            j++;
            break;
        }else if(a[i] == ' ' || a[i] == '\0'){

        }else{
            cout << a[i] << " : error" << endl;
            b[j] = '5';
            j++;
            break;
        }
        i++;
    }
}
int main()
{


    cout << "==================================" << endl;
    cout << "========== Simple Parser =========" << endl;
    cout << "----------------------------------" << endl;
    cout << "Masukan Inputan: ";
    cin.getline(a, 100);

    cout << endl << endl;
    cout << "==================================" << endl;
    cout << "-------- Lexical Analizer --------" << endl;
    lexical(a);
    cout << "----------------------------------" << endl;
    cout << "==================================" << endl;

    cout << endl << endl;
    cout << "==================================" << endl;
    cout << "------------- Parser -------------" << endl;
    i = 0;
    // numb = 1 | opr = 2 | kurb = 3 | kurt = 4
    while(i < j){
        if(b[i] == '1' || b[i] == '2' || b[i] == '3' || b[i] == '4'){
            status = 1;
            if(b[i] == b[i+1]){
                status = 0;
                break;
            }else if(b[0] == '2' || b[0] == '4'){
                status = 0;
                break;
            }else if(b[j-1] == '2' || b[j-1] == '3'){
                status = 0;
                break;
            }else if(b[i] == '3' && b[i+1] == '2'){
                status = 0;
                break;
            }else if(b[i] == '2' && b[i+1] == '4'){
                status = 0;
                break;
            }else{
                status = 1;
            }
        }else{
            status = 0;
            break;
        }
        i++;
    }
    if (status == 0){
        cout << "       \t Tidak Valid" << endl;
    }else if(status == 1){
        cout << "       \t   == Valid ==" << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "==================================" << endl;
    getch();
    return 0;
}
