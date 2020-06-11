#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <random>
#include <time.h>
#include <bitset>

#define BLOCKSIZE 16

using namespace std;



namespace manufacture
{
    
    void print_m()
    {
        cout<<"this is from namespace print_m"<<endl;
    }

     namespace v2
    {
        int getmyint(int x)
        {
            return x;
        }
    }
}

unsigned long long fibo(int mm)
{
    if (mm<2)
        return 1;
    else
        return mm * fibo(mm-1);
}
void binary_ss();
void mycast (void *te)
{
    int *mydoubl = static_cast<int*>(te);
    (*mydoubl)++;
    cout<<*mydoubl<<endl;
}

enum    car{toyota, huyndai, nissan='n'};
int main(int argc, char * argv[])
{
    if (argc!=2)
        return -1;
    ifstream file(argv[1], ios::binary);
    unsigned char c;
    string temp;
    int block =0;
    while (!file.eof())
    {
        temp="";

        cout<<setw(6) <<setfill('0')<<block<<"  ";
        cout<<setfill(' ');
        for (int i=0; i<BLOCKSIZE; i++)
        {
            
            c =file.get();
            if (c == EOF)
                return -1;
            cout<<hex<<setw(4)<<static_cast<short> (c);   
            if (isprint(c))  
                temp+=c;
            else
                temp+='.';
        }
        block+=BLOCKSIZE;
        cout<<setw(20)<<temp<<endl;
    }
    
    return 0;
}
