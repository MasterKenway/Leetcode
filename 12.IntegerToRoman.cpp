//
// Created by Kenway on 7/21/2020.
//
#include <iostream>

class Solution {
public:
//    std::string intToRoman(int num) {
//        char result[20];
//        int i = 0, div = 10000;
//        while (div != 1) {
//            if ((num % div)/(div/10) == 4) {
//                switch (div) {
//                    case 10:
//                        result[i++] = 'I';
//                        result[i++] = 'V';
//                        break;
//                    case 100:
//                        result[i++] = 'X';
//                        result[i++] = 'L';
//                        break;
//                    case 1000:
//                        result[i++] = 'C';
//                        result[i++] = 'D';
//                        break;
//                    default:
//                        break;
//                }
//            } else if ((num % div)/(div/10) == 9) {
//                switch (div) {
//                    case 10:
//                        result[i++] = 'I';
//                        result[i++] = 'X';
//                        break;
//                    case 100:
//                        result[i++] = 'X';
//                        result[i++] = 'C';
//                        break;
//                    case 1000:
//                        result[i++] = 'C';
//                        result[i++] = 'M';
//                        break;
//                    default:
//                        break;
//                }
//            } else {
//                switch (div) {
//                    case 10:
//                        if (num % div < 5) {
//                            for (int j =  0; j < num % div; ++j)
//                                result[i++] = 'I';
//                        }
//                        else {
//                            result[i++] = 'V';
//                            for (int j = 0; j < num % div - 5; ++j)
//                                result[i++] = 'I';
//                        }
//                        break;
//                    case 100:
//                        if ((num % div)/10 < 5) {
//                            for (int j =  0; j < (num % div)/10; ++j)
//                                result[i++] = 'X';
//                        }
//                        else {
//                            result[i++] = 'L';
//                            for (int j = 0; j < (num % div)/10 - 5; ++j)
//                                result[i++] = 'X';
//                        }
//                        break;
//                    case 1000:
//                        if ((num % div)/100 < 5) {
//                            for (int j =  0; j < (num % div)/100 ; ++j)
//                                result[i++] = 'C';
//                        }
//                        else {
//                            result[i++] = 'D';
//                            for (int j = 0; j < (num % div)/100  - 5; ++j)
//                                result[i++] = 'C';
//                        }
//                        break;
//                    case 10000:
//                        for (int j =  0; j < (num % div)/1000 ; ++j)
//                            result[i++] = 'M';
//                        break;
//                    default:
//                        break;
//                }
//            }
//            div /= 10;
//        }
//        result[i] = '\0';
//        return result;
//    }

    std::string intToRoman(int num) {
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::string str[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        std::string result = {};
        int i = 0;
        while (num != 0) {
            while (num >= value[i]) {
                num -= value[i];
                result.append(str[i]);
            }
            i++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::cout << solution.intToRoman(100) << std::endl;
}