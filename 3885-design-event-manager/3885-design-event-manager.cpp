class EventManager {
public:
    unordered_map<int, int> eventCurrPrio;
    priority_queue<int> bestPrio;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> prioEvents;
    unordered_set<int> currPrios;

    unordered_set<int> alreadyUsed;

    EventManager(vector<vector<int>>& events) {
        for (int i = 0; i < events.size(); i++) {
            int eventId = events[i][0];
            int prio = events[i][1];

            if (eventCurrPrio[eventId] == prio) {
                continue;
            }

            eventCurrPrio[eventId] = prio;

            if (!currPrios.contains(prio)) {
                bestPrio.push(prio);
            }

            prioEvents[prio].push(eventId);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if (eventCurrPrio[eventId] == newPriority) {
            return;
        }

        eventCurrPrio[eventId] = newPriority;

        if (!currPrios.contains(newPriority)) {
            bestPrio.push(newPriority);
        }

        prioEvents[newPriority].push(eventId);
    }
    
    int pollHighest() {
        while (!bestPrio.empty()) {

            int prio = bestPrio.top();

            while (!prioEvents[prio].empty()) {
                int eventId = prioEvents[prio].top();
                prioEvents[prio].pop();

                if (eventCurrPrio[eventId] == prio && !alreadyUsed.contains(eventId)) {
                    alreadyUsed.insert(eventId);
                    return eventId;
                }
            }

            bestPrio.pop();
            currPrios.erase(prio);
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */