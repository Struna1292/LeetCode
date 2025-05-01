# Write your MySQL query statement below
SELECT id, movie, description, rating FROM cinema
    WHERE LOWER(description) != "boring" 
    AND id % 2 != 0
    ORDER BY rating DESC;
