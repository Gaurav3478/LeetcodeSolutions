class ParkingSystem {
public:
    vector<int> big, medium, small;
    int bigSz, medSz, smallSz;
    ParkingSystem(int big, int medium, int small) {
        bigSz = big;
        medSz = medium;
        smallSz = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(big.size() < bigSz) {
                big.push_back(1);
                return true;
            }
            else {
                return false;
            }
        }
        else if(carType == 2) {
            if(medium.size() < medSz) {
                medium.push_back(2);
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if(small.size()  < smallSz) {
                small.push_back(3);
                return true;
            }
            else {
                return false;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */