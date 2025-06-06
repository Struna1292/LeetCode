# Write your MySQL query statement below
SELECT tab.actor_id, tab.director_id FROM (
    SELECT actor_id, director_id, COUNT(actor_id) FROM actordirector 
        GROUP BY actor_id, director_id
        HAVING COUNT(actor_id) >= 3) as tab