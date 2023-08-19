/// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dl double
#define st string
#define ch char
#define cn(n) cin >> n
#define cll(n)   \
    long long n; \
    cin >> n
#define cdl(n) \
    double n;  \
    cin >> n
#define cch(c) \
    char c;    \
    cin >> c
#define cst(s) \
    string s;  \
    cin >> s
#define ct(n) cout << n
#define w(n) while (n > 0)
#define elif else if
#define wh(n)    \
    long long n; \
    cin >> n;    \
    while (n--)
#define a(m, n)                 \
    long long a[n];             \
    for (int i = m; i < n; i++) \
    cin >> a[i]
#define b(m, n)                  \
    long long b[n];              \
    for (int i = m; i <= n; i++) \
    b[i] = 0
#define f(m, i, n) for (int i = m; i < n; i++)
#define fr(m, i, n) for (int i = m - 1; i >= n; i--)
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define bye cout << endl

st number_system;
ll base;
bool Valid = true;

bool valid(st main_number)
{
    ch first_symbol = '0', last_symbol;
    if (number_system == "bin")
        last_symbol = '1';
    elif (number_system == "oct") last_symbol = '7';
    elif (number_system == "dec") last_symbol = '9';
    if (number_system == "bin" || number_system == "oct" || number_system == "dec")
    {
        f(0, i, main_number.size())
        {
            if (main_number[i] == '.')
                ;
            elif (main_number[i] < first_symbol || main_number[i] > last_symbol)
            {
                return false;
                break;
            }
        }
    }
    elif (number_system == "hex")
    {
        f(0, i, main_number.size())
        {
            if ((main_number[i] >= '0' && main_number[i] <= '9') || (main_number[i] >= 'A' && main_number[i] <= 'F') || main_number[i] == '.')
                ;
            else
            {
                return false;
                break;
            }
        }
    }
    return true;
}

dl to_decimal(st main_number)
{
    if (number_system == "bin")
        base = 2;
    elif (number_system == "oct") base = 8;
    elif (number_system == "dec") base = 10;
    elif (number_system == "hex") base = 16;
    bool flag = true;
    ll k = 0, point = 0, converted_int, converted_flt, extra;
    dl converted_number = 0;
    f(0, i, main_number.size())
    {
        if (main_number[i] == '.')
        {
            point = i;
            flag = false;
            break;
        }
    }
    if (flag)
        point = main_number.size();
    f(0, i, point)
    {
        if (main_number[i] >= '0' && main_number[i] <= '9')
            converted_int = main_number[i] - '0';
        else
        {
            extra = (ll)main_number[i] - 64;
            converted_int = 9 + extra;
        }
        converted_number += converted_int * pow(base, point - i - 1);
    }
    f(point + 1, i, main_number.size())
    {
        k--;
        if (main_number[i] >= '0' && main_number[i] <= '9')
            converted_flt = main_number[i] - '0';
        else
        {
            extra = (ll)main_number[i] - 64;
            converted_flt = 9 + extra;
        }
        converted_number += converted_flt * pow(base, k);
    }
    return converted_number;
}

int from_decimal(st main_number)
{
    if (number_system == "bin")
        base = 2;
    elif (number_system == "oct") base = 8;
    elif (number_system == "dec") base = 10;
    elif (number_system == "hex") base = 16;
    stringstream temp(main_number);
    dl number = 0;
    temp >> number;
    ll rem, remm, extra, extraa, ascii, asciii;
    ll int_part = (ll)number;
    dl flt_part = number - int_part;
    ch converted_number[500], k = 0;
    if (int_part == 0)
        ct(0);
    else
    {
        w(int_part)
        {
            rem = int_part % base;
            int_part /= base;
            if (rem > 9)
            {
                extra = rem - 9;
                ascii = 64 + extra;
            }
            else
                ascii = 48 + rem;
            converted_number[k++] = ch(ascii);
        }
        fr(k, i, 0) ct(converted_number[i]);
    }
    ct(".");
    f(0, i, 8)
    {
        flt_part *= base;
        remm = (ll)flt_part;
        if (remm > 9)
        {
            extraa = remm - 9;
            asciii = 64 + extraa;
        }
        else
            asciii = 48 + remm;
        ct(ch(asciii));
        flt_part -= (ll)flt_part;
    }
}

int main()
{
    ct("This program performs arithmetic operations on number systems. The functions of this program are: ");
    bye;
    ct("\t- addition of several binary numbers" << endl
                                                << "\t- addition of several octal numbers" << endl);
    ct("\t- addition of several decimal numbers" << endl
                                                 << "\t- addition of several hexa-decimal numbers" << endl);
    ct("\t- subtraction of two binary numbers" << endl
                                               << "\t- subtraction of two octal numbers" << endl);
    ct("\t- subtraction of two decimal numbers" << endl
                                                << "\t- subtraction of two hexa-decimal numbers" << endl);
    ct("\t- multiplication of several binary numbers" << endl
                                                      << "\t- multiplication of several octal numbers" << endl);
    ct("\t- multiplication of several decimal numbers" << endl
                                                       << "\t- multiplication of several hexa-decimal numbers" << endl);
    ct("\t- division of two binary numbers" << endl
                                            << "\t- division of two octal numbers" << endl);
    ct("\t- division of two decimal numbers" << endl
                                             << "\t- division of two hexa-decimal numbers");
    bye;
    ct("(Both integer and float numbers are acceptable.)");
    bye, bye;
    ct("#Use" << endl);
    ct("'add' for addition," << endl);
    ct("'sub' for subtraction," << endl);
    ct("'mul' for multiplication," << endl);
    ct("'div' for division," << endl);
    ct("'bin' for binary," << endl);
    ct("'oct' for octal," << endl);
    ct("'dec' for decimal," << endl);
    ct("'hex' for hexa-decimal.");
    bye, bye;
    ll t = 0;
    while (1)
    {
        t++;
        Valid = true;
        ct("Case-" << t);
        bye;
        ct("Number system: ");
        cn(number_system);
        if (number_system == "bin" || number_system == "oct" || number_system == "dec" || number_system == "hex")
        {
            ct("Arithmetic operation: ");
            cst(operation);
            if (operation == "add" || operation == "sub" || operation == "mul" || operation == "div")
            {
                if (operation == "add" || operation == "mul")
                {
                    ct("Number of inputs: ");
                    cll(time);
                    st temp, answer;
                    dl sum = 0, mul = 1;
                    f(1, i, time + 1)
                    {
                        ct("number " << i << ": ");
                        cst(temp);
                        if (valid(temp))
                        {
                            if (operation == "add")
                                sum += to_decimal(temp);
                            else
                                mul *= to_decimal(temp);
                        }
                        else
                        {
                            Valid = false;
                            break;
                        }
                    }
                    if (Valid)
                    {
                        if (operation == "add")
                            answer = to_string(sum);
                        else
                            answer = to_string(mul);
                        ct("Ans: ");
                        from_decimal(answer);
                    }
                }
                else
                {
                    dl ans;
                    ct("number 1: ");
                    cst(number1);
                    if (valid(number1))
                    {
                        ct("number 2: ");
                        cst(number2);
                        if (valid(number2))
                        {
                            if (operation == "sub")
                            {
                                ans = to_decimal(number1) - to_decimal(number2);
                            }
                            if (operation == "div")
                            {
                                dl div = 0;
                                stringstream temporary(number2);
                                temporary >> div;
                                if (div == 0)
                                    Valid = false;
                                if (Valid)
                                    ans = to_decimal(number1) / to_decimal(number2);
                            }
                            if (Valid)
                            {
                                st answer = to_string(ans);
                                ct("Ans: ");
                                from_decimal(answer);
                            }
                        }
                    }
                }
            }
            else
                Valid = false;
        }
        else
            Valid = false;
        if (!Valid)
            ct("Invalid.");
        bye, bye;
    }
}
