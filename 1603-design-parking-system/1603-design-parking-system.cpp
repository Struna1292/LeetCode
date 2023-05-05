class ParkingSystem {
public:
    int big = 0;
    int medium = 0;
    int small = 0;
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if (carType == 3 && small)
        {
            small--;
            return true;
        }
        else if (carType == 2 && medium)
        {
            medium--;
            return true;
        }
        else if (carType == 1 && big)
        {
            big--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */