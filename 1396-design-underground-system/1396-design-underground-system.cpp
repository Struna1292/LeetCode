class UndergroundSystem {
public:
    struct Client {
        int id;
        string startStation;
        string endStation;
        int time;
    };
    
    vector<Client> travellers;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        travellers.push_back({id, stationName, "", t});
    }
    
    void checkOut(int id, string stationName, int t) {

        for (int i = 0; i < travellers.size(); i++)
        {
            if (travellers[i].id == id && travellers[i].endStation == "")
            {
                travellers[i].endStation = stationName;
                travellers[i].time = t - travellers[i].time;
                break;
            }
        }

    }

    double getAverageTime(string startStation, string endStation) {

        double timeSum = 0;
        double counter = 0;
        for (int i = 0; i < travellers.size(); i++)
        {
            if (travellers[i].startStation == startStation && travellers[i].endStation == endStation)
            {
                timeSum += travellers[i].time;
                counter++;
            }
        }

        return timeSum / counter;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */