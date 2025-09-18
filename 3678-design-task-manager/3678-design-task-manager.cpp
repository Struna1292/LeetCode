class TaskManager {
public:
    struct Comparator {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        }
    };

    // key taskId , value {userid, priority}
    unordered_map<int, vector<int>> um;
    // [priority, taskId, userId]
    priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            vector<int> task = tasks[i];
            int taskId = task[1];
            int priority = task[2];
            int userId = task[0];

            um[taskId] = {userId, priority};

            pq.push({priority, taskId, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        um[taskId] = {userId, priority};

        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        um[taskId][1] = newPriority;

        pq.push({newPriority, taskId, um[taskId][0]}); 
    }
    
    void rmv(int taskId) {
        um.erase(um.find(taskId));
    }
    
    int execTop() {
        
        while (!pq.empty()) {

            vector<int> task = pq.top();
            pq.pop();

            if (um.find(task[1]) != um.end() && um[task[1]][1] == task[0] && um[task[1]][0] == task[2]) {
                um.erase(um.find(task[1]));
                return task[2];
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */