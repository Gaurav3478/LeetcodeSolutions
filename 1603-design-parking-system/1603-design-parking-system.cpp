class ParkingSystem {
    int big;
    int medium;
    int small;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && big > 0) 
        {
            big -= 1;
            return true;
        }
        if(carType == 2 && medium > 0) 
        {
            medium -= 1;
            return true;
        }
        if(carType == 3 && small > 0) 
        {
            small -= 1;
            return true;
        }
        return false; 
    }
};