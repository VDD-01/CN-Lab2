#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string ip;
    cout << "Enter the IP address: " << endl;
    cin >> ip;
    stringstream ss(ip);
    string part;
    int firstOctet;

    getline(ss, part, '.');
    firstOctet = stoi(part);
   
    if(firstOctet >= 0 && firstOctet<=126){
        cout << ip <<" belongs to class A.\n The subnet mask is 255.0.0.0. \n Hosts per network ID = 16777214. (2^24-2, -2 is done because one address is network address and one address is broadcast address)\n # of of networks = 128 (2^7 because the first bit is 0 and only the remaining 7 are used)" << endl;
    }else if(firstOctet >=128 && firstOctet<=191){
        cout << ip <<" belongs to class B.\n The subnet mask is 255.255.0.0. \n Hosts per network ID = 65534. (2^16-2, -2 is done because one address is network address and one address is broadcast address)\n # of of networks = 16384 (2^14 because the first 2 bits are 1 and 0 and only the remaining 14 are used)" << endl;
    }else if(firstOctet >=192 && firstOctet<=223){
        cout << ip <<" belongs to class C.\n The subnet mask is 255.255.255.0. \n Hosts per network ID = 254. (2^8-2, -2 is done because one address is network address and one address is broadcast address)\n # of of networks = 2097152 (2^21 because the first 3 bits are 1 and 0 and 0 and only the remaining 21 are used)" << endl;
    }else if(firstOctet >=224 && firstOctet<=239){
        cout << ip <<" belongs to class D (Multicast).\nSubnet mask not applicable" << endl;
    }else if(firstOctet >=240 && firstOctet<=255){
        cout << ip <<" belongs to class E (Experimental).\nSubnet mask not applicable" << endl;
    } else if (firstOctet == 127){
        cout << "127.x.x.x is reserved for Loopback addresses. A loopback address is a special IP address—such as 127.0.0.1 for IPv4 or ::1 for IPv6—that a computer uses to send data packets to itself. It allows software and network services on your local machine to talk to each other without sending any data out to an external network or the internet." << endl;
    }else{
        cout << "Invalid Ip address." << endl;
    }
}
