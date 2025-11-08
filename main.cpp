#include<bits/stdc++.h>
using namespace std;
int mat;
void pause() {
    cout << "Press any key to continue...";
    getch();
}
void getascll() {
    cout << "(Only can see characters)\n";
    cout << "32 ~ (space)\n";
    for(int i = 33;i <= 126;i++) {
        cout << i << " - " << char(i) << '\n';
    }
    pause();
    return;
}
void calculator();
void randomNumber();
void ascll();
void devmode();
void mathtool();
void choose() {
    system("cls");
    cout << "Welcome to Siprca Tool Box!\n";
    cout << "Please choose one:\n";
    cout << "1.Calculator\n";
    cout << "2.Random number generation\n";
    cout << "3.ASCLL tabular\n";
    cout << "4.Get tips\n";
    cout << "5.Dev mode contrl\n";
    cout << "6.Exit\n";
    cout << "Please input function corresponding number:\n";
    char chs;
    chs = getch();
    switch(chs) {
        case '1':
            system("cls");
            calculator();
            break;
        case '2':
            system("cls");
            randomNumber();
            break;
        case '3':
            system("cls");
            ascll();
            break;
        case '4':
            system("cls");
            cout << "You can go to https://github.com/Mogm-Dev/Siprca-Tool-Box/wiki to have help.\n";
            pause();
            choose();
            break;
        case '5':
            system("cls");
            devmode();
            break;
        case '6':
            cout << "Exiting...\n";
            exit(0);
            break;
        default:
            cout << "Invalid input. Please try again.\n";
            choose();
            break;
    }
}
int main() {
    choose();
    return 0;
}
void calculator() {
    if(mat) {
        cout << "Press d to go to math tool app.\n";
        char ope;
        ope = getch();
        if(ope == 'd') {
            mathtool();
        }
    }
    long long a,b;
    char ch;
    scanf("%lld %c %lld",&a,&ch,&b);
    if(ch == '+') {
        system("cls");
        long long int ans;
        ans = a + b;
        printf("%lld %c %lld = %lld\n",a,ch,b,ans);
        pause();
    } else if(ch == '-') {
        system("cls");
        long long int ans;
        ans = a - b;
        printf("%lld %c %lld = %lld\n",a,ch,b,ans);
        pause();
    } else if(ch == '*') {
        system("cls");
        long long int ans;
        ans = a * b;
        printf("%lld %c %lld = %lld\n",a,ch,b,ans);
        pause();
    } else if(ch == '/') {
        system("cls");
        long long int ans;
        ans = a / b;
        long long int y = a - b * ans;
        printf("%lld %c %lld = %lld ...... %lld\n",a,ch,b,ans,y);
        pause();
    } else if(ch == '^') {
        system("cls");
        long long int ans;
        ans = pow(a,b);
        printf("%lld %c %lld = %lld\n",a,ch,b,ans);
        pause();
    } else if(ch == '#') {
        system("cls");
        printf("%lld %c = %lf\n",a,ch,sqrt(a));
        pause();
    }
    choose();
}

void randomNumber() {
    int mx;
    int mi;
    int rd;
    struct timeb timeSeed;
    
    cout << "Please choose maximum number...\n";
    cin >> mx;
    cout << "\nPlease choose minimum number...\n";
    cin >> mi;
    system("cls");
    
    //Get random number.
    ftime(&timeSeed);
    srand(time(NULL) + timeSeed.millitm);
    rd = (rand() % (mx - mi + 1)) + mi;

    cout << "Random number is: " << rd << ".\n";
    pause();
    choose();
}

void ascll() {
    cout << "Please select:\n";
    cout << "1. See all characters.\n";
    cout << "2. See selected characters.\n";
    cout << "3. See random characters.\n";
    cout << "4. Exit.\n";
    cout << "Please input function corresponding number:\n";
    char chs;
    chs = getch();
    system("cls");
    if(chs == '1') {
        getascll();
        system("cls");
    } else if(chs == '2') {
        cout << "Plese select a ASCLL number(33~126) to see a characters.\n";
        int asc;
        cin >> asc;
        system("cls");
        cout << "Number:" << asc << "\n";
        cout << "Character: " << char(asc) << "\n";
        pause();
        system("cls");
    } else if(chs == '3') {
        struct timeb timeSeed;
        ftime(&timeSeed);
        srand(time(NULL) + timeSeed.millitm);
        int rd = (rand() % (126 - 33 + 1)) + 33;
        cout << "Number:" << rd << "\n";
        cout << "Character: " << char(rd) << "\n";
        pause();
        system("cls");
    } else if(chs == '4') {
        system("cls");
        choose();
    }
    choose();
}

void mathtool() {
    system("cls");
    cout << "Please choose math tool:\n";
    cout << "1.Factorization of prime numbers.\n";
    int ope;
    ope = getch();
    if(ope == '1') {
        system("cls");
        queue<int> prime;
        cout << "Please input ope. number:";
        int num,cnt = 0;
        cin >> num;
        cout << num << " =";
        system("cls");
        while(num > 1) {
            for(int i = 2;i * i <= num;i++) {
                while(num % i == 0) {
                    num /= i;
                    prime.push(i);
                    cnt++;
                }
            }
        }
        for(int i = 1;i <= cnt;i++) {
            int pri;
            pri = prime.front();
            prime.pop();
            if(i == cnt) {
                cout << ' ' << pri;
            } else {
                cout << ' ' << pri << " *";
            }
        }
    }
}
void devmode() {
    cout << "Please input dev code(Remember! If you open the dev mode, you will use the uncreated thing in Siprca.):";
    string code;
    cin >> code;
    if(code == "MAT") {
        mat = true;
    }
    choose();
}