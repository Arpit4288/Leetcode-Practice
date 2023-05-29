class ParkingSystem {
public:
    int bigslot, mediumslot, smallslot;
    int big = 0, medium = 0, small = 0;
    ParkingSystem(int big, int medium, int small) {
        bigslot = big;
        mediumslot = medium;
        smallslot = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(big >= bigslot) return false;
            big++;
            return true;
        }
        if(carType == 2){
            if(medium >= mediumslot) return false;
            medium++;
            return true;
        }
        if(carType == 3){
            if(small >= smallslot) return false;
            small++;
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