class FoodRatings {
public:
    struct Score {
        string food;
        int rating;

        Score(string f, int r) {
            food = f;
            rating = r;
        }
    };

    struct Comparator {
        bool operator()(Score a, Score b) {
            if (a.rating == b.rating) {
                return a.food > b.food;
            }
            return a.rating < b.rating;
        }
    };

    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, priority_queue<Score, vector<Score>, Comparator>> types;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            types[cuisines[i]].push(Score(foods[i], ratings[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRating[food] = newRating;
        string currCuisine = foodCuisine[food];

        types[currCuisine].push(Score(food, newRating));
    }
    
    string highestRated(string cuisine) {

        while (!types[cuisine].empty()) {
            Score currBest = types[cuisine].top();
            if (currBest.rating == foodRating[currBest.food]) {
                return currBest.food;
            }
            else {
                types[cuisine].pop();
            }
        }

        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */