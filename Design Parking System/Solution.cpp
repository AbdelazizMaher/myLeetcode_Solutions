class ParkingSystem {
public:
    int m_big, m_medium, m_small;
    ParkingSystem(int big, int medium, int small) : m_big{big}, m_medium{medium}, m_small{small} {
        
    }
    
    bool addCar(int carType) {
        switch (carType)
        {
        case 1:
            return m_big-- > 0;
        case 2:
            return m_medium-- > 0;
        case 3:
            return m_small-- > 0;                      
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */