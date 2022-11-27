#include <iostream>
#include <string>


int len(std::string str){
    long long c = 0;
    for(int i = 0; str[i] != '\0'; i++){
        c++;
    }
    return c;
}
std::string dec2bin(long long num){
    std::string out;
    while(num != 0){
        char a = (num % 2) + '0';
        out = a + out;
        num /= 2;
    }
    return out;
}
long long bin2dec(std::string num){
    long long out = 0;
    long long k = 1;
    for(int i = len(num) - 1; i >= 0; i--){
        out += (num[i] - '0')*k;
        k *= 2;
    }
    return out;
}

std::string dir2rev(std::string num){
    std::string out = "1";
    for(int i = 1; num[i] != '\0'; i++){
        if(num[i] == '1'){
            out += '0';
        }
        if(num[i] == '0'){
            out += '1';
        }
    }
    return out;
}

int main(){
    long long num;
    int bit;
    
    std::cout << "enter a number: ";
    std::cin >> num;
    std::cout << "enter number of bits: ";
    std::cin >> bit;

    std::string bin = dec2bin(num < 0 ? -num : num);
    int length = len(bin);

    if(length > bit-1){
        std::cout << "entered number longer than the number of bits entered";
        return 0;
    }

    if(num >= 0){
        int shift = bit - length;
        std::string out = std::string(shift, '0') + bin;
        
        std::cout << out;
    }
    else{
        int shift = bit - length - 1;
        std::string direct = '1' + std::string(shift, '0') + bin;
        std::string reverse = dir2rev(direct);
        std::string additional = dec2bin(bin2dec(reverse) + 1);

        std::cout << "direct: " << direct << " reverse: " << reverse << " additional: " << additional;
    }
    return 0;
}   