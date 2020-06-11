#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


#define BLOCKSIZE 16

using namespace std;



int main(int argc, char * argv[])
{
    if (argc!=2){
        cout<<"usage: myhexdump <filename> \n";
        return -1;}
    ifstream file(argv[1], ios::binary);
    if (!file.is_open()){
        cout<<"invalid filename!! \n";
        return -1;
    }
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
    file.close();
    return 0;
}
