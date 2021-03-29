//
// Created by Kenway on 3/19/2021.
//

class ParkingSystem {
private:
    int bigSize, midSize, smSize;

public:
    ParkingSystem(int big, int medium, int small) {
        bigSize = big;
        midSize = medium;
        smSize = small;
    }

    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (bigSize) {
                    bigSize--;
                    return true;
                }
                else return 0;
                break;
            case 2:
                if (midSize) {
                    midSize--;
                    return true;
                }
                else return 0;
                break;
            case 3:
                if (smSize) {
                    smSize--;
                    return true;
                }
                else return 0;
                break;

        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */